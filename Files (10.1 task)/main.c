#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("f.txt", "r+");  // Открываем в режиме чтения и записи
    if (file == NULL) {
        perror("Не удалось открыть файл");
        return 1;
    }

    long long prev = 0, curr = 0, next;
    int count = 0;

    // Ищем последние два числа, читая файл с начала
    while (fscanf(file, "%lld", &curr) == 1) {
        prev = curr;
        count++;
    }

    // Если чисел меньше двух, завершаем с ошибкой
    if (count < 2) {
        printf("В файле меньше двух чисел\n");
        fclose(file);
        return 1;
    }

    // Вычисляем следующее число
    next = prev + curr;

    // Дописываем в конец файла
    fprintf(file, " %lld", next);

    fclose(file);
    printf("Число %lld успешно добавлено в файл.\n", next);
    return 0;
}