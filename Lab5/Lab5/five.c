#include <stdio.h>
#include <string.h>
#include <math.h>
#include "head.h" 
int  main() {
    //    SetConsoleOutputCP(1251);
    //    SetConsoleCP(1251);
    char standart[100];
    snprintf(standart, sizeof(standart), "Введите количество элементов в массиве (не больше %d): ", 100); 
    char welcome[700] = "Тема: динамические массивы,список функции:\n"
        "-1)sos or help or h = инструкция для вас\n"
        "0)exit или 0 = выход\n"
        "1)delete=Из одномерного целочисленного массива удалить все двузначные элементы.\n"
        "2)copy=В двумерном массиве в каждой строке справа от каждого нечетного элемента добавить его копию\n"
        "3)move=В прямоугольной матрице выполнить циклический сдвиг вверх на k позиций..\n";
    printf("%s", welcome);
    while (1) {
        printf("Вызов функции:");
        char choice[30];
        fgets(choice, 20, stdin);
        choice[strlen(choice) - 1] = 0;
        if (strcmp(choice, "exit") == 0 || strcmp(choice, "0") == 0) {
            printf("С вами была компания NOmicrosoft, До Новых Встреч!\n");
            printf("%s", choice);
            return 0;
        }
        else if (strcmp(choice, "delete") == 0 || strcmp(choice, "1") == 0) {
            int method = method_filling();
            int size = size_1d(method);
            int *array = create_1d_array(size,method); 
            print_1d_array(array, size);
            delete_two_digit(&array, &size);
            printf("Новый ");
            print_1d_array(array, size);
            if (array != NULL) {
                free(array);
            }
        }
        else if (strcmp(choice, "sos") == 0 || strcmp(choice, "help") == 0 || strcmp(choice, "h") == 0 || strcmp(choice, "-1") == 0) {
            printf("\n**************\n%s", welcome);
        }
        else if (strcmp(choice, "copy") == 0 || !strcmp(choice, "2")) {
            int method = method_filling();
            enum matrix type= JAGGED;
            int rowscount;  // количество строк
            int* rows;      // указатель для блока памяти для хранения информации по строкам
            int** table = create_2d_array(method, &rows, &rowscount, type);
            if (table == NULL) {
                printf("Не удалось выделить память\n");
                return 1;
            }
            print_matrix(table, rows, rowscount);
            copy_odd_elements(table, rows, rowscount);
            print_matrix(table, rows, rowscount);
            free_matrix(table, rows, rowscount);
        }
        else if (strcmp(choice, "move") == 0 || !strcmp(choice, "3")) {
            int method = method_filling();
            enum matrix type= RECTANGLE;
            int rowscount;  
            int* rows;      
            int** table = create_2d_array(method, &rows, &rowscount, type);
            if (table == NULL) {
                printf("Не удалось выделить память\n");
                return 1;
            }
            print_matrix(table, rows, rowscount);
            move_element(table, rows, rowscount);
            print_matrix(table, rows, rowscount);
            free_matrix(table, rows, rowscount);
        }
        else { printf("\nПопался:%s", choice); }
        //vimrcpaths = "C:\Users\Vitos;C:\Users\Vitos\vimfiles;C:\Users\Vitos"
    }
}