#include <stdio.h>
#include <stdlib.h>

// Déqueueir la structure d'un élément de la liste simplement chaînée
typedef struct ElementPrep {
    int valeur;
    struct ElementPrep *suivant;
} Element;

// Déqueueir la structure de contrôle de la liste simplement chaînée
typedef struct Liste {
    Element *tete;
    Element *queue;
    int nef;
} Liste;

// Fonction pour créer un élément vide de la liste
Element* CreerElement() {
    Element *nouveau = (Element*)malloc(sizeof(Element));
    if (nouveau == NULL) {
        printf("Erreur d'allocation de memoire.\n");
        exit(1);
    }
    nouveau->suivant = NULL;
    nouveau->valeur = NULL;
    return nouveau;
}

// Fonction pour créer une liste vide
Liste* CreerListe() {
    Liste *nouvelleListe = (Liste*)malloc(sizeof(Liste));
    if (nouvelleListe == NULL) {
        printf("Erreur d'allocation de memoire.\n");
        exit(1);
    }
    nouvelleListe->tete = NULL;
    nouvelleListe->queue = NULL;
    nouvelleListe->nef = 0;
    return nouvelleListe;
}

// Fonction pour créer une liste en respectant l'ordre de lecture des entiers
void CreerListeOrdre(Liste *Li) {
    int valeur;
    printf("Entrez une suite d'entiers (terminez par 0) :\n");
    while (1) {
        scanf("%d", &valeur);
        if (valeur == 0) break;

        Element *nouveau = CreerElement();
        nouveau->valeur = valeur;

        if (Li->tete == NULL) {
            Li->tete = nouveau;
            Li->queue = nouveau;
        } else {
            Li->queue->suivant = nouveau;
            Li->queue = nouveau;
        }
        Li->nef++;
    }
}

// Fonction pour créer une liste en rangeant les entiers par ordre croissant
void CreerListeCroissante(Liste *Li) {
    int valeur;
    printf("Entrez une suite d'entiers (terminez par 0) :\n");
    while (1) {
        scanf("%d", &valeur);
        if (valeur == 0) break;

        Element *nouveau = CreerElement();
        nouveau->valeur = valeur;

        if (Li->tete == NULL) {
            Li->tete = nouveau;
            Li->queue = nouveau;
        } else {
            Element *courant = Li->tete;
            Element *precedent = NULL;

            while (courant != NULL && courant->valeur < valeur) {
                precedent = courant;
                courant = courant->suivant;
            }

                nouveau->suivant = courant;
                precedent->suivant = nouveau;
            

            if (courant == NULL) {
                Li->queue = nouveau;
            }
        }
    }
}

// Fonction pour ajouter un élément à la queue de la liste
void Ajoutqueue(Liste *Li, int vaf) {
    Element *nouveau = CreerElement();
    nouveau->valeur = vaf;

    if (Li->tete == NULL) {
        Li->tete = nouveau;
        Li->queue = nouveau;
    } else {
        Li->queue->suivant = nouveau;
        Li->queue = nouveau;
    }
}

// Fonction pour concaténer deux listes
Liste* Concatenation(Liste *Li1, Liste *Li2) {
    Liste *resultat = CreerListe();

    Element *courant = Li1->tete;
    while (courant != NULL) {
        Ajoutqueue(resultat, courant->valeur);
        courant = courant->suivant;
    }

    courant = Li2->tete;
    while (courant != NULL) {
        Ajoutqueue(resultat, courant->valeur);
        courant = courant->suivant;
    }

    return resultat;
}

// Fonction pour rechercher un élément dans la liste
int RechercheElem(Liste *Li, int vr) {
    Element *courant = Li->tete;
    while (courant != NULL) {
        if (courant->valeur == vr) return 1;
        courant = courant->suivant;
    }
    return 0;
}

// Fonction pour supprimer un élément après une position donnée
int SuppPos(Liste *Li, int poss) {
    if (Li->tete == NULL || poss < 0) {
        return 0; // Liste vide ou position invalide
    }

    Element *courant = Li->tete;
    Element *precedent = NULL;
    int position = 0;

    while (courant != NULL && position < poss) {
        precedent = courant;
        courant = courant->suivant;
        position++;
    }

    if (courant == NULL || courant->suivant == NULL) {
        return 0; // Position invalide
    }

    Element *aSupprimer = courant->suivant;
    courant->suivant = aSupprimer->suivant;
    free(aSupprimer);

    if (courant->suivant == NULL) {
        Li->queue = courant;
    }

    return 1; // Suppression réussie
}

// Fonction pour afficher la liste
void AfficherListe(Liste *Li) {
    Element *courant = Li->tete;
    while (courant != NULL) {
        printf("%d -> ", courant->valeur);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

int main() {
    // Créer deux listes
    Liste *liste1 = CreerListe();
    Liste *liste2 = CreerListe();

    // Créer la première liste dans l'ordre de lecture
    printf("Creation de la premiere liste (ordre de lecture) :\n");
    CreerListeOrdre(liste1);
    printf("Liste 1 : ");
    AfficherListe(liste1);

    // Créer la deuxième liste en ordre croissant
    printf("Creation de la deuxieme liste (ordre croissant) :\n");
    CreerListeCroissante(liste2);
    printf("Liste 2 : ");
    AfficherListe(liste2);

    // Concaténer les deux listes
    Liste *listeConcat = Concatenation(liste1, liste2);
    printf("Liste concatenee : ");
    AfficherListe(listeConcat);

    // Rechercher un élément dans la liste concaténée
    int valeurRecherchee;
    printf("Entrez une valeur a rechercher : ");
    scanf("%d", &valeurRecherchee);
    if (RechercheElem(listeConcat, valeurRecherchee)) {
        printf("La valeur %d est presente dans la liste.\n", valeurRecherchee);
    } else {
        printf("La valeur %d n'est pas presente dans la liste.\n", valeurRecherchee);
    }

    // Supprimer un élément après une position donnée
    int positionSuppression;
    printf("Entrez la position apres laquelle supprimer un element : ");
    scanf("%d", &positionSuppression);
    if (SuppPos(listeConcat, positionSuppression)) {
        printf("Element supprime avec succes.\n");
    } else {
        printf("Suppression echouee.\n");
    }
    printf("Liste apres suppression : ");
    AfficherListe(listeConcat);

    // Libérer la mémoire
    free(liste1);
    free(liste2);
    free(listeConcat);

    return 0;
}
