#include <stdio.h>

// Échanger deux éléments
void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partitionner le tableau autour du pivot
int partition(int T[], int g, int d) {
    int pivot = T[d]; // Choisir le dernier élément comme pivot
    int i = (g - 1);     // Index du plus petit élément

    for (int j = g; j <= d - 1; j++) {
        // Si l'élément actuel est plus petit que le pivot
        if (T[j] < pivot) {
            i++; // Incrémenter l'index du plus petit élément
            echanger(&T[i], &T[j]);
        }
    }
    echanger(&T[i + 1], &T[d]); // Placer le pivot à sa place correcte
    return (i + 1);
}

// Fonction récursive pour trier le tableau
void triRapide(int T[], int g, int d) {
    if (g < d) {
        // Partitionner le tableau
        int pi = partition(T, g, d);

        // Trier les sous-tableaux récursivement
        triRapide(T, g, pi - 1);
        triRapide(T, pi + 1, d);
    }
}

int main() {
    int T[] = {64, 25, 12, 22, 11};
    int n = sizeof(T) / sizeof(T[0]);

    triRapide(T, 0, n - 1);

    printf("Tableau trie par tri rapide : \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    return 0;
}