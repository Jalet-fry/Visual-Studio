#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union {
    char* string_data;
    char** binary_data;
} FileData;

typedef struct {
    FileData data;
    int data_type; // 0 - строковое представление, 1 - двоичное представление
} FileInfo;

void setStringData(FileInfo* file_info, char* str);
void setBinaryData(FileInfo* file_info, char** binary_data, int num_bytes);
char* getStringData(FileInfo* file_info);
char** getBinaryData(FileInfo* file_info);
void freeFileInfo(FileInfo* file_info);
char* get_binary_code_char(char symbol);
char get_char_code(char* binary_code);
char* get_string_code(char** binary_codes, int num_bytes);

int how_much_bin(char** binary_data){
    int num_elements = 0;
    while (binary_data[num_elements] != NULL) {
        num_elements++;
    }
    return num_elements;
}
void setStringData(FileInfo* file_info, char* str) {
    if (file_info->data_type == 1) {
        // Если ранее были установлены двоичные данные, очищаем память
        for (int i = 0; file_info->data.binary_data[i]; i++) {
            free(file_info->data.binary_data[i]);
        }
        free(file_info->data.binary_data);
    }

    file_info->data.string_data = malloc(strlen(str) + 1);
    strcpy(file_info->data.string_data, str);
    file_info->data_type = 0;
}

void setBinaryData(FileInfo* file_info, char** binary_data, int num_bytes) {
    if (file_info->data_type == 0) {
        // Если ранее были установлены строковые данные, очищаем память
        free(file_info->data.string_data);
    }

    file_info->data.binary_data = malloc((num_bytes + 1) * sizeof(char*));
    for (int i = 0; i < num_bytes; i++) {
        file_info->data.binary_data[i] = malloc(strlen(binary_data[i]) + 1);
        strcpy(file_info->data.binary_data[i], binary_data[i]);
    }
    file_info->data.binary_data[num_bytes] = NULL; // Устанавливаем завершающий NULL-указатель
    file_info->data_type = 1;
}

char* getStringData(FileInfo* file_info) {
    if (file_info->data_type == 0) {
        return file_info->data.string_data;
    } else {

        return get_string_code(file_info->data.binary_data, how_much_bin(file_info->data.binary_data));
    }
}

char** getBinaryData(FileInfo* file_info) {
    if (file_info->data_type == 1) {
        return file_info->data.binary_data;
    } else {
        char* str = file_info->data.string_data;
        int num_bytes = strlen(str);
        char** binary_data = malloc((num_bytes + 1) * sizeof(char*));
        for (int i = 0; i < num_bytes; i++) {
            binary_data[i] = get_binary_code_char(str[i]);
        }
        binary_data[num_bytes] = NULL; // Устанавливаем завершающий NULL-указатель
        return binary_data;
    }
}

void freeFileInfo(FileInfo* file_info) {
    if (file_info->data_type == 0) {
        free(file_info->data.string_data);
    } else {
        char** binary_data = file_info->data.binary_data;
        for (int i = 0; binary_data[i]; i++) {
            free(binary_data[i]);
        }
        free(binary_data);
    }
}

char* get_binary_code_char(char symbol) {
    char* binaryCode = (char*)malloc(9); // 8 бит + завершающий нулевой символ
    if (binaryCode) {
        binaryCode[8] = '\0'; // Устанавливаем завершающий нулевой символ

        // Заполняем двоичный код символа
        for (int i = 7; i >= 0; --i) {
            binaryCode[i] = (symbol & 1) ? '1' : '0';
            symbol >>= 1;
        }
    }
    return binaryCode;
}

char get_char_code(char* binary_code) {
    return (char)strtol(binary_code, NULL, 2);
}

char* get_string_code(char** binary_codes, int num_bytes) {
    char* result = (char*)malloc(num_bytes + 1); // +1 для завершающего нулевого символа
    if (result) {
        for (int i = 0; i < num_bytes; i++) {
            result[i] = get_char_code(binary_codes[i]);
        }
        result[num_bytes] = '\0'; // Завершающий нулевой символ
    }
    return result;
}

void changeDataType(FileInfo* file_info, int new_type) {
    if (file_info->data_type == new_type) {
        return; // Ничего не делаем, если типы данных уже совпадают
    }

    if (new_type == 0) { // Меняем на строковое представление
        char* str = getStringData(file_info);
        setStringData(file_info, str);
        free(str);
    } else { // Меняем на двоичное представление
        char** binary_data = getBinaryData(file_info);
        setBinaryData(file_info, binary_data, how_much_bin(binary_data)); 
        // Освобождаем память, занятую двоичными данными
        for (int i = 0; binary_data[i]; i++) {
            free(binary_data[i]);
        }
        free(binary_data);
    }
}
int main() {
    FileInfo file_info;
    setStringData(&file_info, "ABCD");
    printf("String data: %s\n", getStringData(&file_info));

    // Установка двоичных данных
    char* binary_data[] = {"01000001", "01000010", "01000011", "01000100", NULL};
    setBinaryData(&file_info, binary_data, how_much_bin(binary_data));
    char** binary_data_read = getBinaryData(&file_info);
    printf("Binary data: ");
    for (int i = 0; binary_data_read[i]; i++) {
        printf("%s ", binary_data_read[i]);
    }
    printf("\n");

    // Изменение типа данных
    changeDataType(&file_info, 0); // Меняем на строковое представление
    printf("String data: %s\n", getStringData(&file_info));
    changeDataType(&file_info, 1); // Меняем на строковое представление
    for (int i = 0; file_info.data.binary_data[i]; i++) {
        printf("%s ", file_info.data.binary_data[i]);
    }

    // Освобождение памяти
    freeFileInfo(&file_info);

    return 0;