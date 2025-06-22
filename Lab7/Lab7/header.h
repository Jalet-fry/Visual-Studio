#ifndef HEADER_H 
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>

#define DELIMS " \n\t.,!?\\|"

/*Аргументы для задач :
cd .\x64\Debug\;.\Lab7.exe 
.\Lab7.exe 1 2 "This PARTA goes to river"
.\Lab7.exe 2 p "She pо уліце poртал" "три"
.\Lab7.exe 3 "zaraza ! blin" "sex hat keine macht" "a fly fly to moon"  "cola out"
.\Lab7.exe 4  1 -3.5 -8.5 5
.\Lab7.exe 1 2 "This PARTA goes to river";.\Lab7.exe 2 p "She pо уліце poртал" "три";.\Lab7.exe 3 "zaraza ! blin" "sex hat keine macht" "a fly fly to moon"  "cola out";.\Lab7.exe 4  1 -3.5 -8.5 5

;;
*/
void my_strncpy(char* dest, char* src, int max_len);
int my_strlen(const char *str);
char *my_strchr(char *str, int c);
char* my_strcat(char* dest, const char* src);
void my_strcpy(char *dest, char *src);
char* my_strtok(char* str, const char* delim);
int my_atoi(char *str);
typedef void (*task_func)(int, char **);
#endif 
