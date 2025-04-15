#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void print_and_restore(stack* source, stack* temp); // Fonction pour afficher une pile et restituer son contenu dans une pile intermédiaire
void split_stack(stack* s, stack* evenStack, stack* oddStack); // Fonction pour séparer la pile en deux : une pour les nombres pairs et une pour les impairs


int main() {
	
    stack s, evenStack, oddStack, tempStack;
    
    // Initialiser les piles
    init(&s);
    init(&evenStack);
    init(&oddStack);
    init(&tempStack);

    // Exemple : ajouter des éléments à la pile principale
    push(&s, 10);
    push(&s, 15);
    push(&s, 20);
    push(&s, 25);
    push(&s, 30);

    // Afficher la pile d'origine
    printf("Pile originale : ");
    print_and_restore(&s, &tempStack);

    // Séparer la pile en deux : une pour les nombres pairs et une pour les impairs
    split_stack(&s,&evenStack,&oddStack);

    // Afficher les piles résultantes : pile des nombres pairs
    printf("Pile des nombres pairs : ");
    print_and_restore(&evenStack, &tempStack);

    // Afficher les piles résultantes : pile des nombres impairs
    printf("Pile des nombres impairs : ");
    print_and_restore(&oddStack, &tempStack);

    return 0;
}


void print_and_restore(stack* source, stack* temp) {
	
    while (!is_empty(source)) {
        int data = pop(source);  // Récupère l'élément du sommet de la pile source
        printf("%d ", data);  // Affiche l'élément
        push(temp, data);  // Empile l'élément dans la pile temporaire
    }
    printf("\n");

    // Restitue les éléments de la pile temporaire dans la pile source
    while (!is_empty(temp)) {
        push(source, pop(temp));
    }
}

void split_stack(stack* s, stack* evenStack, stack* oddStack) {
	
    while (!is_empty(s)) {
        int data = pop(s);  // Récupère l'élément du sommet de la pile s
        if (data % 2 == 0) {
            push(evenStack, data);  // Si pair, on l'ajoute à evenStack
        } else {
            push(oddStack, data);  // Si impair, on l'ajoute à oddStack
        }
    }
}
