#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        if(i == n-1){
            printf("%d", arr[i]);
            break;
        }
        printf("%d,", arr[i]);
    }
    printf("\n\n");
}

void invertArray(int arr[], int n){
    for (int i=0; i<n/2; i++){
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }

    printf("Inverted array: \n");
    printArray(arr, n);
}

int main(){
    int n;
    int upperBound = 1000;  
    int lowerBound = 0;  
    int intervalByN;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n > 100){
        n = 100;
    }

    if(n < 0){
        n = 0;
    }

    intervalByN = (upperBound - lowerBound) / n;

    int arr[n];

    // create an array of n random numbers
    for (int i=0; i<n; i++){
        int randomValue = (rand() % intervalByN) + (i * intervalByN);
        arr[i] = randomValue;
    }

    // print the array
    printf("Original Array: \n");
    printArray(arr, n);

    invertArray(arr, n);

    return 0;
}