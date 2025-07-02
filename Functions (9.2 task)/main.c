#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "module.c"

int main() {
    int n;          // Matrix size (n x n)
    double max;     // Maximum value below/on main diagonal
    
    // Get matrix size from user
    printf("Input size of n-matrix (square matrix): ");
    scanf("%d", &n);
    
    // Validate input
    if (n <= 1) {
        printf("Invalid array size! Size must be greater than 1.\n");
        return 1;
    }
    
    // Initialize random number generator
    srand(time(NULL));
    
    // Create and populate matrix with random values
    double** matrix = createRandomMatrix(n);
    if (matrix == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Display the generated matrix
    printf("\nMatrix:\n");
    printMatrix(matrix, n);
    
    // Find maximum value under/on main diagonal
    max = findMaxBelowDiagonal(matrix, n);
    printf("\nMaximum value below and on the main diagonal: %.0f\n", max);
    
    // Release allocated memory
    freeMatrix(matrix, n);
    
    return 0;
}
