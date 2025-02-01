#include <stdio.h>

void triBulles(int arr[], int n) {
    int i, j, temp;

    // Parcourir le tableau
    for (i = 0; i < n - 1; i++) {
        // Comparer les éléments adjacents
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Échanger si l'élément actuel est plus grand que le suivant
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    triBulles(arr, n);

    printf("Tableau trié à bulles : \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}