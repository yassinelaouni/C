#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Enregistrement {
    char nom[50];
    int matricule;
};

int main() {
    FILE *fichier;
    int n, i;

    // Demander le nombre d'enregistrements
    printf("Entrez le nombre d'enregistrements : ");
    scanf("%d", &n);

    // Ouvrir le fichier en mode écriture
    fichier = fopen("FICHIER1.TXT", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    // Saisir les enregistrements et les écrire dans le fichier
    for (i = 0; i < n; i++) {
        struct Enregistrement enr;
        printf("Entrez le nom de l'enregistrement %d : ", i + 1);
        scanf("%s", enr.nom);
        printf("Entrez le matricule de l'enregistrement %d : ", i + 1);
        scanf("%d", &enr.matricule);

        fprintf(fichier, "%s %d\n", enr.nom, enr.matricule);
    }

    // Fermer le fichier
    fclose(fichier);

    // Afficher le contenu du fichier
    printf("\nContenu du fichier FICHIER1.TXT :\n");
    fichier = fopen("FICHIER1.TXT", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    char ligne[100];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        printf("%s", ligne);
    }

    fclose(fichier);
     
     

    return 0;
}
