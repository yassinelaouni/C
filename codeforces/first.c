#include <stdio.h>

int main() {
    int a;
    int res = 0;
    int n;
    int count = 0;

    scanf("%d", &n);

    while (n--) {
        count = 0;
        for (int i = 0; i < 3; i++) {
            scanf("%d", &a);
            if (a == 1) {  // Corrected: Move condition inside the loop
                count++;
            }
        }

        if (count >= 2) {  // If at least 2 values are 1, increment res
            res++;
        }
    }

    printf("%d", res);
    return 0;
}
