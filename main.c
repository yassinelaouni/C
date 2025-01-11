#include <stdio.h>

int main() {
    int compteur = 0;
    int i = 1;
    int n;

    printf("Entrez la valeur de n : ");
    scanf("%d", &n);

    while (i < n) {
        int j = i + 1;
        while (j <= n) {
            compteur++;
            j++;
        }
        i = i * 2;
    }

    printf("La valeur finale du compteur est : %d\n", compteur);
    return 0;
}