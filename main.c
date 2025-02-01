#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if the array is sorted
bool isPalindrome(char T[], int first,int last) {
    if (first >= last) return true; 
    if (T[first] != T[last]) return false; 
    return isPalindrome(T,first + 1, last - 1); 
}

int main() {
    char T[] = "KAYAK"; 
    int n = 5 ; 
    printf("Est palindrome: %s\n", isPalindrome(T,0, n-1) ? "Oui" : "Non");

    return 0;
}