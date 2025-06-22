#include "main.h"
int correct(char* text) {
    char input[100];
    int valid = 0;
    int num;
    char* endptr; 
    valid = 0;
    while (!valid) {
        printf("%s\n", text);
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
        return NULL; // В случае ошибки выделения памяти возвращаем NULL
    }
    strcpy(returning_text, input);
    return returning_text; // Возвращаем строку
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

// Функция для создания хэш-таблицы
Hashtable* create_hashtable() {
    Hashtable *hashtable = malloc(sizeof(Hashtable));
    hashtable->entries = malloc(sizeof(HashtableEntry*) * TABLE_SIZE);

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashtable->entries[i] = NULL;
    }

    return hashtable;
}

// Простая хэш-функция
unsigned int hash_function(char *key) {
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    // Для каждого символа в строке
    for (; i < key_len; ++i) {
        value = value * 37 + key[i];
    }

    // Убедимся, что значение не выходит за пределы таблицы
    value = value % TABLE_SIZE;

    return value;
}
unsigned long hash_djb2(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash;
}

Car* ht_get(Hashtable *hashtable, char *key) {
    unsigned int slot = hash_djb2(key) % TABLE_SIZE; // Используем хэш-функцию для определения индекса

    // Перебираем элементы в слоте
    HashtableEntry *entry = hashtable->entries[slot];

    while (entry != NULL) {
        if (strcmp(entry->key_model, key) == 0) {
            return entry->car;
        }
        entry = entry->next;
    }

    // Если элемент не найден
    return NULL;
}


// Функция для вставки элемента в хэш-таблицу
void ht_set(Hashtable *hashtable, char *key, Car *car) {
    unsigned int slot = hash_function(key);

    // Создаем новый элемент для вставки
    HashtableEntry *entry = malloc(sizeof(HashtableEntry));
    entry->car = car;
    entry->key_model = strdup(key);
    entry->next = hashtable->entries[slot]; // Добавляем в начало списка

    // Вставляем элемент
    hashtable->entries[slot] = entry;
}

// Функция для поиска элемента в хэш-таблице
//Car* ht_get(Hashtable *hashtable, char *key) {
//    unsigned int slot = hash_function(key);
//
 ///   // Перебираем элементы в слоте
//    HashtableEntry *entry = hashtable->entries[slot];

//    while (entry != NULL) {
//       if (strcmp(entry->key_model, key) == 0) {
//            return entry->car;
//        }
//        entry = entry->next;
//    }

    // Если элемент не найден
//    return NULL;
//}

// Функция для удаления хэш-таблицы
void ht_delete(Hashtable *hashtable) {
    // Перебираем все слоты
    for (int i = 0; i < TABLE_SIZE; ++i) {
        HashtableEntry *entry = hashtable->entries[i];

        // Удаляем все элементы в списке
        while (entry != NULL) {
            HashtableEntry *temp = entry;
            entry = entry->next;
            free(temp->key_model);
            free(temp);
        }
    }

    // Удаляем массив слотов и саму хэш-таблицу
    free(hashtable->entries);
    free(hashtable);
}
Hashtable *fill_our_hash(char *filename) {
    FILE *open_bin_file = save_fileOpener(filename, "rb");
    int size_cars;
    fread(&size_cars, sizeof(size_cars), 1, open_bin_file);
    //Tree *our_tree = (Tree*)malloc(sizeof(Tree));
    Hashtable *hashtable = create_hashtable();
    Car* new_car = NULL;

    for (int i = 0; i < size_cars; i++) {
		new_car = read_1_car(open_bin_file);
        ht_set(hashtable, new_car->model, new_car);
        new_car = NULL;
    }
    fclose(open_bin_file);
    return hashtable;

}
