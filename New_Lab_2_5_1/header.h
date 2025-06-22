#ifndef HEADER_H 
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
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

typedef struct tree{
    Car* cars;
    struct tree *left;
    struct tree *right;
} Tree;


int correct(char* c);
void check_number(int* number, int start, int end);

Tree *fill_our_tree(char *filename);
void deleteConfiguration_without_questions(Car* cars, int index_model, int confIndex);
void removeModelByIndex(Car **cars, int *carsCount, int index);
Car* read_1_car(FILE *fd);
char* read_binary_string(FILE* fd);
void print_One_configur(Car *cars, int index_model, int index_configur);
void printAllModels(Car *cars, int carsCount);
void printModelWithConfigurations(Car *cars, int index);
void printBasedOnNumber(Car *cars, int carsCount, int number);
Tree* get_next_tree_node(Tree* node, int dif);
// PRINTING
int nodePrint(Tree* node, int index); 
void treePrint(Tree* top);
FILE *save_fileOpener(void* filePath, void* mode);
void save_to_file(Tree *our_tree, char *file_path,char* mode, char flag_of_delete);


void write_car(FILE* saves, Car* cars);
void burn_tree(Tree **our_tree);
void god_save_the_tree(Tree* our_tree, FILE* file, char flag_of_delete);
void save_to_file(Tree *our_tree, char *file_path,char* mode, char flag_of_delete);
int* find_life_spans(Car *cars, int carsCount);



void find_min_life_cycle(Tree* our_tree, int *min_life_cycle);
int check_min_cycle(Tree* our_tree, int min_life_cycle);
void *find_all_min_model(Tree* our_tree, int min_life_cycle);
Tree *delete_min_root(Tree* root);
int delete_min_son(Tree* our_tree, Tree *son);
Tree* delete_model_with_min_lifecycle(Tree* our_tree);
void find_model_by_life_cycle_main(Tree* our_tree);
void sort_in_tree_by_bodytypes(Tree *our_tree);


Car *create_car();
Tree *add_Car_to_Tree(Tree *our_tree, Car *new_car);
#endif // HEADER_H
