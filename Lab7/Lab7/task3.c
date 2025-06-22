#include "task3.h" 

int count_words(const char *str){
    int words = 0; 
    int in_word = 0; 
    while (*str != 0){ 
        if (my_strchr(DELIMS, *str) != NULL){
        //if (*str == ' ' || *str == '\\n' || *str == '\\t' || *str == '.' || *str == ',' || *str == '!' || *str == '?'){ 
            in_word = 0; 
        }
        else { 
            if (in_word == 0){ 
                words++; 
                in_word = 1; 
            }
        }
        str++; 
    }
    return words; 
}
void TASK3(int size, char** mass){
        char **copy = malloc((size - 1) * sizeof(char *));
    // копируем каждую строку из mass в copy
    for (int i = 1; i < size; i++) {
        // выделяем память для копии строки
        copy[i - 1] = malloc((my_strlen(mass[i]) + 1) * sizeof(char));
        // копируем содержимое строки
        my_strcpy(copy[i - 1], mass[i]);
    }
    for (int i = 1; i < size; i++){
        int new_count = count_words(mass[i]);
        int location = i - 1;
        char* remember = mass[i];
        while(location >= 0 && count_words(mass[location]) > new_count){
            mass[location+1] = mass[location];
            location = location - 1;
        }
        mass[location+1] = remember;
    }
    for (int i = 0; i < size; i++) {
        printf("%d : %s\n", count_words(mass[i]), mass[i]);
    }
}
void task3(int size, const char** mass){
    char **copy = malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        copy[i] = malloc((my_strlen(mass[i]) + 1) * sizeof(char));
        my_strcpy(copy[i], mass[i]);
    }
    for (int i = 1; i < size; i++){
        int new_count = count_words(copy[i]);
        int location = i - 1;
        char* remember = copy[i];
        while(location >= 0 && count_words(copy[location]) > new_count){
            copy[location+1] = copy[location];
            location = location - 1;
        }
        copy[location+1] = remember;
    }
    for (int i = 0; i < size; i++) {
        printf("%d : %s\n", count_words(copy[i]), copy[i]);
    }
    for (int i = 0; i < size - 1; i++) {
        free(copy[i]);
    }
    free(copy);
}
