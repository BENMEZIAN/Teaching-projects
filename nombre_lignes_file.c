#include <stdio.h>


int number_lines(char * filename);


int main() {
	
    int NbLines = number_lines("example.txt");

    printf("Nombre de lignes : %d\n", NbLines);

    return 0;
}

int number_lines(char * filename){
	
	FILE *f;
    char ligne[256];  // buffer pour stocker une ligne
    int nb_lignes = 0;

    f = fopen(filename, "r");

    if (f == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return 1;
    }

    while (fgets(ligne, sizeof(ligne), f) != NULL) {
        nb_lignes++;
    }

    fclose(f);
    
    return nb_lignes;
}