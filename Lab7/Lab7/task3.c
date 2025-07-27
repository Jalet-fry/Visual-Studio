#include "task3.h" 

int count_words(const char *str){
    int words = 0; 
    int in_word = 0; 
    while (*str != 0){ 
        if (my_strchr(DELIMS, *str) != NULL){
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

void task3(int argc, char **args){
    char **copy = malloc(argc * sizeof(char *));
    for (int i = 0; i < argc; i++) {
        copy[i] = malloc((my_strlen(args[i]) + 1) * sizeof(char));
        my_strcpy(copy[i], args[i]);
    }
    
    for (int i = 1; i < argc; i++){
        int new_count = count_words(copy[i]);
        int location = i - 1;
        char* remember = copy[i];
        while(location >= 0 && count_words(copy[location]) > new_count){
            copy[location+1] = copy[location];
            location = location - 1;
        }
        copy[location+1] = remember;
    }
    
    for (int i = 0; i < argc; i++) {
        printf("%d : %s\n", count_words(copy[i]), copy[i]);
    }
    
    for (int i = 0; i < argc; i++) {
        free(copy[i]);
    }
    free(copy);
}
