#include <stdio.h>

int NombreChemins(int n, int m) {
    if (n == 0 || m == 0)
        return 1;
    return NombreChemins(n - 1, m) + NombreChemins(n, m - 1);
}

int main() {
    int n = 3, m = 6;
    printf("Nombre de chemins de (%d, %d) a (0, 0): %d\n", n, m, NombreChemins(n, m));
    return 0;
}

/*
NombreChemins(3, 6)
├── NombreChemins(2, 6)
│   ├── NombreChemins(1, 6)
│   │   ├── NombreChemins(0, 6) → 1
│   │   └── NombreChemins(1, 5)
│   │       ├── NombreChemins(0, 5) → 1
│   │       └── NombreChemins(1, 4)
│   │           ├── NombreChemins(0, 4) → 1
│   │           └── NombreChemins(1, 3)
│   │               ├── NombreChemins(0, 3) → 1
│   │               └── NombreChemins(1, 2)
│   │                   ├── NombreChemins(0, 2) → 1
│   │                   └── NombreChemins(1, 1)
│   │                       ├── NombreChemins(0, 1) → 1
│   │                       └── NombreChemins(1, 0) → 1
│   │                       → 2
│   │                   → 3
│   │               → 4
│   │           → 5
│   │       → 6
│   └── NombreChemins(2, 5)
│       ├── NombreChemins(1, 5) → 6
│       └── NombreChemins(2, 4)
│           ├── NombreChemins(1, 4) → 5
│           └── NombreChemins(2, 3)
│               ├── NombreChemins(1, 3) → 4
│               └── NombreChemins(2, 2)
│                   ├── NombreChemins(1, 2) → 3
│                   └── NombreChemins(2, 1)
│                       ├── NombreChemins(1, 1) → 2
│                       └── NombreChemins(2, 0) → 1
│                       → 3
│                   → 6
│               → 10
│           → 15
│       → 21
└── NombreChemins(3, 5)
    ├── NombreChemins(2, 5) → 21
    └── NombreChemins(3, 4)
        ├── NombreChemins(2, 4) → 15
        └── NombreChemins(3, 3)
            ├── NombreChemins(2, 3) → 10
            └── NombreChemins(3, 2)
                ├── NombreChemins(2, 2) → 6
                └── NombreChemins(3, 1)
                    ├── NombreChemins(2, 1) → 3
                    └── NombreChemins(3, 0) → 1
                    → 4
                → 10
            → 20
        → 35
    → 56

*/