#include <stdio.h>
#include <ctype.h>

void analyzeFile(char *filename);


int main() {
	
    analyzeFile("example.txt");
    
    return 0;
}

void analyzeFile(char *filename) {
	
    FILE *f = fopen(filename, "r");

    if (f == NULL) {
        printf("Cannot open file.\n");
        return;
    }

	char line[1024];
    int chars = 0, words = 0, lines = 0;

    while (fgets(line, sizeof(line), f) != NULL) {
        lines++;

        for (int i = 0; line[i] != '\0'; i++) {
            chars++;

            // word detection
            if (!isspace((unsigned char)line[i]) && (i == 0 || isspace((unsigned char)line[i - 1]))) {
                words++;
            }
        }
    }

    fclose(f);

    printf("Characters: %d\n", chars);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);
}