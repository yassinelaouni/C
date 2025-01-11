#include <stdio.h>

// Échanger deux éléments
void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partitionner le tableau autour du pivot
int partition(int arr[], int bas, int haut) {
    int pivot = arr[haut]; // Choisir le dernier élément comme pivot
    int i = (bas - 1);     // Index du plus petit élément

    for (int j = bas; j <= haut - 1; j++) {
        // Si l'élément actuel est plus petit que le pivot
        if (arr[j] < pivot) {
            i++; // Incrémenter l'index du plus petit élément
            echanger(&arr[i], &arr[j]);
        }
    }
    echanger(&arr[i + 1], &arr[haut]); // Placer le pivot à sa place correcte
    return (i + 1);
}

// Fonction récursive pour trier le tableau
void triRapide(int arr[], int bas, int haut) {
    if (bas < haut) {
        // Partitionner le tableau
        int pi = partition(arr, bas, haut);

        // Trier les sous-tableaux récursivement
        triRapide(arr, bas, pi - 1);
        triRapide(arr, pi + 1, haut);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    triRapide(arr, 0, n - 1);

    printf("Tableau trie par tri rapide : \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}