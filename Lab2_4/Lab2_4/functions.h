#ifndef FUNCTIONS_H 
#define FUNCTIONS_H
#include "header.h"
#include "queue.h"
#include "functions.h"
int correct(char* c);
char* input_name(char* c);
void check_number(int* number, int start, int end);
char* read_binary_string(FILE* fd, int include_zero);
void promptForSave(Floor* floors, char* file_user);
#endif 
