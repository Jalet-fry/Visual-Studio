#ifndef MAIN_H 
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#define INITIAL_TABLE_SIZE 27
#define MAX_LOAD_FACTOR 0.7
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

typedef struct HashtableEntry {
    char *key_model;
    Car *car;
    struct HashtableEntry *next; // Для разрешения коллизий методом цепочек
} HashtableEntry;

//typedef struct {
//    HashtableEntry **entries;
//} Hashtable;

typedef struct {
    HashtableEntry **entries;
    int size;
    int count;
} Hashtable;

int correct(char* text);
char* input_name(char* prompt);
void delete_conf_without_questions(Car* cars, int index_model, int confIndex);
void remove_model_by_index(Car **cars, int carsCount, int index);
Car* read_1_car(FILE *fd);
char* read_binary_string(FILE* fd);
void print_One_configur(Car *cars, int index_model, int index_configur);
void print_all_models(Car *cars, int carsCount);
void print_model_with_configurations(Car *cars, int index);
void print_based_on_number(Car *cars, int carsCount, int number);
FILE *save_fileOpener(char* filePath, char* mode);
void write_car(FILE* saves, Car* cars);
Car *create_car();
unsigned long hash_djb2(char *str);
Car* ht_get(Hashtable *hashtable, char *key);
Hashtable *ht_delete(Hashtable *hashtable);
void print_hashtable(Hashtable *hashtable);
int compare_body_type(const void *a, const void *b);
int compareCounts(const void *a, const void *b);
int findBodyTypeIndex(char **bodyTypes, int totalTypes, char *bodyType);
void addBodyType(char ***bodyTypes, int **counts, int *totalTypes, char *bodyType);
void sortBodyTypes(char **bodyTypes, int *counts, int totalTypes);
void printSortedBodyTypes(char **bodyTypes, int *counts, int totalTypes);
void list_by_bodytype(Hashtable* hashtable);
unsigned long hash_function(char* key);
Hashtable* create_hashtable(int size);
void ht_resize(Hashtable **hashtable);
void ht_set(Hashtable **hashtable, char *key, Car *car);
Hashtable *fill_our_hash(char *filename);
int find_life_spans(Car *car, int compare_life_span);
int find_min_life_span(Hashtable* hashtable);
void free_hash_element(HashtableEntry* table, int index);
void delete_by_min_life_cycle(Hashtable* hashtable);
void save_to_file(Hashtable* hashtable, char *file_name);
Car** ht_get_all(Hashtable* hashtable, char* key);


void delete_by_your_name(Hashtable* hashtable, int index, char* your_name);
void delete_by_your_name_main(Hashtable* hashtable);
Hashtable* add_car(Hashtable* hashtable);
void find_all_cars(Hashtable *hashtable);
void delete_dublicate_your_name(Hashtable* hashtable, int index, char* your_name, int index_dublicate);

#endif

