#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char INTRO[500]; // Chaine pour l'introduction des données
    char *TEXTE[5]; // Tableau des pointeurs sur les 5 chaines
    char *PAIDE; // Pointeur d'aide pour l'échange des pointeurs
    int I, J; // Indices courants
    char CAIDE[50];
    // Saisie des données et allocation dynamique de mémoire
    puts("Introduire 5 phrases terminees chaque fois par un retour a la ligne:");

    for (I = 0; I < 5; I++) {
        printf("Phrase N%d: ", I + 1);
        gets(INTRO);


        // Réservation de la mémoire
        TEXTE[I] = (char*) malloc(strlen(INTRO));

        // S'il y a assez de mémoire
        if (TEXTE[I]) {
            strcpy(TEXTE[I], INTRO);
        } else {
            printf("\aPas assez de memoire \n");
            exit(-1);
        }
    }

    // Afficher le tableau donné
    puts("Contenu du tableau donn");
    for (I = 0; I < 5; I++) {
        puts(TEXTE[I]);
    }

    // Inverser l'ordre des phrases avec le pointeur PAIDE
    for (I = 0, J = 4; I < J; I++, J--) {
       /* PAIDE = TEXTE[I];
        TEXTE[I] = TEXTE[J];
        TEXTE[J] = PAIDE;*/
        strcpy( CAIDE,TEXTE[I]);
        TEXTE[I]=(char*)realloc(TEXTE[I],(strlen(TEXTE[J]))*sizeof(char));
        strcpy( TEXTE[I],TEXTE[J]);
        TEXTE[J]=(char*)realloc(TEXTE[J],(strlen(CAIDE))*sizeof(char));
        strcpy(TEXTE[J],CAIDE);

    }

    // Afficher le tableau résultat
    puts("Contenu du tableau resultat:");
    for (I = 0; I < 5; I++) {
        puts(TEXTE[I]);
    }

    // Libération de l'espace mémoire
    for (I = 0; I < 5; I++) {
        free(TEXTE[I]);
        free(TEXTE);
    }

    return 0;


}
