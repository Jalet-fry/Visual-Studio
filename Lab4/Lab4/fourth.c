#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#define N 8
void print_array(int arr[N][N], int line, int column) {
    printf("Массив:[");
    for (int a = 0; a < line; a++) {
        for (int b = 0; b < column; b++) {
            if (b == 0) {
                printf("\n\t\t{%d", arr[a][b]);
            }
            else if (b == (column - 1)) {
                printf("%d}", arr[a][b]);
            }
            else { printf("%d", arr[a][b]); }
            if (((a < line - 1 || b < column - 1) && !(a == line - 1 && b == column - 1))) {
                printf(",");
            }
        }
    }
    printf("]\n");
}
//Задача 3:минимальный элемент в левом треугольнике матрицы
int diag_min(int arr[N][N], int line, int column) {
    int min = arr[1][0];
    for (int y = 0; y < column; y++) {
        int x = line - 1 - y;
        if (x - y > 1) {
            for (int i = y + 1; i < x; i++) {
                if (arr[i][y] < min) {
                    min = arr[i][y];
                }
            }
        }

    }
    return min;
}
//Задача 1 про седловые точки:функция find_saddle_points проверяет элементы через is_saddle_points 
int is_saddle_point(int arr[N][N], int i, int j, int line, int column) {
    //Помни:i=столбец, j = строка внутри столбца
    int min_col_in_line = arr[i][0],max_col_in_line=arr[i][0];
    int min_col_in_line_index = 0, max_col_in_line_index = 0;
    for (int a = 1; a < line; a++) {
        if (arr[i][a] < min_col_in_line) {
            min_col_in_line = arr[i][a];
            min_col_in_line_index = a;
        }
        if (arr[i][a] > max_col_in_line){
            max_col_in_line = arr[i][a];
            max_col_in_line_index = a;
        }
    }
    int max_line_in_col = arr[0][j], min_line_in_col = arr[0][j];
    int min_line_in_col_index = 0, max_line_in_col_index = 0;
    for (int b = 1; b < column; b++) {
        if (arr[b][j] > max_line_in_col) {
            max_line_in_col = arr[b][j];
            max_line_in_col_index = b;
        }
        if (arr[b][j] < min_line_in_col){
            min_line_in_col = arr[b][j];
            min_line_in_col_index = b;
        }

    }
    return (i == min_line_in_col_index && j == max_col_in_line_index || i == max_line_in_col_index && j == min_col_in_line_index);
}

