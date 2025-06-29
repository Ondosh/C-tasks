Условия задачи:

![[Pasted image 20250629194505.png]]

Исходный код с комментариями:

```C
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

  

/**
 * Function to compute the factorial of a number using recursion.
 * @param n The input integer (must be non-negative).
 * @return Factorial of n (n!).
 */

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;  // Base case: 0! = 1 and 1! = 1
    }
    return n * factorial(n - 1);  // Recursive call
}

int main() {
    int n;          // Variable to store the size of the array
    double result = 1.0;  // Initialize result to 1 (multiplicative identity)

    // Prompt user to input the size of the array
    printf("Input size of array: ");
    scanf("%d", &n);

    // Check if the input size is valid (must be positive)
    if (n <= 0) {
        printf("Invalid array size!\n");
        return 1;  // Exit with error code 1
    }

    // Dynamically allocate memory for the array
    double *arr = (double*)malloc(n * sizeof(double));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  // Exit if memory allocation fails
    }

  

    // Prompt user to enter elements of the array
    printf("Enter %d elements (can be any real numbers):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);  // Read each element
    }

  

    // Display the generated array
    printf("Generated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%lf ", arr[i]);
    }
    printf("\n");

    // Iterate through the array and apply the condition:
    // Check if (i+1 < arr[i]) AND (arr[i] < factorial(i))
    for (int i = 0; i < n; i++) {
        if (i + 1 < arr[i] && arr[i] < factorial(i)) {
            result *= arr[i];  // Multiply elements that satisfy the condition
            printf("Element satisfying the condition: %lf\n", arr[i]);
        }
    }

    // Compute the final result (reciprocal of the product)
    if (result != 0) {
        result = 1.0 / result;
        printf("Final result: %lf\n", result);
    } else {
        printf("No elements satisfy the condition or division by zero occurred.\n");
    }

    // Free dynamically allocated memory
    free(arr);
    return 0;  // Successful execution
}
```