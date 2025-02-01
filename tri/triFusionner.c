#include <stdio.h>
#include <stdlib.h>

// Fusionner deux sous-tableaux triés
void triFusionner(int arr[], int gauche, int milieu, int droite) {
    int i, j, k;
    int n1 = milieu - gauche + 1;
    int n2 = droite - milieu;

    // Tableaux temporaires
    int *G = (int *)malloc(n1 * sizeof(int));
    int *D = (int *)malloc(n2 * sizeof(int));

    // Copier les données dans les tableaux temporaires
    for (i = 0; i < n1; i++) G[i] = arr[gauche + i];
    for (j = 0; j < n2; j++) D[j] = arr[milieu + 1 + j];

    // Fusionner les tableaux temporaires dans arr[gauche..droite]
    i = 0; j = 0; k = gauche;
    while (i < n1 && j < n2) {
        if (G[i] <= D[j]) {
            arr[k] = G[i];
            i++;
        } else {
            arr[k] = D[j];  
            j++;
        }
        k++;
    }

    // Copier les éléments restants de G (s'il y en a)
    while (i < n1) {
        arr[k] = G[i];
        i++;
        k++;
    }

    // Copier les éléments restants de D (s'il y en a)
    while (j < n2) {
        arr[k] = D[j];
        j++;
        k++;
    }

    free(G);
    free(D);
}

// Fonction récursive pour trier le tableau
void triFusion(int arr[], int gauche, int droite) {
    if (gauche < droite) {
        int milieu = gauche + (droite - gauche) / 2;

        // Trier les deux moitiés
        triFusion(arr, gauche, milieu);
        triFusion(arr, milieu + 1, droite);

        // Fusionner les moitiés triées
        triFusionner(arr, gauche, milieu, droite);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    triFusion(arr, 0, n - 1);

    printf("Tableau trié par fusion : \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}