#include <stdio.h>
#include <math.h>

int main() {
    float a, result, interval;
    interval = 2;

    puts("Введите а:");
    scanf("%f", &a);
    // real number a

    while ((a > 1) || (a < -1)){
        if (a > 1) {
            a = a - interval;
        } else {
            a = a + interval;
        }
    }

    result = pow(a, 2) + 1;

    printf("Относительно начальных условий, а находится на: %f\n", a);
    printf("Y = %f", result);
    return 0;
}