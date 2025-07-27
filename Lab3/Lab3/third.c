#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>

#define MAX_SIZE 100

// Прототипы функций
void print_matrix(int* matrix, int size);
double get_valid_number(const char* prompt);
void fill_array(double* array, int size);
void print_array(double* array, int size);
int count_in_range(double* array, int size, double a, double b);
int find_last_max_index(double* array, int size);
double sum_after_last_max(double* array, int size);
void insert_zeros_after_even(double* array, int* size);
void sort_array(double* array, int size);
double find_rarest_odd(double* array, int size);

int main() {
    printf("Демонстрация работы с матрицей:\n");
    int demo_matrix[4][4] = {{1,2,3,4}, {1,2,3,4}, {1,2,3,4}, {1,2,3,4}};
    print_matrix((int*)demo_matrix, 4);
    printf("\n");

    char menu[] = 
        "Меню программы:\n"
        "1) range_sum - Количество элементов в диапазоне и сумма после максимума\n"
        "2) even - Вставить 0 после каждого четного элемента\n"
        "3) rarity - Найти наиболее редкое нечетное число\n"
        "0) exit - Выход из программы\n"
        "Введите команду: ";

    double array[MAX_SIZE];
    int current_size = 0;
    char command[20];

    while (1) {
        printf("\n%s", menu);
        
        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("Ошибка чтения ввода.\n");
            continue;
        }
        
        // Удаляем символ новой строки
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0 || strcmp(command, "0") == 0) {
            printf("Программа завершена. До свидания!\n");
            break;
        }
        else if (strcmp(command, "range_sum") == 0 || strcmp(command, "1") == 0) {
            current_size = (int)get_valid_number("Введите размер массива (до 100): ");
            if (current_size <= 0 || current_size > MAX_SIZE) {
                printf("Некорректный размер массива.\n");
                continue;
            }
            
            fill_array(array, current_size);
            printf("Введенный массив:\n");
            print_array(array, current_size);
            
            double a = get_valid_number("Введите нижнюю границу диапазона: ");
            double b = get_valid_number("Введите верхнюю границу диапазона: ");
            
            int count = count_in_range(array, current_size, a, b);
            printf("Количество элементов в диапазоне [%.2f, %.2f]: %d\n", a, b, count);
            
            double sum = sum_after_last_max(array, current_size);
            printf("Сумма элементов после последнего максимума: %.2f\n", sum);
        }
        else if (strcmp(command, "even") == 0 || strcmp(command, "2") == 0) {
            current_size = (int)get_valid_number("Введите размер массива (до 100): ");
            if (current_size <= 0 || current_size > MAX_SIZE) {
                printf("Некорректный размер массива.\n");
                continue;
            }
            
            fill_array(array, current_size);
            printf("Исходный массив:\n");
            print_array(array, current_size);
            
            insert_zeros_after_even(array, &current_size);
            printf("Массив после вставки нулей:\n");
            print_array(array, current_size);
        }
        else if (strcmp(command, "rarity") == 0 || strcmp(command, "3") == 0) {
            current_size = (int)get_valid_number("Введите размер массива (до 100): ");
            if (current_size <= 0 || current_size > MAX_SIZE) {
                printf("Некорректный размер массива.\n");
                continue;
            }
            
            fill_array(array, current_size);
            printf("Введенный массив:\n");
            print_array(array, current_size);
            
            sort_array(array, current_size);
            double rarest = find_rarest_odd(array, current_size);
            printf("Наиболее редкое нечетное число: %.2f\n", rarest);
        }
        else {
            printf("Неизвестная команда. Попробуйте снова.\n");
        }
    }

    return 0;
}

// Функция для вывода матрицы
void print_matrix(int* matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i * size + j]);
        }
        printf("\n");
    }
}

// Функция для получения корректного числа от пользователя
double get_valid_number(const char* prompt) {
    char input[50];
    double number;
    char* endptr;

    while (1) {
        printf("%s", prompt);
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Ошибка чтения ввода. Попробуйте снова.\n");
            continue;
        }
        
        // Удаляем символ новой строки
        input[strcspn(input, "\n")] = '\0';
        
        number = strtod(input, &endptr);
        
        // Проверяем, что ввод корректен
        if (endptr == input || *endptr != '\0') {
            printf("Ошибка: введите число. Попробуйте снова.\n");
        } else {
            return number;
        }
    }
}

// Функция для заполнения массива
void fill_array(double* array, int size) {
    printf("Введите %d элементов массива:\n", size);
    for (int i = 0; i < size; i++) {
        char prompt[30];
        sprintf(prompt, "Элемент %d: ", i + 1);
        array[i] = get_valid_number(prompt);
    }
}

// Функция для вывода массива
void print_array(double* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

// Функция для подсчета элементов в диапазоне
int count_in_range(double* array, int size, double a, double b) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] >= a && array[i] <= b) {
            count++;
        }
    }
    return count;
}

// Функция для поиска индекса последнего максимального элемента
int find_last_max_index(double* array, int size) {
    int max_index = 0;
    double max_value = array[0];
    
    for (int i = 1; i < size; i++) {
        if (array[i] >= max_value) {
            max_value = array[i];
            max_index = i;
        }
    }
    
    return max_index;
}

// Функция для подсчета суммы после последнего максимума
double sum_after_last_max(double* array, int size) {
    int last_max_index = find_last_max_index(array, size);
    double sum = 0.0;
    
    for (int i = last_max_index + 1; i < size; i++) {
        sum += array[i];
    }
    
    return sum;
}

// Функция для вставки нулей после четных элементов
void insert_zeros_after_even(double* array, int* size) {
    int original_size = *size;
    int new_size = original_size;
    
    // Сначала подсчитаем, сколько нулей нужно вставить
    for (int i = 0; i < original_size; i++) {
        if ((int)array[i] % 2 == 0) {
            new_size++;
        }
    }
    
    if (new_size > MAX_SIZE) {
        printf("Ошибка: недостаточно места в массиве для вставки нулей.\n");
        return;
    }
    
    // Вставляем нули с конца массива
    int j = new_size - 1;
    for (int i = original_size - 1; i >= 0; i--) {
        array[j--] = array[i];
        if ((int)array[i] % 2 == 0) {
            array[j--] = 0.0;
        }
    }
    
    *size = new_size;
}

// Функция для сортировки массива (быстрая сортировка)
void sort_array(double* array, int size) {
    if (size <= 1) return;
    
    double pivot = array[size / 2];
    int i, j;
    
    for (i = 0, j = size - 1; ; i++, j--) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        
        if (i >= j) break;
        
        double temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    
    sort_array(array, i);
    sort_array(array + i, size - i);
}

// Функция для поиска наиболее редкого нечетного числа
double find_rarest_odd(double* array, int size) {
    double rarest = 0;
    int min_frequency = INT_MAX;
    int current_frequency = 0;
    double current_number;
    
    for (int i = 0; i < size; i++) {
        if ((int)array[i] % 2 != 0) {
            if (i == 0 || array[i] != current_number) {
                if (i > 0 && current_frequency < min_frequency) {
                    min_frequency = current_frequency;
                    rarest = current_number;
                }
                current_number = array[i];
                current_frequency = 1;
            } else {
                current_frequency++;
            }
        }
    }
    
    // Проверяем последнее число
    if (current_frequency < min_frequency) {
        rarest = current_number;
    }
    
    return rarest;
}
