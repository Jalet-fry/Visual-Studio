#include "task1.h" 

char* my_strrev(char* start, char* end) {
    if (start == NULL || end == NULL) {
        return NULL;
    }
    long long size = end - start;
    for (long long x = 0; x < size / 2; x++) {
        int temp = start[x];
        start[x] = start[size - 1 - x];
        start[size - 1 - x] = temp;
    }
    return start;
}

// Принимает указатель на указатель на следующий символ
// Возвращает указатель на начало слова или NULL, если слов нет
char *find_next_word(char **next, char *delim) {
    char *p; 
    if (next == NULL || *next == NULL) { 
        return NULL; 
    }
    p = *next; 
    while (**next != 0) { 
        if (my_strchr(delim, **next) != NULL) { 
            (*next)++; 
            if (*p != 0) { 
                return p; 
            } else { 
                p = *next; 
            }
        } else { 
            (*next)++; 
        }
    }
    if (*p != 0) { 
        *next = NULL; 
        return p; 
    } else { 
        return NULL; 
    }
}

void task1(int argc, char** args) {
    if (argc != 2) {
        printf("У вас %d \n", argc);
        printf("Неверное количество аргументов\n");
        return;
    }
    int k = my_atoi(args[0]);
    if (k == 0) {
        printf("Неверный формат числа\n");
        return;
    }
    char* str = args[1];
    char* token;
    int count = 0;
    char* next = str;
    token = find_next_word(&next, DELIMS);
    while (token != NULL) {
        count++;
        if (count == k) {
            char* end_word = token + 1;
            while (*end_word != 0) {
                if (my_strchr(DELIMS, *end_word) != NULL) {
                    break;// Нашли разделитель после нужного слова
                }
                end_word++;
            }
            my_strrev(token, end_word);
        }
        token = find_next_word(&next, DELIMS);
    }
    printf("|%s|\n", str);
}


// Возвращает число или 0, если строка не содержит только число
int my_atoi(char *str) {
    int x = 0; 
    int sign = 1; // Переменная для хранения знака числа
    if (str == NULL) {
        return 0;
    }
    while (*str == ' ') {
        str++;
    }
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            x = x * 10 + (*str - '0');
            str++;
        } else {
            return 0;
        }
    }
    return x * sign;
}

