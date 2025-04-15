#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
	

	stack s;    // Declare the stack
	
    init(&s);   // Initialize the stack
    
    // Push some values onto the stack
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    
    // Peek the top value of the stack
    printf("Top of the stack: %d\n", top(&s));
    
    // Pop values from the stack
    printf("Popped: %d\n", pop(&s));  // Should pop 30
    printf("Popped: %d\n", pop(&s));  // Should pop 20
    
    // Check if the stack is empty
    if (is_empty(&s)) {
        printf("The stack is empty.\n");
    } else {
        printf("The stack is not empty.\n");
    }
    
    // Pop the remaining value
    printf("Popped: %d\n", pop(&s));  // Should pop 10
    
    // Finally check if the stack is empty again
    if (is_empty(&s)) {
        printf("The stack is empty.\n");
    } else {
        printf("The stack is not empty.\n");
    }
	
	
	return 0;
}