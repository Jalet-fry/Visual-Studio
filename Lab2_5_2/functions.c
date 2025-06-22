#include "main.h"
int correct(char* text) {
    char input[100];
    int valid = 0;
    int num;
    char* endptr; 
    valid = 0;
    while (!valid) {
        printf("%s", text);
        fgets(input, sizeof(input) / sizeof(char), stdin);
        if (input[0] != '\n') {
            num = (int)strtol(input, &endptr, 10);
            if (*endptr != '\n' && *endptr != '\0') {
                printf("Это не число.Попробуйте еще раз.\n");
            }
            else {
                valid = 1;
                printf("Вы ввели число: %d\n", num);
            }
        }
    }
    return num;
}

char* input_name(char* prompt) {
    char input[100];
    char *returning_text;
    printf("%s", prompt);
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return NULL; 
    }
    input[strcspn(input, "\n")] = '\0';
    returning_text = malloc(strlen(input) + 1);
    if (returning_text == NULL) {
        return NULL; 
    }
    strcpy(returning_text, input);
    return returning_text; 
}

void delete_conf_without_questions(Car* cars, int index_model, int confIndex) {
    free(cars[index_model].configurations[confIndex].body_type);
    for (int i = confIndex; i < cars[index_model].configurations_count - 1; i++) {
        cars[index_model].configurations[i] = cars[index_model].configurations[i + 1];
    }
    cars[index_model].configurations_count--;
    if (cars[index_model].configurations_count == 0) {
        free(cars[index_model].configurations);
        cars[index_model].configurations = NULL; 
    } else {
        Configuration *temp = realloc(cars[index_model].configurations, cars[index_model].configurations_count * sizeof(Configuration));
        if (!temp) {
            printf("Ошибка выделения памяти при уменьшении массива конфигураций.\n");
        } else {
            cars[index_model].configurations = temp;
        }
    }
}

void remove_model_by_index(Car **cars, int carsCount, int index) {
    if (index < 0 || index >= carsCount && carsCount != 0) {
        printf("Неверный индекс, что-то вы и без беса попутали\n");
        return;
    }
    for (int x = 0; x < (*cars)->configurations_count; x++) {
        delete_conf_without_questions(*cars, index, 0);
    }
    free((*cars)->model);
        if (index < (carsCount) - 1) {
            memmove(*cars + index, *cars + index + 1, (carsCount - index - 1) * sizeof(Car));
        }
        else if(index == 0 && (carsCount) == 1){
            free(*cars);
            *cars = NULL;
        }
    (carsCount)--; 
    if (*cars != NULL) {
        *cars = realloc(*cars, (carsCount) * sizeof(Car));
    }
}


Car* read_1_car(FILE *fd) {
    Car* cars = malloc(sizeof(Car));
    cars->model = read_binary_string(fd);
	fread(&cars->configurations_count, sizeof(cars->configurations_count), 1, fd);
	cars->configurations = malloc(cars->configurations_count * sizeof(Configuration));
    for (int j = 0; j < cars->configurations_count; j++) {
        Configuration* conf = cars->configurations + j;
        conf->body_type = read_binary_string(fd);
        fread(&conf->engine_volume, sizeof(conf->engine_volume), 1, fd);
        fread(&conf->production_start_year, sizeof(conf->production_start_year), 1, fd);
        fread(&conf->production_end_year, sizeof(conf->production_end_year), 1, fd);
    }
    return cars;
}
char* read_binary_string(FILE* fd) {
    char buffer[256], *result = NULL;
    int size_buffer = 0;
    while (fread(buffer + size_buffer, sizeof(buffer[0]), 1, fd) != 0) {
        if (!buffer[size_buffer++]) {
            result = malloc(size_buffer);
            memcpy(result, buffer, size_buffer);
            break;
        }
    }
    return result;
}

