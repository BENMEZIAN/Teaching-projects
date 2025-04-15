#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
int isPalindrome(char * str);

int main() {
	
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);  // Reads a single word (no spaces)

    if (isPalindrome(str)) {
        printf("'%s' is a palindrome.\n", str);
    } else {
        printf("'%s' is not a palindrome.\n", str);
    }

    return 0;
}

int isPalindrome(char * str) {
	
    int i = 0;
    int j = strlen(str) - 1;
    int pal = 1;  // Assume true

    while (i < j && pal == 1) {
        if (tolower(str[i]) != tolower(str[j])) {
            pal = 0;  // Not a palindrome
            break; // to exit from the loop
        }else{
        	i++;
			j--;
		}
    }

    return pal;
}