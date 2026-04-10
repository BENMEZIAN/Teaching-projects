#include <stdio.h>


void writeFile(char *filename); /* Function 1: write mode */
void appendFile(char *filename); /* Function 2: append mode */


int main() {
	
    char filename[] = "append.txt";

    writeFile(filename);   // first action: overwrite file
    appendFile(filename);  // second action: add content

    return 0;
}

void writeFile(char *filename) {
	
    FILE *f = fopen(filename, "w");

    if (f == NULL) {
        printf("Error opening file in write mode.\n");
        return;
    }

    fprintf(f, "This is the first line (write mode).\n");
    fprintf(f, "Old content is erased.\n");

    fclose(f);

    printf("File written successfully.\n");
}

/* Function 2: append mode */
void appendFile(char *filename) {
	
    FILE *f = fopen(filename, "a");

    if (f == NULL) {
        printf("Error opening file in append mode.\n");
        return;
    }

    fprintf(f, "This line is added (append mode).\n");

    fclose(f);

    printf("Content appended successfully.\n");
}