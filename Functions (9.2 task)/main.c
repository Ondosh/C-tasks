#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
double** createRandomMatrix(int n);
void printMatrix(double** matrix, int n);
double findMaxBelowDiagonal(double** matrix, int n);
void freeMatrix(double** matrix, int n);

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