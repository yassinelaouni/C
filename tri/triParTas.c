#include <stdio.h>

// Échanger deux éléments
void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify un sous-arbre enraciné à l'indice i
void heapify(int arr[], int n, int i) {
    int plusGrand = i;       // Initialiser le plus grand comme racine
    int gauche = 2 * i + 1;  // Indice du fils gauche
    int droite = 2 * i + 2;  // Indice du fils droit

    // Si le fils gauche est plus grand que la racine
    if (gauche < n && arr[gauche] > arr[plusGrand]) {
        plusGrand = gauche;
    }

    // Si le fils droit est plus grand que le plus grand actuel
    if (droite < n && arr[droite] > arr[plusGrand]) {
        plusGrand = droite;
    }

    // Si le plus grand n'est pas la racine
    if (plusGrand != i) {
        echanger(&arr[i], &arr[plusGrand]); // Échanger
        heapify(arr, n, plusGrand);         // Heapify récursivement le sous-arbre affecté
    }
}

// Fonction principale pour le tri par tas
void triParTas(int arr[], int n) {
    // Construire le max-heap (réorganiser le tableau)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extraire les éléments un par un du tas
    for (int i = n - 1; i > 0; i--) {
        // Déplacer la racine actuelle à la fin
        echanger(&arr[0], &arr[i]);

        // Appeler heapify sur le tas réduit
        heapify(arr, i, 0);
    }
}

// Afficher le tableau
void afficherTableau(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 1, 2, 3, 4, 8, 9, 10, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Tableau initial : \n");
    afficherTableau(arr, n);

    triParTas(arr, n);

    printf("Tableau trie par tas : \n");
    afficherTableau(arr, n);

    return 0;
}