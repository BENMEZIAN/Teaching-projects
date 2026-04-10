#include <stdio.h>

void copy_content(char * source,char * destination);


int main() {
	
	copy_content("source.txt","destination.txt");
	
    printf("Copie terminee.\n");

    return 0;
}

void copy_content(char * source,char * destination){
	
	FILE *src, *dest;
    char ligne[256];

    src = fopen(source, "r");
    dest = fopen(destination, "w");

    if (src == NULL || dest == NULL) {
        printf("Erreur d'ouverture des fichiers.\n");
    }

    while (fgets(ligne, sizeof(ligne), src) != NULL) {
        fputs(ligne, dest);
    }

    fclose(src);
    fclose(dest);
}