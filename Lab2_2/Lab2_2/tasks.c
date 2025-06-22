#include "header.h"
void task1(char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 2;
    }
    int num, max;
    char str[100], *endptr;
    max = INT_MIN;
    while (fscanf(file, "%s", str) != EOF) {
        num = strtol(str, &endptr, 0);
        if (*endptr == '\0') {
            if (num > max) {
                max = num;
            }
        }
    }
    fclose(file);
    printf("The maximum number in the file is %d\n", max);
}
void task2(char *filename) {
    int max = INT_MIN, min = INT_MAX;
    FILE *readFile, *tempFile;

    readFile = fopen(filename, "r");
    if (readFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    tempFile = tmpfile();
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(readFile);
        return;
    }

    findMaxMin(readFile, &max, &min);
    rewind(readFile);
    replaceMaxMinInFile(readFile, tempFile, max, min);

    fclose(readFile);
    readFile = fopen(filename, "w");
    if (readFile == NULL) {
        printf("Error opening file.\n");
        fclose(tempFile);
        return;
    }

    rewind(tempFile);
    copyFileContent(tempFile, readFile);

    fclose(tempFile);
    fclose(readFile);
    printf("The maximum and minimum numbers have been swapped and saved to the original file.\n");
}

void findMaxMin(FILE *file, int *max, int *min) {
    char buffer[1024], word[256], *endptr;
    int num;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (buffer[0] == '\n') continue; // Пропускаем пустые строки
        char *ptr = buffer;
        while (sscanf(ptr, "%s", word) == 1) {
            ptr += strlen(word) + 1;
            if (strspn(word, "-0123456789") == strlen(word)) {
                num = strtol(word, &endptr, 10);
                if (word != endptr) {
                    if (num > *max) *max = num;
                    if (num < *min) *min = num;
                }
            }
        }
    }
}

void replaceMaxMinInFile(FILE *readFile, FILE *tempFile, int max, int min) {
    char buffer[1024], word[256], *endptr;
    int num;

    while (fgets(buffer, sizeof(buffer), readFile) != NULL) {
        if (buffer[0] == '\n') {
            fputs("\n", tempFile); // Сохраняем пустые строки
            continue;
        }
        char *ptr = buffer;
        while (sscanf(ptr, "%s", word) == 1) {
            ptr += strlen(word) + (ptr[strlen(word)] == '\0' ? 0 : 1);
            if (strspn(word, "-0123456789") == strlen(word)) {
                num = strtol(word, &endptr, 10);
                if (word != endptr) {
                    if (num == max) {
                        fprintf(tempFile, "%d ", min);
                    } else if (num == min) {
                        fprintf(tempFile, "%d ", max);
                    } else {
                        fprintf(tempFile, "%d ", num);
                    }
                }
            } else {
                fprintf(tempFile, "%s ", word);
            }
        }
        fprintf(tempFile, "\n");
    }
}

void copyFileContent(FILE *source, FILE *destination) {
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), source) != NULL) {
        fputs(buffer, destination);
    }
}

