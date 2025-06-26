#include <stdio.h>
#include <math.h>


int main() {
    float x, y;

    printf("Пожалуйста введите любой x: ");
    scanf("%f", &x);

    if (x > 2) {
        y = 4;
    }
    else if (x > -1) {
        y = pow(x, 2);
    }
    else {
        y = -1/(pow(x, 2));
    }

    printf("y равен: %f", y);
    return 0;
}
