#include "header.h"
#include "functions.h"
union CharBits {
    char value;
    struct {
        unsigned low : 4;  // Младшие 4 бита
        unsigned high : 4; // Старшие 4 бита
    } bits;
};

void printBits(unsigned char num, int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
	printf("\n");

}

void task1() {
    union CharBits charBits;
    int number;
    char inputStr[10]; 
    printf("Введите число (от -128 до 127): ");
    if (fgets(inputStr, sizeof(inputStr), stdin)) {
        number = atoi(inputStr);
        if (number >= CHAR_MIN && number <= CHAR_MAX) {
            charBits.value = (unsigned char)number;
        } else {
            printf("Число вне диапазона. Используется значение по умолчанию: -2.\n");
            charBits.value = -2;
        }
        printf("Старшие 4 бита: ");
        printBits(charBits.bits.high, 4);
        printf("\nhigh = %d\n", charBits.bits.high);
        printf("Младшие 4 бита: ");
        printf("\nlow = %d\n", charBits.bits.low);
        printBits(charBits.bits.low, 4);
    } else {
        printf("Ошибка ввода.\n");
    }
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
void sortAndPrintBodyTypes(Car *cars, int carsCount) {
    char **bodyTypes = malloc(sizeof(char *) * 100);
    int *counts = calloc(100, sizeof(int));
    int totalTypes = 0;

    for (int i = 0; i < carsCount; i++) {
        for (int j = 0; j < cars[i].configurations_count; j++) {
            int index = findBodyTypeIndex(bodyTypes, totalTypes, cars[i].configurations[j].body_type);
            if (index != -1) {
                counts[index]++;
            } else {
                addBodyType(&bodyTypes, &counts, &totalTypes, cars[i].configurations[j].body_type);
            }
        }
    }
    sortBodyTypes(bodyTypes, counts, totalTypes);
    printSortedBodyTypes(bodyTypes, counts, totalTypes);
    free(bodyTypes);
    free(counts);
}


int findMinLifeSpan(Car *cars, int carsCount) {
    int minSpan = INT_MAX;
    for (int i = 0; i < carsCount; i++) {
        for (int j = 0; j < cars[i].configurations_count; j++) {
            int span = cars[i].configurations[j].production_end_year - cars[i].configurations[j].production_start_year;
            if (span < minSpan) {
                minSpan = span;
            }
        }
    }
    return minSpan;
}

void removeModelsByLifeSpan(Car **cars, int *carsCount) {
    int minSpan = findMinLifeSpan(*cars, *carsCount);
    for (int i = 0; i < *carsCount; i++) {
        int span = (*cars)[i].configurations[0].production_end_year - (*cars)[i].configurations[0].production_start_year;
        if (span == minSpan) {
            removeModelByIndex(cars, carsCount, i);
        }
    }
}
///int find_min_model(Car *cars, int carsCount) {
///    int minStartYear = INT_MAX;
///    int maxEndYear = INT_MIN;
///    // Находим минимальный и максимальный годы производства среди всех конфигураций
///    for (int i = 0; i < carsCount; i++) {
///        for (int j = 0; j < cars[i].configurations_count; j++) {
///            if (cars[i].configurations[j].production_start_year < minStartYear) {
///                minStartYear = cars[i].configurations[j].production_start_year;
///            }
///            if (cars[i].configurations[j].production_end_year > maxEndYear) {
///                maxEndYear = cars[i].configurations[j].production_end_year;
///            }
///        }
///    }
///    return maxEndYear - minStartYear;
///}
///void kill_model(Car** cars, int* carsCount) {
///    int minSpan = find_min_model(*cars, *carsCount);
///    for (int i = 0; i < *carsCount; i++) {
///        int span = (*cars)[i].configurations[0].production_end_year - (*cars)[i].configurations[0].production_start_year;
///        if (span == minSpan) {
///            removeModelByIndex(cars, carsCount, i);
///        }
///    }
///}
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

void kill_model(Car **cars, int *carsCount) {
    int *lifeSpans = find_life_spans(*cars, *carsCount);
    if (lifeSpans == NULL) {
        return;
    }
    int minSpan = INT_MAX;
    for (int i = 0; i < *carsCount; i++) {
        if (lifeSpans[i] < minSpan) {
            minSpan = lifeSpans[i];
       //     printf("minSpan = %d\n", minSpan);
        }
    }
	printf("finally minSpan = %d\n", minSpan);
    for (int i = (*carsCount) - 1; i >= 0; i--) {
        if (lifeSpans[i] == minSpan) {
            removeModelByIndex(cars, carsCount, i);
            //lifeSpans = realloc((*carsCount) * sizeof(int))
        }
    }
    free(lifeSpans);
}

