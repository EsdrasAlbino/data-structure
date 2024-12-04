#include <stdio.h>
#include <stdlib.h>

// Define the structure for dynamic array
struct DynamicArray {
    int* array;
    int size;      // Current number of elements
    int capacity;  // Total available space
};

// Function to create a dynamic array
struct DynamicArray* createDynamicArray(int initialCapacity) {
    struct DynamicArray* arr = (struct DynamicArray*)malloc(sizeof(struct DynamicArray));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    arr->array = (int*)malloc(initialCapacity * sizeof(int));
    if (arr->array == NULL) {
        printf("Memory allocation failed!\n");
        free(arr);
        exit(1);
    }
    
    arr->size = 0;
    arr->capacity = initialCapacity;
    return arr;
}

// Function to resize the array when needed
void resize(struct DynamicArray* arr) {
    int newCapacity = arr->capacity * 2;
    int* newArray = (int*)realloc(arr->array, newCapacity * sizeof(int));
    
    if (newArray == NULL) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }
    
    arr->array = newArray;
    arr->capacity = newCapacity;
}

// Function to append an element to the array
void append(struct DynamicArray* arr, int element) {
    if (arr->size == arr->capacity) {
        resize(arr);
    }
    
    arr->array[arr->size++] = element;
}

// Function to get element at specific index
int get(struct DynamicArray* arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Index out of bounds!\n");
        exit(1);
    }
    return arr->array[index];
}

// Function to set element at specific index
void set(struct DynamicArray* arr, int index, int element) {
    if (index < 0 || index >= arr->size) {
        printf("Index out of bounds!\n");
        exit(1);
    }
    arr->array[index] = element;
}

// Function to get current size of array
int getSize(struct DynamicArray* arr) {
    return arr->size;
}

// Function to get current capacity of array
int getCapacity(struct DynamicArray* arr) {
    return arr->capacity;
}

// Function to free the memory allocated for dynamic array
void freeDynamicArray(struct DynamicArray* arr) {
    free(arr->array);
    free(arr);
}

int main() {
    // Create a dynamic array with initial capacity of 2
    struct DynamicArray* arr = createDynamicArray(2);
    
    // Append some elements
    append(arr, 10);
    append(arr, 20);
    append(arr, 30);  // This will trigger resize
    append(arr, 40);
    
    // Print all elements
    printf("Array elements: ");
    for (int i = 0; i < getSize(arr); i++) {
        printf("%d ", get(arr, i));
    }
    printf("\n");
    
    // Demonstrate get and set operations
    printf("Element at index 2: %d\n", get(arr, 2));
    set(arr, 1, 25);
    printf("After setting index 1 to 25: ");
    for (int i = 0; i < getSize(arr); i++) {
        printf("%d ", get(arr, i));
    }
    printf("\n");
    
    // Print size and capacity
    printf("Size: %d\n", getSize(arr));
    printf("Capacity: %d\n", getCapacity(arr));
    
    // Free the memory
    freeDynamicArray(arr);
    
    return 0;
}