void find_saddle_points(int arr[N][N], int line, int column) {
    int found = 0;
    for (int i = 0; i < line; i++) {
        for(int j = i; j < column; j++){
            if (is_saddle_point(arr, i, j, line, column)) {
                printf("Saddle point at [%d][%d]=%d\n", i, j,arr[i][j]);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("No saddle point in the matrix\n");
    }
}

//Задача 2
int enough_for_reverse(int arr[N][N], int up, int i) {
    int flag = 0;
    for (int j = 0; j < up; j++) {
        if (arr[i][j] > 0) {
            flag += 1;
            return 1;
        }
    }
    return 0;
}
void invert_signs(int arr[N][N], int up, int right) {
    for (int i = 0; i < up; i++) {
        for (int j = 0; j < right; j++) {
            arr[i][j] = -arr[i][j]; 
        }
    }
}

void reversed(int arr[N][N], int up, int right) {
    int count = 0;
    for (int i = 0; i < right; i++) {
        count += enough_for_reverse(arr, up, i);
        if (count == right) {
            invert_signs(arr, up, right);
            printf("\nНовый ");
            print_array(arr, up, right);
        }
    }

}
void  main() {
    //    SetConsoleOutputCP(1251);
    //    SetConsoleCP(1251);
    char standart[100]; 
    snprintf(standart, sizeof(standart), "Введите количество элементов в массиве (не больше %d): ", 100); // записываем в строку отформатированный текст с подстановкой значения N
    char welcome[700] = "Тема:одномерные массивы,список функции:\n"
        "-1)sos or help or h = инструкция для вас\n"
        "0)exit или 0 = выход\n"
        "1)saddle=найти седловые точки\n"
        "2)reversed=сделать -1*matrix если в столбце хоть положительный\n"
        "3)diag_min=минимаьный элемент меж 2 диагоналей.\n";
    printf("%s", welcome);
    while (1) {
        int matrix_saddle[N][N] = { {44, 46, 48, 70},
                                    {30, 33, 32, 60},  // Ответы:44,60
                                    {43, 69, 63, 62},
                                    {42, 35, 13, 67} };
        int even_matrix_diag[N][N] = { {44, 46, 48, 70, 80, 90},
                                       {40, 33, 32, 60, 80, 90},  // Ответ:15
                                       {43, 15, 63, 62, 80, 90},
                                       {42, 30, 13, 67, 80, 90},
                                       {44, 69, 63, 62, 80, 90},
                                       {43, 69, 63, 62, 80, 90 }, };
        int uneven_matrix_diag[N][N] = { {44, 46, 48, 70, 80},
                                         {40, 33, 32, 60, 80},  // Ответ:-43
                                         {15, -43, 63, 62, 80},
                                         {42, 30, 13, 67, 80},
                                         {44, 69, 63, 62, 80},};
        int matrix_reversed_working[N][N] = { {2, -4, -6, -8},
                                              {-1, 3, -2, -1},
                                              {-2, -2, 7, -0},
                                              {-4, -1, -0, 8} };
        int matrix_reversed_work[N][N] = { {2, -4, -6},
                                           {-1, 3, -2},
                                           {-2, -2, 7},
                                           {-4, -1, -0} };

        int matrix_reversed_lazy[N][N] = { {2, -4, -6, -8},
                                           {-1, 3, -2, -1},
                                           {-2, -2, -7, -0},
                                           {-4, -1, -0, 8} };


        int backup_reversed[N][N]; 
        for (int i = 0; i < N; i++) { 
            for (int j = 0; j < N; j++) { 
                backup_reversed[i][j] = matrix_reversed_working[i][j]; 
            }
        }
        int backup_work[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                backup_work[i][j] = matrix_reversed_work[i][j];
            }
        }
        printf("Вызов функции:");
        char choice[30];
        scanf_s("%s", choice, sizeof(choice));
        fflush(stdin);
        if (strcmp(choice, "exit") == 0 || strcmp(choice, "0") == 0) {
            printf("С вами была компания NOmicrosoft, До Новых Встреч!\n");
            printf("%s", choice);
            break; 
        }
        else if (strcmp(choice, "saddle") == 0 || strcmp(choice, "1") == 0) {
            print_array(matrix_saddle, 4, 4);
            find_saddle_points(matrix_saddle, 4, 4);
        }
        else if (strcmp(choice, "sos") == 0 || strcmp(choice, "help") == 0 || strcmp(choice, "h") == 0 || strcmp(choice, "-1") == 0) {
            printf("\n**************\n%s", welcome);
        }
        else if (strcmp(choice, "reversed") == 0 || !strcmp(choice, "2")) {
            printf("Сработает с ");
            print_array(backup_work,4, 3);
            reversed(backup_work, 4, 3);
            printf("Был ");
            print_array(backup_reversed,4,4);
            reversed(backup_reversed, 4, 4);
            printf("Не сработает с ");
            print_array(matrix_reversed_lazy,4,4);
            reversed(matrix_reversed_lazy, 4, 4);
        }
        else if (strcmp(choice, "diag_min") == 0 || !strcmp(choice, "3")) {
            print_array(even_matrix_diag, 6, 6);
            int even_min_diag=diag_min(even_matrix_diag, 6, 6);
            printf("Mинималный элемент в четной матрице в области 2 = %d\n",even_min_diag);
            print_array(uneven_matrix_diag, 5, 5);
            int uneven_min_diag=diag_min(uneven_matrix_diag, 5, 5);
            printf("Mинималный элемент в нечетной матрице в области 2 = %d\n",uneven_min_diag);
        
        }
        else { printf("%s", choice); }
    }
}
