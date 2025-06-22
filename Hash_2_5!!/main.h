#ifndef MAIN_H 
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#define TABLE_SIZE 100
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

typedef struct {
    HashtableEntry **entries;
} Hashtable;

Car *create_car();



int correct(char* text);
char* input_name(char* prompt);
Hashtable* create_hashtable();
unsigned int hash_function(char *key);
unsigned long hash_djb2(char *str);
Car* ht_get(Hashtable *hashtable, char *key);
void ht_set(Hashtable *hashtable, char *key, Car *car);
Car* ht_get(Hashtable *hashtable, char *key);
void ht_delete(Hashtable *hashtable);
Hashtable *fill_our_hash(char *filename);
void task1();
void menu_files();

#endif // HEADER_H