void print_One_configur(Car *cars, int index_model, int index_configur) {
        printf("  %d)\tТип кузова: %s, Объем двигателя: %d, Год начала выпуска: %d, Год окончания выпуска: %d\n",
            index_configur,
            cars[index_model].configurations[index_configur].body_type,
            cars[index_model].configurations[index_configur].engine_volume,
            cars[index_model].configurations[index_configur].production_start_year,
            cars[index_model].configurations[index_configur].production_end_year);
}
void print_all_models(Car *cars, int carsCount) {
    for (int i = 0; i < carsCount; i++) {
        printf("%d)\tМодель: %s\n", i, cars->model);
    }
}

void print_model_with_configurations(Car *cars, int index) {
    printf("%d)\tМодель: %s\n", index, cars[0].model);
    for (int j = 0; j < cars[0].configurations_count; j++) {
        printf("  %d.%d)\tТип кузова: %s, Объем двигателя: %d, Год начала выпуска: %d, Год окончания выпуска: %d\n",
               index, j,
               cars[0].configurations[j].body_type,
               cars[0].configurations[j].engine_volume,
               cars[0].configurations[j].production_start_year,
               cars[0].configurations[j].production_end_year);
    }
}

void print_based_on_number(Car *cars, int carsCount, int number) {
    if (!number) {
        print_all_models(cars, carsCount);
    } else {
        for (int i = 0; i < carsCount; i++) {
            print_model_with_configurations(cars, i);
        }
    }
}


FILE *save_fileOpener(char* filePath, char* mode) {
	FILE* file = fopen(filePath, mode);
    if (!file) {
        perror("ERROR:");
        return NULL;
    }
    return file;
}
void write_car(FILE* saves, Car* cars) {
    fwrite(cars->model, strlen(cars->model) + 1, 1, saves);
    fwrite(&cars->configurations_count, sizeof(cars->configurations_count), 1, saves);
    for (int j = 0; j < cars->configurations_count; j++) {
        Configuration* conf = &cars->configurations[j];
        fwrite(conf->body_type, strlen(conf->body_type) + 1, 1, saves);
        fwrite(&conf->engine_volume, sizeof(conf->engine_volume), 1, saves);
        fwrite(&conf->production_start_year, sizeof(conf->production_start_year), 1, saves);
        fwrite(&conf->production_end_year, sizeof(conf->production_end_year), 1, saves);
    }
}

Car *create_car() {
    Car* temp = malloc(sizeof(Car));
    if (temp == NULL) {
        printf("Ошибка выделения памяти.\n");
        return NULL;
    }
    printf("Введите название модели: ");
    temp->model = malloc(20 * sizeof(char));
    fgets(temp->model, 20, stdin);
    temp->model[strcspn(temp->model, "\n")] = 0;
    temp->configurations_count = correct("Введите число конфигураций: ");
    temp->configurations_count = (temp->configurations_count > 0) ? temp->configurations_count : 1;
    temp->configurations = malloc(temp->configurations_count * sizeof(Configuration));
    for (int j = 0; j < temp->configurations_count; j++) {
        printf("Введите тип кузова: ");
        temp->configurations[j].body_type = malloc(15 * sizeof(char));
        fgets(temp->configurations[j].body_type, 15, stdin);
        temp->configurations[j].body_type[strcspn(temp->configurations[j].body_type, "\n")] = 0;
        temp->configurations[j].engine_volume = correct("Введите объем двигателя: ");
        temp->configurations[j].production_start_year = correct("Введите год начала выпуска: ");
        temp->configurations[j].production_end_year = correct("Введите год окончания выпуска: ");
    }
    fflush(stdin);
    return temp;
}


unsigned long hash_function(const char* str) {
    unsigned long hash = 0;
    int c, position = 0;
    while (c = *str++) {
        ++position;
        
        hash = c*position + (hash << 6) * (position << 16) + (c % position) * (position % c);
    }

    return hash;
}
unsigned long hash_djb2(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash;
}
Car** ht_get_all(Hashtable* hashtable, char* key) {
    unsigned int slot = hash_function(key) % hashtable->size;
    Car** found_cars = NULL;
    int found_count = 0;
    HashtableEntry* entry = hashtable->entries[slot];
    while (entry != NULL) {
        if (strcmp(entry->key_model, key) == 0) {
            
            found_cars = realloc(found_cars, (found_count + 1) * sizeof(Car*));
            found_cars[found_count] = entry->car;
            found_count++;
        }
        entry = entry->next;
    }
    for (int i = 0; i < found_count; i++) {
        print_model_with_configurations(found_cars[i], i);
    }

    return found_cars;
}

