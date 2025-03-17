#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 1000

// Fonction pour trouver la valeur maximale qu'on peut obtenir
int knapsack(int weights[], int values[], int n, int W) {
    int f[MAX_ITEMS + 1][MAX_WEIGHT + 1];
    
    // Remplir la matrice f
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                f[i][w] = 0; // Base case
            } else if (weights[i - 1] <= w) {
                f[i][w] = (values[i - 1] + f[i - 1][w - weights[i - 1]] > f[i - 1][w]) 
                          ? (values[i - 1] + f[i - 1][w - weights[i - 1]]) 
                          : f[i - 1][w];
            } else {
                f[i][w] = f[i - 1][w];
            }
        }
    }

    return f[n][W]; // Valeur optimale
}

int main() {
    int values[] = {3, 5, 6, 7, 10}; // Valeurs des objets
    int weights[] = {2, 3, 4, 4, 8};   // Poids des objets
    int W = 10;                     // Capacité du sac
    int n = sizeof(values) / sizeof(values[0]);

    int max_value = knapsack(weights, values, n, W);
    printf("La valeur maximale que l'on peut obtenir est: %d\n", max_value);

    return 0;
}