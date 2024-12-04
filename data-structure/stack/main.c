#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the structure for stack
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to create a new stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    stack->top = -1;
    return stack;
}

// Function to check if stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an item onto stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to peek at the top item without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return stack->items[stack->top];
}

// Function to free the memory allocated for stack
void freeStack(struct Stack* stack) {
    free(stack);
}

int main() {
    struct Stack* stack = createStack();
    
    // Push some elements
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    
    // Print top element
    printf("Top element: %d\n", peek(stack));
    
    // Pop and print elements
    printf("Popped elements: ");
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");
    
    // Free the memory
    freeStack(stack);
    
    return 0;
}
