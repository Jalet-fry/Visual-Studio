#include "task2.h" 

void task2(int argc, char **args) {
    if (args[0] == NULL || args[1] == NULL || args[2] == NULL) {
        printf("Неверное количество аргументов\n");
        return;
    }
    char C = args[0][0]; 
    char *S = args[1]; 
    char *S0 = args[2]; 
    char result[100] = ""; 
    for (int i = 0; S [i] != '\0'; i++) {
        if (S [i] == C) {
            my_strcat(result, S0);
        } else {
            result [my_strlen(result)] = S [i];
        }
    }
    printf("%s\n", result); 
}
