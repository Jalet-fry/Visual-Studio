///jidjsjfidhijd#include "header.h"
///jidjsjfidhijdvoid task1(char* filename, char method) {
///jidjsjfidhijd    int limit, max_length;
///jidjsjfidhijd    if (doom(filename, method)) {
///jidjsjfidhijd        int first[] = { 9, 8, 7, 6, 5, 6, 7, 9, 8};
///jidjsjfidhijd        int size = sizeof(first) / sizeof(first[0]);
///jidjsjfidhijd        fill(filename, first, size);
///jidjsjfidhijd        printing_file(filename);
///jidjsjfidhijd        limit = 38;
///jidjsjfidhijd        max_length = Max_length(filename, size, limit);
///jidjsjfidhijd    }
///jidjsjfidhijd    else {
///jidjsjfidhijd        FILE* f = fopen(filename, "rb");
///jidjsjfidhijd		if (f == NULL) {
///jidjsjfidhijd			printf("Не удалось открыть файл %s\n", filename);
///jidjsjfidhijd			return 2;
///jidjsjfidhijd		}
///jidjsjfidhijd        assert(!fseek(f, 0, SEEK_END));
///jidjsjfidhijd        limit = correct("Введите предел суммы:");
///jidjsjfidhijd        max_length = Max_length(filename, ftell(f) / 4, limit);
///jidjsjfidhijd        printing_file(filename);
///jidjsjfidhijd    }
///jidjsjfidhijd    printf("Максимальная длина подмассива с суммой не более %d равна %d\n", limit, max_length);
///jidjsjfidhijd}
///jidjsjfidhijd
///jidjsjfidhijdvoid task2(char* filename, char method){
///jidjsjfidhijd    if (doom(filename, method)) {
///jidjsjfidhijd        int second[] = { 20, 15, 16, 13, -13, 24, 15, -18 };
///jidjsjfidhijd        int size_second = sizeof(second) / sizeof(second[0]);
///jidjsjfidhijd        fill(filename, second, size_second);
///jidjsjfidhijd        printing_file(filename);
///jidjsjfidhijd    }
///jidjsjfidhijd    zeroing(filename);
///jidjsjfidhijd    printing_file(filename);
///jidjsjfidhijd}
///jidjsjfidhijd
///jidjsjfidhijdvoid task3(char* filename, char method) {
///jidjsjfidhijd    if (doom(filename, method)) {
///jidjsjfidhijd        int third[] = { 0, 15, 16, -13, -13, 25, 27, -27, 20 };
///jidjsjfidhijd        int size_third = sizeof(third) / sizeof(third[0]);
///jidjsjfidhijd        fill(filename, third, size_third);
///jidjsjfidhijd        printing_file(filename);
///jidjsjfidhijd    }
///jidjsjfidhijd    FILE* f = fopen(filename, "rb");
///jidjsjfidhijd    if (f == NULL) {
///jidjsjfidhijd        printf("Не удалось открыть файл %s\n", filename);
///jidjsjfidhijd        return;
///jidjsjfidhijd    }
///jidjsjfidhijd    assert(!fseek(f, 0, SEEK_END));
///jidjsjfidhijd    long size = ftell(f);
///jidjsjfidhijd    int count = size / 4;
///jidjsjfidhijd    fclose(f);
///jidjsjfidhijd    sort(filename, count);
///jidjsjfidhijd    printf("Уже отсортировали тебя мы:\n");
///jidjsjfidhijd    printing_file(filename);
///jidjsjfidhijd}
///jidjsjfidhijd
///jidjsjfidhijdint Max_length(char* filename, int n, int limit) {
///jidjsjfidhijd    FILE* fp = fopen(filename, "rb");
///jidjsjfidhijd    if (fp == NULL) {
///jidjsjfidhijd        printf("Не удалось открыть файл %s\n", filename);
///jidjsjfidhijd        return 2;
///jidjsjfidhijd    }
///jidjsjfidhijd    int max_length = 0, curr_length = 0, curr_sum = 0, elem = 0;
///jidjsjfidhijd    for (int i = 0; i < n; i++) {
///jidjsjfidhijd        assert(fread(&elem, sizeof(int), 1, fp));
///jidjsjfidhijd        curr_sum += elem;
///jidjsjfidhijd        curr_length++;
///jidjsjfidhijd        while (curr_sum > limit) {
///jidjsjfidhijd            assert(!fseek(fp, -curr_length * sizeof(int), SEEK_CUR));
///jidjsjfidhijd            assert(fread(&elem, sizeof(int), 1, fp));
///jidjsjfidhijd            curr_sum -= elem;
///jidjsjfidhijd            curr_length--;
///jidjsjfidhijd            assert(!fseek(fp, curr_length * sizeof(int), SEEK_CUR));
///jidjsjfidhijd        }
///jidjsjfidhijd        if (curr_length > max_length) {
///jidjsjfidhijd            max_length = curr_length;
///jidjsjfidhijd        }
///jidjsjfidhijd    }
///jidjsjfidhijd    fclose(fp);
///jidjsjfidhijd    return max_length;
///jidjsjfidhijd}
///jidjsjfidhijd
///jidjsjfidhijdint zeroing(char* filename) {
///jidjsjfidhijd    FILE* fp = fopen(filename, "rb+");
///jidjsjfidhijd    if (fp == NULL) {
///jidjsjfidhijd        return -1;
///jidjsjfidhijd    }
///jidjsjfidhijd    assert(!fseek(fp, 0, SEEK_END));
///jidjsjfidhijd    long size = ftell(fp);
///jidjsjfidhijd    int n = size / sizeof(int), zero = 0, curr, prev;
///jidjsjfidhijd    for (int i = n - 1; i >= 0; i--) {
///jidjsjfidhijd        int offset = i * sizeof(int);
///jidjsjfidhijd        assert(!fseek(fp, offset, SEEK_SET));
///jidjsjfidhijd        assert(fread(&curr, sizeof(int), 1, fp));
///jidjsjfidhijd        if (i > 0) {
///jidjsjfidhijd            assert(!fseek(fp, offset - sizeof(int), SEEK_SET));
///jidjsjfidhijd            assert(fread(&prev, sizeof(int), 1, fp));
///jidjsjfidhijd            if (curr < prev) {
///jidjsjfidhijd                curr = zero;
///jidjsjfidhijd            }
///jidjsjfidhijd        }
///jidjsjfidhijd        assert(!fseek(fp, offset, SEEK_SET));
///jidjsjfidhijd        assert(fwrite(&curr, sizeof(int), 1, fp));
///jidjsjfidhijd    }
///jidjsjfidhijd    fclose(fp);
///jidjsjfidhijd    return 0;
///jidjsjfidhijd}
///jidjsjfidhijd
///jidjsjfidhijdvoid sort (char* filename, int ending){
///jidjsjfidhijd    FILE *file = fopen(filename, "rb+");
///jidjsjfidhijd    int mid = (ending % 2) ? ending / 2  : ending / 2 - 1, moving = 0, min_index = 0,buffer;
///jidjsjfidhijd    for (int i = 0; i < ending - 1; i++) {
///jidjsjfidhijd        int min_index = 0, min_value;
///jidjsjfidhijd        int first_end = (moving >= 0) ? mid - moving + 1 : mid + moving + 1;
///jidjsjfidhijd        int second_start = (moving > 0) ? mid + moving : mid - moving + 1;
///jidjsjfidhijd        assert(fread(&min_value, sizeof(min_value), 1, file));
///jidjsjfidhijd        for (int j = 1; j < ending; j++) {
///jidjsjfidhijd            if(j == first_end){
///jidjsjfidhijd                j = second_start;
///jidjsjfidhijd                assert(!fseek(file, j * sizeof(min_value), SEEK_SET));
///jidjsjfidhijd            }
///jidjsjfidhijd            assert(fread(&buffer, sizeof(int), 1, file));
///jidjsjfidhijd            if (min_value > buffer) {
///jidjsjfidhijd                min_index = j;
///jidjsjfidhijd                min_value = buffer;
///jidjsjfidhijd            }
///jidjsjfidhijd        }
///jidjsjfidhijd        swap(file, mid + moving, min_index);
///jidjsjfidhijd        assert(!fseek(file, 0, SEEK_SET));
///jidjsjfidhijd        moving *= -1;
///jidjsjfidhijd        if (moving >= 0) { moving += 1; }
///jidjsjfidhijd    }
///jidjsjfidhijd    fclose(file);
///jidjsjfidhijd}
