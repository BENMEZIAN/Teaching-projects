#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Définition d'un nœud
typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* createNode(int data); // Fonction pour créer un nouveau nœud
Node* append(Node** head, int data); // Fonction pour insérer un élément à la fin de la liste
void printList(Node* head); // Fonction pour afficher une liste
bool areEqual(Node** head1, Node** head2); // Fonction pour tester deux listes si sont égales
int length(Node* head); // Fonction pour calculer la taille d'une liste
int occurrences(Node* head, int value); // Fonction pour calculer l'occurence d'une valeur dans une liste
bool areSimilar(Node** head1, Node** head2); // Fonction pour tester deux listes si sont similaires
bool areComparable(Node** head1, Node** head2); // Fonction pour tester deux listes si sont comparables



int main() {
	
    Node *list1 = NULL, *list2 = NULL;
    int n1, n2, value;

    printf("Entrez le nombre d'elements de la 1ere liste : ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Element %d : ", i + 1);
        scanf("%d", &value);
        list1 = append(&list1, value);
    }

    printf("Entrez le nombre d'elements de la 2eme liste : ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Element %d : ", i + 1);
        scanf("%d", &value);
        list2 = append(&list2, value);
    }

    printf("\nListe 1 : ");
    printList(list1);
    printf("Liste 2 : ");
    printList(list2);
    
    printf("\nResults :\n");
    
    if(areEqual(&list1, &list2) == true){
    	printf("Les listes sont egales.\n");
	}else{
		printf("Les listes ne sont pas egales.\n");
	}
	
    if(areSimilar(&list1, &list2) == true){
    	printf("Les listes sont similaires.\n");
	}else{
		printf("Les listes ne sont pas similaires.\n");
	}
	
	if(areComparable(&list1, &list2) == true){
		printf("Les listes sont comparables.\n");
	}else{
		printf("Les listes ne sont pas comparables.\n");
	}
	
	
	
    return 0;
}


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* append(Node** head, int data) {
	
    Node* newNode = createNode(data);

    // Si la liste est vide, le nouvel élément devient la tête
    if (*head == NULL){
    	return newNode;
	}

    // Sinon, on parcourt jusqu’au dernier élément
    Node* temp = (*head);
    while (temp->next != NULL){
    	temp = temp->next;
	}

    temp->next = newNode;
    return (*head);
}

void printList(Node* head) {
   
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int length(Node* head) {
    
	int count = 0;
    Node* temp = head;
    
	while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int occurrences(Node* head, int value) {
	
    int count = 0;
    Node* temp = head;
    
	while (temp != NULL) {
        if (temp->data == value){
        	count++;
		}
        temp = temp->next;
    }
    return count;
}

bool areEqual(Node** head1, Node** head2) {
	
	Node* p = (*head1), *q = (*head2);
	bool equal = true;
    
    while (p != NULL && q != NULL) {
        // Si les données diffèrent à une position, elles ne sont pas égales
        if (p->data != q->data){
        	equal = false;
		}
        // Avancer dans les deux listes
        p = p->next;
        q = q->next;
    }

    // Si l'une des deux listes est plus longue que l'autre
    if (p != NULL || q != NULL){
    	equal = false;
	}

    return equal;
}

bool areSimilar(Node** head1, Node** head2) {
    
    bool similar = true;
    
    if(length((*head1)) != length((*head2))){
    	similar = false;
	}

    Node* temp = (*head1);
    while (temp != NULL) {
        int val = temp->data;
        int occ1 = occurrences((*head1), val);
        int occ2 = occurrences((*head2), val);

        if (occ1 != occ2){
        	similar = false;
		}

        temp = temp->next;
    }
    
    return similar;
}

bool areComparable(Node** head1, Node** head2) {
	
	Node* p = *head1;
	bool comparable = true;
    
	while (p != NULL) {
        // Vérifie que l'élément p->data existe dans les deux listes
        if (occurrences(*head2, p->data) >= 1 && occurrences(*head1, p->data) >= 1) {
            comparable = true;
        } else {
            comparable = false;
        }
        p = p->next;
    }

    return comparable;
}