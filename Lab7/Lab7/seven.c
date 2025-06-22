#include "header.h" 
#include "task1.h" 
#include "task2.h" 
#include "task3.h" 
#include "task4.h"
#define Max 5

int main(int argc, char **argv){
    //    SetConsoleOutputCP(1251);
    //    SetConsoleCP(1251);
    if (argc < 2) {
        printf("Неверное количество аргументов: %d; %d\n", argc, __LINE__);
        return -1;
    }
    int task_num = my_atoi(argv[1]); 
    void (*operations[Max])(int, char**) = {NULL, task1, task2, task3, task4};
    task_func tasks[] = {NULL, task1, task2, task3};
    if (task_num >= 1 && task_num <= Max - 1) {
        //tasks[task_num](argc - 2, argv + 2);
        printf("----------------\nEverything will be al right\n");
        operations[task_num](argc - 2, argv + 2);
        printf("\nEverything will be al right\n--------------------");
    } else {
		printf("Неверный номер задачи\n");
		return -1;
    }
    return 0;
}
