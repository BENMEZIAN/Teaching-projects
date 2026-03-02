#include <stdio.h>


void display(int T[], int n); // Fonction pour afficher les éléments d'un tableau
int somme(int T[], int n); // Fonction pour calculer la somme des éléments d'un tableau


int main() {
	
    int T[10]; int n;

    // Demander la taille du tableau
    printf("Entrez le nombre d'elements du tableau : ");
    scanf("%d", &n);

    // Remplir le tableau avec les valeurs entrées par l'utilisateur
    for (int i = 0; i < n; i++) {
        printf("Entrez l'element %d : ", i + 1);
        scanf("%d", &T[i]);
    }

    // Affichage du tableau
    display(T,n);

    // Calcul et affichage de la somme
    int som = somme(T, n);
    printf("Somme des elements : %d\n", som);

    return 0;
}

// Fonction pour afficher les éléments d'un tableau
void display(int T[], int n) {
	int i;
    printf("Elements du tableau : ");
    for (i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
}

// Fonction pour calculer la somme des éléments d'un tableau
int somme(int T[], int n) {
    int i,s = 0;
    for (i = 0; i < n; i++) {
        s = s + T[i];
    }
    return s;
}