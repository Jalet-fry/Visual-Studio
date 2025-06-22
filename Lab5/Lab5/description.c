#include <string.h>
#include "head.h" 
#include <stdio.h>
#include <stdlib.h>
int method_filling() {
    int method;
    printf("Выберите способ заполнения массива:\n");
    printf("1 - ввести значения с клавиатуры\n2 - использовать тестовые значения\n");
    method = correct("Введите 1 или 2:");
    if(method != 1 && method != 2) { 
        printf("Тогда пусть будет тест\n");
        method = 2;
    }
    return method;
}
int size_1d(int method) {
    int size;
    if (method == 1) {
        size = correct("Введите размер одномерного массива:"); 
        while (size < 1) {
            size = correct("Введите корректный размер одномерного массива\nЭлементов в  строке:"); 
        }
    }
    else {
        size = 10;
    }
    return size;
}
void size_2d(int method, int* rows, int* colums) {
    if (method == 1) {
        *rows = correct("Введите количество строк массива:"); 
        while (*rows < 1) {
            *rows = correct("Строк всего будет:");
        }
        *colums = correct("Введите количество столбцов массива:"); 
        while (*colums < 1) {
            *rows = correct("Строк всего будет:");
        }
    }
    else {
        *rows = 5;
        *colums = 5;
    }
}
int correct(char* c) {
    char input[100];
    int valid = 0;
    int num;
    char* endptr; 
    valid = 0;
    while (!valid) {
        printf("%s\n", c);
        fgets(input, sizeof(input) / sizeof(char), stdin);
        num = (int)strtol(input, &endptr, 10); 
        if (*endptr != '\n' && *endptr != '\0') { 
            printf("Это не число.Попробуйте еще раз.\n");
        }
        else {
            valid = 1;
            printf("Вы ввели число: %d\n", num);
        }
    }
    return num;
}

int* create_1d_array(int size, int method) {
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти.\n");
        return NULL;
    }
    if (method == 1) {
        for (int i = 0; i < size; i++) { 
            char* element = malloc(50 * sizeof(char));
            snprintf(element, 50, "Введите [%d] элемент массива:", i);
            arr[i] = (int)correct(element);
            free(element);
        }
    }
    else {
        int static_arr[] = { 1, 34, 563, 7, 90, 1, -22, 345, -44, 5 }; 
        for (int i = 0; i < size; i++) { 
            arr[i] = static_arr[i];
        }
    }
    return arr;
}


void print_1d_array(int* arr, int size) {
    printf("Массив:{");
    if (arr != NULL) {
        for (int a = 0; a < size; a++) {
            printf("%d", arr[a]);
            if (a < size - 1) {
                printf(", ");
            }
        }
    }
    printf("}\n");
}

int** create_2d_array(int method, int** rows, int* rowscount, enum matrix type){
    int** table;
    switch (method)
    {
    case 1: 
        *rowscount = correct("Строк всего будет:");
        while (*rowscount < 1) {
            *rowscount = correct("Строк всего будет:");
        }
        *rows = malloc(sizeof(int) * (*rowscount));
        table = malloc(*rowscount * sizeof(int*));
        for (int i = 0; i < *rowscount; i++)
        {
            char element[50];
            switch (type)
            {
            case JAGGED:
                snprintf(element, 50, "Элементов в %d строке:", i);
                (*rows)[i] = correct(element);
                while ((*rows)[i] < 1) {
                    (*rows)[i] = correct(element);
                }
                break;
            case RECTANGLE:
                if (i == 0) {
                    snprintf(element, 50, "Элементов в каждой строке:");
                    (*rows)[i] = correct(element);
                    while (*rows[i] < 1) {
                        *rows[i] = correct("Элементов в каждой строке:");
                    }
                }
                else {
                    (*rows)[i] = (*rows)[i-1];
                }
                break;
            }
            table[i] = malloc((*rows)[i] * sizeof(int));
            if (table[i] == NULL) {
                printf("\n\tПамяти нету\n");
                return NULL;
            }
            for (int j = 0; j < (*rows)[i]; j++)
            {
                char elem[50];
                snprintf(elem, sizeof(elem), "table[%d][%d]=", i, j);
                table[i][j] = correct(elem);
            }
        }
        break;
    case 2: 
        *rowscount = 4;
        *rows = malloc(sizeof(int) * (*rowscount));
        switch (type)
        {
        case JAGGED:
            (*rows)[0]=2,(*rows)[1]=4,(*rows)[2]=5,(*rows)[3]=1;
            break;
        case RECTANGLE:
            (*rows)[0]=(*rows)[1]=(*rows)[2]=(*rows)[3]=3;
            break;
        }
        int data[] = { 1, 5, 9, 2, 6, 10, 3, 7, 11, 4, 8, 12 };
        table = malloc(*rowscount*sizeof(int*));
        int k = 0;
        for (int i = 0; i < *rowscount; i++)
        {
            table[i] = malloc((*rows)[i] * sizeof(int));
            for (int j = 0; j < (*rows)[i]; j++)
            {
                table[i][j] = data[k];
                k++;
            }
        }
        break;
    default:
        printf("Invalid method\n");
        printf("Ошибка выделения памяти.\n");
        table = NULL;
        return table; 
    }
    return table; 
}

