#ifndef HEADER_H 
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#undef NDEBUG
void task1(char* filename);
//[    1    2    3    4    5    6    7    8    9   45  -45    1    2    3    4    5    6    7 ]
//������������ ����� ���������� � ������ �� ����� 0 ����� 8
void task2(char* filename);
void findMaxMin(FILE *file, int *max, int *min);
void replaceMaxMinInFile(FILE *readFile, FILE *tempFile, int max, int min);
void copyFileContent(FILE *source, FILE *destination);
#endif // HEADER_H
