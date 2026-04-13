#include <stdio.h>
#include <string.h>

typedef struct Etudiant {
    char nom[50];
    int age;
    float moyenne;
}Etudiant;

int main() {
	
    Etudiant e1; // variable de type Etudiant
    Etudiant *ep; // pointeur sur Etudiant

    // Initialisation
    strcpy(e1.nom, "Ali");
    e1.age = 20;
    e1.moyenne = 15.5;

    ep = &e1;

    // Affichage via pointeur
    printf("Nom : %s\n", (*ep).nom); // p->nom
    printf("Age : %d\n", (*ep).age); // p->age
    printf("Moyenne : %.2f\n", (*ep).moyenne); // p->moyenne

    return 0;
}