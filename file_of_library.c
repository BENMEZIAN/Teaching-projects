#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure Livre
typedef struct {
    int id;
    char titre[100];
    char auteur[100];
    float prix;
} Livre;

// Prototypes des fonctions
void creerLivres(); // Ajouter les livres dans le fichier
void afficherLivres(); // Afficher les livres en lisant directement depuis le fichier
int rechercherLivreParTitre(char titreRecherche[]); // Rechercher un livre par titre en parcourant le fichier
void mettreAJourPrix(int id, float nouveauPrix); // Mettre à jour le prix d'un livre en réécrivant le fichier
void trouverLivrePlusCher(); // Trouver le livre le plus cher en lisant le fichier
int getch();

int main() {
	
    int choix;
    
    while(1) {
    	system("cls");
        printf("------------Menu Bibliotheque---------\n");
        printf("1. Ajouter des livres.\n");
        printf("2. Afficher tous les livres.\n");
        printf("3. Rechercher un livre par titre.\n");
        printf("4. Mettre a jour le prix d'un livre.\n");
        printf("5. Trouver le livre le plus cher.\n");
        printf("6. Quitter.\n");
        printf("--------------------------------------\n");
        printf("Choix : ");
        scanf("%d", &choix);
        getchar(); // Nettoyer le buffer

        switch (choix) {
            case 1:
                creerLivres();
                break;
            case 2:
                afficherLivres();
                break;
            case 3: {
                char titreRecherche[100];
                printf("Entrez le titre du livre a rechercher : ");
                fgets(titreRecherche, sizeof(titreRecherche), stdin);
                titreRecherche[strcspn(titreRecherche, "\n")] = '\0';

                int position = rechercherLivreParTitre(titreRecherche);
                if (position != -1) {
                    printf("Livre trouve a la ligne %d dans le fichier.\n", position);
                } else {
                    printf("Livre non trouve.\n");
                }
                break;
            }
            case 4: {
                int id;
                float nouveauPrix;
                printf("Entrez l'ID du livre : ");
                scanf("%d", &id);
                printf("Entrez le nouveau prix : ");
                scanf("%f", &nouveauPrix);
                mettreAJourPrix(id, nouveauPrix);
                break;
            }
            case 5:
                trouverLivrePlusCher();
                break;
            case 6:
                printf("Merci d'avoir utilise le programme !\n");
                exit(0);
                break;
            default:
                printf("Choix invalide, réessayez.\n");
                break;
        }
        
		getch();   
    }


    return 0;
}

void creerLivres() {
	
    FILE *fichier = fopen("bibliotheque.txt", "w");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier !\n");
        return;
    }

    Livre livre;
    char choix;
    do {
        printf("Entrez l'ID du livre : ");
        scanf("%d", &livre.id);
        getchar();

        printf("Entrez le titre du livre : ");
        fgets(livre.titre, sizeof(livre.titre), stdin);
        livre.titre[strcspn(livre.titre, "\n")] = '\0';

        printf("Entrez l'auteur du livre : ");
        fgets(livre.auteur, sizeof(livre.auteur), stdin);
        livre.auteur[strcspn(livre.auteur, "\n")] = '\0';

        printf("Entrez le prix du livre : ");
        scanf("%f", &livre.prix);

        fprintf(fichier, "%d\n%s\n%s\n%.2f\n", livre.id, livre.titre, livre.auteur, livre.prix);

        printf("Voulez-vous ajouter un autre livre ? (o/n) : ");
        getchar();
        scanf("%c", &choix);
    } while (choix == 'o' || choix == 'O');

    fclose(fichier);
}

