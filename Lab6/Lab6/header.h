#ifndef HEADER_H // защита от повторного включения
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#define Abs(x) ((x>0)? x : -x )

int method_filling();
double measure_time(int method, void (*func)(int*, int), int* array, int size);
void swap(int *a, int *b);

int size_1d(int method);
void size_2d(int method, int* rows, int* colums);


int correct(char* c);

int* create_1d_array(int size, int method);
void print_1d_array(int* arr, int size);

int** create_2d_array(int method, int* rows, int *rowscounte);
void print_matrix(int** table, int rows, int rowscount);
void free_matrix(int** table,int rowscount);
//Сами задачи
void sort_even_after_max(int* arr, int size);
void sort_back_even_after_max(int* arr, int size);
void bubble_sort_even(int *arr, int size);
void shellsort(int **table, int rowscount, int rows);
int maxCol(int **table, int rowscount, int col);
void swapCol(int **table, int rowscount, int col1, int col2);
void sortColByMax(int **table, int rowscount, int rows);
#endif // HEADER_H