#include <stdio.h>

int main() 
{
    int a[50][50], b[50][50], product[50][50];
    int arows, acolumns, brows, bcolumns;
    int i, j, k;

    // Input Matrix A
    printf("Enter the rows and columns of matrix A: ");
    scanf("%d %d", &arows, &acolumns);

    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < arows; i++) 
    {
        for (j = 0; j < acolumns; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Input Matrix B
    printf("Enter the rows and columns of matrix B: ");
    scanf("%d %d", &brows, &bcolumns);

    // Check if multiplication is possible
    if (acolumns != brows) 
    {
        printf("ERROR! Can't multiply the matrices.\n");
        return 1; // Exit program
    }

    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < brows; i++) 
    {
        for (j = 0; j < bcolumns; j++) 
        {
            scanf("%d", &b[i][j]);
        }
    }

    // Matrix Multiplication
    for (i = 0; i < arows; i++) 
    {
        for (j = 0; j < bcolumns; j++) 
        {
            int sum = 0; // Fix: Reset sum for each element
            for (k = 0; k < acolumns; k++) 
            {
                sum = sum + a[i][k] * b[k][j];
            }
            product[i][j] = sum;
        }
    }

    // Display Resultant Matrix
    printf("Resultant matrix: \n");
    for (i = 0; i < arows; i++) 
    {
        for (j = 0; j < bcolumns; j++) 
        {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}
