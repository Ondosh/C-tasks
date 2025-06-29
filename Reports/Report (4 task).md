Условия задачи: (под буквой "в")

![[4.png]]

```C
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

  

int main() {
    int num, first_fig, last_fig;  // Variables for input number, first digit, and last digit
    int digits = 1;  // Initialize digit counter (minimum 1 digit for any number)

    printf("Enter number num: ");  // Prompt user for input
    scanf("%d", &num);  // Read the original number

    // Count the number of digits in the number
    int numdig = num;  // Create a copy to work with
    while (numdig > 9) {  // Continue while number has more than 1 digit
        digits += 1;    
        numdig /= 10;    
    }
    printf("Number of digits: %d\n", digits);  // Print digit count

    // Extract the first digit
    first_fig = num / (int)pow(10, digits - 1);  // Divide by 10^(digits-1)
    
    // Extract the last digit
    last_fig = num % 10;  // Modulo 10 gives the last digit
    
    // Remove both first and last digits to get the middle part
    int middle_part = num % (int)pow(10, digits - 1);  // Remove first digit
    middle_part = middle_part / 10;                             // Remove last digit
    
    // Construct the new number with swapped first and last digits
    int new_num = last_fig * (int)pow(10, digits - 1);  // Move last digit to first position
    new_num += (middle_part * 10) + first_fig;          // Add back the middle digits, add first digit at the end

    // Print results
    printf("Number after swapping first and last digits: %d\n", new_num);
    return 0;  
}
```
