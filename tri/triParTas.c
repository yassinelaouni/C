#include <stdio.h>

// Échanger deux éléments
void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify un sous-arbre enraciné à l'indice i
void heapify(int T[], int n, int i) {
    int plusGrand = i;       // Initialiser le plus grand comme racine
    int g = 2 * i + 1;  // Indice du fils g
    int d = 2 * i + 2;  // Indice du fils droit

    // Si le fils g est plus grand que la racine
    if (g < n && T[g] > T[plusGrand]) {
        plusGrand = g;
    }
 
    // Si le fils droit est plus grand que le plus grand actuel
    if (d < n && T[d] > T[plusGrand]) {
        plusGrand = d;
    }

    // Si le plus grand n'est pas la racine
    if (plusGrand != i) {
        echanger(&T[i], &T[plusGrand]); // Échanger
        heapify(T, n, plusGrand);         // Heapify récursivement le sous-arbre affecté
    }
}

// Fonction principale pour le tri par tas
void triParTas(int T[], int n) {
    // Construire le max-heap (réorganiser le tableau)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(T, n, i);
    }

    // Extraire les éléments un par un du tas
    for (int i = n - 1; i > 0; i--) {
        // Déplacer la racine actuelle à la fin
        echanger(&T[0], &T[i]);

        // Appeler heapify sur le tas réduit
        heapify(T, i, 0);
    }
}

// Afficher le tableau
void afficherTableau(int T[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
}

int main() {
    int T[] = {12, 11, 13, 5, 6, 7, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 1, 2, 3, 4, 8, 9, 10, 14};
    int n = sizeof(T) / sizeof(T[0]);

    printf("Tableau initial : \n");
    afficherTableau(T, n);

    triParTas(T, n);

    printf("Tableau trie par tas : \n");
    afficherTableau(T, n);

    return 0;
}