#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure DateNaisRepere
struct DateNaisRepere {
    int jour, mois, annee;
};

// Définition de la structure EtudiantRepere
struct EtudiantRepere {
    char nom[45];
    int age, note;
    struct DateNaisRepere Date;
};

// Fonction pour écrire des enregistrements dans un fichier
void ecrireFichier() {
    FILE *pFile;
    char nom[30];
    int matricule, nbenreg, i;

    // Ouverture du fichier en mode écriture
    pFile = fopen("FICHIER1.TXT", "w");
    if (pFile == NULL) {
        printf("Erreur à l'ouverture du fichier.\n");
        return;
    }

    // Saisie des données
    printf("Taper le nombre d'enregistrements a creer : ");
    scanf("%d", &nbenreg);

    for (i = 1; i <= nbenreg; i++) {
        printf("L'enregistrement No: %d\n", i);
        printf("Numero de matricule: ");
        scanf("%d", &matricule);
        printf("Nom: ");
        scanf("%s", nom);
        fprintf(pFile, "%d %s\n", matricule, nom);
    }

    // Fermeture du fichier
    fclose(pFile);
}

// Fonction pour afficher le contenu d'un fichier
void afficherFichier(char *nomFichier) {
    FILE *pFile;
    char nom[30];
    int matricule;

    // Ouverture du fichier en mode lecture
    pFile = fopen(nomFichier, "r");
    if (pFile == NULL) {
        printf("Erreur à l'ouverture du fichier.\n");
        return;
    }

    // Affichage du contenu du fichier
    printf("**** Voici le contenu du fichier %s ***\n", nomFichier);
    while (fscanf(pFile, "%d %s", &matricule, nom) != EOF) {
        printf("Matricule: %d\n", matricule);
        printf("Nom: %s\n", nom);
    }

    // Fermeture du fichier
    fclose(pFile);
}

// Fonction pour insérer un nouvel enregistrement dans un fichier trié
void insererEnregistrement() {
    FILE *pFile1, *pFile2;
    char nom[30], NewNom[30];
    int matricule, NewMatricule;
    int TROUVE = 0;

    // Saisie du nouvel enregistrement
    printf("L'enregistrement à ajouter :\n");
    printf("Numéro de matricule : ");
    scanf("%d", &NewMatricule);
    printf("Nom : ");
    scanf("%s", NewNom);

    // Ouverture du nouveau fichier en mode écriture
    pFile2 = fopen("FICHIER2.TXT", "w");
    if (pFile2 == NULL) {
        printf("Erreur à l'ouverture du fichier.\n");
        return;
    }

    // Ouverture de l'ancien fichier en mode lecture
    pFile1 = fopen("FICHIER1.TXT", "r");
    if (pFile1 == NULL) {
        printf("Erreur à l'ouverture du fichier.\n");
        fclose(pFile2);
        return;
    }

    // Parcourir l'ancien fichier et insérer le nouvel enregistrement
    while (fscanf(pFile1, "%d %s", &matricule, nom) != EOF) {
        if (strcmp(nom, NewNom) > 0 && TROUVE == 0) {
            fprintf(pFile2, "%d %s\n", NewMatricule, NewNom);
            TROUVE = 1;
        }
        fprintf(pFile2, "%d %s\n", matricule, nom);
    }

    // Si le nouvel enregistrement n'a pas encore été inséré
    if (TROUVE == 0) {
        fprintf(pFile2, "%d %s\n", NewMatricule, NewNom);
    }

    // Fermeture des fichiers
    fclose(pFile1);
    fclose(pFile2);
}

int main() {
    int choix;

    while (1) {
        printf("\nMenu :\n");
        printf("1. Créer des enregistrements\n");
        printf("2. Afficher le contenu de FICHIER1.TXT\n");
        printf("3. Insérer un nouvel enregistrement\n");
        printf("4. Afficher le contenu de FICHIER2.TXT\n");
        printf("5. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ecrireFichier();
                break;
            case 2:
                afficherFichier("FICHIER1.TXT");
                break;
            case 3:
                insererEnregistrement();
                break;
            case 4:
                afficherFichier("FICHIER2.TXT");
                break;
            case 5:
                exit(0);
            default:
                printf("Choix invalide.\n");
        }
    }

    return 0;
}