#include <stdio.h>
#include <math.h>

int main() {
    float x, y, z, result_a, result_b;
    // Initializing variables as float

    printf("Please input x: ");
    scanf("%f", &x);

    printf("Please input y: ");
    scanf("%f", &y);

    printf("Please input z: ");
    scanf("%f", &z);
    // User inputs 3 variables

    result_a = (3 + exp(y - 1)) / (1 + (pow(x, 2)*abs(y - tan(z))));
    result_b = (1 + abs(y - x)) + (pow(y - x, 2) / 2) + (pow(abs(y - x), 3) / 3);
    // Calculating 2 results

    printf("Result A: %f\n", result_a);
    printf("Result B: %f\n", result_b);
    // Outputs a result

    return 0;
    // No errors: returns 0
}
