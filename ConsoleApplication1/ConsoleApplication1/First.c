#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <tgmath.h>
#include <stdio.h>
#include <math.h>

// Функция для вычисления расстояния от точки до начала координат
double distance(double x, double y) {
    return sqrt(x * x + y * y);
}

void report() {
    char discipline[255];
    printf("Доступные дисциплины\n0)Возврат к функциям\n1)Информатика\n2)Культурология\n3)Математика\n4)Иностранный язык\n5)Экономика\nВведите название дисциплины:");
    scanf("%s", discipline);
    if (strcmp(discipline, "Информатика") == 0 || strcmp(discipline, "1") == 0) {
        printf("Отчетность по дисциплине %s: экзамен, зачет\n", discipline);
    }
    else if (strcmp(discipline, "возврат") == 0 || strcmp(discipline, "0") == 0 || strcmp(discipline, "Возврат") == 0) {
        printf("Возврат к функциям осуществлен\n");
        return;
    }
    else if (strcmp(discipline, "Культурология") == 0 || strcmp(discipline, "2") == 0) {
        printf("Отчетность по дисциплине %s: зачет\n", discipline);
    }
    else if (strcmp(discipline, "Математика") == 0 || strcmp(discipline, "3") == 0) {
        printf("Отчетность по дисциплине %s: экзамен, зачет\n", discipline);
    }
    else if (strcmp(discipline, "Иностранный язык") == 0 || strcmp(discipline, "4") == 0) {
        printf("Отчетность по дисциплине %s: экзамен, зачет\n", discipline);
    }
    else if (strcmp(discipline, "Экономика") == 0 || strcmp(discipline, "5") == 0) {
        printf("Отчетность по дисциплине %s: экзамен\n", discipline);
    }
    else {
        printf("Дисциплина %s не найдена в списке\n", discipline);
    }
    printf("");
}

void  coordinate() {
    double x1, y1, x2, y2, x3, y3;
    printf("Введите координаты точки A (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Введите координаты точки B (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);
    printf("Введите координаты точки C (x3, y3): ");
    scanf("%lf %lf", &x3, &y3);
    double d1 = distance(x1, y1);
    double d2 = distance(x2, y2);
    double d3 = distance(x3, y3);
    if (d1 <= d2 && d1 <= d3) {
        printf("Точка A (%.2f, %.2f) ближе всего к началу координат\n", x1, y1);
    }
    else if (d2 <= d1 && d2 <= d3) {
        printf("Точка B (%.2f, %.2f) ближе всего к началу координат\n", x2, y2);
    }
    else {
        printf("Точка C (%.2f, %.2f) ближе всего к началу координат\n", x3, y3);
    }
}

void solve() {
    double a, b, c, S;
    printf("Введите катеты прямоугольного треугольника:\n");
    scanf("%lf %lf", &a, &b);
    c = sqrt(a * a + b * b);
    S = 0.5 * a * b;
    printf("Гипотенуза=%.2lf \n Площадь=%.2lf \n", c, S);
}
void comparison() {
    int a, b, c;
    printf("Введите числа a,b и c:");
    scanf("%d %d %d", &a, &b, &c);
    if (a == b || a == c || b == c) {
        printf("Среди чисел %d %d %d есть равные чисел\n", a, b, c);
    }
    else { printf("Среди чисел %d %d %d нету равных чисел\n", a, b, c); }
}
int main() {
 //   SetConsoleOutputCP(1251);
 //   SetConsoleCP(1251);
    char welcome[600] = "Привествуем вас,выберите функции:\n"
        "-1)sos or help or h = инструкция для вас\n"
        "0)exit или 0 = выход\n"
        "1)comprarison = Сравнение 3-х чисел\n"
        "2)solve=найди гипотенузу и площадь треугольника по катетам\n"
        "3)coordinate=вычислим кратчайшее расстояние до начала координат\n"
        "4)report= Форма сдачи предмета\n";
    printf("%s", welcome);
    // Бесконечный цикл
    while (1) {
        printf("Вызов функции:");
        char choice[20];// Строка для хранения выбора пользователя
        scanf("%s", choice);
        if (strcmp(choice, "exit") == 0 || !strcmp(choice, "0")) {
            printf("С вами была компания NOmicrosoft, До Новых Встреч!\n");
            printf("%s", choice);
            break; // Выход из цикла
        }
        else if (strcmp(choice, "comprarison") == 0 || strcmp(choice, "1") == 0) {
            comparison();
        }
        else if (strcmp(choice, "sos") == 0 || strcmp(choice, "help") == 0 || strcmp(choice, "h") == 0 || strcmp(choice, "-1") == 0) {
            printf("\n**************\n%s", welcome);
        }
        else if (strcmp(choice, "solve") == 0 || !strcmp(choice, "2")) {
            solve();
        }
        else if (strcmp(choice, "coordinate") == 0 || !strcmp(choice, "3")) {
            coordinate();
        }
        else if (strcmp(choice, "report") == 0 || !strcmp(choice, "4")) {
            report();
        }
        else { printf("%s", choice); }
    }
}
