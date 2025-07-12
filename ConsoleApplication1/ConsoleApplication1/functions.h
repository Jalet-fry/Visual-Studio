#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

// Объявления функций
double distance(double x, double y);
void report();
void coordinate();
void solve();
void comparison();
void test();  // Добавил объявление функции test() из test.c

// Главное меню
void run_main_menu();

#endif