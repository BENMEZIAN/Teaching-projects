#include <stdio.h>
#include <string.h>

// Définition de la structure Livre
typedef struct Livre {
    int id;
    char titre[100];
    char auteur[100];
    float prix;
} Livre;


void creerLivres(Livre livres[], int *n); // Procédure pour créer un tableau de livres avec n passé par référence
void afficherLivres(Livre livres[], int n); // Procédure pour afficher les détails de tous les livres
int rechercherLivreParTitre(Livre livres[], int n, char titreRecherche[]); // Fonction pour rechercher un livre par son titre et retourner sa position
void mettreAJourPrix(Livre livres[], int n, int id, float nouveauPrix); // Procédure pour mettre à jour le prix d'un livre par son ID
Livre trouverLivrePlusCher(Livre livres[], int n); // Fonction pour retourner le livre le plus cher


int main() {
	
    int n; // Le nombre de livres, initialisé à 0 par la procédure
    Livre livres[5]; // Tableau de livres avec capacité maximale de 5 livres

    // 1. Création du tableau de livres
    creerLivres(livres, &n);

    // 2. Affichage des livres
    afficherLivres(livres, n);
    
    // 3. Recherche d'un livre par titre
    char titreRecherche[100];
    getchar(); // Nettoyer le buffer
    printf("Entrez le titre du livre a rechercher : ");
    fgets(titreRecherche, sizeof(titreRecherche), stdin);
    titreRecherche[strcspn(titreRecherche, "\n")] = '\0';

    int position = rechercherLivreParTitre(livres, n, titreRecherche);
    if (position != -1) {
        printf("Livre trouve a la position %d.\n", position + 1);
    } else {
        printf("Livre non trouve.\n");
    }
      
    // 4. Mise à jour du prix d'un livre
    int idUpdate;
    float nouveauPrix;
    printf("Entrez l'ID du livre pour mettre a jour le prix : ");
    scanf("%d", &idUpdate);
    printf("Entrez le nouveau prix : ");
    scanf("%f", &nouveauPrix);
    mettreAJourPrix(livres, n, idUpdate, nouveauPrix);
    
    // 5. Livre le plus cher
    Livre livreCher = trouverLivrePlusCher(livres, n);
    printf("Le livre le plus cher est :\n");
    printf("ID : %d | Titre : %s | Auteur : %s | Prix : %.2f\n",livreCher.id, livreCher.titre, livreCher.auteur, livreCher.prix);
    

    

    return 0;
}


void creerLivres(Livre livres[], int *n) {
	
    *n = 0; 
	char choix;
    
    do {
        printf("Saisie du livre %d :\n", *n + 1);
        printf("Entrez l'ID du livre : ");
        scanf("%d", &livres[*n].id);
        getchar(); // Nettoyer le buffer

        printf("Entrez le titre du livre : ");
        fgets(livres[*n].titre, sizeof(livres[*n].titre), stdin);
        livres[*n].titre[strcspn(livres[*n].titre, "\n")] = '\0'; // Supprimer le saut de ligne

        printf("Entrez l'auteur du livre : ");
        fgets(livres[*n].auteur, sizeof(livres[*n].auteur), stdin);
        livres[*n].auteur[strcspn(livres[*n].auteur, "\n")] = '\0';

        printf("Entrez le prix du livre : ");
        scanf("%f", &livres[*n].prix);

        (*n)++; // Incrémenter n

        printf("Voulez-vous ajouter un autre livre ? (o/n) : ");
        getchar(); // Nettoyer le buffer
        scanf("%c", &choix);
    } while (choix == 'o' || choix == 'O');
}

void afficherLivres(Livre livres[], int n) {
	
    printf("\nListe des livres :\n");
	printf("------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("ID : %d | Titre : %s | Auteur : %s | Prix : %.2f\n",livres[i].id, livres[i].titre, livres[i].auteur, livres[i].prix);
    }
    printf("------------------------------\n");
}

int rechercherLivreParTitre(Livre livres[], int n, char titreRecherche[]) {
	
    for (int i = 0; i < n; i++) {
        if (strcmp(livres[i].titre, titreRecherche) == 0) {
            return i; // Retourner l'index si trouvé
        }
    }
    return -1; // Livre non trouvé
}

void mettreAJourPrix(Livre livres[], int n, int id, float nouveauPrix) {
	
    for (int i = 0; i < n; i++) {
        if (livres[i].id == id) {
            livres[i].prix = nouveauPrix;
            printf("Prix du livre avec ID %d mis a jour avec succes.\n", id);
            return;
        }
    }
    printf("Livre avec ID %d non trouvre.\n", id);
}

Livre trouverLivrePlusCher(Livre livres[], int n) {
	
    Livre plusCher = livres[0];
    for (int i = 1; i < n; i++) {
        if (livres[i].prix > plusCher.prix) {
            plusCher = livres[i];
        }
    }
    return plusCher;
}