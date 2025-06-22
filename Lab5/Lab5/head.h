#ifndef HEADER_H // защита от повторного включения
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#define Abs(x) ((x>0)? x : -x )
enum matrix {
    JAGGED = 1,
    RECTANGLE = 2
};

int method_filling();

int size_1d(int method);
void size_2d(int method, int* rows, int* colums);


int correct(char* c);

int* create_1d_array(int size, int method);
void print_1d_array(int* arr, int size);

int** create_2d_array(int method, int** rows, int *rowscount, enum matrix type);
void print_matrix(int** table, int* rows, int rowscount);
void free_matrix(int** table, int* rows, int rowscount);
//Сами задачи
void delete_two_digit(int** arr, int* size);
void copy_odd_elements(int** table, int* rows, int rowscount);
void move_elements(int** table, int* rows, int rowscount);
void move_element(int** table, int* rows, int rowscount);
#endif // HEADER_H
