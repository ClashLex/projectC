#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        printf("ERROR! Memory allocation failed for rows.\n");
        return NULL;
    }
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("ERROR! Memory allocation failed for columns.\n");
            return NULL;
        }
    }
    return matrix;
}

// Function to free allocated memory
void freeMatrix(int** matrix, int rows) {
    if (matrix == NULL) return;
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to read matrix elements with validation
int readMatrix(int** matrix, int rows, int cols, char matrixName) {
    printf("Enter the elements of matrix %c:\n", matrixName);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            int result = scanf("%d", &matrix[i][j]);
            
            if (result != 1) {
                printf("ERROR! Invalid input. Please enter an integer.\n");
                // Clear input buffer
                while (getchar() != '\n');
                return 0;
            }
        }
    }
    return 1;
}

// Function to display a matrix
void displayMatrix(int** matrix, int rows, int cols, char matrixName) {
    printf("\nMatrix %c:\n", matrixName);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%6d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform matrix multiplication
int** multiplyMatrices(int** a, int arows, int acols, int** b, int brows, int bcols) {
    if (acols != brows) {
        printf("ERROR! Can't multiply the matrices. Columns of A (%d) must equal rows of B (%d).\n", acols, brows);
        return NULL;
    }
    
    int** product = allocateMatrix(arows, bcols);
    if (product == NULL) return NULL;
    
    // Initialize product matrix to 0
    for (int i = 0; i < arows; i++) {
        for (int j = 0; j < bcols; j++) {
            product[i][j] = 0;
        }
    }
    
    // Perform multiplication
    for (int i = 0; i < arows; i++) {
        for (int j = 0; j < bcols; j++) {
            for (int k = 0; k < acols; k++) {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    return product;
}

int main() {
    int arows, acolumns, brows, bcolumns;
    int** matrixA = NULL;
    int** matrixB = NULL;
    int** product = NULL;
    
    // Input dimensions for Matrix A
    printf("========== Matrix Multiplication ==========%s\n\n", "");
    
    printf("Enter the rows and columns of matrix A: ");
    if (scanf("%d %d", &arows, &acolumns) != 2) {
        printf("ERROR! Invalid input for matrix A dimensions.\n");
        return 1;
    }
    
    if (arows <= 0 || acolumns <= 0) {
        printf("ERROR! Rows and columns must be positive integers.\n");
        return 1;
    }
    
    // Allocate memory for Matrix A
    matrixA = allocateMatrix(arows, acolumns);
    if (matrixA == NULL) return 1;
    
    // Read Matrix A
    if (!readMatrix(matrixA, arows, acolumns, 'A')) {
        freeMatrix(matrixA, arows);
        return 1;
    }
    
    // Input dimensions for Matrix B
    printf("\nEnter the rows and columns of matrix B: ");
    if (scanf("%d %d", &brows, &bcolumns) != 2) {
        printf("ERROR! Invalid input for matrix B dimensions.\n");
        freeMatrix(matrixA, arows);
        return 1;
    }
    
    if (brows <= 0 || bcolumns <= 0) {
        printf("ERROR! Rows and columns must be positive integers.\n");
        freeMatrix(matrixA, arows);
        return 1;
    }
    
    // Allocate memory for Matrix B
    matrixB = allocateMatrix(brows, bcolumns);
    if (matrixB == NULL) {
        freeMatrix(matrixA, arows);
        return 1;
    }
    
    // Read Matrix B
    if (!readMatrix(matrixB, brows, bcolumns, 'B')) {
        freeMatrix(matrixA, arows);
        freeMatrix(matrixB, brows);
        return 1;
    }
    
    // Display input matrices
    displayMatrix(matrixA, arows, acolumns, 'A');
    displayMatrix(matrixB, brows, bcolumns, 'B');
    
    // Multiply matrices
    product = multiplyMatrices(matrixA, arows, acolumns, matrixB, brows, bcolumns);
    
    if (product != NULL) {
        displayMatrix(product, arows, bcolumns, 'C');
        printf("\n========== Multiplication Successful ==========%s\n", "");
    } else {
        printf("Multiplication failed!\n");
    }
    
    // Free allocated memory
    freeMatrix(matrixA, arows);
    freeMatrix(matrixB, brows);
    if (product != NULL) {
        freeMatrix(product, arows);
    }
    
    return 0;
}