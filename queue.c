#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int getch();

int main() {
	
    queue q;
    init(&q);

    // Enqueue some values
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    // Check the first element
    printf("First element in the queue: %d\n", firstQueue(&q));

    // Dequeue elements
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));

    // Check the first element after dequeue
    printf("First element in the queue after dequeues: %d\n", firstQueue(&q));

    // Dequeue the last element
    printf("Dequeued element: %d\n", dequeue(&q));

    // Try to dequeue from an empty queue
    printf("Dequeued element: %d\n", dequeue(&q));

    return 0;
}