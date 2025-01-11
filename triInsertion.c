#include <stdio.h>

void triInsertion(int arr[], int n) {
    int i, j, key;

    // Parcourir le tableau
    for (i = 1; i < n; i++) {
        key = arr[i]; // Élément à insérer
        j = i - 1;

        // Déplacer les éléments plus grands que key vers la droite
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insérer key à sa place correcte
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    triInsertion(arr, n);

    printf("Tableau trié par insertion : \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}