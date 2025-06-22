#include <string.h>
#include <math.h>
#include <time.h>
#include "header.h"
int  main() {
    //    SetConsoleOutputCP(1251);
    //    SetConsoleCP(1251);
    char standart[100];
    snprintf(standart, sizeof(standart), "Введите количество элементов в массиве (не больше %d): ", 100); 
    char welcome[700] = "Тема: динамические массивы,список функции:\n"
        "-1)sos or help or h = инструкция для вас\n"
        "0)exit или 0 = выход\n"
        "1)choice=. В одномерном массиве выполнить сортировку четных элементов, расположенных после первого максимального, методом выбора.\n"
        "2)shell= В прямоугольной матрице выполнить сортировку столбцов по убыванию значения максимального элемента методом Шелла.\n";
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
        else if (strcmp(choice, "choice") == 0 || strcmp(choice, "1") == 0) {
            int method = method_filling();
            int size = size_1d(method);
            int *array = create_1d_array(size,method); 
            int *copy_for_backup = malloc(size * sizeof(int));
            if (copy_for_backup != NULL) {memcpy(copy_for_backup, array, size * sizeof(int));}
            else { return -1; }
            double time_first_choice = measure_time(method, sort_even_after_max, array, size);
            printf("Теперь с отсортированным массивом:\n");
			double time_second_choice = measure_time(method, sort_even_after_max, array, size);
            printf("Теперь сортируем задом_наперед исходный массив:\n");
            memcpy(array, copy_for_backup, size * sizeof(int));
			measure_time(method, sort_back_even_after_max, array, size);
            printf("Чтобы отсортировать уже обратный массив:\n");
			double time_back_choice = measure_time(method, sort_even_after_max, array, size);
            if (time_back_choice > time_second_choice) {
                printf("На отсортированном быстрее чем на обратном на %f секунд\n", time_first_choice - time_second_choice);
            }
            else{
                printf("На отсортированном медленнее чем на обратном на %f секунд\n", time_second_choice - time_first_choice );
            }
            printf("Теперь сортируем пузырьком исходный массив:\n");
            memcpy(array, copy_for_backup, size * sizeof(int));
			double time_bubble = measure_time(method, bubble_sort_even, array, size);
            if (time_first_choice > time_bubble) {
                printf("Пузырьком быстрее выбора на %f секунд\n", time_first_choice - time_bubble);
            }
            else{
                printf("Пузырьком медленнее выбора на %f секунд\n", time_bubble - time_first_choice );
            }
            if (array != NULL) {free(array);}
            if (copy_for_backup != NULL) {free(copy_for_backup);}
        }
        else if (strcmp(choice, "sos") == 0 || strcmp(choice, "help") == 0 || strcmp(choice, "h") == 0 || strcmp(choice, "-1") == 0) {
            printf("\n**************\n%s", welcome);
        }
        else if (strcmp(choice, "shell") == 0 || !strcmp(choice, "2")) {
            int method = method_filling();
            int rowscount;  
            int rows;      
            int** table = create_2d_array(method, &rows, &rowscount);
            if (table == NULL) {
                printf("Не удалось выделить память\n");
                return 1;
            }
            print_matrix(table, rows, rowscount);
            sortColByMax(table, rowscount, rows);
            //shellsort(table, rowscount, rows);
            print_matrix(table, rows, rowscount);
            free_matrix(table,rowscount);
        }
        else { printf("\nПопался:%s", choice); }
        
    }
}