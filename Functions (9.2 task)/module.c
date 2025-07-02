#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Creates a square matrix filled with random values (0-99)
 * @param n Size of the matrix (n x n)
 * @return Pointer to allocated matrix, NULL on failure
 */
double** createRandomMatrix(int n) {
    // Allocate row pointers
    double** matrix = (double**)malloc(n * sizeof(double*));
    if (matrix == NULL) return NULL;
    
    for (int i = 0; i < n; i++) {
        // Allocate each row
        matrix[i] = (double*)malloc(n * sizeof(double));
        if (matrix[i] == NULL) {
            // Cleanup already allocated rows if failed
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
        
        // Fill with random values
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    
    return matrix;
}

/**
 * Prints matrix contents
 * @param matrix Matrix to print
 * @param n Size of the matrix (n x n)
 */
void printMatrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6.0f", matrix[i][j]);  // Format as whole numbers
        }
        printf("\n");
    }
}

/**
 * Finds maximum value on/below main diagonal
 * @param matrix Matrix to search
 * @param n Size of the matrix (n x n)
 * @return Maximum value found
 */
double findMaxBelowDiagonal(double** matrix, int n) {
    if (matrix == NULL || n <= 0) return 0;
    
    double max = matrix[0][0];  // Initialize with first element
    
    // Only check elements where column ≤ row (lower triangular)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    
    return max;
}

/**
 * Safely deallocates matrix memory
 * @param matrix Matrix to free
 * @param n Size of the matrix (n x n)
 */
void freeMatrix(double** matrix, int n) {
    if (matrix == NULL) return;
    
    // Free each row
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    // Free row pointers
    free(matrix);
}
