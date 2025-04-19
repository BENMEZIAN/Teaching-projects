#include <stdio.h>
#include <string.h>

typedef struct Etudiant{
    char nom[30];
    int age;
    float moyenne;
} Etudiant;


float calculerMoyenneGenerale(Etudiant etudiants[], int n); // Fonction pour calculer la moyenne générale de tous les étudiants
void trierParMoyenneDecroissante(Etudiant etudiants[], int n); // Fonction pour trier les étudiants par moyenne décroissante (tri par sélection)
void afficherEtudiants(Etudiant etudiants[], int n); // Fonction d'affichage


int main() {
	
	int n = 3;
    Etudiant etudiants[n];

    printf("=== Saisie des etudiants ===\n");
    for (int i = 0; i < n; i++) {
        printf("\nEtudiant %d :\n", i + 1);
        printf("Nom : ");
        scanf(" %[^\n]", etudiants[i].nom);  // lit une ligne entière, y compris les espaces

        printf("Age : ");
        scanf("%d", &etudiants[i].age);

        printf("Moyenne : ");
        scanf("%f", &etudiants[i].moyenne);
    }

    printf("\n--- Liste initiale ---\n");
    afficherEtudiants(etudiants, n);

    float moyenneGenerale = calculerMoyenneGenerale(etudiants, n);
    printf("\nMoyenne generale de la classe : %.2f\n", moyenneGenerale);

    trierParMoyenneDecroissante(etudiants, n);

    printf("\n--- Liste triee par moyenne decroissante ---\n");
    afficherEtudiants(etudiants, n);

    return 0;
}


float calculerMoyenneGenerale(Etudiant etudiants[], int n) {
	
    float somme = 0.0;
    for (int i = 0; i < n; i++) {
        somme += etudiants[i].moyenne;
    }
    return somme / n;
}

void trierParMoyenneDecroissante(Etudiant etudiants[], int n) {
	
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (etudiants[j].moyenne > etudiants[i].moyenne) {
                Etudiant temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
}

void afficherEtudiants(Etudiant etudiants[], int n) {
	
    printf("Liste des etudiants :\n");
    for (int i = 0; i < n; i++) {
        printf("Nom : %s, Age : %d, Moyenne : %.2f\n", etudiants[i].nom, etudiants[i].age, etudiants[i].moyenne);
    }
}