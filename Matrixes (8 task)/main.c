#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    double x; // x должен быть определен для вычисления a_ij = cos(x^2 + n)
    
    printf("Введите натуральное число n: ");
    scanf("%d", &n);
    printf("Введите значение x: ");
    scanf("%lf", &x);
    
    // Выделяем память для матрицы
    double** matrix = calloc(n, sizeof(double*));
    if (matrix == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    // Выделяем память для каждой строки и заполняем матрицу
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)calloc(n, sizeof(double));
        if (matrix[i] == NULL) {
            printf("Ошибка выделения памяти\n");
            
            // Освобождаем ранее выделенную память в случае ошибки
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            
            return 1;
        }
        
        // Заполняем строку матрицы
        for (int j = 0; j < n; j++) {
            double arg = i*i + n; // i+1 и j+1 так как индексы с 1
            matrix[i][j] = cos(arg);
        }
    }
    
    // Подсчет положительных элементов
    int positive_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > 0) {
                positive_count++;
            }
        }
    }
    
    printf("Количество положительных элементов в матрице: %d\n", positive_count);
    
    // Освобождаем память
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}