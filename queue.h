#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
}Node;

// Structure for the queue
typedef struct queue{
    Node* front;
    Node* rear;
}queue;

void init(queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(queue* q) {
//    return q->front == NULL;
	if(q->front==NULL){
		return 1;
	}else{
		return 0;
	}
}

void enqueue(queue* q, int value) {
	
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(queue* q) {
	
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1; // Return a sentinel value indicating failure
    }

    Node* temp = q->front;
    int dequeuedValue = temp->data;

    q->front = q->front->next;
    free(temp);

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return dequeuedValue;
}

int firstQueue(queue* q){
	return q->front->data;
}