Car* ht_get(Hashtable *hashtable, char *key) {
    unsigned int slot = hash_function(key) % hashtable->size;
    HashtableEntry *entry = hashtable->entries[slot];
    while (entry != NULL) {
        if (strcmp(entry->key_model, key) == 0) {
            return entry->car;
        }
        entry = entry->next;
    }
    return NULL;
}
Hashtable* ht_delete(Hashtable *hashtable) {
    for (int i = 0; i < hashtable->size; ++i) {
        HashtableEntry *entry = hashtable->entries[i];
        while (entry != NULL) {
            HashtableEntry *temp = entry;
            entry = entry->next;
            free_hash_element(temp, i);
            hashtable->count--;
        }
    }
    free(hashtable->entries);
    free(hashtable);
}
void print_hashtable(Hashtable *hashtable) {
    if (hashtable) {
        printf("size = %d, count = %d\n", hashtable->size, hashtable->count);
        for (int i = 0; i < hashtable->size; i++) {
            HashtableEntry* entry = hashtable->entries[i];
            while (entry != NULL) {
                print_model_with_configurations(entry->car, i);
                entry = entry->next;
            }
        }
    }
    else {
        printf("Actual hashtable is empty");
    }
}
int compare_body_type(const void *a, const void *b) {
    return strcmp(((Configuration *)a)->body_type, ((Configuration *)b)->body_type);
}

