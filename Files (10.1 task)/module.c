#include <stdio.h>
#include <stdlib.h>

int append_next_fibonacci(const char* filename) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        perror("Не удалось открыть файл");
        return -1;
    }

    long long prev = 0, curr = 0, next;
    int count = 0;

    // Ищем последние два числа, читая файл с начала
    while (fscanf(file, "%lld", &next) == 1) {
        prev = curr;
        curr = next;
        count++;
    }

    // Если чисел меньше двух, завершаем с ошибкой
    if (count < 2) {
        fprintf(stderr, "В файле меньше двух чисел\n");
        fclose(file);
        return -1;
    }

    // Вычисляем следующее число (теперь prev и curr - два последних разных числа)
    next = prev + curr;

    // Дописываем в конец файла
    fprintf(file, " %lld", next);

    fclose(file);
    printf("Число %lld успешно добавлено в файл.\n", next);
    return 0;
}