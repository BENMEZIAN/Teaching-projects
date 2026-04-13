#include <stdio.h>

int main() {
	
    char *str = "Hello";
    char *word;

    word = str;

    printf("String : %s\n", str);
    
    printf("Char by char : ");
    while(*word != '\0') {
        printf("%c", *word);
        word++;
    }

    return 0;
}