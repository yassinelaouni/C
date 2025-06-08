#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Enregistrement {
    char nom[50];
    int matricule;
};

int main() {
    FILE *fichier1, *fichier2;
    struct Enregistrement enr, nouveauEnr;
    int n = 0, i, j;
    struct Enregistrement *enregistrements;

    // Ouvrir FICHIER1.TXT en mode lecture
    fichier1 = fopen("FICHIER1.TXT", "r");
    if (fichier1 == NULL) {
        printf("Erreur lors de l'ouverture du fichier FICHIER1.TXT.\n");
        return 1;
    }

    // Compter le nombre d'enregistrements dans FICHIER1.TXT
    char ligne[100];
    while (fgets(ligne, sizeof(ligne), fichier1)) {
        n++;
    }

    // Allouer de la mémoire pour stocker les enregistrements
    enregistrements = (struct Enregistrement *)malloc((n + 1) * sizeof(struct Enregistrement));
    if (enregistrements == NULL) {
        printf("Erreur d'allocation de mémoire.\n");
        fclose(fichier1);
        return 1;
    }

    // Revenir au début du fichier
    rewind(fichier1);

    // Lire les enregistrements dans un tableau
    for (i = 0; i < n; i++) {
        fscanf(fichier1, "%s %d", enregistrements[i].nom, &enregistrements[i].matricule);
    }

    // Fermer FICHIER1.TXT
    fclose(fichier1);

    // Saisir le nouvel enregistrement
    printf("Entrez le nom du nouvel enregistrement : ");
    scanf("%s", nouveauEnr.nom);
    printf("Entrez le matricule du nouvel enregistrement : ");
    scanf("%d", &nouveauEnr.matricule);

    // Trouver la position d'insertion du nouvel enregistrement
    for (i = 0; i < n; i++) {
        if (strcmp(nouveauEnr.nom, enregistrements[i].nom) < 0) {
            break;
        }
    }

    // Décaler les enregistrements pour faire de la place
    for (j = n; j > i; j--) {
        enregistrements[j] = enregistrements[j - 1];
    }

    // Insérer le nouvel enregistrement
    enregistrements[i] = nouveauEnr;
    n++;

    // Ouvrir FICHIER2.TXT en mode écriture
    fichier2 = fopen("FICHIER2.TXT", "w");
    if (fichier2 == NULL) {
        printf("Erreur lors de l'ouverture du fichier FICHIER2.TXT.\n");
        free(enregistrements);
        return 1;
    }

    // Écrire les enregistrements dans FICHIER2.TXT
    for (i = 0; i < n; i++) {
        fprintf(fichier2, "%s %d\n", enregistrements[i].nom, enregistrements[i].matricule);
    }

    // Fermer FICHIER2.TXT
    fclose(fichier2);

    // Afficher le contenu de FICHIER2.TXT
    printf("\nContenu du fichier FICHIER2.TXT :\n");
    fichier2 = fopen("FICHIER2.TXT", "r");
    if (fichier2 == NULL) {
        printf("Erreur lors de l'ouverture du fichier FICHIER2.TXT.\n");
        free(enregistrements);
        return 1;
    }

    // Lire et afficher le contenu du fichier en utilisant feof
    while (feof(fichier2) == 0) {
        fgets(ligne, sizeof(ligne), fichier2);
        printf("%s", ligne);
    }

    fclose(fichier2);

    // Libérer la mémoire
    free(enregistrements);

    return 0;
}