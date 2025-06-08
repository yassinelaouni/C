#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    /* Declarations */
    char INTR0[500]; /* chaine pour l'introduction des données */
    char *TEXTE[5]; /* Tableau des pointeurs sur les 5 chaînes */
    char *PAIDE; /* pointeur d'aide pour l'échange des pointeurs */
    int I, J; /* indices courants */

    /* Saisie des données et allocation dynamique de mémoire */
    puts("Introduire 5 phrases terminees chaque fois par un retour à la ligne :");
    for (I = 0; I < 5; I++)
    {
        /* Lecture d'une phrase */
        printf("Phrase %d : ", I + 1);
        gets(INTR0);

        /* Réservation de la mémoire */
        TEXTE[I] = (char *)malloc(strlen(INTR0) + 1);

        /* S'il y a assez de mémoire, ... */
        if (TEXTE[I])
            strcpy(TEXTE[I], INTR0);
        else
        {
            /* sinon afficher un message d'erreur */
            printf("\aPas assez de mémoire \n");
            /* et quitter le programme. */
            exit(EXIT_FAILURE);
        }
    }

    /* Afficher le tableau donné */
    puts("Contenu du tableau donne :");
    for (I = 0; I < 5; I++) {
        puts(TEXTE[I]);
    }

    /* Inverser l'ordre des phrases avec le pointeur PAIDE */
    for (I = 0, J = 4; I < J; I++, J--) {
        PAIDE = TEXTE[I];
        TEXTE[I] = TEXTE[J];
        TEXTE[J] = PAIDE;
    }

    /* Afficher le tableau résultat */
    puts("Contenu du tableau resultat :");
    for (I = 0; I < 5; I++) {
        puts(TEXTE[I]);
    }

    /**********************libération de l'espace mémoire***************/
    for (I = 0; I < 5; I++)
        free(TEXTE[I]); // Libérer la mémoire allouée pour chaque chaîne
    /*********************************IMPORTANT*********************************/

    // Wait for user input before closing
    printf("Press any key to exit...");
    getchar();

    return 0;
}
