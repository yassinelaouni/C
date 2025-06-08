#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>  // Added for isdigit()

typedef struct Element {
    int valeur;
    struct Element *suivant;
} Element;

typedef struct Pile {
    Element *tete;
    int nef;
} Pile;

Element* CreerElement() {
    Element *El = (Element*)malloc(sizeof(Element));
    if (El == NULL) {
        exit(EXIT_FAILURE);
    }
    El->valeur = 0;
    El->suivant = NULL;
    return El;
}

Pile* CreerPile() {
    Pile *Pi = (Pile*)malloc(sizeof(Pile));
    if (Pi == NULL) {
        exit(EXIT_FAILURE);
    }
    Pi->tete = NULL;
    Pi->nef = 0;
    return Pi;
}

void Empiler(Pile *Pi, int vad) {
    if (Pi == NULL) {
        exit(EXIT_FAILURE);
    }
    Element *El = CreerElement();
    El->valeur = vad;
    El->suivant = Pi->tete;
    Pi->tete = El;
    Pi->nef++;
}

int Depiler(Pile *Pi) {
    if (Pi == NULL || Pi->tete == NULL) {
        printf("Erreur: depilement sur pile vide\n");
        exit(EXIT_FAILURE);
    }
    Element *ptr = Pi->tete;
    int vsd = ptr->valeur;
    Pi->tete = ptr->suivant;
    free(ptr);
    Pi->nef--;
    return vsd;
}

void AfficherPile(Pile *Pi) {
    if (Pi == NULL) {
        printf("Pile inexistante\n");
        return;
    }
    Element *ptr = Pi->tete;
    while (ptr != NULL) {
        printf("%d\n", ptr->valeur);
        ptr = ptr->suivant;
    }
    printf("NULL\n");
}

int main() {
    Pile *Pi1 = CreerPile();
    char exp[20];
    char sym = '\0';  // Initialize operator
    int x, y, res;
    
    printf("Saisir une expression : ");
    fgets(exp, sizeof(exp), stdin);  // Replaced gets() with fgets()
    exp[strcspn(exp, "\n")] = '\0';  // Remove newline character
    
    printf("exp: %s\t taille: %ld\n", exp, strlen(exp));
    
    for(int i = 0; i < strlen(exp); i++) {
        if(isdigit(exp[i])) {
            Empiler(Pi1, exp[i] - '0');
            printf("\nEmpile: %d\n", exp[i] - '0');
            AfficherPile(Pi1);
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
            sym = exp[i];  // Store operator for later use
        }
        else if(exp[i] == ')') {
            x = Depiler(Pi1);
            y = Depiler(Pi1);
            printf("\nOperation: %d %c %d\n", y, sym, x);
            
            switch(sym) {
                case '+': res = y + x; break;
                case '-': res = y - x; break;
                case '*': res = y * x; break;
                default: 
                    printf("Operateur invalide\n");
                    exit(EXIT_FAILURE);
            }
            
            printf("Resultat: %d\n", res);
            Empiler(Pi1, res);
            AfficherPile(Pi1);
        }
        // Ignore other characters (spaces, '(' etc.)
    }
    
    printf("\nResultat final:\n");
    AfficherPile(Pi1);
    
    // Clean up
    while(Pi1->tete != NULL) {
        Depiler(Pi1);
    }
    free(Pi1);
    
    return 0;
}