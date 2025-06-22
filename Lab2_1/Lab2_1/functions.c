#include "header.h"
#include <stdio.h>
#include <string.h>
#define MAX_LEN 60 

int doom(char* filename, int method) {
    if (method == 1) {
        if (input(filename)) {
            return 0;
        }
    }
    return 1;
}

int input(char* filename) {
    char line[MAX_LEN];
    int x;
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        return 3;
    }
    printf("Введите числа через пробел (нажмите enter для окончания ввода): ");
    fgets(line, MAX_LEN, stdin);
    line[strcspn(line, "\n")] = '\0';
    char* ptr = line;
    char* endptr;
    while (*ptr) {
        x = strtol(ptr, &endptr, 10); 
        if (ptr == endptr) { 
            break; 
        }
        //fwrite(&x, sizeof(int), 1, fp); 
        assert(fwrite(&x, sizeof(int), 1, fp)); 
        ptr = endptr; 
    }
    fclose(fp);
    printf("Числа, прочитанные из файла: ");
    printing_file(filename);
    return 1;
}

int correct(char* c) {
    char input[100];
    char* endptr;
    int valid = 0, num;
    while (!valid) {
        printf("%s\n", c);
        fgets(input, sizeof(input) / sizeof(int), stdin);
        num = strtol(input, &endptr, 10); 
        if (*endptr != '\n' && *endptr != '\0' && *endptr != ' ') { 
            printf("Это не число.Попробуйте еще раз.\n");
        }
        else {
            valid = 1;
            printf("Вы ввели число: %d\n", num);
        }
    }
    return num;
}

void fill(char* filename, int array[], int size_array) {
    FILE* fd = fopen(filename, "wb");
    assert(fwrite(array, sizeof(int), size_array, fd) == size_array);
    fclose(fd);
}

void printing_file(char* filename) {
    FILE* fd = fopen(filename, "rb");
    //fseek(fd, 0, SEEK_SET);
    assert(!fseek(fd, 0, SEEK_SET));
    printf("\n\t\t\t\t[");
    int elem;
    while (fread(&elem, sizeof(elem), 1, fd)) {
        printf(" %4d", elem);
    }
    printf(" ]\n");
    fclose(fd);
}

void print_file_2(FILE *file) {
    long poz = ftell(file); 
    //fseek(file, 0, SEEK_SET);
    assert(!fseek(file, 0, SEEK_SET));
    printf("\n[");
    int elem;
    while (fread(&elem, sizeof(elem), 1, file)) {
        printf(" %4d", elem);
    }
    printf(" ]\n");
    //fseek(file, poz, SEEK_SET);
    assert(!fseek(file, poz, SEEK_SET));
}

void swap(FILE *file, int i, int j) {
    int x, y;
    if (i != j) {
        assert(!fseek(file, i * sizeof(int), SEEK_SET));
        assert(fread(&x, sizeof(int), 1, file));
        assert(!fseek(file, j * sizeof(int), SEEK_SET));
        assert(fread(&y, sizeof(int), 1, file));
        assert(!fseek(file, i * sizeof(int), SEEK_SET));
        assert(fwrite(&y, sizeof(int), 1, file));
        assert(!fseek(file, j * sizeof(int), SEEK_SET));
        assert(fwrite(&x, sizeof(int), 1, file));
    }
}



