#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *TEXTE[5];  
    char INTRO[500]; 
    char *PAIDE;     
    int I, J;        

    printf("Entrez 5 phrases, chacune se terminant par Entree :\n");
    
    for (I = 0; I < 5; I++) {
        printf("Phrase %d : ", I + 1);
        fgets(INTRO, sizeof(INTRO), stdin);
        INTRO[strcspn(INTRO, "\n")] = '\0';

        TEXTE[I] = (char *)malloc(strlen(INTRO) + 1);
        if (TEXTE[I]) {
            strcpy(TEXTE[I], INTRO);
        } else {
            printf("\aMemoire insuffisante !\n");
            exit(-1);
        }
    }
    printf("\nOrdre original :\n");
    for (I = 0; I < 5; I++) {
        puts(TEXTE[I]);
    }
    for (I = 0, J = 4; I < J; I++, J--) {
        // PAIDE = TEXTE[I];
        // TEXTE[I] = TEXTE[J];
        // TEXTE[J] = PAIDE;
        strcpy()

    }
    printf("\nOrdre inverse :\n");
    for (I = 0; I < 5; I++) {
        puts(TEXTE[I]);
    }
    for (I = 0; I < 5; I++) {
        free(TEXTE[I]);
    }

    return 0;
}
