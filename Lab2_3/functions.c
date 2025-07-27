#include "header.h"
#include "functions.h"
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
        printf("Значит будет %d\n", *number);
    }
}
void promptForSave(Car* cars, int size_cars, char* file_user) {
    if (cars != NULL) {
        printf("Хотите сохранить текущую структуру в файл перед выходом? (y/n): ");
        char answer;
        do {
            answer = getchar();
        } while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N');
        
        if (answer == 'y' || answer == 'Y') {
            saver(cars, size_cars, file_user);
        }
        while ((answer = getchar()) != '\n' && answer != EOF) { }
    }
} 
void saver(Car* cars, int count_structure, char* filename) {
    FILE* saves = fopen(filename, "wb");
    fwrite(&count_structure, sizeof(count_structure), 1, saves);
    for (int i = 0; i < count_structure; i++) {
        fwrite(cars[i].model, strlen(cars[i].model) + 1, 1, saves);
        fwrite(&cars[i].configurations_count, sizeof(cars[i].configurations_count), 1, saves);
        for (int j = 0; j < cars[i].configurations_count; j++) {
            Configuration* conf = &cars[i].configurations[j];
            fwrite(conf->body_type, strlen(conf->body_type) + 1, 1, saves);
            fwrite(&conf->engine_volume, sizeof(conf->engine_volume), 1, saves);
            fwrite(&conf->production_start_year, sizeof(conf->production_start_year), 1, saves);
            fwrite(&conf->production_end_year, sizeof(conf->production_end_year), 1, saves);
        }
    }
    fclose(saves);
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
Car* reader(int* size_cars, char* filename) {
    FILE* fd = fopen(filename, "rb");
    fread(size_cars, sizeof(*size_cars), 1, fd);
    Car* cars = malloc((*size_cars) * sizeof(Car));
    for (int i = 0; i < (*size_cars); i++) {
        cars[i].model = read_binary_string(fd);
        fread(&cars[i].configurations_count, sizeof(cars[i].configurations_count), 1, fd);
        cars[i].configurations = malloc(cars[i].configurations_count * sizeof(Configuration));
        for (int j = 0; j < cars[i].configurations_count; j++) {
            Configuration* conf = cars[i].configurations + j;
            conf->body_type = read_binary_string(fd);
            fread(&conf->engine_volume, sizeof(conf->engine_volume), 1, fd);
            fread(&conf->production_start_year, sizeof(conf->production_start_year), 1, fd);
            fread(&conf->production_end_year, sizeof(conf->production_end_year), 1, fd);
        }
    }
    fclose(fd);
    return cars;
}
void menu_file() {
    Car* cars = NULL;
    int size_cars = 0, user_choice, exit_flag = 0;
    char file_default[] = "C:\\Files_for_testing\\default_structure.bin", file_user[] = "C:\\Files_for_testing\\user_tree_new.bin"; 
    char file_welcome[] =
        "Доступные команды: \n"
        "1) default.bin (только чтение)\n"
        "2) user.bin (чтение и запись)\n"
        "3) Выход\n";
    while (!exit_flag) {          
        printf("%s", file_welcome);
        user_choice = correct("Ваш выбор:");
        switch (user_choice) {
        case 1:
            cars = reader(&size_cars, file_default);
            menu_structure(&cars, &size_cars, file_user, &exit_flag);
            break;
        case 2:
            cars = reader(&size_cars, file_user);
            menu_structure(&cars, &size_cars, file_user, &exit_flag);
            break;
        case 3:
            exit_flag = 1; // Выход из функции
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    }
	promptForSave(cars, size_cars, file_user); // Вызов функции сохранения перед выходом
    for (int i = size_cars - 1; i >= 0 && cars != NULL; i--) {
        removeModelByIndex(&cars, &size_cars, i);
    }
    if (cars == NULL) {
        printf("success");
    }
}

void menu_structure(Car** cars, int* size_cars, char* file_user, int* exit_flag) {
    int user_choice, index;
    char file_comand[] =
        "Выберите действие:\n"
        "0. Возврат в главное меню\n"
        "1. Изменить структуру\n"
        "2. Сохранить структуру в user.bin\n"
        "3. Запуск задачи со структурой\n"
        "4. Возврат в предыдущее меню\n"
        "5. Вывести текущую структуру\n"
        "6. Вывести все модели\n";
    while (!*exit_flag) {
        printf("%s", file_comand);
        user_choice = correct("Ваш выбор:");
        switch (user_choice) {
        case 1:
            change_structure(cars, size_cars, exit_flag);
            break;
        case 2:
            saver(*cars, *size_cars, file_user);
            break;
        case 3:
            sortAndPrintBodyTypes(*cars, *size_cars);
			//removeModelsByLifeSpan(cars, size_cars); 
            kill_model(cars, size_cars); 
            break;
        case 4:
            return; 
        case 0:
            *exit_flag = 1; 
            break;
        case 5:
            printBasedOnNumber(*cars, *size_cars, 1);
            break;
        case 6:
			printBasedOnNumber(*cars, *size_cars, 0);
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    }
}
void change_structure(Car** cars, int* size_cars, int* exit_flag) {
    int user_choice, index;
    char file_comand[] =
        "\tWe are in Changing\nВыберите действие:\n"
        "\t0. Возврат в главное меню\n"
        "\t1. Добавить модель\n"
        "\t2. Удалить модель\n"
        "\t3. Изменить модель\n"
        "\t4. Вывести текущую структуру\n"
        "\t5. Вывести все модели\n"
        "\t6. Возврат в меню структуры\n";
    while (!*exit_flag) {
        printf("%s", file_comand);
        user_choice = correct("Ваш выбор:");
        switch (user_choice) {
        case 1: 
            addModel(cars, size_cars, exit_flag);
            break;
        case 2:
            index = correct("Выбери индекс:");
            removeModelByIndex(cars, size_cars, index);
            break;
        case 3:
            editModel(cars, size_cars, exit_flag, 0);
            break;
        case 4:
            printBasedOnNumber(*cars, *size_cars, 1);
            break;
        case 5:
			printBasedOnNumber(*cars, *size_cars, 0);
            break;
        case 6:
            return;
        case 0:
            *exit_flag = 1; // Установка флага выхода для возврата в начальное меню
            break;
        }
    }
}

void addModel(Car** cars, int* carsCount, int* exit_flag) {
    (*carsCount)++;
    Car* temp = realloc(*cars, (*carsCount) * sizeof(Car));
    if (temp == NULL) {
        printf("Ошибка выделения памяти.\n");
        return;
    }
    *cars = temp;
    printf("Введите название модели: ");
    (*cars)[*carsCount - 1].model = malloc(20 * sizeof(char));
    fgets((*cars)[*carsCount - 1].model, 20, stdin);
    (*cars)[*carsCount - 1].model[strcspn((*cars)[*carsCount - 1].model, "\n")] = 0;
    (*cars)[*carsCount - 1].configurations_count = correct("Введите число конфигураций: ");
    (*cars)[*carsCount - 1].configurations_count = ((*cars)[*carsCount - 1].configurations_count > 0) ? (*cars)[*carsCount - 1].configurations_count : 1;
    (*cars)[*carsCount - 1].configurations = malloc((*cars)[*carsCount - 1].configurations_count * sizeof(Configuration));
    for (int j = 0; j < (*cars)[*carsCount - 1].configurations_count; j++) {
        printf("Введите тип кузова: ");
        (*cars)[*carsCount - 1].configurations[j].body_type = malloc(15 * sizeof(char));
        fgets((*cars)[*carsCount - 1].configurations[j].body_type, 15, stdin);
        (*cars)[*carsCount - 1].configurations[j].body_type[strcspn((*cars)[*carsCount - 1].configurations[j].body_type, "\n")] = 0;
        (*cars)[*carsCount - 1].configurations[j].engine_volume = correct("Введите объем двигателя: ");
        (*cars)[*carsCount - 1].configurations[j].production_start_year = correct("Введите год начала выпуска: ");
        (*cars)[*carsCount - 1].configurations[j].production_end_year = correct("Введите год окончания выпуска: ");
    }
    fflush(stdin);
    editModel(cars, carsCount, exit_flag, 1);
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

void editModelName(Car* cars, int index_model) {
    printf("Введите новое название модели: ");
    char* newModel = malloc(20 * sizeof(char));
    fgets(newModel, 20, stdin);
    newModel[strcspn(newModel, "\n")] = 0; 
    free(cars[index_model].model); 
    cars[index_model].model = newModel;
}


void editModel(Car** cars, int* carsCount, int *exit_flag, int last) {
    int index_model = last ? (*carsCount) - 1 : correct("Выберите индекс модели для изменения: ");
    if (index_model < 0 || index_model >= *carsCount) {
        printf("Некорректный индекс.\n");
        return;
    }
    const char* options = "\t0. Возврат в главное меню\n"
                          "\t1. Название модели\n"
                          "\t2. Изменить конфигурацию\n"
                          "\t3. Добавить конфигурацию\n"
                          "\t4. Удалить конфигурацию\n"
                          "\t5. Вывести текущую модель\n"
                          "\t6. Возврат в меню структуры\n";
    while (!*exit_flag) {
        printf("Доступные возможности:\n%sТекущий индекс модели:%d\n", options, index_model);
        int choice = correct("Выберите доступную возможность: ");
        if (choice > 0 && choice <= 5) {
            void (*actions[])(Car*, int) = { NULL, editModelName, editConfiguration, addConfiguration, deleteConfiguration, printModelWithConfigurations };
            actions[choice](*cars, index_model);
        }
        else if (choice == 0) {
            *exit_flag = 1;
        }
        else if (choice == 6) {
            return;
        }
        else {
            printf("Некорректный выбор.\n");
        }
    }
}


void editConfiguration(Car* cars, int index_model) {
    int index_configuration = correct("Выберите индекс конфигурации для изменения: ");
    check_number(&index_configuration, 0, cars[index_model].configurations_count - 1);
    const char* options =
        "\t0. Возврат в меню модели\n"
        "\t1. Тип кузова\n"
        "\t2. Объем двигателя\n"
        "\t3. Год начала выпуска\n"
        "\t4. Год конца выпуска\n"
        "\t5. Изменить всю конфигурацию\n"
        "\t6. Вывести текущую конфигурацию\n";
    while (1) {
        printf("Доступные возможности:\n%sТекущий индекс модели:%d\n", options, index_model);
        int choice = correct("Выберите доступную возможность: ");
        void (*actions[])(Car*, int, int) = {NULL, editBodyType, editEngineVolume, editProductionStartYear, editProductionEndYear, NULL, print_One_configur};
        if (choice == 6 || choice > 0 && choice < 5) {
            actions[choice](cars, index_model, index_configuration);
        }
        else if (choice == 5) {
            for (int x = 1; x < 5; x++) {
                actions[x](cars, index_model, index_configuration);
            }
        }
        else if (choice == 0) {
            break;
        } else {
            printf("Некорректный выбор.\n");
        }
    }
}
void editBodyType(Car* cars, int index_model, int index_configuration) {
    printf("Введите новый тип кузова: ");
    cars[index_model].configurations[index_configuration].body_type = malloc(30 * sizeof(char));
    fgets(cars[index_model].configurations[index_configuration].body_type, 30, stdin);
    cars[index_model].configurations[index_configuration].body_type[strcspn(cars[index_model].configurations[index_configuration].body_type, "\n")] = 0;
}

void editEngineVolume(Car* cars, int index_model, int index_configuration) {
    cars[index_model].configurations[index_configuration].engine_volume = correct("Введите новый объем двигателя: ");
}

void editProductionStartYear(Car* cars, int index_model, int index_configuration) {
    cars[index_model].configurations[index_configuration].production_start_year = correct("Введите новый год начала выпуска: ");
}

void editProductionEndYear(Car* cars, int index_model, int index_configuration) {
    cars[index_model].configurations[index_configuration].production_end_year = correct("Введите новый год окончания выпуска: ");
}
void deleteConfiguration(Car *cars, int index_model) {
    int confIndex = correct("Выберите индекс конфигурации для удаления: ");
    if (confIndex < 0 || confIndex >= cars[index_model].configurations_count) {
        printf("Некорректный индекс\n");
        return;
    }
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
void addConfiguration(Car *cars, int index_model) {
    Configuration *temp = realloc(cars[index_model].configurations, (cars[index_model].configurations_count + 1) * sizeof(Configuration));
    if (!temp) {
        printf("Ошибка выделения памяти при добавлении новой конфигурации.\n");
    } else {
        cars[index_model].configurations = temp;
        int new_conf_index = cars[index_model].configurations_count;
        cars[index_model].configurations[new_conf_index].body_type = malloc(15 * sizeof(char));
        printf("Введите новый тип кузова: ");
        fgets(cars[index_model].configurations[new_conf_index].body_type, 15, stdin);
        cars[index_model].configurations[new_conf_index].body_type[strcspn(cars[index_model].configurations[new_conf_index].body_type, "\n")] = 0;
        cars[index_model].configurations[new_conf_index].engine_volume = correct("Введите новый объем двигателя: ");
        cars[index_model].configurations[new_conf_index].production_start_year = correct("Введите новый год начала выпуска: ");
        cars[index_model].configurations[new_conf_index].production_end_year = correct("Введите новый год окончания выпуска: ");
        cars[index_model].configurations_count++;
    }
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

