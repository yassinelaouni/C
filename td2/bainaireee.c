#include <stdio.h>

void Binaire(int N) {
    if (N > 2) {
        printf("%d", N % 2);
    }
    Binaire(N / 2);
}

int main() {
    int N;
    printf("Entrez un nombre entier: ");
    scanf("%d", &N);
    printf("La representation binaire de %d est: ", N);
    Binaire(N);
    printf("\n");
    return 0;
}