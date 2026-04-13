#include <stdio.h>

int main() {
	
    int a = 10; // variable entière
    int *p; // pointeur sur entier

    p = &a; // p contient l'adresse de a

    printf("Adresse de a = %x\n", p);
    printf("Contenu de l'adresse p = %d\n", *p);

    return 0;
}