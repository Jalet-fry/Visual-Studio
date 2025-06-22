#include "header.h"
#include "functions.h"
int correct(char* text) {
    char input[100];
    int valid = 0;
    int num;
    char* endptr; 
    valid = 0;
    while (!valid) {
        printf("%s\n", text);
        fgets(input, sizeof(input) / sizeof(char), stdin);
        if (input[0] != '\n') {
            num = (int)strtol(input, &endptr, 10);
            if (*endptr != '\n' && *endptr != '\0') {
                printf("Это не число.Попробуйте еще раз.\n");
            }
            else {
                valid = 1;
                printf("Вы ввели число: %d\n", num);
            }
        }
    }
    return num;
}
char* input_name(char* prompt) {
    char input[100];
    char *returning_text;
    printf("%s", prompt);
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return NULL; 
    }
    input[strcspn(input, "\n")] = '\0';
    returning_text = malloc(strlen(input) + 1);
    if (returning_text == NULL) {
        return NULL; // В случае ошибки выделения памяти возвращаем NULL
    }
    strcpy(returning_text, input);
    return returning_text; // Возвращаем строку
}
//char* input_name(char* c) {
//    char input[100];
//    int valid = 0;
//    char *endptr, *returning_text;
//    valid = 0;
//    printf("%s", c);
//    fgets(input, sizeof(input) / sizeof(char), stdin);
//    input[strcspn(input, "\n")] = '\0';
//    returning_text = malloc(strlen(input));
//    return returning_text;
//}
void check_number(int* number, int start, int end) {
    if (*number < start || *number > end) {
        *number = end;
        printf("Значит будет %d\n", *number);
    }
}


char* read_binary_string(FILE* fd, int include_zero) {
    char buffer[256], *result = NULL;
    int size_buffer = 0;
        while (fread(buffer + size_buffer, sizeof(buffer[0]), 1, fd) != 0) {
            //if (buffer[size_buffer] == '\0') {
            if (!buffer[size_buffer]) {
                size_buffer += include_zero ? 1 : 0; 
                result = (char *)malloc(size_buffer);
                memcpy(result, buffer, size_buffer);
                break;
            }
            size_buffer++;
        }
    //printf("\nВернука я тебе |%s| = Size(|%d|) = STRLEN(%d)\n", result, sizeof(result), strlen(result));
    return result;
}
void promptForSave(Floor* queue, char* file_user) {
    if (queue != NULL) {
        printf("Хотите сохранить текущую структуру в файл перед выходом? (y/n): ");
        char answer;
        do {
            answer = getchar();
        } while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N');
        
        if (answer == 'y' || answer == 'Y') {
            saver(queue, file_user);
        }
        while ((answer = getchar()) != '\n' && answer != EOF) { }
    }
} 