void print_matrix(int** table, int* rows, int rowscount)
{
    printf("{");
    for (int i = 0; i < rowscount; i++)
    {
            printf("\t");
        for (int j = 0; j < rows[i]; j++)
        {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }
    printf("}\n");
}


void free_matrix(int** table, int* rows, int rowscount)
{
    for (int i = 0; i < rowscount; i++)
    {
        free(table[i]);
    }
    free(table);
    free(rows);
}
int is_two_digit(int n) {
    return Abs(n) > 10 && Abs(n) < 99;
}
void delete_two_digit(int** arr, int* size) {
    int new_massiv_index = 0;
    for (int i = 0; i < *size; i++) {
        if (!is_two_digit((*arr)[i])) {
            (*arr)[new_massiv_index] = (*arr)[i];
            new_massiv_index++;
        }
    }
    if (new_massiv_index > 0) {
        *arr = (int*)realloc(*arr, new_massiv_index * sizeof(int));
    }
    else{
        free(*arr);
        *arr = NULL;
    }
    *size = new_massiv_index;
}          

void copy_odd_elements(int** table, int* rows, int rowscount) {
    int way_of_solve;
    printf("Выберите способ сдвига:\n");
    printf("1 - через memmove\n2 - через for\n");
    way_of_solve = correct("Введите 1 или 2:");
    if (way_of_solve != 1 && way_of_solve != 2) {
        printf("Значит будет через memmove\n");
        way_of_solve = 1;
    }
    for (int i = 0; i < rowscount; i++) 
    {
        for (int j = rows[i]-1; j >= 0; j--)
        {
            if (table[i][j] % 2 != 0) 
            {
                rows[i]++;
                table[i] = realloc(table[i], rows[i] * sizeof(int));
                if (table[i] == NULL) 
                {
                    printf("все очень плохо");
                    return; 
                }
                if (way_of_solve == 1) {
                    memmove(&table[i][j + 2], &table[i][j + 1], (rows[i] - j - 2) * sizeof(int));
                    table[i][j + 1] = table[i][j];
                }
                else {
                    for (int x = rows[i]-1; x > j; x--){
                        table[i][x] = table[i][x-1];
                    }
                }
            }
        }
    }
}
void check(int rows, int rowscount, int* change_up, int* change_left) {
    if (*change_up > rowscount - 1) {
        *change_up -= rowscount;
        *change_left += 1;
        if (*change_left > rows - 1) {
            *change_left -= rows;
        }
    }
    if (*change_left > rows - 1) {
        *change_left -= rows;
    }
}
void move_on_1_step(int** table, int* rows, int rowscount) {
    int x = 0, y = 0, temp = table[y][x];
    for (int a = 0; a < rowscount * rows[0] - 1; a++) {
        int change_left = x, change_up = y + 1;
        check(rows[0], rowscount, &change_up, &change_left);
        table[y][x] = table[change_up][change_left];
        y = change_up, x = change_left;
    }
    table[y][x] = temp;
}
void move_elements(int** table, int* rows, int rowscount) {
    int method, move_left, move_up, number;
    printf("Выберите способ задания числа сдвига:\n");
    printf("1 - ввести значение с клавиатуры\n2 - использовать тестовое значение\n");
    method = correct("Введите 1 или 2:");
    if (method != 1 && method != 2 || method == 2) {
        number = 11;
        printf("Тогда пусть будет тестовое:%d\n", number);
    }
    else if (method == 1){
        number = correct("Введите число");
    }
    number %= (rowscount * rows[0]);
    if (number < 0) {
        number = rowscount * rows[0] + number;
    }
    for (int b = 0; b < number; b++) {
        move_on_1_step(table, rows, rowscount);
    }
}


void move_element(int** table, int* rows, int rowscount) {
    int method, move_left, move_up, number;
    printf("Выберите способ задания числа сдвига:\n");
    printf("1 - ввести значение с клавиатуры\n2 - использовать тестовое значение\n");
    method = correct("Введите 1 или 2:");
    if (method != 1 && method != 2 || method == 2) {
        number = 11;
        printf("Тогда пусть будет тестовое:%d\n", number);
    }
    else if (method == 1){
        number = correct("Введите число");
    }
    number %= (rowscount * rows[0]);
    if (number < 0) {
        number = rowscount * rows[0] + number;
    }
    move_left = number / rowscount;
    move_up = number % rowscount;
    
    int y = 0, x = 0, start_y = 0, start_x = 0, temp = table[y][x];
    for (int a = 0; a < rowscount * rows[0]; a++) {
        int change_left = x + move_left, change_up = y + move_up;
        
        check(rows[0], rowscount, &change_up, &change_left);
        if (change_up == start_y && change_left == start_x) {
            table[y][x] = temp;
            y = change_up + 1, x = change_left;
            check(rows[0], rowscount, &y, &x);
            start_y = y, start_x = x, temp = table[y][x];
        }
        else {
            table[y][x] = table[change_up][change_left];
            y = change_up, x = change_left;
        }
    }
}


