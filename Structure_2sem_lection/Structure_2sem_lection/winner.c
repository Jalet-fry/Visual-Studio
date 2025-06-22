#include <stdio.h>
#include <locale.h>
#include <uchar.h>
int main(void) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    char16_t english[] = u"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char16_t russian[] = u"абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ 123?!";
    printf("English:\n");
    for (int x = 0; x < sizeof(english) / sizeof(char16_t); x++) {
        printf("%lc = %d\n", english[x], english[x]);
    }
    printf("Russian:\n");
    for (int x = 0; x < sizeof(russian) / sizeof(char16_t); x++) {
        printf("%lc = %d\n", russian[x], russian[x]);
    }
    return 0;
}
