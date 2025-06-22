#include "header.h"
void print_menu() {
    char  *defis = "-----------------------------------------------------------------------------------------------------\n";
    char welcome[] =
        "Тема: текстовые файлы,список функции:\n"
        "-1 || sos || help || h = инструкция для вас\n"
        " 0 || exit или 0 = выход\n"
        " 1 || find =  Определить максимальное число, записанное в файле.\n"
        " 2 || swap = Все максимальные числа файла заменить на минимальные, а все минимальные – на максимальные.\n";
    printf("%s%sВызов функции: ", defis, welcome);
}
int main(int argc, char *argv[]) {
    char *filename = argv[1], choice[30];
    while (1) {
        print_menu();
        fgets(choice, 20, stdin);
        choice[strlen(choice) - 1] = 0;
        if (!strcmp(choice, "exit") || !strcmp(choice, "0")) {
            printf("С вами была компания NOmicrosoft, До Новых Встреч!\n %s", choice);
            return 0;
        }
        else if (!strcmp(choice, "sos") || !strcmp(choice, "help") || !strcmp(choice, "h") || !strcmp(choice, "-1")) {
            print_menu();
        }
        else if (!strcmp(choice, "find") || !strcmp(choice, "1")) {
            task1(filename);
        }
        else if (!strcmp(choice, "swap") || !strcmp(choice, "2")) {
			task2(filename);
        }
        else { printf("\nПопался:%s", choice); }
    }
}

