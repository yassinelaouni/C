#include <stdio.h>
#include <string.h>

int EstPalindrome(const char *mot, int debut, int fin) {
    if (debut >= fin)
        return 1;
    return mot[debut] == mot[fin] && EstPalindrome(mot, debut + 1, fin - 1);
}

int main() {
    char mot[] = "KAYAK";
    printf("Est palindrome: %s\n", EstPalindrome(mot, 0, strlen(mot) - 1) ? "Oui" : "Non");
    return 0;
}
