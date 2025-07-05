#include <stdio.h>
#include <string.h>
#include "module.c"

int main() {
    FILE *file = fopen("f.txt", "r+");
    if (file == NULL) {
        perror("Не удалось открыть файл");
        return 1;
    }

    char good_word[256];
    int length = find_special_word(file, good_word);

    if (length == 0) {
        printf("There is no good words :(\n");
    } else {
        printf("Good word: %s\nLength of it: %d\n", good_word, length);
    }

    fclose(file);
    return 0;
}