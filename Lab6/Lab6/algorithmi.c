#include <string.h>
#include "header.h" 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000
#define taboo 3
int method_filling() {
    int method;
    printf("Выберите способ заполнения массива:\n");
    printf("1 - ввести значения с клавиатуры\n2 - использовать тестовые значения\n3 - рандом для %d и 20 элементов в 1-мерном и 2-мерном массиве соотвественно\n", N);
    method = correct("Введите 1, 2 и 3:");
    if(method != 1 && method != 2 && method != 3) { 
        printf("Тогда пусть будет тест\n");
        method = 2;
    }
    return method;
}

double measure_time(int method, void (*func)(int*, int), int* array, int size) {
    method != taboo ? print_1d_array(array, size) : 0;
    clock_t start = clock();
    func(array, size);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    if (method != taboo) {
        printf("\nНовый:");
        print_1d_array(array, size);
    }
    printf("Время сортировки: %f секунд\n", time_spent);
    return time_spent;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int size_1d(int method) {
    int size;
    if (method == 1) {
        size = correct("Введите размер одномерного массива:"); 
        while (size < 1) {
            size = correct("Введите корректный размер одномерного массива\nЭлементов в  строке:"); 
        }
    }
    else if (method == 3) {
        size = N;
    }
    else {
        size = 13;
    }
    return size;
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
    else if (method == 3) {
        srand(time(NULL));
        for (int i = 0; i < size; i++) { 
            arr[i] = -20 + rand()%(41);
        }
    }
    else {
        int static_arr[] = { 1, 34, 566, -77, 90, 0, 15, -22,-192, 566, -44, 13, 6 }; 
        for (int i = 0; i < size; i++) { 
            arr[i] = static_arr[i];
        }
    }
    return arr;
}

void print_1d_array(int* arr, int size) {
    printf("{");
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

int** create_2d_array(int method, int* rows, int* rowscount){
    int** table;
    switch (method)
    {
        case 1: 
            *rowscount = correct("Строк всего будет:");
            while (*rowscount < 1) {
                *rowscount = correct("Строк всего будет:");
            }
            table = malloc(*rowscount * sizeof(int*));
            char element[50];
            snprintf(element, 50, "Элементов в каждой строке:");
            *rows = correct(element);
            while (*rows < 1) {
                *rows = correct("Элементов в каждой строке:");
            }
            for (int i = 0; i < *rowscount; i++) {
                table[i] = malloc((*rows) * sizeof(int));
                if (table[i] == NULL) {
                    printf("\n\tПамяти нету\n");
                    return NULL;
                }
                for (int j = 0; j < *rows; j++) {
                    char elem[20];
                    snprintf(elem, sizeof(elem), "table[%d][%d]=", i, j);
                    table[i][j] = correct(elem);
                }
            }
            break;
        case 2: 
            *rowscount = 4;
            table = malloc((*rowscount)*sizeof(int*));
            int data[] = { 1, 6, 11, -2, 5, 12, 3, -7, 9, 4, 8, -10 };
            int k = 0;
            *rows=3;
            for (int i = 0; i < *rowscount; i++)
            {
                table[i] = malloc((*rows) * sizeof(int));
                for (int j = 0; j < *rows; j++)
                {
                    table[i][j] = data[k];
                    k++;
                }
            }
            break;
        case 3:
            *rowscount = 4;
            table = malloc((*rowscount)*sizeof(int*));
            *rows=5;
            srand(time(NULL));
            for (int i = 0; i < *rowscount; i++)
            {
                table[i] = malloc((*rows) * sizeof(int));
                for (int j = 0; j < *rows; j++)
                {
                    table[i][j] = -20 + rand()%(41);
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

void print_matrix(int** table, int rows, int rowscount) {
    printf("{");
    for (int i = 0; i < rowscount; i++)
    {
            printf("\t");
        for (int j = 0; j < rows; j++)
        {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }
    printf("}\n");
}

void free_matrix(int** table, int rowscount){
    for (int i = 0; i < rowscount; i++)
    {
        free(table[i]);
    }
    free(table);
}
void sort_even_after_max(int* arr, int size) {
    int max_index = 0;
    int index_even = -1;
    int last_even = -1;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[max_index]) {
            max_index = i;
        }
        if (index_even == -1 && i > max_index && arr[i] % 2 == 0) {
            index_even = i;
        }
        if (arr[i] % 2 == 0) { last_even = i; }
    }
    if (index_even != -1) {
        for (int i = index_even; i <= last_even; i++) {
            int min_index = i;
            for (int j = i + 1; j <= last_even; j++) {
                if (arr[j] % 2 == 0 && arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }
            if (arr[i] % 2 == 0 && arr[min_index] % 2 == 0 && arr[i] != arr[min_index]) {
                swap(&arr[i], &arr[min_index]);
            }
        }
    }
}
void sort_back_even_after_max(int* arr, int size) {
    int max_index = 0;
    int first_even = -1;
    int last_even = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] > arr[max_index]) {
            max_index = i;
        }
        if (first_even == -1 && i > max_index && arr[i] % 2 == 0) {
            first_even = i;
        }
        if (arr[i] % 2 == 0) { last_even = i; }
    }
    if (first_even != -1) {
        for (int i = first_even; i <= last_even; i++) {
            int max_even = i;
            for (int j = i + 1; j <= last_even; j++) {
                if (arr[j] % 2 == 0 && arr[j] > arr[max_even]) {
                    max_even = j;
                }
            }
            if (arr[i] % 2 == 0 && arr[max_even] % 2 == 0 && arr[i] != arr[max_even]) {
                swap(&arr[i], &arr[max_even]);
            }
        }
    }
}
void bubble_sort_even(int *arr, int size) {
    int max_index = 0;
    int first_even = -1;
    int last_even = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] > arr[max_index]) {
            max_index = i;
        }
        if (first_even == -1 && i > max_index && arr[i] % 2 == 0) {
            first_even = i;
        }
        if (arr[i] % 2 == 0) { last_even = i; }
    }
    if (first_even != -1) {
        for (int i = first_even; i <= last_even; i++) {
            if (arr[i] % 2 == 0) {
                for (int j = i + 1; j <= last_even; j++) {
                    
                    if (arr[j] % 2 == 0 && arr[i] > arr[j]) {
                        swap(&arr[i], &arr[j]);
                    }
                }
            }
        }

    }
}
void shellsort(int **table, int rowscount, int rows) {
    int d[] = {1, 4, 10, 23, 57, 145, 356, 911, 1968, 4711, 11969, 27901, 84801, 213331, 543749, 1355339, 3501671, 8810089, 21521774, 58548857, 157840433, 410151271, 1131376761, 2147483647};
    int m = 0;
    while (d[m] < rowscount) {
        m++;
    }
    for (int j = 0; j < rows; j++) {
        for (int i = m - 1; i >= 0; i--) {
            int gap = d[i];
            for (int x = gap; x < rowscount; x++) {
                int temp = table[x][j];
                int y = x - gap;
                while (y >= 0 && table[y][j] < temp) {
                    table[y + gap][j] = table[y][j];
                    y -= gap;
                }
                table[y + gap][j] = temp;
            }
        }
    }
}
// Функция для нахождения максимального элемента в столбце матрицы
int maxCol(int **table, int rowscount, int col) {
    int max = table[0][col]; // Предполагаем, что первый элемент максимальный
    for (int i = 1; i < rowscount; i++) { // Проходим по всем элементам столбца
        max = max(max, table[i][col]); // Обновляем максимальный, если нашли элемент больше него
    }
    return max; // Возвращаем максимальный элемент
}

// Функция для обмена двух столбцов матрицы
void swapCol(int **table, int rowscount, int col1, int col2) {
    for (int i = 0; i < rowscount; i++) { // Проходим по всем элементам столбцов
        int temp = table[i][col1]; // Сохраняем значение из первого столбца
        table[i][col1] = table[i][col2]; // Копируем значение из второго столбца в первый
        table[i][col2] = temp; // Копируем сохраненное значение во второй столбец
    }
}

// Функция для сортировки столбцов матрицы по убыванию значения максимального элемента
void sortColByMax(int **table, int rowscount, int rows) {
    int gap = rows / 2; // Задаем начальный интервал
    while (gap > 0) { // Пока интервал больше нуля
        for (int i = gap; i < rows; i++) { // Проходим по всем столбцам с заданным интервалом
            int j = i; // Задаем индекс текущего столбца
            while (j >= gap && maxCol(table, rowscount, j - gap) < maxCol(table, rowscount, j)) { // Пока не дошли до начала и предыдущий столбец меньше текущего
                swapCol(table, rowscount, j - gap, j); // Меняем столбцы местами
                j -= gap; // Переходим к следующему предыдущему столбцу
            }
        }
        gap /= 2; // Уменьшаем интервал в два раза
    }
}
