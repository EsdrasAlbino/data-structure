#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for Queue
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if queue is full
int isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Function to check if queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Function to add an element to queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue Overflow!\n");
        return;
    }
    
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    
    queue->rear++;
    queue->items[queue->rear] = item;
}

// Function to free the memory allocated for queue
void freeQueue(struct Queue* queue) {
    free(queue);
}

int main() {
    struct Queue* queue = createQueue();
    
    // Add some elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    
    // Print the elements
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
    
    // Free the memory
    freeQueue(queue);
    
    return 0;
}
