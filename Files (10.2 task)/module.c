#include <string.h>

int find_special_word(FILE *file, char *good_word) {
    char word[256] = "";
    int length_of_good_word = 0;
    good_word[0] = '\0'; // Инициализируем пустой строкой

    while (fscanf(file, "%255s", word) == 1) {
        // Проверяем, что слово достаточно длинное и 3-й символ - 'е' в UTF-8
        if (strlen(word) >= 4 && 
            (unsigned char)word[2] == 0xD0 && 
            (unsigned char)word[3] == 0xB5) {
            
            if (strlen(word) >= length_of_good_word) {
                strcpy(good_word, word);
                length_of_good_word = strlen(good_word);
            }
        }
    }

    // Возвращаем длину в символах (UTF-8 может быть многобайтовым)
    return length_of_good_word > 0 ? length_of_good_word / 2 : 0;
}