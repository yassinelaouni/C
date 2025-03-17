#include <stdio.h>

// Échanger deux éléments
void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void triSelection(int T[], int n) {
    int i, j, minIndex;

    // Parcourir le tableau
    for (i = 0; i < n - 1; i++) {
        // Trouver l'indice du minimum dans le sous-tableau non trié
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (T[j] < T[minIndex]) {
                minIndex = j;
            }
        } 

        echanger(&T[minIndex], &T[i]);
    }
}

int main() {
    int T[] = {64, 25, 12, 22, 11};
    int n = sizeof(T) / sizeof(T[0]);

    triSelection(T, n);

    printf("Tableau trie par selection : \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    return 0;
}


