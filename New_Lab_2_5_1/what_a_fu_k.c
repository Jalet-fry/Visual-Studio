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

typedef struct Tree{
    Car* cars;
    struct Tree *left;
    struct Tree *right;
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
void nodePrint(Tree* node); 
void treePrint(Tree* top);
FILE *save_fileOpener(void* filePath, void* mode);
int correct(char* c) {
    char input[100];
    int valid = 0;
    int num;
    char* endptr; 
    valid = 0;
    while (!valid) {
        printf("%s\n", c);
        fgets(input, sizeof(input) / sizeof(char), stdin);
        if (input[0] == '\n') {
            return -1;
        }
        num = (int)strtol(input, &endptr, 10); 
        if (*endptr != '\n' && *endptr != '\0') { 
            printf("Это не число.Попробуйте еще раз.\n");
        }
        else {
            valid = 1;
            printf("Вы ввели число: %d\n", num);
        }
    }
    return num;
}
void check_number(int* number, int start, int end) {
    if (*number < start || *number > end) {
        *number = end;
        printf("Let it be  %d\n", *number);
    }
}

Tree *add_Car_to_Tree(Tree *our_tree, Car *new_car){
    Tree *new_tree = (Tree*)malloc(sizeof(Tree)), *current = our_tree;
    new_tree->cars = new_car;
    new_tree->left = new_tree->right = NULL;
    if (!our_tree) {
        our_tree = new_tree;
        new_tree = NULL;
        return our_tree;
    }
    int difference = strcmp(new_car->model, our_tree->cars->model);
    while (get_next_tree_node(current, difference) != NULL && difference != 0) {
        current = get_next_tree_node(current, difference);
        difference = strcmp(new_car->model, current->cars->model);
    }
    if (difference == 0) {
        printf("\n\tIncorrect name.\n");
        return NULL;
    }

    if (difference > 0) {
        current->right = new_tree;
    } else if (difference < 0) {
        current->left = new_tree;
    }
    return our_tree;
}
Tree *fill_our_tree(char *filename) {
    FILE *open_bin_file = save_fileOpener(filename, "rb");
    int size_cars;
    fread(&size_cars, sizeof(size_cars), 1, open_bin_file);
    Tree *our_tree = (Tree*)malloc(sizeof(Tree));
    Car* new_car = NULL;

    for (int i = 0; i < size_cars; i++) {
		new_car = read_1_car(open_bin_file);
        our_tree = add_Car_to_Tree(our_tree, new_car);
    }
    return our_tree;

}
void deleteConfiguration_without_questions(Car* cars, int index_model, int confIndex) {
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

void removeModelByIndex(Car **cars, int *carsCount, int index) {
    if (index < 0 || index >= *carsCount && *carsCount != 0) {
        printf("Неверный индекс, что-то вы и без беса попутали\n");
        return;
    }
    for (int x = 0; x < (*cars)[index].configurations_count; x++) {
        deleteConfiguration_without_questions(*cars, index, 0);
    }
    free((*cars)[index].model);
        if (index < (*carsCount) - 1) {
            memmove(*cars + index, *cars + index + 1, (*carsCount - index - 1) * sizeof(Car));
        }
        else if(index == 0 && (*carsCount) == 1){
            free(*cars);
            *cars = NULL;
        }
    (*carsCount)--; 
    printf("New carsCount = %d\n", *carsCount);
    if (*cars != NULL) {
        *cars = realloc(*cars, (*carsCount) * sizeof(Car));
    }
}


Car* read_1_car(FILE *fd) {
    Car* cars = malloc(sizeof(Car));
    cars[0].model = read_binary_string(fd);
	fread(&cars[0].configurations_count, sizeof(cars[0].configurations_count), 1, fd);
	cars[0].configurations = malloc(cars[0].configurations_count * sizeof(Configuration));
    for (int j = 0; j < cars[0].configurations_count; j++) {
        Configuration* conf = cars[0].configurations + j;
        conf->body_type = read_binary_string(fd);
        fread(&conf->engine_volume, sizeof(conf->engine_volume), 1, fd);
        fread(&conf->production_start_year, sizeof(conf->production_start_year), 1, fd);
        fread(&conf->production_end_year, sizeof(conf->production_end_year), 1, fd);
    }
    fclose(fd);
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
void printAllModels(Car *cars, int carsCount) {
    for (int i = 0; i < carsCount; i++) {
        printf("%d)\tМодель: %s\n", i, cars[i].model);
    }
}

void printModelWithConfigurations(Car *cars, int index) {
    printf("%d)\tМодель: %s\n", index, cars[index].model);
    for (int j = 0; j < cars[index].configurations_count; j++) {
        printf("  %d.%d)\tТип кузова: %s, Объем двигателя: %d, Год начала выпуска: %d, Год окончания выпуска: %d\n",
               index, j,
               cars[index].configurations[j].body_type,
               cars[index].configurations[j].engine_volume,
               cars[index].configurations[j].production_start_year,
               cars[index].configurations[j].production_end_year);
    }
}

void printBasedOnNumber(Car *cars, int carsCount, int number) {
    if (!number) {
        printAllModels(cars, carsCount);
    } else {
        for (int i = 0; i < carsCount; i++) {
            printModelWithConfigurations(cars, i);
        }
    }
}

Tree* get_next_tree_node(Tree* node, int dif) {
    if (node == NULL) return NULL;
    if(dif > 0) return node->right;
    return node->left;
}
// PRINTING
void nodePrint(Tree* node) { 
    if (node->left != NULL) nodePrint(node->left);
    
    printModelWithConfigurations(node->cars, 0);
    if (node->right != NULL) nodePrint(node->right);
}

void treePrint(Tree* top) {
    if (top == NULL) {
        printf("\n\tCurrent model tree is free.\n");
        return;
    }
    printf("\n\tOur tree:");
    nodePrint(top);
    printf("\n");
}

FILE *save_fileOpener(void* filePath, void* mode) {
	FILE* file = fopen(filePath, mode);
    if (!file) {
        perror("ERROR:");
        return NULL;
    }
    return file;
}


void main() {
	char file_default[] = "C:\\Files_for_testing\\queue.bin", file_user[] = "C:\\Files_for_testing\\user_tree.bin", choice;
	Tree *user_tree = fill_our_tree(file_user);
	while (1) {
		choice = correct("\n\tMenu:\n\t1) Create new model\n\t2) Find model by name\n\t3) Get year list\n\t4) Delete by frame type\n\t5) Print current model list\n\t6) Save current tree\n\t7) delete by ind\n\t8) Exit\n\tSelect the option:");
		switch (choice) {

			break;
		default:
			printf("\n\nIncorrect input");
			break;
		}
	}
}