void afficherLivres() {
	
    FILE *fichier = fopen("bibliotheque.txt", "r");
    if (fichier == NULL) {
        printf("Aucun livre enregistre.\n");
        return;
    }

    Livre livre;
    printf("\nListe des livres enregistres :\n");
    printf("-------------------------------\n");
    while (fscanf(fichier, "%d\n", &livre.id) != EOF) {
        fgets(livre.titre, sizeof(livre.titre), fichier);
        livre.titre[strcspn(livre.titre, "\n")] = '\0';

        fgets(livre.auteur, sizeof(livre.auteur), fichier);
        livre.auteur[strcspn(livre.auteur, "\n")] = '\0';

        fscanf(fichier, "%f\n", &livre.prix);
        printf("ID : %d | Titre : %s | Auteur : %s | Prix : %.2f\n",livre.id, livre.titre, livre.auteur, livre.prix);
    }
    printf("-------------------------------\n");
    fclose(fichier);
}

int rechercherLivreParTitre(char titreRecherche[]) {
	
    FILE *fichier = fopen("bibliotheque.txt", "r");
    if (fichier == NULL) {
        return -1;
    }

    Livre livre;
    int ligne = 1;
    while (fscanf(fichier, "%d\n", &livre.id) != EOF) {
        fgets(livre.titre, sizeof(livre.titre), fichier);
        livre.titre[strcspn(livre.titre, "\n")] = '\0';

        fgets(livre.auteur, sizeof(livre.auteur), fichier);
        livre.auteur[strcspn(livre.auteur, "\n")] = '\0';

        fscanf(fichier, "%f\n", &livre.prix);

        if (strcmp(livre.titre, titreRecherche) == 0) {
            fclose(fichier);
            printf("\nLivre trouve :\n");
            printf("-------------------------------\n");
            printf("ID : %d\n", livre.id);
            printf("Titre : %s\n", livre.titre);
            printf("Auteur : %s\n", livre.auteur);
            printf("Prix : %.2f euro\n", livre.prix);
            printf("-------------------------------\n");
            return ligne;
        }
        ligne++;
    }

    fclose(fichier);
    return -1;
}

void mettreAJourPrix(int id, float nouveauPrix) {
	
    FILE *fichier = fopen("bibliotheque.txt", "r");
    if (fichier == NULL) {
        printf("Fichier introuvable !\n");
        return;
    }

    Livre livres[100];
    int n = 0, trouve = 0;

    while (fscanf(fichier, "%d\n", &livres[n].id) != EOF) {
        fgets(livres[n].titre, sizeof(livres[n].titre), fichier);
        livres[n].titre[strcspn(livres[n].titre, "\n")] = '\0';

        fgets(livres[n].auteur, sizeof(livres[n].auteur), fichier);
        livres[n].auteur[strcspn(livres[n].auteur, "\n")] = '\0';

        fscanf(fichier, "%f\n", &livres[n].prix);

        if (livres[n].id == id) {
            livres[n].prix = nouveauPrix;
            trouve = 1;
        }
        n++;
    }
    fclose(fichier);

    if (trouve) {
        fichier = fopen("bibliotheque.txt", "w");
        for (int i = 0; i < n; i++) {
            fprintf(fichier, "%d\n%s\n%s\n%.2f\n",livres[i].id, livres[i].titre, livres[i].auteur, livres[i].prix);
        }
        fclose(fichier);
        printf("Prix mis a jour avec succes.\n");
    } else {
        printf("Livre non trouve.\n");
    }
}

void trouverLivrePlusCher() {
	
    FILE *fichier = fopen("bibliotheque.txt", "r");
    if (fichier == NULL) {
        printf("Aucun livre enregistre.\n");
        return;
    }

    Livre livre, plusCher;
    plusCher.prix = 0;

    while (fscanf(fichier, "%d\n", &livre.id) != EOF) {
        fgets(livre.titre, sizeof(livre.titre), fichier);
        livre.titre[strcspn(livre.titre, "\n")] = '\0';

        fgets(livre.auteur, sizeof(livre.auteur), fichier);
        livre.auteur[strcspn(livre.auteur, "\n")] = '\0';

        fscanf(fichier, "%f\n", &livre.prix);

        if (livre.prix > plusCher.prix) {
            plusCher = livre;
        }
    }
    fclose(fichier);

    printf("Livre le plus cher : %s (%.2f) euro.\n", plusCher.titre, plusCher.prix);
}