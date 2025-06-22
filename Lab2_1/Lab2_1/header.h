#ifndef HEADER_H 
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#undef NDEBUG
int input(char* filename);
int doom(char* filename, int method);
void printing_file(char* filename);
void print_file_2(FILE *file);
int correct(char* c);
void fill(char* filename, int array[], int size_array);
void task1(char* filename, char method);
int Max_length(char* filename, int limit);
//[    1    2    3    4    5    6    7    8    9   45  -45    1    2    3    4    5    6    7 ]
//Максимальная длина подмассива с суммой не более 0 равна 8
int zeroing(char* filename);
void sort (char* filename);
void swap(FILE *file, int i, int j);
void task2(char* filename, char method);
void task3(char* filename, char method);
#endif // HEADER_H