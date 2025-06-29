#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;              // Variable to store the size of the array
    int number = 0;     // Counter for numbers that satisfy the condition (appear more than once)

    // Prompt user to input the size of the array
    printf("Input size of array: ");
    scanf("%d", &n);

    // Check if the input size is valid (must be positive)
    if (n <= 0) {
        printf("Invalid array size!\n");
        return 1;  // Exit with error code 1
    }

    // Allocate memory for the array of doubles
    double *arr = (double*)malloc(n * sizeof(double));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  // Exit if memory allocation fails
    }
    
    // Prompt user to enter elements of the array
    printf("Enter %d elements (can be any real numbers):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);  // Read each element
    }

    // Check each element in the array to see if it appears more than once
    for (int i = 0; i < n; i++) {
        int flag = 0;  // Counter for how many times arr[i] appears in the array
        
        // Compare the current element with all elements in the array
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                flag += 1;  // Increment counter if duplicate is found
            }
        }
        
        // If the element appears more than once, increment the result counter
        if (flag > 1) {
            number += 1;
        }
    }
    
    // Print the result and free allocated memory
    printf("Number of numbers that satisfying the condition: %d", number);
    free(arr);  // Release the allocated memory
    return 0;   // Exit successfully
}