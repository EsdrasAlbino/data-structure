#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;


// i can define Node as a type with: typedef struct Node Node;

Node *createList(int data){
    Node *head = malloc(sizeof(Node));
    head->data = data;
    head->next = NULL;
    return head;
}

// Function to create a new node
 Node* createNode(int data) {
     Node* newNode = ( Node*)malloc(sizeof( Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
 Node* insertAtBeginning( Node* head, int data) {
     Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the list
 Node* insertAtEnd( Node* head, int data) {
     Node* newNode = createNode(data);
    
    if (head == NULL) {
        return newNode;
    }
    
     Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to print the linked list
void printList( Node* head) {
     Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList( Node* head) {
     Node* current = head;
    while (current != NULL) {
         Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
     Node* head = NULL;  // Initialize an empty list
    
    // Insert some elements
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtBeginning(head, 5);
    head = insertAtEnd(head, 30);
    
    // Print the list
    printf("Linked List: ");
    printList(head);
    
    // Free the memory
    freeList(head);
    
    return 0;
}
