#include <stdio.h>

// Fonction pour échanger deux valeurs
void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction heapify pour transformer un sous-arbre en max-heap
void heapify(int arr[], int n, int i) {
    int plusGrand = i;       // On commence par le nœud actuel
    int gauche = 2 * i + 1;  // Indice du fils gauche
    int droite = 2 * i + 2;  // Indice du fils droit

    // Si le fils gauche est plus grand que le nœud actuel
    if (gauche < n && arr[gauche] > arr[plusGrand]) {
        plusGrand = gauche;
    }

    // Si le fils droit est plus grand que le nœud actuel
    if (droite < n && arr[droite] > arr[plusGrand]) {
        plusGrand = droite;
    }

    // Si le nœud actuel n'est pas le plus grand
    if (plusGrand != i) {
        echanger(&arr[i], &arr[plusGrand]); // On échange les valeurs
        heapify(arr, n, plusGrand);         // On appelle heapify sur le nouveau nœud
    }
}

// Fonction pour transformer le tableau en max-heap
void construireMaxHeap(int arr[], int n) {
    // On commence par le dernier nœud non feuille et on remonte
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Fonction pour afficher le tableau
void afficherTableau(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 7, 15, 6, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Tableau initial : \n");
    afficherTableau(arr, n);

    // Transformer le tableau en max-heap
    construireMaxHeap(arr, n);

    printf("Tableau apres transformation en max-heap : \n");
    afficherTableau(arr, n);

    return 0;
}