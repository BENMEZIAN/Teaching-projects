#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main() {
	
    stack s, evenStack, oddStack, temp;
    
    // Initialiser les piles
    init(&s);
    init(&evenStack);
    init(&oddStack);
    init(&temp);

    // Exemple : ajouter des éléments à la pile principale
    push(&s, 10);
    push(&s, 15);
    push(&s, 20);
    push(&s, 25);
    push(&s, 30);
    
    // Affichage de la pile originale
    printf("La pile originale : ");
    while (!is_empty(&s)) {
        int data = pop(&s);  // Récupère l'élément du sommet de la pile source
        printf("%d ", data);  // Affiche l'élément
        push(&temp, data);  // Empile l'élément dans la pile temporaire
    }
    printf("\n");

    // Restitue les éléments de la pile temporaire dans la pile des paires
    while (!is_empty(&temp)) {
        push(&s, pop(&temp));
    }

    // Séparer la pile en deux : une pour les nombres pairs et une pour les impairs
    while (!is_empty(&s)) {
        int data = pop(&s);  // Récupère l'élément du sommet de la pile s
        if (data % 2 == 0) {
            push(&evenStack, data);  // Si pair, on l'ajoute à evenStack
        } else {
            push(&oddStack, data);  // Si impair, on l'ajoute à oddStack
        }
    }

    // Afficher les piles résultantes
    printf("La pile des nombres paires : ");
    while (!is_empty(&evenStack)) {
        int data = pop(&evenStack);  // Récupère l'élément du sommet de la pile source
        printf("%d ", data);  // Affiche l'élément
        push(&temp, data);  // Empile l'élément dans la pile temporaire
    }
    printf("\n");

    // Restitue les éléments de la pile temporaire dans la pile des paires
    while (!is_empty(&temp)) {
        push(&evenStack, pop(&temp));
    }
    
    printf("La pile des nombres impaires : ");
    while (!is_empty(&oddStack)) {
        int data = pop(&oddStack);  // Récupère l'élément du sommet de la pile source
        printf("%d ", data);  // Affiche l'élément
        push(&temp, data);  // Empile l'élément dans la pile temporaire
    }
    printf("\n");

    // Restitue les éléments de la pile temporaire dans la pile des paires
    while (!is_empty(&temp)) {
        push(&oddStack, pop(&temp));
    }

    return 0;
}
