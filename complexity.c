#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Parcours d'un tableau : O(n) */
void parcours(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        tab[i] += 1;   // opération simple
    }
}

/* Double boucle : O(n^2) */
void doubleBoucle(int n) {
    int cpt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cpt++;
        }
    }
}

/* Recherche séquentielle : O(n) */
int rechercheSequentielle(int tab[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (tab[i] == x)
            return i;
    }
    return -1;
}

/* Recherche dichotomique : O(log n) */
int rechercheDichotomique(int tab[], int n, int x) {
    int gauche = 0, droite = n - 1;

    while (gauche <= droite) {
        int milieu = (gauche + droite) / 2;

        if (tab[milieu] == x)
            return milieu;
        else if (tab[milieu] < x)
            gauche = milieu + 1;
        else
            droite = milieu - 1;
    }
    return -1;
}

/* Remplissage du tableau avec des valeurs croissantes */
void remplirTableau(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        tab[i] = i * 2;
    }
}

int main() {
    int n = 1000000;
    int x = 500;
    int *tab;

    clock_t debut, fin;
    double temps;

    tab = (int *)malloc(n * sizeof(int));
    if (tab == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return 1;
    }

    remplirTableau(tab, n);

    /* Parcours */
    debut = clock();
    parcours(tab, n);
    fin = clock();
    temps = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("Parcours tableau : %f s\n", temps);

    /* Double boucle */
    debut = clock();
    doubleBoucle(2000);
    fin = clock();
    temps = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("Double boucle : %f s\n", temps);

    /* Recherche séquentielle */
    debut = clock();
    rechercheSequentielle(tab, n, x);
    fin = clock();
    temps = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("Recherche sequentielle : %f s\n", temps);

    /* Recherche dichotomique */
    debut = clock();
    rechercheDichotomique(tab, n, x);
    fin = clock();
    temps = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("Recherche dichotomique : %f s\n", temps);

    free(tab);
    return 0;
}
