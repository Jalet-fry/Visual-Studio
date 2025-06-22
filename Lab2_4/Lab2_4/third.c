#include "header.h"
void print_welcome_menu() {
    char  *defis = "-----------------------------------------------------------------------------------------------------\n";
    char welcome[] =
        "Тема: Списки,список функции:\n"
        "-1 || sos || help || h = инструкция для вас\n"
        " 0 || exit или 0 = выход\n"
        " 1 || stek =  Сортировка стека по убыванию лишь стеками\n"
        " 2 || queue = Общежитие в виде очереди.\n";
    printf("%s%sВызов функции: ", defis, welcome);
}
int main() {
    char  choice[30];
    while (1) {
        print_welcome_menu();
        fgets(choice, 20, stdin);
        choice[strlen(choice) - 1] = 0;
        if (!strcmp(choice, "exit") || !strcmp(choice, "0")) {
            printf("С вами была компания NOmicrosoft, До Новых Встреч!\n %s", choice);
            return 0;
        }
        else if (!strcmp(choice, "sos") || !strcmp(choice, "help") || !strcmp(choice, "h") || !strcmp(choice, "-1")) {
            print_welcome_menu();
        }
        else if (!strcmp(choice, "stek") || !strcmp(choice, "1")) {
            task1();
        }
        else if (!strcmp(choice, "queue") || !strcmp(choice, "2")) {
            menu_files();
        }
        else { printf("\nПопался:%s\n", choice); }
    }
}

