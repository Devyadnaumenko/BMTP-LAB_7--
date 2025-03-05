#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define WORD "програма"

void to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int is_separate_word(const char *sentence, const char *word) {
    size_t word_len = strlen(word);
    const char *p = sentence;

    while ((p = strstr(p, word)) != NULL) {
        if ((p == sentence || !isalnum((unsigned char)*(p - 1))) &&
            (*(p + word_len) == '\0' || !isalnum((unsigned char)*(p + word_len)))) {
            return 1;
        }
        p += word_len;
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    char sentence[256];
    printf("Введіть речення: ");
    if (!fgets(sentence, sizeof(sentence), stdin)) {
        printf("Помилка вводу!\n");
        return 1;
    }

    // Видалення пробілів на початку і кінці
    char *start = sentence;
    while (isspace((unsigned char)*start)) start++;

    char *end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';

    size_t len = strlen(start);
    if (len == 0 || (start[len - 1] != '.' && start[len - 1] != '!' && start[len - 1] != '?')) {
        printf("Помилка: речення має закінчуватися на '.', '!' або '?'\n");
        return 1;
    }

    // Перетворення всього речення в нижній регістр для правильного пошуку
    to_lower(sentence);

    if (is_separate_word(sentence, WORD)) {
        printf("Так\n");
    } else {
        printf("Ні\n");
    }

    return 0;
}
