#include <stdio.h>
#include <stdlib.h>

int **randomMatrix(int m, int n, int upperBound, int lowerBound){
    int *matrix[m][n];

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            matrix[i][j] = (rand() % (upperBound - lowerBound + 1)) + lowerBound;
        }
    }
    return matrix;
}

void printMatrix(int m, int n, int *matrix){

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if(j == n-1){
                printf("%d", matrix[i][j]);
                break;
            }
            printf("%d,", matrix[i][j]);
        }
        printf("\n");
    }
}



int main(){
    int m,n,p;
    int upperBound = 100;
    int lowerBound = -100;

    while (m < 2 || n < 2 || p < 2 || m > 10 || n > 10 || p > 10)
    {
        printf("Enter the number m, n e p between 2 and 10 to create matrix\n");
         scanf("%d %d %d", &m, &n, &p);
    }

    // add random values to the matrixs
    int **matrix1 = randomMatrix(m, n, upperBound, lowerBound);
    int **matrix2 = randomMatrix(n, p, upperBound, lowerBound);

    // print the matrixs
    printf("Matrix 1: \n");
    printMatrix(m, n, matrix1);




    return 0;
}