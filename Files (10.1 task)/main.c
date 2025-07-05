#include "module.c"
#include <stdio.h>

int main() {
    const char* filename = "f.txt";
    
    if (append_next_fibonacci(filename) == 0) {
        printf("Операция выполнена успешно.\n");
    } else {
        printf("Произошла ошибка при обработке файла.\n");
    }
    
    return 0;
}