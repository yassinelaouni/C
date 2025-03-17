#include <stdio.h>

void Binaire(int N) {
    char binaire[32]; // Stocker la représentation binaire (max 32 bits pour un int)
    int longueur = 0;

    if (N == 0) {
        printf("0");
        return;
    }

    // Convertir en binaire (ordre inversé)
    while (N > 0) {
        binaire[longueur++] = (N % 2) + '0'; // Stocke '0' ou '1' comme caractère
        N /= 2;
    }

    // Affichage dans le bon ordre (car stocké en sens inverse)
    for (int i = longueur - 1; i >= 0; i--) {
        printf("%c", binaire[i]);
    }
}

int main() {
    int N;
    printf("Entrez un nombre entier: ");
    scanf("%d", &N);
    printf("La représentation binaire de %d est: ", N);
    Binaire(N);
    printf("\n");
    return 0;
}
