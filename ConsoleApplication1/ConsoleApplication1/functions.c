#include "functions.h"
#include <Windows.h>

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
}

void coordinate() {
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
    printf("Гипотенуза=%.2lf \nПлощадь=%.2lf \n", c, S);
}

void comparison() {
    int a, b, c;
    printf("Введите числа a, b и c: ");
    scanf("%d %d %d", &a, &b, &c);
    
    if (a == b || a == c || b == c) {
        printf("Среди чисел %d %d %d есть равные числа\n", a, b, c);
    }
    else { 
        printf("Среди чисел %d %d %d нет равных чисел\n", a, b, c); 
    }
}

void test() {
    double x;
    printf("Введите угол в градусах: ");
    scanf("%lf", &x);
    
    x = x * 3.14 / 180;
    double sin_val = 0, cos_val = 0;
    int end = 10;
    
    for(int n = 0; n < end; n++) {
        sin_val += (pow(-1, n) * pow(x, 2*n + 1) / factorial_test(2*n + 1));
        cos_val += (pow(-1, n) * pow(x, 2*n) / factorial_test(2*n));
        printf("sin=%lf \n", sin_val);
        printf("cos=%lf \n", cos_val);
    }
    
    printf("Итоговый sin=%lf \n", sin_val);
    printf("Итоговый cos=%lf \n", cos_val);
    printf("tangens=%lf \n", sin_val / cos_val);
}

int factorial_test(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

void run_main_menu() {
    char welcome[600] = "Приветствуем вас! Выберите функцию:\n"
        "-1) sos/help/h - инструкция\n"
        "0) exit/0 - выход\n"
        "1) comparison - сравнение 3 чисел\n"
        "2) solve - гипотенуза и площадь треугольника\n"
        "3) coordinate - расстояние до начала координат\n"
        "4) report - форма сдачи предмета\n"
        "5) test - вычисление sin/cos/tg\n";
    
    printf("%s", welcome);
    
    while (1) {
        printf("Вызов функции: ");
        char choice[20];
        scanf("%s", choice);
        
        if (strcmp(choice, "exit") == 0 || strcmp(choice, "0") == 0) {
            printf("До свидания!\n");
            break;
        }
        else if (strcmp(choice, "comparison") == 0 || strcmp(choice, "1") == 0) {
            comparison();
        }
        else if (strcmp(choice, "sos") == 0 || strcmp(choice, "help") == 0 || 
                 strcmp(choice, "h") == 0 || strcmp(choice, "-1") == 0) {
            printf("\n**************\n%s", welcome);
        }
        else if (strcmp(choice, "solve") == 0 || strcmp(choice, "2") == 0) {
            solve();
        }
        else if (strcmp(choice, "coordinate") == 0 || strcmp(choice, "3") == 0) {
            coordinate();
        }
        else if (strcmp(choice, "report") == 0 || strcmp(choice, "4") == 0) {
            report();
        }
        else if (strcmp(choice, "test") == 0 || strcmp(choice, "5") == 0) {
            test();
        }
        else {
            printf("Неизвестная команда: %s\n", choice);
        }
    }
}