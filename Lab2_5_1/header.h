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


Car *create_car();
int correct(char* c);
void check_number(int* number, int start, int end);

Tree *fill_our_tree(char *filename);
void delete_configuration_without_questions(Car* cars, int index_model, int confIndex);
void remove_model_by_index(Car **cars, int carsCount, int index);
Car* read_1_car(FILE *fd);
char* read_binary_string(FILE* fd);
void print_One_configur(Car *cars, int index_model, int index_configur);
void print_all_models(Car *cars, int carsCount);
void print_model_with_configurations(Car *cars, int index, int level);
void print_based_on_number(Car *cars, int carsCount, int number);
Tree* get_next_tree_node(Tree* node, int dif);
// PRINTING
void print_level(int level);
int node_printing(Tree* node, int index, int level); 
void tree_printing(Tree* top);
int node_print_beautiful(Tree* node, int index, int level, int method);
void tree_print_beautiful(Tree* top, int method);
int node_print_for_life_cycle(Tree* node, int index, int level, char* sides, int method);
void tree_print_for_model_life_cycle(Tree* top, int method);
FILE *save_fileOpener(void* filePath, void* mode);
void save_to_file(Tree *our_tree, char *file_path,char* mode, char flag_of_delete);


void write_car(FILE* saves, Car* cars);
void burn_tree(Tree **our_tree);
void god_save_the_tree(Tree* our_tree, FILE* file, char flag_of_delete);
void save_to_file(Tree *our_tree, char *file_path,char* mode, char flag_of_delete);
int* find_life_spans(Car *cars, int carsCount);



void find_min_life_cycle(Tree* our_tree, int *min_life_cycle);
void find_models_with_cycle_threshold(Tree* our_tree, int life_cycle_threshold);
int check_min_cycle(Tree* our_tree, int min_life_cycle);
Tree *delete_min_root(Tree* root);
int delete_min_son(Tree* our_tree, Tree *son);
Tree* delete_model_with_min_lifecycle(Tree* our_tree);
void find_model_by_life_cycle_main(Tree* our_tree);
void find_model_by_life_cycle_configur_main(Tree* our_tree);
void find_models_with_your_conf_cycle(Tree *our_tree, int min_life_cycle_conf);
void sort_in_tree_by_bodytypes(Tree *our_tree);


Tree *Bad_add_Car_to_Tree(Tree *our_tree, Car *new_car);
Tree* delete_by_your_index_main(Tree* old_tree);
Tree* delete_by_your_index(Tree* root, int indexToDelete, int* currentIndex, Tree* parent);
//void delete_by_your_index(Tree* root, int indexToDelete);



Tree* delete_node_by_index(Tree* root, int index);
Tree *free_tree(Tree* user_tree);
Tree *add_Car_to_Tree(Tree *our_tree, Car *new_car);
int calculate_life_cycle_model(Car *car);
int compare_life_cycle_model(Car *car, int life_cycle);


int count_children(Tree* node);
Tree* balance(Tree* top);
#endif // HEADER_H
