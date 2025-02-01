#include <stdio.h>

int EstTrie(int arr[], int n) {
    if (n == 1)
        return 1;
    return arr[n - 2] <= arr[n - 1] && EstTrie(arr, n - 1);
}

int main() {
    int tableau[] = {1, 2, 3, 4, 5};
    int n = sizeof(tableau) / sizeof(tableau[0]);
    printf("Est trie: %s\n", EstTrie(tableau, n) ? "Oui" : "Non");
    return 0;
}
