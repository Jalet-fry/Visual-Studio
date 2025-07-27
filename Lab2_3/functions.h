#ifndef FUNCTIONS_H 
#define FUNCTIONS_H
#include "header.h"
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
#endif 
