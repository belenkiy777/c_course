#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int is_snake_case(char* in) {
    if (!isalpha(in[0])) return 0; // если 1ый символ не буква - сразу минус
    for (int i = 0; in[i] != 0; i++) {
        if (!(islower(in[i]) || in[i] == '_' || isdigit(in[i]))) return 0; // если у нас встретилось что-то помимо этого - минус
        if (in[i] == '_' && (i == 0 || in[i + 1] == '\0' || in[i + 1] == '_' || isdigit(in[i + 1])))
            return 0;
        // запрещаем двойное подчеркивание и подчеркивание в конце
    }
    return 1;
}

int isCamelCase(char* in) {
    if (!islower(in[0])) return 0; // если 1ый символ не строчная буква - сразу минус
    for (int i = 0; in[i] != 0; i++) {
        if (!(isalpha(in[i]) || isdigit(in[i]))) return 0; // если у нас встретилось что-то помимо этого - минус
    }
    return 1;
}
void snake_to_camel(char* in, char* out) {
    int j = 0;
    int go_up = 0;
    for (int i = 0; in[i] != 0; i++) {
        if (in[i] == '_') {
            go_up = 1; // флаг поднятия следующей буквы
        }
        else {
            if (go_up) { // мы прошли подчеркивание и поднимаем букву
                out[j] = toupper(in[i]);
                go_up = 0;
            }
            else {
                out[j] = in[i]; // если не нашли _, оставляем как есть
            }
            j++; // пропускаем подчеркивание и не записываем в полученную строку
        }
    }
    out[j] = '\0';
}

void camel_to_snake(char* in, char* out) {
    int j = 0;
    for (int i = 0; in[i] != 0; i++) {
        if (isupper(in[i])) { // если встретилась заглавная буква, ставим _, двигаем j и опускаем регистр
            out[j] = '_';
            j++;
            out[j] = tolower(in[i]);
            j++;
        }
        else {
            out[j] = in[i]; // если нет, оставляем как есть и двигаем j
            j++;
        }
    }
    out[j] = '\0';
}

int main(void) {
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");
    if (input == NULL || output == NULL) {
        perror("Error while opening files");
        return 1;
    }
    char buffer[256];
    char result[512];
    // 5 abcdefgh 
    // в буфер запишется abcd0, efgh перейдет на следующую строку
    while (fgets(buffer, sizeof(buffer), input) != NULL) { // 

        buffer[strcspn(buffer, "\n")] = '\0';
        if (is_snake_case(buffer)) {
            snake_to_camel(buffer, result);
            fputs(result, output);
            fputs("\n", output);
        }
        else if (isCamelCase(buffer)) {
            camel_to_snake(buffer, result);
            fputs(result, output);
            fputs("\n", output);
        }
        else {
            fputs("*error*\n", output);
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
