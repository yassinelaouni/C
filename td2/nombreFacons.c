#include <stdio.h>

// Fonction récursive pour calculer le nombre de façons
int nbFacons(int obj, int *S, int n) {
    if (obj == 0)
        return 1; // Si l'objectif est atteint
    if (obj < 0)
        return 0; // Si l'objectif est dépassé
    if (obj > 0 && n == 0)
        return 0; // Si aucun élément n'est disponible

    // Inclure ou exclure l'élément actuel
    return nbFacons(obj - S[0], S, n) + nbFacons(obj, S + 1, n - 1);
}

int main() {
    int S[] = {3, 5, 10}; 
    int obj = 20;         
    int n = sizeof(S) / sizeof(S[0]);

    printf("Le nombre de facons est : %d\n", nbFacons(obj, S, n));
    return 0;
}

/*
(20, {3, 5, 10})  
├── Inclure 3 → (17, {3, 5, 10})  
│   ├── Inclure 3 → (14, {3, 5, 10})  
│   │   ├── Inclure 3 → (11, {3, 5, 10})  
│   │   │   ├── Inclure 3 → (8, {3, 5, 10})  
│   │   │   │   ├── Inclure 3 → (5, {3, 5, 10})  
│   │   │   │   │   ├── Inclure 3 → (2, {3, 5, 10})  
│   │   │   │   │   │   ├── Inclure 3 → (-1, {3, 5, 10}) → 0  
│   │   │   │   │   │   └── Exclure 3 → (2, {5, 10})  
│   │   │   │   │   │       ├── Inclure 5 → (-3, {5, 10}) → 0  
│   │   │   │   │   │       └── Exclure 5 → (2, {10})  
│   │   │   │   │   │           ├── Inclure 10 → (-8, {10}) → 0  
│   │   │   │   │   │           └── Exclure 10 → (2, {}) → 0  
│   │   │   │   │   └── Exclure 3 → (5, {5, 10})  
│   │   │   │   │       ├── Inclure 5 → (0, {5, 10}) → 1 (solution)  
│   │   │   │   │       └── Exclure 5 → (5, {10})  
│   │   │   │   │           ├── Inclure 10 → (-5, {10}) → 0  
│   │   │   │   │           └── Exclure 10 → (5, {}) → 0  
│   │   │   │   └── Exclure 3 → (8, {5, 10})  
│   │   │   │       ├── Inclure 5 → (3, {5, 10})  
│   │   │   │       │   ├── Inclure 5 → (-2, {5, 10}) → 0  
│   │   │   │       │   └── Exclure 5 → (3, {10})  
│   │   │   │       │       ├── Inclure 10 → (-7, {10}) → 0  
│   │   │   │       │       └── Exclure 10 → (3, {}) → 0  
│   │   │   │       └── Exclure 5 → (8, {10})  
│   │   │   │           ├── Inclure 10 → (-2, {10}) → 0  
│   │   │   │           └── Exclure 10 → (8, {}) → 0  
│   │   │   └── Exclure 3 → (11, {5, 10})  
│   │   │       ├── Inclure 5 → (6, {5, 10})  
│   │   │       │   ├── Inclure 5 → (1, {5, 10})  
│   │   │       │   │   ├── Inclure 5 → (-4, {5, 10}) → 0  
│   │   │       │   │   └── Exclure 5 → (1, {10})  
│   │   │       │   │       ├── Inclure 10 → (-9, {10}) → 0  
│   │   │       │   │       └── Exclure 10 → (1, {}) → 0  
│   │   │       │   └── Exclure 5 → (6, {10})  
│   │   │       │       ├── Inclure 10 → (-4, {10}) → 0  
│   │   │       │       └── Exclure 10 → (6, {}) → 0  
│   │   │       └── Exclure 5 → (11, {10})  
│   │   │           ├── Inclure 10 → (1, {10})  
│   │   │           │   ├── Inclure 10 → (-9, {10}) → 0  
│   │   │           │   └── Exclure 10 → (1, {}) → 0  
│   │   │           └── Exclure 10 → (11, {}) → 0  
│   │   └── Exclure 3 → (14, {5, 10})  
│   │       ├── Inclure 5 → (9, {5, 10})  
│   │       │   ├── Inclure 5 → (4, {5, 10})  
│   │       │   │   ├── Inclure 5 → (-1, {5, 10}) → 0  
│   │       │   │   └── Exclure 5 → (4, {10})  
│   │       │   │       ├── Inclure 10 → (-6, {10}) → 0  
│   │       │   │       └── Exclure 10 → (4, {}) → 0  
│   │       │   └── Exclure 5 → (9, {10})  
│   │       │       ├── Inclure 10 → (-1, {10}) → 0  
│   │       │       └── Exclure 10 → (9, {}) → 0  
│   │       └── Exclure 5 → (14, {10})  
│   │           ├── Inclure 10 → (4, {10})  
│   │           │   ├── Inclure 10 → (-6, {10}) → 0  
│   │           │   └── Exclure 10 → (4, {}) → 0  
│   │           └── Exclure 10 → (14, {}) → 0  
│   └── Exclure 3 →     (17, {5, 10})
        ├── Inclure 5 → (12, {5, 10})
        │   ├── Inclure 5 → (7, {5, 10})
        │   │   ├── Inclure 5 → (2, {5, 10})
        │   │   │   ├── Inclure 5 → (-3, {5, 10}) → 0
        │   │   │   └── Exclure 5 → (2, {10})
        │   │   │       ├── Inclure 10 → (-8, {10}) → 0
        │   │   │       └── Exclure 10 → (2, {}) → 0
        │   │   └── Exclure 5 → (7, {10})
        │   │       ├── Inclure 10 → (-3, {10}) → 0
        │   │       └── Exclure 10 → (7, {}) → 0
        │   └── Exclure 5 → (12, {10})
        │       ├── Inclure 10 → (2, {10})
        │       │   ├── Inclure 10 → (-8, {10}) → 0
        │       │   └── Exclure 10 → (2, {}) → 0
        │       └── Exclure 10 → (12, {}) → 0
        └── Exclure 5 → (17, {10})
            ├── Inclure 10 → (7, {10})
            │   ├── Inclure 10 → (-3, {10}) → 0
            │   └── Exclure 10 → (7, {}) → 0
            └── Exclure 10 → (17, {}) → 0
*/

