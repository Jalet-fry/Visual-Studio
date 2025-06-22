#include "header.h"
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
    //Tree *our_tree = (Tree*)malloc(sizeof(Tree));
    Tree* our_tree = NULL;
    Car* new_car = NULL;

    for (int i = 0; i < size_cars; i++) {
		new_car = read_1_car(open_bin_file);
        our_tree = add_Car_to_Tree(our_tree, new_car);
        new_car = NULL;
    }
    fclose(open_bin_file);
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
void printAllModels(Car *cars, int carsCount) {
    for (int i = 0; i < carsCount; i++) {
        printf("%d)\tМодель: %s\n", i, cars->model);
    }
}

void printModelWithConfigurations(Car *cars, int index) {
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
int nodePrint(Tree* node, int index) { 
    if (node->left != NULL) {
        index = nodePrint(node->left, index);
    }
    
    printModelWithConfigurations(node->cars, ++index);
    if (node->right != NULL) {
        index = nodePrint(node->right, index);
    }
    return index;
}

void treePrint(Tree* top) {
    if (top == NULL) {
        printf("\n\tCurrent model tree is free.\n");
        return;
    }
    printf("\n\tOur tree:\n");
    nodePrint(top, -1);
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

void burn_tree(Tree **our_tree) {
    free(our_tree);
}
void god_save_the_tree(Tree* our_tree, FILE* file, char flag_of_delete) {
    if (our_tree == NULL) return;
    write_car(file, our_tree->cars);
    if (flag_of_delete) {
        removeModelByIndex(&our_tree->cars, 1, 0);
        if (!our_tree->left && !our_tree->right) {
            burn_tree(&our_tree);
        }

    }
    god_save_the_tree(our_tree->left, file, flag_of_delete);
    god_save_the_tree(our_tree->right, file, flag_of_delete);


}
void save_to_file(Tree *our_tree, char *file_path,char* mode, char flag_of_delete) {
    int last_index = nodePrint(our_tree, -1);
    last_index++;
	FILE* saving_file = fopen(file_path, mode);
	fwrite(&last_index, sizeof(last_index), 1, saving_file);
    god_save_the_tree(our_tree, saving_file, flag_of_delete);

    fclose(saving_file);
}
/// <summary>
/// 
/// </summary>
/// <param name="cars"></param>
/// <param name="carsCount"></param>
/// <returns></returns>
int* find_life_spans(Car *cars, int carsCount) {
    int *lifeSpans = malloc(carsCount * sizeof(int));
    if (lifeSpans == NULL) {
        return NULL;
    }
    for (int i = 0; i < carsCount; i++) {
        int minStartYear = INT_MAX;
        int maxEndYear = INT_MIN;
        for (int j = 0; j < cars[i].configurations_count; j++) {
            if (cars[i].configurations[j].production_start_year < minStartYear) {
                minStartYear = cars[i].configurations[j].production_start_year;
            }
            if (cars[i].configurations[j].production_end_year > maxEndYear) {
                maxEndYear = cars[i].configurations[j].production_end_year;
            }
        }
	//	printf("max = %d, min = %d\n", maxEndYear, minStartYear);
        lifeSpans[i] = maxEndYear - minStartYear;
      //  printf("lifeSpans[%d] = %d\n", i, lifeSpans[i]);
    }
    return lifeSpans;
}
/// <summary>
/// 
/// </summary>
/// <param name="our_tree"></param>
/// <param name="min_life_cycle"></param>
/// <param name="count_model"></param>
/// <returns></returns>
void find_min_life_cycle(Tree* our_tree, int *min_life_cycle) {
    if (our_tree->left != NULL) {
        find_min_life_cycle(our_tree->left, min_life_cycle);
    }
    int Max_year = INT_MIN, Min_year = INT_MAX;
    for (int j = 0; j < our_tree->cars->configurations_count; j++) {
        if (our_tree->cars->configurations[j].production_start_year < Min_year) {
            Min_year = our_tree->cars->configurations[j].production_start_year;
        }
        if (our_tree->cars->configurations[j].production_end_year > Max_year) {
            Max_year = our_tree->cars->configurations[j].production_end_year;
        }
    }
    if (Max_year - Min_year < (*min_life_cycle)) {
        (*min_life_cycle) = Max_year - Min_year;
    }
    if (our_tree->right != NULL) {
        find_min_life_cycle(our_tree->right, min_life_cycle);
    }
    
}
int check_min_cycle(Tree *our_tree, int min_life_cycle){
    int Max_year = INT_MIN, Min_year = INT_MAX;
    for (int j = 0; j < our_tree->cars->configurations_count; j++) {
        if (our_tree->cars->configurations[j].production_start_year < Min_year) {
            Min_year = our_tree->cars->configurations[j].production_start_year;
        }
        if (our_tree->cars->configurations[j].production_end_year > Max_year) {
           Max_year = our_tree->cars->configurations[j].production_end_year;
        }
    }
    return Max_year - Min_year == min_life_cycle;
}
void *find_all_min_model(Tree* our_tree, int min_life_cycle) {
    if (our_tree->left != NULL) {
        find_all_min_model(our_tree->left, min_life_cycle);
    }
    if (check_min_cycle(our_tree, min_life_cycle)) {
        printf("С минимальным %d циклом:\n", min_life_cycle);
        printModelWithConfigurations(our_tree->cars, 0);

    }
    if (our_tree->right != NULL) {
        find_all_min_model(our_tree->right, min_life_cycle);
    }
}

Tree *delete_min_root(Tree* root) {
        //if (root->left && root->right) {
        if (root->left) {
            Tree* actual_son = root->left, *new_dad = root->left;
            while (actual_son->right) {
                actual_son = actual_son->right;
            }
            actual_son->right = root->right;

            free(root);
            root = new_dad;
            new_dad = NULL;
        }
        else if (!root->left && root->right) {
            Tree* new_dad = root->right;
            free(root);
            root = new_dad;
            new_dad = NULL;
        }
        else if (!root->left && root->right) {
            free(root);
            root = NULL;
        }
        return root;
}
int delete_min_son(Tree* our_tree, Tree *son) {
    if (our_tree->left == son) {
        if (son->left) {
            our_tree->left = son->left;
			Tree* actual_vnuc = son->right;
            while (actual_vnuc->right) {
                actual_vnuc = actual_vnuc->right;
            }
            actual_vnuc->right = son->right;
        }
        else if (son->right) {
            our_tree->left = son->right;
        }
        else {
            our_tree->left = NULL;
        }
    }
    else if (our_tree->right == son) {
        if (son->left) {
            our_tree->right = son->left;
			Tree* actual_vnuc = son->right;
            while (actual_vnuc->right) {
                actual_vnuc = actual_vnuc->right;
            }
            actual_vnuc->right = son->right;
        }
        else if (son->right) {
            our_tree->right = son->right;
        }
        else {
            our_tree->right = NULL;
        }
    }
    free(son);
    son = NULL;

}
int find_min_for_delete(Tree *our_tree, int min_life_cycle) {
    if (our_tree->left && find_min_for_delete(our_tree->left, min_life_cycle)) {
        delete_min_son(our_tree, our_tree->left);
    }
    if (our_tree->right && find_min_for_delete(our_tree->right, min_life_cycle)) {
        delete_min_son(our_tree, our_tree->right);
    }
    return check_min_cycle(our_tree, min_life_cycle);
}

Tree* delete_model_with_min_lifecycle(Tree* our_tree) {
    int min_life_cycle = INT_MAX;
    find_min_life_cycle(our_tree, &min_life_cycle);
    if (find_min_for_delete(our_tree, min_life_cycle)) {
        return delete_min_root(our_tree);
    }
    return our_tree;
}
void find_model_by_life_cycle_main(Tree* our_tree) {
    int min_life_cycle = INT_MAX;
    find_min_life_cycle(our_tree, &min_life_cycle);
    find_all_min_model(our_tree, min_life_cycle);
}





// Функция для сравнения типов кузова
int compareBodyType(const void *a, const void *b) {
    return strcmp(((Configuration *)a)->body_type, ((Configuration *)b)->body_type);
}

// Функция для сравнения количества вхождений
int compareCounts(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
// Функция для поиска типа кузова в массиве
int findBodyTypeIndex(char **bodyTypes, int totalTypes, char *bodyType) {
    for (int k = 0; k < totalTypes; k++) {
        if (strcmp(bodyType, bodyTypes[k]) == 0) {
            return k;
        }
    }
    return -1;
}

// Функция для добавления нового типа кузова в массив
void addBodyType(char ***bodyTypes, int **counts, int *totalTypes, char *bodyType) {
    (*bodyTypes)[*totalTypes] = bodyType;
    (*counts)[*totalTypes] = 1;
    (*totalTypes)++;
}

// Функция для сортировки типов кузова по количеству вхождений
void sortBodyTypes(char **bodyTypes, int *counts, int totalTypes) {
    for (int i = 0; i < totalTypes - 1; i++) {
        for (int j = 0; j < totalTypes - i - 1; j++) {
            if (counts[j] < counts[j + 1]) {
                // Меняем местами количество вхождений и типы кузова
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

// Функция для вывода отсортированных типов кузова
void printSortedBodyTypes(char **bodyTypes, int *counts, int totalTypes) {
    printf("\n[\t");
    for (int i = 0; i < totalTypes; i++) {
        printf("\nКузов %s: число %d\n", bodyTypes[i], counts[i]);
    }
    printf("\n]");
}

// Основная функция для сортировки и печати типов кузова
void sortAndPrintBodyTypes(Tree *our_tree, char** bodyTypes, int* counts,int totalTypes) {
    if (our_tree->left) {
		sortAndPrintBodyTypes(our_tree->left, bodyTypes, counts, &totalTypes);
    }
        for (int j = 0; j < our_tree->cars->configurations_count; j++) {
            int index = findBodyTypeIndex(bodyTypes, totalTypes, our_tree->cars->configurations[j].body_type);
            if (index != -1) {
                counts[index]++;
            } else {
                addBodyType(&bodyTypes, &counts, &totalTypes, our_tree->cars->configurations[j].body_type);
            }
        }

    if (our_tree->right) {
		sortAndPrintBodyTypes(our_tree->right, bodyTypes, counts, &totalTypes);
    }
    sortBodyTypes(bodyTypes, counts, totalTypes);
    printSortedBodyTypes(bodyTypes, counts, totalTypes);
    free(bodyTypes);
    free(counts);
}
void sort_in_tree_by_bodytypes(Tree *our_tree) {
    char **bodyTypes = malloc(sizeof(char *) * 100);
    int *counts = calloc(100, sizeof(int));
    int totalTypes = 0;
    sortAndPrintBodyTypes(our_tree, bodyTypes, counts, totalTypes);

}

