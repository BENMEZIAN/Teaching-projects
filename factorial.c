#include <stdio.h>

// Function to calculate factorial
int factorial(int n);

int main() {
	
    int number;

    do {
        printf("Enter a non-negative number: ");
        scanf("%d", &number);

        if (number < 0) {
            printf("Invalid input, please enter a non-negative number.\n");
        }    
    } while (number < 0);

    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        int result = factorial(number);
        printf("Factorial of %d is %d\n", number, result);
    }

    return 0;
}


int factorial(int n) {
	
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}