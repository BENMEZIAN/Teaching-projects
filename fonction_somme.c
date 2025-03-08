#include <stdio.h>

// Déclaration de la fonction qui calcule la somme
int somme(int a, int b) {
    return a + b;
}

int main() {
	
    int num1, num2, resultat;

    // Demander à l'utilisateur d'entrer deux nombres
    printf("Entrez le premier nombre: ");
    scanf("%d", &num1);
    printf("Entrez le deuxième nombre: ");
    scanf("%d", &num2);

    // Appeler la fonction somme
    resultat = somme(num1, num2);

    // Afficher le résultat
    printf("La somme de %d et %d est: %d\n", num1, num2, resultat);

    return 0;
}