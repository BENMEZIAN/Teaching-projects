#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} node;

void create(node **start, int data);
void display(node **start);
void insert_begin(node **start, int data);
void insert_end(node **start, int data);
void insert_pos(node **start, int pos, int data);
void delete_begin(node **start);
void delete_end(node **start);
void delete_pos(node **start, int pos);
void count(node **start);

int main() {
    node *start = NULL;

    // Créer une liste avec des valeurs initiales
    create(&start, 10);
    create(&start, 20);
    create(&start, 30);
    printf("Initial list: ");
    display(&start);

    // Insérer un élément au début
    insert_begin(&start, 5);
    printf("After inserting 5 at the beginning: ");
    display(&start);

    // Insérer un élément à la fin
    insert_end(&start, 40);
    printf("After inserting 40 at the end: ");
    display(&start);

    // Insérer un élément à une position spécifique
    insert_pos(&start, 2, 15); // Insérer 15 à la position 2
    printf("After inserting 15 at position 2: ");
    display(&start);

    // Supprimer le premier élément
    delete_begin(&start);
    printf("After deleting the first element: ");
    display(&start);

    // Supprimer le dernier élément
    delete_end(&start);
    printf("After deleting the last element: ");
    display(&start);
    

	// Supprimer un élément à une position spécifique
    delete_pos(&start, 2); // Supprimer l'élément à la position 2
    printf("After deleting the element at position 2: ");
    display(&start);

    // Compter le nombre d'éléments dans la liste
    count(&start);

    return 0;
}

void create(node **start, int data) {
    node *temp, *ptr;
    temp = (node *)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Out of Memory Space\n");
        exit(0);
    }

    temp->info = data;
    temp->next = NULL;

    if (*start == NULL) {
        *start = temp;
    } else {
        ptr = *start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void display(node **start) {
    node *ptr = *start;
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }

    while (ptr != NULL) {
        printf("%d -> ", ptr->info);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void insert_begin(node **start, int data) {
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Out of Memory Space\n");
        return;
    }

    temp->info = data;
    temp->next = *start;
    *start = temp;
}

void insert_end(node **start, int data) {
    node *temp, *ptr;
    temp = (node *)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Out of Memory Space\n");
        return;
    }

    temp->info = data;
    temp->next = NULL;

    if (*start == NULL) {
        *start = temp;
    } else {
        ptr = *start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void insert_pos(node **start, int pos, int data) {
    node *ptr, *temp;
    int i;

    if (temp == NULL) {
        printf("Out of Memory Space\n");
        return;
    }

    if (pos == 1) {
    	insert_begin(start,data);
    } else {
    	
    	temp = (node *)malloc(sizeof(node));
		temp->info = data;
		temp->next = NULL;
        ptr = *start;
        
        for (i = 1; i < pos - 1; i++) {
            ptr = ptr->next;
        }
        
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void delete_begin(node **start) {
    if (*start == NULL) {
        printf("List is Empty\n");
        return;
    }

    node *ptr = *start;
    *start = (*start)->next;
    free(ptr);
}

void delete_end(node **start) {
    if (*start == NULL) {
        printf("List is Empty\n");
        return;
    }

    node *ptr = *start, *temp = NULL;

    if (ptr->next == NULL) {
        free(ptr);
        *start = NULL;
    } else {
        while (ptr->next != NULL) {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);
    }
}

void delete_pos(node **start, int pos) {
    int i;
    node *temp, *ptr;

    if (*start == NULL) {
        printf("The List is Empty\n");
        return;
    }

    if (pos == 1) {
    	delete_begin(start);
    } else {
        ptr = *start;
        for (i = 0; i < pos - 1; i++) {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        free(ptr);
    }
}

void count(node **start) {
    node *temp = *start;
    int cpt = 0;

    while (temp != NULL) {
        cpt++;
        temp = temp->next;
    }

    printf("The number of elements is: %d\n", cpt);
}