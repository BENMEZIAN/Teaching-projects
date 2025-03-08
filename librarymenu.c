#include <stdio.h>
#include <string.h>

// Définition de la structure Livre
typedef struct Livre {
    int id;
    char titre[100];
    char auteur[100];
    float prix;
} Livre;

// Prototypes des fonctions
void creerLivres(Livre livres[], int *n);
void afficherLivres(Livre livres[], int n);
int rechercherLivreParTitre(Livre livres[], int n, char titreRecherche[]);
void mettreAJourPrix(Livre livres[], int n, int id, float nouveauPrix);
Livre trouverLivrePlusCher(Livre livres[], int n);


int main() {
	
    int n = 0;
    Livre livres[5];
    int choix;

    do {
        // Affichage du menu
        printf("===== MENU =====\n");
        printf("1. Ajouter des livres\n");
        printf("2. Afficher les livres\n");
        printf("3. Rechercher un livre par titre\n");
        printf("4. Mettre a jour le prix d'un livre\n");
        printf("5. Afficher le livre le plus cher\n");
        printf("6. Quitter\n");
        printf("=====================\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                creerLivres(livres, &n);
                break;

            case 2:
                afficherLivres(livres, n);
                break;

            case 3: {
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
                break;
            }

            case 4: {
                int idUpdate;
                float nouveauPrix;
                printf("Entrez l'ID du livre pour mettre a jour le prix : ");
                scanf("%d", &idUpdate);
                printf("Entrez le nouveau prix : ");
                scanf("%f", &nouveauPrix);
                mettreAJourPrix(livres, n, idUpdate, nouveauPrix);
                break;
            }

            case 5: {
                if (n > 0) {
                    Livre livreCher = trouverLivrePlusCher(livres, n);
                    printf("Le livre le plus cher est :\n");
                    printf("ID : %d | Titre : %s | Auteur : %s | Prix : %.2f\n",livreCher.id, livreCher.titre, livreCher.auteur, livreCher.prix);
                } else {
                    printf("Aucun livre n'est disponible.\n");
                }
                break;
            }

            case 6:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide, veuillez reessayer.\n");
        }

    } while (choix != 6);

    return 0;
}

// Procédure pour créer un tableau de livres
void creerLivres(Livre livres[], int *n) {
    char choix;
    do {
        if (*n >= 5) {
            printf("Capacité maximale atteinte (5 livres).\n");
            break;
        }

        printf("Saisie du livre %d :\n", *n + 1);
        printf("Entrez l'ID du livre : ");
        scanf("%d", &livres[*n].id);
        getchar();

        printf("Entrez le titre du livre : ");
        fgets(livres[*n].titre, sizeof(livres[*n].titre), stdin);
        livres[*n].titre[strcspn(livres[*n].titre, "\n")] = '\0';

        printf("Entrez l'auteur du livre : ");
        fgets(livres[*n].auteur, sizeof(livres[*n].auteur), stdin);
        livres[*n].auteur[strcspn(livres[*n].auteur, "\n")] = '\0';

        printf("Entrez le prix du livre : ");
        scanf("%f", &livres[*n].prix);

        (*n)++;

        printf("Voulez-vous ajouter un autre livre ? (o/n) : ");
        getchar(); // Nettoyer le buffer
        scanf("%c", &choix);
    } while ((choix == 'o' || choix == 'O') && *n < 5);
}

// Procédure pour afficher tous les livres
void afficherLivres(Livre livres[], int n) {
    if (n == 0) {
        printf("Aucun livre a afficher.\n");
        return;
    }

    printf("\nListe des livres :\n");
    printf("------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("ID : %d | Titre : %s | Auteur : %s | Prix : %.2f\n",livres[i].id, livres[i].titre, livres[i].auteur, livres[i].prix);
    }
    printf("------------------------------\n");
}

// Fonction de recherche par titre
int rechercherLivreParTitre(Livre livres[], int n, char titreRecherche[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(livres[i].titre, titreRecherche) == 0) {
            return i;
        }
    }
    return -1;
}

// Procédure de mise à jour du prix d'un livre
void mettreAJourPrix(Livre livres[], int n, int id, float nouveauPrix) {
    for (int i = 0; i < n; i++) {
        if (livres[i].id == id) {
            livres[i].prix = nouveauPrix;
            printf("Prix du livre avec ID %d mis a jour avec succes.\n", id);
            return;
        }
    }
    printf("Livre avec ID %d non trouve.\n", id);
}

// Fonction pour trouver le livre le plus cher
Livre trouverLivrePlusCher(Livre livres[], int n) {
    Livre plusCher = livres[0];
    for (int i = 1; i < n; i++) {
        if (livres[i].prix > plusCher.prix) {
            plusCher = livres[i];
        }
    }
    return plusCher;
}