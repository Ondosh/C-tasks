#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int n;
    int randomLimit = 100;

    printf("Input matrix order: ");
    scanf("%d", &n);

    double** matrix = (double**)malloc(n * sizeof(double*));
    double *vector = (double*)malloc(n * sizeof(double));
    if (matrix == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
    matrix[i] = malloc(n * sizeof(double));
    if (matrix[i] == NULL) {
        printf("Ошибка выделения памяти\n");
        // Здесь надо освободить уже выделенную память, чтобы не было утечек
        for (int j = 0; j < i; j++)
            free(matrix[j]);
        free(matrix);
        return 1;
    }}
    
    srand(time(NULL)); // Initialization of random seed

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % randomLimit;
            printf("%3.0f", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Vector: \n");
    for (int i = 0; i < n; i++) {
        vector[i] = rand() % randomLimit;
        printf("%3.0f", vector[i]);
    }
    printf("\n");

    printf("Result vector: \n");

    for (int i = 0; i < n; i++) {
        double result = 0;
        for (int j = 0; j < n; j++) {
            result += matrix[i][j]*vector[j];
        }
        printf("%6.0f", result);
    }

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}