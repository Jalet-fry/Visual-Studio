#include "header.h"
void task1(char* filename, char method) {
    int limit, max_length;
    if (doom(filename, method)) {
        int first[] = { 9, 8, 7, 6, 5, 6, 7, 9, 8};
        int size = sizeof(first) / sizeof(first[0]);
        fill(filename, first, size);
        printing_file(filename);
        limit = 38;
        max_length = Max_length(filename, limit);
    }
    else {
        FILE* f = fopen(filename, "rb");
		if (f == NULL) {
			printf("Не удалось открыть файл %s\n", filename);
			return 2;
		}
        assert(!fseek(f, 0, SEEK_END));
        limit = correct("Введите предел суммы:");
        max_length = Max_length(filename,limit);
        printing_file(filename);
    }
    printf("Максимальная длина подмассива с суммой не более %d равна %d\n", limit, max_length);
}

void task2(char* filename, char method){
    if (doom(filename, method)) {
        int second[] = { 20, 15, 16, 13, -13, 24, 15, -18 };
        int size_second = sizeof(second) / sizeof(second[0]);
        fill(filename, second, size_second);
        printing_file(filename);
    }
    zeroing(filename);
    printing_file(filename);
}

void task3(char* filename, char method) {
    if (doom(filename, method)) {
        int third[] = { 0, 15, 16, -13, -13, 25, 27, -27, 20 };
        int size_third = sizeof(third) / sizeof(third[0]);
        fill(filename, third, size_third);
        printing_file(filename);
    }
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Не удалось открыть файл %s\n", filename);
        return;
    }
    fclose(f);
    sort(filename);
    printf("Уже отсортировали тебя мы:\n");
    printing_file(filename);
}

int Max_length(char* filename,int limit) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Не удалось открыть файл %s\n", filename);
        return 2;
    }
    assert(!fseek(fp, 0, SEEK_END));
    int ending = ftell(fp)/ sizeof(int);
    assert(!fseek(fp, 0, SEEK_SET));
    int max_length = 0, curr_length = 0, curr_sum = 0, elem = 0;
    for (int i = 0; i < ending; i++) {
        assert(fread(&elem, sizeof(int), 1, fp));
        curr_sum += elem;
        curr_length++;
        while (curr_sum > limit) {
            assert(!fseek(fp, -curr_length * sizeof(int), SEEK_CUR));
            assert(fread(&elem, sizeof(int), 1, fp));
            curr_sum -= elem;
            curr_length--;
            assert(!fseek(fp, curr_length * sizeof(int), SEEK_CUR));
        }
        if (curr_length > max_length) {
            max_length = curr_length;
        }
    }
    fclose(fp);
    return max_length;
}

int zeroing(char* filename) {
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL) {
        return -1;
    }
    assert(!fseek(fp, 0, SEEK_END));
    long size = ftell(fp);
    int n = size / sizeof(int), zero = 0, curr, prev;
    for (int i = n - 1; i >= 0; i--) {
        int offset = i * sizeof(int);
        assert(!fseek(fp, offset, SEEK_SET));
        assert(fread(&curr, sizeof(int), 1, fp));
        if (i > 0) {
            assert(!fseek(fp, offset - sizeof(int), SEEK_SET));
            assert(fread(&prev, sizeof(int), 1, fp));
            if (curr < prev) {
                curr = zero;
            }
        }
        assert(!fseek(fp, offset, SEEK_SET));
        assert(fwrite(&curr, sizeof(int), 1, fp));
    }
    fclose(fp);
    return 0;
}

void sort (char* filename){
    FILE *file = fopen(filename, "rb+");
    assert(!fseek(file, 0, SEEK_END));
    //long size = ftell(file);
    int ending = ftell(file) / sizeof(int);
    assert(!fseek(file, 0, SEEK_SET));
    int mid = (ending % 2) ? ending / 2  : ending / 2 - 1, moving = 0, min_index = 0,buffer;
    for (int i = 0; i < ending - 1; i++) {
        int min_index = 0, min_value;
        int first_end = (moving >= 0) ? mid - moving + 1 : mid + moving + 1;
        int second_start = (moving > 0) ? mid + moving : mid - moving + 1;
        assert(fread(&min_value, sizeof(min_value), 1, file));
        for (int j = 1; j < ending; j++) {
            if(j == first_end){
                j = second_start;
                assert(!fseek(file, j * sizeof(min_value), SEEK_SET));
            }
            assert(fread(&buffer, sizeof(int), 1, file));
            if (min_value > buffer) {
                min_index = j;
                min_value = buffer;
            }
        }
        swap(file, mid + moving, min_index);
        assert(!fseek(file, 0, SEEK_SET));
        moving *= -1;
        if (moving >= 0) { moving += 1; }
    }
    fclose(file);
}
