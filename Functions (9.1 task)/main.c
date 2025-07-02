#include <stdio.h>
#include "module.c"


int main() {
    int m, a, c;
    printf("Input 'n', 'a' and 'c': ");
    scanf("%d%d%d", &m, &a, &c);

    if (m < 0) {
        printf("Error: 'n' must be non-negative.\n");
        return 1;
    }

    int result = f(m, a, c);
    printf("Result is: %d\n", result);
    return 0;
}
