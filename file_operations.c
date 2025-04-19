#include <stdio.h>

// Fonction qui ouvre le fichier et lit caractère par caractère
void read_char_by_char(const char *filename) {
    FILE *file = fopen(filename, "r");  // Ouvrir le fichier en mode lecture
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier\n");
        return;
    }

    char ch;
    printf("Lecture caractère par caractère :\n");
    while ((ch = fgetc(file)) != EOF) {  // Lire chaque caractère jusqu'à la fin du fichier
        putchar(ch);  // Afficher le caractère
    }

    fclose(file);  // Fermer le fichier après utilisation
}

// Fonction qui ouvre le fichier et lit ligne par ligne
void read_line_by_line(const char *filename) {
    FILE *file = fopen(filename, "r");  // Ouvrir le fichier en mode lecture
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier\n");
        return;
    }

    char line[256];
    printf("Une ligne entière :\n");
    while (fgets(line, sizeof(line), file)) {  // Lire une ligne à la fois
        printf("%s", line);  // Afficher la ligne lue
    }

    fclose(file);  // Fermer le fichier après utilisation
}

int main() {
	
    char *filename = "example.txt";  // Nom du fichier à ouvrir
    
    printf("Lecture d'un fichier caractere par caractere:\n");
    printf("--------------------------------------------:\n");
    read_char_by_char(filename);
    printf("\n\n");
    
    printf("Lecture d'un fichier line par line:\n");
    printf("-----------------------------------\n");
    read_line_by_line(filename);
    printf("\n\n");
    
    return 0;
}