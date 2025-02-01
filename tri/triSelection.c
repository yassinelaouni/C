#include <stdio.h>

void triSelection(int arr[], int n) {
    int i, j, minIndex, temp;

    // Parcourir le tableau
    for (i = 0; i < n - 1; i++) {
        // Trouver l'indice du minimum dans le sous-tableau non trié
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        } 

        // Échanger l'élément minimum avec l'élément actuel
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    triSelection(arr, n);

    printf("Tableau trie par selection : \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}


