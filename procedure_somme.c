#include <stdio.h>

// Déclaration de la procédure qui calcule la somme (version 1)
void somme1(int a, int b) {
    int s;
	s = a + b;
    printf("La somme de %d et %d est: %d\n", a, b, s);
}

// Déclaration de la procédure qui calcule la somme (version 2)
void somme2(int a, int b,int * s) {
	(*s) = a + b;
    printf("La somme de %d et %d est: %d\n", a, b, (*s));
}


int main() {
	
    int num1, num2, s;

    // Demander à l'utilisateur d'entrer deux nombres
    printf("Entrez le premier nombre: ");
    scanf("%d", &num1);
    printf("Entrez le deuxième nombre: ");
    scanf("%d", &num2);
    
    printf("\n");

    // Appeler la procédure somme1
    printf("La somme avec la procedure somme1\n");
	somme1(num1, num2);
	
	printf("---------------------------------\n");
	
	// Appeler la procédure somme2
	printf("La somme avec la procedure somme2 (passage par adresse)\n");
	somme2(num1, num2,&s);

    

    return 0;
}