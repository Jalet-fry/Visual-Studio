#ifndef HEADER_H 
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
//#undef NDEBUG
typedef struct {
    char* body_type;
    int engine_volume;
    int production_start_year;
    int production_end_year;
} Configuration;

typedef struct {
    char* model;
    int configurations_count;
    Configuration *configurations;
} Car;
typedef enum {
    Chevrolet_Impala = 1,
    DeLorean_DMC_12 = 2,
    Aston_Martin_DB5 = 3,
    // Добавьте дополнительные модели здесь, если необходимо
} CarModel;

typedef struct {
    unsigned int changes_allowed : 1;
} Flag;

void printBits(unsigned char num, int size);
void task1();
void menu_file();
// Функция для сравнения типов кузова
int compareBodyType(const void *a, const void *b);
// Функция для сравнения количества вхождений
int compareCounts(const void *a, const void *b);
// Функция для поиска типа кузова в массиве
int findBodyTypeIndex(char **bodyTypes, int totalTypes, char *bodyType);
// Функция для добавления нового типа кузова в массив
void addBodyType(char ***bodyTypes, int **counts, int *totalTypes, char *bodyType);
// Функция для сортировки типов кузова по количеству вхождений
void sortBodyTypes(char **bodyTypes, int *counts, int totalTypes);
// Функция для вывода отсортированных типов кузова
void printSortedBodyTypes(char **bodyTypes, int *counts, int totalTypes);
// Основная функция для сортировки и печати типов кузова
void sortAndPrintBodyTypes(Car *cars, int carsCount);
int findMinLifeSpan(Car *cars, int carsCount);
void removeModelsByLifeSpan(Car **cars, int *carsCount);
int* find_life_spans(Car *cars, int carsCount);
void kill_model(Car **cars, int *carsCount);

//FUNCTIONS_H
void promptForSave(Car* cars, int size_cars, char* file_user);
void saver(Car* cars, int count_structure, char* filename);
char* read_binary_string(FILE* fd);
Car* reader(int* size_cars, char* filename);

void change_structure(Car** cars, int* size_cars, int* exit_flag);
void menu_structure(Car** cars, int* size_cars, char* file_user, int* exit_flag);

int correct(char* c);
void check_number(int* number, int start, int end);

void addModel(Car** cars, int* carsCount, int* exit_flag);
void removeModelByIndex(Car **cars, int *carsCount, int index);
void editModel(Car** cars, int* carsCount, int* exit_flag, int last);

void addConfiguration(Car *cars, int index_model);
void deleteConfiguration(Car *cars, int index_model);
void deleteConfiguration_without_questions(Car* cars, int index_model, int index_conf);
void editConfiguration(Car *cars, int index_model);

void editBodyType(Car* cars, int index_model, int index_configuration);
void editEngineVolume(Car* cars, int index_model, int index_configuration);
void editProductionStartYear(Car* cars, int index_model, int index_configuration);
void editProductionEndYear(Car* cars, int index_model, int index_configuration);

void printAllModels(Car *cars, int carsCount);
void print_One_configur(Car* cars, int index_model, int index_configur);
void printModelWithConfigurations(Car *cars, int index);
void printBasedOnNumber(Car *cars, int carsCount, int number);
//QUEUE_H
#endif // HEADER_H
