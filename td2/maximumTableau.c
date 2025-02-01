#include <stdio.h>

int MaximumTableau(int arr[], int n) {
    if (n == 1)
        return arr[0];
    int maxRestant = MaximumTableau(arr, n - 1);
    return arr[n - 1] > maxRestant ? arr[n - 1] : maxRestant;
}

int main() {
    int tableau[] = {3, 1, 4, 1, 5, 9};
    int n = sizeof(tableau) / sizeof(tableau[0]);
    printf("Maximum d'un tableau : %d\n", MaximumTableau(tableau, n));
    return 0;
}
