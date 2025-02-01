#include <stdio.h>

float puissance(float x, int n) {
    float res = 1;
    for (int i = 0; i < n; i++) {
        res *= x;  // Multiplication répétée
    }
    return res;
}

int main() {
    float x = 2.0;  // Base
    int n = 5;       // Exposant
    printf("%.2f^%d = %.2f\n", x, n, puissance(x, n));
    return 0;
}