int compareCounts(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
int findBodyTypeIndex(char **bodyTypes, int totalTypes, char *bodyType) {
    for (int k = 0; k < totalTypes; k++) {
        if (strcmp(bodyType, bodyTypes[k]) == 0) {
            return k;
        }
    }
    return -1;
}

void addBodyType(char ***bodyTypes, int **counts, int *totalTypes, char *bodyType) {
    (*bodyTypes)[*totalTypes] = bodyType;
    (*counts)[*totalTypes] = 1;
    (*totalTypes)++;
}

void sortBodyTypes(char **bodyTypes, int *counts, int totalTypes) {
    for (int i = 0; i < totalTypes - 1; i++) {
        for (int j = 0; j < totalTypes - i - 1; j++) {
            if (counts[j] < counts[j + 1]) {
                
                int tempCount = counts[j];
                counts[j] = counts[j + 1];
                counts[j + 1] = tempCount;
                char *tempType = bodyTypes[j];
                bodyTypes[j] = bodyTypes[j + 1];
                bodyTypes[j + 1] = tempType;
            }
        }
    }
}

void printSortedBodyTypes(char **bodyTypes, int *counts, int totalTypes) {
    printf("\n[\t");
    for (int i = 0; i < totalTypes; i++) {
        printf("\nКузов %s: число %d\n", bodyTypes[i], counts[i]);
    }
    printf("\n]");
}

void list_by_bodytype(Hashtable* hashtable) {
	char **bodyTypes = malloc(sizeof(char *) * 100);
    int *counts = calloc(100, sizeof(int));
    int totalTypes = 0;

    for (int i = 0; i < hashtable->size; i++) {
        if (hashtable->entries[i]) {
            for (int j = 0; j < hashtable->entries[i]->car->configurations_count; j++) {
                int index = findBodyTypeIndex(bodyTypes, totalTypes, hashtable->entries[i]->car->configurations[j].body_type);
                if (index != -1) {
                    counts[index]++;
                }
                else {
                    addBodyType(&bodyTypes, &counts, &totalTypes, hashtable->entries[i]->car->configurations[j].body_type);
                }
            }
        }
    }
    sortBodyTypes(bodyTypes, counts, totalTypes);
    printSortedBodyTypes(bodyTypes, counts, totalTypes);
    free(bodyTypes);
    free(counts);
}
Hashtable* create_hashtable(int size) {
    Hashtable *hashtable = malloc(sizeof(Hashtable));
    hashtable->size = size;
    hashtable->count = 0;
    hashtable->entries = malloc(sizeof(HashtableEntry*) * hashtable->size);

    for (int i = 0; i < hashtable->size; i++) {
        hashtable->entries[i] = NULL;
    }

    return hashtable;
}

void ht_resize(Hashtable **hashtable) {
    if ((double)(*hashtable)->count / (*hashtable)->size < MAX_LOAD_FACTOR) {
        return;
    }
    int new_size = (*hashtable)->size * 2;
    Hashtable *new_hashtable = create_hashtable(new_size);
    new_hashtable->count = (*hashtable)->count; 
    for (int i = 0; i < (*hashtable)->size; i++) {
        HashtableEntry *entry = (*hashtable)->entries[i];
        while (entry != NULL) {
            HashtableEntry *next_entry = entry->next; 
            
            unsigned int index = hash_function(entry->key_model) % new_hashtable->size;
            entry->next = new_hashtable->entries[index];
            new_hashtable->entries[index] = entry;
            entry = next_entry; 
        }
    }
    free((*hashtable)->entries);
    free(*hashtable);
    *hashtable = new_hashtable;
}
void ht_set(Hashtable **hashtable, char *key, Car *car) {
    ht_resize(hashtable);
    unsigned int index = hash_function(key) % (*hashtable)->size;
    printf("%s hash = %llu, new = %d\n", car->model, hash_function(key), index);
    HashtableEntry *entry = malloc(sizeof(HashtableEntry));
    entry->car = car;
    entry->key_model = malloc(strlen(key) + 1);
    memcpy(entry->key_model, key, strlen(key) + 1);
    entry->next = (*hashtable)->entries[index];
    (*hashtable)->entries[index] = entry;
    (*hashtable)->count++;
}

Hashtable *fill_our_hash(char *filename) {
    FILE *open_bin_file = fopen(filename, "rb");
    int size_cars;
    fread(&size_cars, sizeof(size_cars), 1, open_bin_file);
    Hashtable *hashtable = create_hashtable(INITIAL_TABLE_SIZE);
    Car* new_car = NULL;

    for (int i = 0; i < size_cars; i++) {
        new_car = read_1_car(open_bin_file);
        ht_set(&hashtable, new_car->model, new_car);
    }
    fclose(open_bin_file);
    return hashtable;
}


int find_life_spans(Car *car) {
	int minStartYear = INT_MAX;
	int maxEndYear = INT_MIN;
    for (int j = 0; j < car->configurations_count; j++) {
        if (car->configurations[j].production_start_year < minStartYear) {
            minStartYear = car->configurations[j].production_start_year;
        }
        if (car->configurations[j].production_end_year > maxEndYear) {
            maxEndYear = car->configurations[j].production_end_year;
        }
    }
	return maxEndYear - minStartYear;

}

int find_min_life_span(Hashtable* hashtable) {
    int min_span = INT_MAX, car_span;
    for (int i = 0; i < hashtable->size; i++) {
        if (hashtable->entries[i]) {
            car_span = find_life_spans(hashtable->entries[i]->car);
            if (car_span < min_span) {
                min_span = car_span;
            }

        }
    }
    return min_span;
    
}
void free_hash_element(HashtableEntry* table, int index) {
    remove_model_by_index(&table->car, 1, 0);
    free(table->key_model);
    free(table);
    table = NULL;
}
void delete_by_min_life_cycle(Hashtable* hashtable) {
    int min_span = find_min_life_span(hashtable);
    for (int i = 0; i < hashtable->size; i++) {
        HashtableEntry *entry = hashtable->entries[i], *prev_entry = hashtable->entries[i];
        while (entry != NULL) {
            if (find_life_spans(entry->car) == min_span) {
                if (entry == hashtable->entries[i]) {
                    hashtable->entries[i] = entry->next;
                    prev_entry = entry->next;
                } else {
                    prev_entry->next = entry->next;
                }
                free_hash_element(entry, i);
                hashtable->count--;
                entry = (prev_entry) ? prev_entry->next : NULL;
            } else {
                prev_entry = entry;
                entry = entry->next;
            }
        }
    }
}


void delete_by_your_name(Hashtable* hashtable, int index, char* your_name) {
	HashtableEntry *entry = hashtable->entries[index], *prev_entry = hashtable->entries[index];
    while (entry != NULL) {
        if (strcmp(your_name, entry->key_model) == 0) {
            if (entry == hashtable->entries[index]) {
                hashtable->entries[index] = entry->next;
                prev_entry = entry->next;
            }
            else {
                prev_entry->next = entry->next;
            }
            free_hash_element(entry, index);
            hashtable->count--;
            entry = (prev_entry) ? prev_entry->next : NULL;
        }
        else {
            prev_entry = entry;
            entry = entry->next;
        }
    }
}

//void delete_dublicate_your_name(Hashtable* hashtable, int index, char* your_name, int index_dublicate) {
//	HashtableEntry *entry = hashtable->entries[index], *prev_entry = hashtable->entries[index];
//    int current_index = -1;
//    while (entry != NULL) {
//        if (strcmp(your_name, entry->key_model) == 0) {
//			current_index++;
//            if (entry == hashtable->entries[index]) {
//                hashtable->entries[index] = entry->next;
//                prev_entry = entry->next;
//            }
//            else {
//                prev_entry->next = entry->next;
//            }
//            if (current_index == index_dublicate) {
//                prev_entry->next = entry->next;
//                free_hash_element(entry, index);
//				hashtable->count--;
//            }
//            entry = (prev_entry) ? prev_entry->next : NULL;
//        }
//        else {
//            prev_entry = entry;
//            entry = entry->next;
//        }
//    }
//}
void delete_dublicate_your_name(Hashtable* hashtable, int index, char* your_name, int index_dublicate) {
    HashtableEntry *entry = hashtable->entries[index];
    HashtableEntry *prev_entry = NULL;
    int current_index = -1;

    while (entry != NULL) {
        if (strcmp(your_name, entry->key_model) == 0) {
            current_index++;
            if (current_index == index_dublicate) {
                if (prev_entry == NULL) {
                    // Удаляем первый элемент в списке
                    hashtable->entries[index] = entry->next;
                } else {
                    // Удаляем элемент, не первый в списке
                    prev_entry->next = entry->next;
                }
                HashtableEntry *temp = entry;
                entry = entry->next;
                free_hash_element(temp, index);
                hashtable->count--;
            } else {
                prev_entry = entry;
                entry = entry->next;
            }
        } else {
            prev_entry = entry;
            entry = entry->next;
        }
    }
}

void delete_by_your_name_main(Hashtable* hashtable) {
    char* your_name = input_name("Write your deleting car:");
    int index = hash_function(your_name) % hashtable->size;
	Car** found_cars = ht_get_all(hashtable, your_name);
	free(found_cars);
    int index_dublicate = correct("Enter the index of deleting dublicate:");
    delete_dublicate_your_name(hashtable, index, your_name, index_dublicate);
    //delete_by_your_name(hashtable, index, your_name);
}


void save_to_file(Hashtable* hashtable, char *file_name) {
    FILE* fd = fopen(file_name, "wb");
    fwrite(&hashtable->count, sizeof(hashtable->count), 1, fd);
    for (int i = 0; i < hashtable->size; i++) {
        HashtableEntry *entry = hashtable->entries[i];
        while (entry != NULL) {
            write_car(fd, entry->car);
            entry = entry->next;
        }
    }
    fclose(fd);
}

Hashtable* add_car(Hashtable* hashtable) {
            Car *new_car = create_car();
            ht_set(&hashtable, new_car->model, new_car);
            new_car = NULL;
            return hashtable;
}
void find_all_cars(Hashtable *hashtable) {
            char* lost_car = input_name("What is your car:");
			Car** found_cars = ht_get_all(hashtable, lost_car);
			free(found_cars);
			found_cars = NULL;
}

