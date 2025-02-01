#include <stdio.h>

// Fonction récursive pour calculer la longueur d'une chaîne
int longueur(char *S, int i) {
    if (S[i] == '\0') { // Cas de base : fin de la chaîne
        return 0;
    } else { // Cas récursif
        return 1 + longueur(S, i + 1);
    }
}

int main() {
    char S[] = "Bonjour"; // Exemple de chaîne
    int taille = longueur(S, 0); // Appel de la fonction récursive
    printf("La longueur de la chaîne est : %d\n", taille); // Affichage du résultat
    return 0;
}