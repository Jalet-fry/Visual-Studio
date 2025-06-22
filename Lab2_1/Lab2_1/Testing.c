#include "header.h"
void print_menu(char method) {
    char welcome[] =
        "Тема: бинарные файлы,список функции:\n"
        "-2 || in = замена способа ввода данных\n"
        "-1 || sos || help || h = инструкция для вас\n"
        " 0 || exit или 0 = выход\n"
        " 1 || sum =  Вычислить максимальную длину непрерывной последовательности элементов, сумма которых не превышает заданное значение\n"
        " 2 || zero =  Занулить элементы, меньшие предыдущего\n"
        " 3 || sort = Отсортировать элементы по возрастанию относительно центра.\n";
    char *machine = "автоматическое\n", *vvod = "ручное\n", *standart = "Текущее состояние ввода:", *defis = "-----------------------------------------------------------------------------------------------------\n";
    printf("%s%s%s%sВызов функции: ", defis, standart, method == 2 ? machine : vvod, welcome);
}
int main(int argc, char *argv[]) {
    char *filename = argv[1], method = 2, choice[30];
    while (1) {
        print_menu(method);
        fgets(choice, 20, stdin);
        choice[strlen(choice) - 1] = 0;
        if (!strcmp(choice, "exit") || !strcmp(choice, "0")) {
            printf("С вами была компания NOmicrosoft, До Новых Встреч!\n %s", choice);
            return 0;
        }
        else if (!strcmp(choice, "in") || !strcmp(choice, "-2")) {
            method = 3 - method;
        }
        else if (!strcmp(choice, "sum") || !strcmp(choice, "1")) {
            task1(filename, method);
        }
        else if (!strcmp(choice, "sos") || !strcmp(choice, "help") || !strcmp(choice, "h") || !strcmp(choice, "-1")) {
            print_menu(method);
        }
        else if (!strcmp(choice, "zero") || !strcmp(choice, "2")) {
            task2(filename, method);
        }
        else if (!strcmp(choice, "sort") || !strcmp(choice, "3")) {
            task3(filename, method);
        }
        else { printf("\nПопался:%s", choice); }
    }
}

