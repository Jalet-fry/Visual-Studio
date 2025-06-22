#include "header.h"
//#define PRINT_MODEL
int correct(char* c) {
    char input[100];
    int valid = 0;
    int num;
    char* endptr; 
    valid = 0;
    while (!valid) {
        printf("%s", c);
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


Tree *Bad_add_Car_to_Tree(Tree *our_tree, Car *new_car){
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
Tree *fill_our_tree(char *filename) {
    FILE *open_bin_file = save_fileOpener(filename, "rb");
    int size_cars;
    fread(&size_cars, sizeof(size_cars), 1, open_bin_file);
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
void delete_configuration_without_questions(Car* cars, int index_model, int confIndex) {
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
    for (int x = 0; x < (*cars)[index].configurations_count; x++) {
        delete_configuration_without_questions(*cars, index, 0);
    }
    free((*cars)[index].model);
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

void print_model_with_configurations(Car *cars, int index, int level) {
    printf(" %d)\tМодель: %s\n", index, cars[0].model);
    for (int j = 0; j < cars[0].configurations_count; j++) {
		print_level(level);
        printf(" %d.%d)\tТип кузова: %s, Объем двигателя: %d, Год начала выпуска: %d, Год окончания выпуска: %d\n",
               index, j,
               cars[0].configurations[j].body_type,
               cars[0].configurations[j].engine_volume,
               cars[0].configurations[j].production_start_year,
               cars[0].configurations[j].production_end_year);
    }
    printf("\n");
}

void print_based_on_number(Car *cars, int carsCount, int number) {
    if (!number) {
        print_all_models(cars, carsCount);
    } else {
        for (int i = 0; i < carsCount; i++) {
            print_model_with_configurations(cars, i, 0);
        }
    }
}

Tree* get_next_tree_node(Tree* node, int dif) {
    if (node == NULL) return NULL;
    if(dif > 0) return node->right;
    return node->left;
}
// PRINTING
int node_print_new(Tree* node, int index, int level, char* sides, int method) {
    if (node == NULL) {
        return index;
    }

    sides[level] = '-';
    index = node_print_new(node->left, index, level + 1, sides, method);
    sides[level] = 0;
    printf(sides);
//#ifdef PRINT_MODEL 
//    print_model_with_configurations(node->cars, ++index, level);
//#else 
//    printf(" %d) |%d|\n", ++index, calculate_life_cycle(node->cars));
//#endif
    if (method) {
		print_model_with_configurations(node->cars, ++index, level);
    }
    else {
		printf(" %d) |%d|\n", ++index, calculate_min_life_cycle_configurations(node->cars));
    }
    
    sides[level] = '+';
    index = node_print_new(node->right, index, level + 1, sides, method);

    return index;
}
int node_print_beautiful(Tree* node, int index, int level) { 
    if (node == NULL) {
        return index;
    }

    index = node_print_beautiful(node->left, index, level + 1);

    print_level(level);

    printf("-->");
    printf("\n");
    
    index = node_print_beautiful(node->right, index, level + 1);

    return index;
}

void tree_print_beautiful(Tree* top, int method) {
    if (top == NULL) {
        printf("\n\tТекущее дерево моделей пусто.\n");
        return;
    }
    printf("\n\tНаше дерево:\n");
    //node_print_beautiful(top, -1, 0);
    char buffer[50];
    memset(buffer, 0, sizeof(buffer));
    node_print_new(top, -1, 0, buffer, method);
    printf("\n");
}

int node_print_for_life_cycle(Tree* node, int index, int level, char* sides, int method) {
    if (node == NULL) {
        return index;
    }

    sides[level] = '-';
    index = node_print_for_life_cycle(node->left, index, level + 1, sides, method);
    sides[level] = 0;
    printf(sides);
    if (method) {
		print_model_with_configurations(node->cars, ++index, level);
    }
    else {
		printf(" %d) |%d|\n", ++index, calculate_life_cycle_model(node->cars));
    }
    
    sides[level] = '+';
    index = node_print_for_life_cycle(node->right, index, level + 1, sides, method);

    return index;
}
void tree_print_for_model_life_cycle(Tree* top, int method) {
    if (top == NULL) {
        printf("\n\tТекущее дерево моделей пусто.\n");
        return;
    }
    printf("\n\tНаше дерево:\n");
    //node_print_beautiful(top, -1, 0);
    char buffer[50];
    memset(buffer, 0, sizeof(buffer));
    node_print_for_life_cycle(top, -1, 0, buffer, method);
    printf("\n");
}
void print_level(int level) {
    for (int i = 0; i < level; i++) {
        printf(" "); 
    }
}

int node_printing(Tree* node, int index, int level) { 
    if (node->left != NULL) {
        index = node_printing(node->left, index, level + 1);
    }
    ++index;
    if (node->right != NULL) {
        index = node_printing(node->right, index, level + 1);
    }
    return index;
}

void tree_printing(Tree* top) {
    if (top == NULL) {
        printf("\n\tТекущее дерево моделей пусто.\n");
        return;
    }
    printf("\n\tНаше дерево:\n");
    node_printing(top, -1, 0);
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
        remove_model_by_index(&our_tree->cars, 1, 0);
        if (!our_tree->left && !our_tree->right) {
            burn_tree(&our_tree);
        }

    }
    god_save_the_tree(our_tree->left, file, flag_of_delete);
    god_save_the_tree(our_tree->right, file, flag_of_delete);


}
void save_to_file(Tree *our_tree, char *file_path,char* mode, char flag_of_delete) {
    int last_index = node_printing(our_tree, -1, 0);
    last_index++;
	FILE* saving_file = fopen(file_path, mode);
	fwrite(&last_index, sizeof(last_index), 1, saving_file);
    god_save_the_tree(our_tree, saving_file, flag_of_delete);

    fclose(saving_file);
}
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
        lifeSpans[i] = maxEndYear - minStartYear;
    }
    return lifeSpans;
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

Tree *delete_min_root(Tree* root) {
        if (root->left) {
            Tree* actual_son = root->left, *new_dad = root->left;
            while (actual_son->right) {
                actual_son = actual_son->right;
            }
            actual_son->right = root->right;

            remove_model_by_index(&root->cars, 1, 0);
            free(root);
            root = new_dad;
            new_dad = NULL;
        }
        else if (!root->left && root->right) {
            Tree* new_dad = root->right;
            remove_model_by_index(&root->cars, 1, 0);
            free(root);
            root = new_dad;
            new_dad = NULL;
        }
        else if (!root->left && !root->right) {
            remove_model_by_index(&root->cars, 1, 0);
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
void find_min_life_cycle(Tree* our_tree, int *min_life_cycle) {
    if (our_tree == NULL) return;

    int current_life_cycle = calculate_life_cycle_model(our_tree->cars);
    if (current_life_cycle < *min_life_cycle) {
        *min_life_cycle = current_life_cycle;
    }
    find_min_life_cycle(our_tree->left, min_life_cycle);
    find_min_life_cycle(our_tree->right, min_life_cycle);
}

void find_min_life_cycle_configur(Tree* our_tree, int *min_life_cycle) {
    if (our_tree == NULL) return;

    int current_life_cycle = calculate_min_life_cycle_configurations(our_tree->cars);
    if (current_life_cycle < *min_life_cycle) {
        *min_life_cycle = current_life_cycle;
    }
    find_min_life_cycle_configur(our_tree->left, min_life_cycle);
}

void find_model_by_life_cycle_main(Tree* our_tree) {
    int min_life_cycle = INT_MAX;
    find_min_life_cycle(our_tree, &min_life_cycle);
    printf("Min_life = %d\n", min_life_cycle);
	find_models_with_cycle_threshold(our_tree, min_life_cycle);
}


void find_model_by_life_cycle_configur_main(Tree* our_tree) {
    int min_life_cycle_conf = INT_MAX;
    find_min_life_cycle_configur(our_tree, &min_life_cycle_conf);
    printf("Min_life = %d\n", min_life_cycle_conf);
    find_models_with_your_conf_cycle(our_tree, min_life_cycle_conf);
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
void add_body_type(char ***bodyTypes, int **counts, int *totalTypes, char *bodyType) {
    (*bodyTypes)[*totalTypes] = bodyType;
    (*counts)[*totalTypes] = 1;
    (*totalTypes)++;
}

// Функция для сортировки типов кузова по количеству вхождений
void sort_bodytypes(char **bodyTypes, int *counts, int totalTypes) {
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

void printSortedBodyTypes(char **bodyTypes, int *counts, int totalTypes) {
    printf("\n[\t");
    for (int i = 0; i < totalTypes; i++) {
        printf("\nКузов %s: число %d\n", bodyTypes[i], counts[i]);
    }
    printf("\n]");
}

void sortAndPrintBodyTypes(Tree *our_tree, char** bodyTypes, int* counts, int *totalTypes) {
    if (our_tree->left) {
        sortAndPrintBodyTypes(our_tree->left, bodyTypes, counts, totalTypes);
    }
    for (int j = 0; j < our_tree->cars->configurations_count; j++) {
        int index = findBodyTypeIndex(bodyTypes, *totalTypes, our_tree->cars->configurations[j].body_type);
        if (index != -1) {
            counts[index]++;
        } else {
            add_body_type(&bodyTypes, &counts, totalTypes, our_tree->cars->configurations[j].body_type);
        }
    }
    if (our_tree->right) {
        sortAndPrintBodyTypes(our_tree->right, bodyTypes, counts, totalTypes);
    }
    // Сортировка и печать должны производиться после обхода всего дерева
    if (our_tree->left == NULL && our_tree->right == NULL) {
        sort_bodytypes(bodyTypes, counts, *totalTypes);
    }
}
void sort_in_tree_by_bodytypes(Tree *our_tree) {
    char **bodyTypes = malloc(sizeof(char *) * 100);
    int *counts = calloc(100, sizeof(int));
    int totalTypes = 0;
    sortAndPrintBodyTypes(our_tree, bodyTypes, counts, &totalTypes);
	printSortedBodyTypes(bodyTypes, counts, totalTypes);
    free(bodyTypes);
    free(counts);
}

Tree* find_node_by_index(Tree* root, int index, int* current_index, Tree** temp_parent, Tree** parent) {
    if (root == NULL) {
        return NULL;
    }
    Tree* found = NULL;
    if (root->left != NULL) {
        *temp_parent = root; 
        found = find_node_by_index(root->left, index, current_index, temp_parent, parent);
        if (found != NULL) {
            return found;
        }
    }
    if (*current_index == index) {
        if ((*temp_parent)->left == root || (*temp_parent)->right == root) {
            *parent = *temp_parent; 
        }
        return root;
    }
    *current_index += 1;
    if (root->right != NULL) {
        *temp_parent = root; 
        found = find_node_by_index(root->right, index, current_index, temp_parent, parent);
        if (found != NULL) {
            return found;
        }
    }

    return NULL;
}

Tree* delete_node_by_index(Tree* root, int index) {
    int current_index = 0;
    Tree* parent = NULL;
    Tree* temp_parent = NULL;
    Tree* node_to_delete = find_node_by_index(root, index, &current_index, &temp_parent, &parent);

    if (node_to_delete == NULL) {
		printf("\n\tAHTUNG!. Index is false.\n");
        return root;
    }

    if (parent == NULL) {
        // Удаляем корень.
        return delete_min_root(node_to_delete);
    } else {
        // Удаляем потомка и обновляем ссылку на родителя.
        if (parent->left == node_to_delete || parent->right == node_to_delete) {
            delete_min_son(parent, node_to_delete);
        }
        return root;
    }
}

Tree* delete_by_your_index_main(Tree* old_tree) {
    if (old_tree == NULL) {
		printf("\n\tCANCERED!. Model tree is empty.\n");
		return NULL;
	}
    int index = -1, step = -1;
    while (index < 0) {
        index = correct("Write your index(start from 0):");
    }
    old_tree = delete_node_by_index(old_tree, index);
    return old_tree;
}
//Tree* delete_by_your_index(Tree* root, int indexToDelete, int* currentIndex, Tree* parent) {
//    if (root == NULL) {
//        return NULL;
//    }
//    if (*currentIndex == indexToDelete) {
//        if (parent == NULL) {
//            return delete_min_root(root);
//        } else {
//            delete_min_son(parent, root);
//            return NULL;
//        }
//    }
//    if (root->left != NULL) {
//        if (delete_node_by_index(root->left, indexToDelete, currentIndex, root) != NULL) {
//            return root;
//        }
//    }
//    if (root->right != NULL) {
//        if (delete_node_by_index(root->right, indexToDelete, currentIndex, root) != NULL) {
//            return root;
//        }
//    }
//	*currentIndex += 1;
//	//*currentIndex -= 1;
//    return root;
//}
Tree* free_tree(Tree* user_tree) {
    if (user_tree == NULL) {
        return NULL;
    }
    free_tree(user_tree->left);
    free_tree(user_tree->right);
    remove_model_by_index(&user_tree->cars, 1, 0);
    free(user_tree);
    user_tree = NULL;
    return NULL;


}

Tree *add_Car_to_Tree(Tree *our_tree, Car *new_car) {
    Tree *new_tree = (Tree*)malloc(sizeof(Tree));
    new_tree->cars = new_car;
    new_tree->left = new_tree->right = NULL;
    //int new_car_life_cycle = calculate_life_cycle(new_car);
    int new_car_life_cycle = calculate_min_life_cycle_configurations(new_car);
    if (!our_tree) {
        return new_tree;
    }
    Tree *current = our_tree;
    while (current != NULL) {
        //int current_car_life_cycle = calculate_life_cycle(current->cars);
		int current_car_life_cycle = calculate_min_life_cycle_configurations(current->cars);
        if (new_car_life_cycle < current_car_life_cycle) {
            if (current->left == NULL) {
                current->left = new_tree;
                break;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = new_tree;
                break;
            }
            current = current->right;
        }
    }
    return our_tree;
}

int calculate_life_cycle_model(Car *car) {
    int min_start_year = INT_MAX;
    int max_end_year = INT_MIN;
    for (int i = 0; i < car->configurations_count; i++) {
        if (car->configurations[i].production_start_year < min_start_year) {
            min_start_year = car->configurations[i].production_start_year;
        }
        if (car->configurations[i].production_end_year > max_end_year) {
            max_end_year = car->configurations[i].production_end_year;
        }
    }
    return max_end_year - min_start_year;
}

int calculate_min_life_cycle_configurations(Car* car) {
    int result = INT_MAX, temp_result = INT_MAX;
    for (int i = 0; i < car->configurations_count; i++) {
        temp_result = car->configurations[i].production_end_year - car->configurations[i].production_start_year;
        if (temp_result < result) {
            result = temp_result;
        }
    }
    return result;
}
int compare_life_cycle_model(Car *car, int life_cycle) {
    return calculate_life_cycle_model(car) == life_cycle;
}
void find_models_with_cycle_threshold(Tree* our_tree, int life_cycle_threshold) {
    if (our_tree == NULL) {
        return;
    }

    int current_life_cycle = calculate_life_cycle_model(our_tree->cars);
    if (current_life_cycle == life_cycle_threshold) {
        printf("Модель с жизненным циклом %d:\n", life_cycle_threshold);
        print_model_with_configurations(our_tree->cars, 0, 0);
    }

    if (current_life_cycle > life_cycle_threshold && our_tree->left != NULL) {
            find_models_with_cycle_threshold(our_tree->left, life_cycle_threshold);
    }
    if (current_life_cycle <= life_cycle_threshold && our_tree->right != NULL) {
            find_models_with_cycle_threshold(our_tree->right, life_cycle_threshold);
    }
}
void find_models_with_your_conf_cycle(Tree* our_tree, int life_cycle_threshold) {
    if (our_tree == NULL) {
        return;
    }
    int current_life_cycle = calculate_min_life_cycle_configurations(our_tree->cars);
    if (current_life_cycle == life_cycle_threshold) {
        printf("Модель с минимальным жизненным циклом комплектации %d:\n", life_cycle_threshold);
        print_model_with_configurations(our_tree->cars, 0, 0);
    }
    if (current_life_cycle > life_cycle_threshold && our_tree->left != NULL) {
            find_models_with_your_conf_cycle(our_tree->left, life_cycle_threshold);
    }
    if (current_life_cycle <= life_cycle_threshold && our_tree->right != NULL) {
            find_models_with_your_conf_cycle(our_tree->right, life_cycle_threshold);
    }
}

int count_children(Tree* node) {
    return (node) ? count_children(node->left) + 1 + count_children(node->right) : 0;
}
Tree* balance_left(Tree* top, int left_child, int right_child) {
    if (left_child > right_child + 1) {
        if (calculate_min_life_cycle_configurations(top->cars) != calculate_min_life_cycle_configurations(top->left->cars)) {
            for (int i = 0; i < (left_child - right_child) / 2; i++) {
                Tree* max_left = top->left;
                Tree* max_left_prev = max_left;
                Tree* new_right = add_Car_to_Tree(top->right, top->cars);
                while (max_left->right) {
                    max_left_prev = max_left;
                    max_left = max_left->right;
                }
                if (max_left != max_left_prev) {
                    max_left_prev->right = max_left->left;
                    max_left->left = top->left;
                }
                free(top);
                top = max_left;
                top->right = new_right;
            }
        }
    }
    return top;
}

Tree* balance_right(Tree* top, int left_child, int right_child) {
    if (right_child - left_child > 1) {
        if (calculate_min_life_cycle_configurations(top->cars) != calculate_min_life_cycle_configurations(top->right->cars)) {
            for (int i = 0; i < (right_child - left_child) / 2; i++) {

                Tree* min_right = top->right;
                Tree* min_right_prev = min_right;
                Tree* new_left = add_Car_to_Tree(top->left, top->cars);
                while (min_right->left) {
                    min_right_prev = min_right;
                    min_right = min_right->left;
                }
                if (min_right != min_right_prev) {
                    min_right_prev->left = min_right->right;
                    min_right->right = top->right;
                }
                free(top);
                top = min_right;
                top->left = new_left;
            }
        }
    }
    return top;
}
Tree* balance(Tree* top) {
    if (!top) {
        return top;
    }
    top = balance_left(top, count_children(top->left), count_children(top->right));
    top = balance_right(top, count_children(top->left), count_children(top->right));
	//int left_child = count_children(top->left), right_child = count_children(top->right);
    //if (left_child > right_child + 1) {
    //    for (int i = 0; i < (left_child - right_child) / 2; i++) {
    //        Tree* max_left = top->left;
    //        Tree* max_left_prev = max_left;
    //        Tree* new_right = add_Car_to_Tree(top->right, top->cars);
    //        while (max_left->right) {
    //            max_left_prev = max_left;
    //            max_left = max_left->right;
    //        }
    //        if (max_left != max_left_prev) {
    //            max_left_prev->right = max_left->left;
    //            max_left->left = top->left;
    //        }
    //        free(top);
    //        top = max_left;
    //        top->right = new_right;
    //    }
    //}
    //else if (right_child - left_child > 1) {
    //    for (int i = 0; i < (right_child - left_child) / 2; i++) {

    //        Tree* min_right = top->right;
    //        Tree* min_right_prev = min_right;
    //        Tree* new_left = add_Car_to_Tree(top->left, top->cars);
    //        while (min_right->left) {
    //            min_right_prev = min_right;
    //            min_right = min_right->left;
    //        }
    //        if (min_right != min_right_prev) {
    //            min_right_prev->left = min_right->right;
    //            min_right->right = top->right;
    //        }
    //        free(top);
    //        top = min_right;
    //        top->left = new_left;
    //    }
    //}
	top->left = balance(top->left);
	top->right = balance(top->right);
    return top;
}



