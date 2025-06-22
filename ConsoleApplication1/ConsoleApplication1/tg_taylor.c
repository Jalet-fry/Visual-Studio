#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <corecrt_math_defines.h>

// Функция для вычисления факториала
unsigned long long factorial(int n)
{
	int i;
	unsigned long long f = 1;
	for (i = 1; i <= n; i++)
	{
		f *= i;
		//    printf("i=%d  f=%d\n",i,f);
	}
	return f;
}

// Функция для вычисления биномиального коэффициента
unsigned long long binomial(int n, int k)
{
	int i;
	unsigned long long res = 1;
	if (k > n - k)
	{
		k = n - k;
	}
	for (i = 0; i < k; i++)
	{
		res *= (n - i);
		res /= (i + 1);
	}
	return res;
}

// Функция для возвращения массива чисел Бернулли размера n
double *bernoulli(int n)
{
	int i, k;
	// Выделяем память для массива
	double *result = malloc(n * sizeof(double));
	if (result == NULL)
	{
		printf("Ошибка выделения памяти\n");
		return NULL;
	}
	// Задаем начальное значение
	result[0] = 1.0;
	// Вычисляем остальные значения по рекуррентной формуле
	for (i = 1; i < n; i++)
	{
		result[i] = 0.0;
		for (k = 0; k < i; k++)
		{
			result[i] -= binomial(i + 1, k) * result[k] / (i + 1);
		}
	}
	// Возвращаем массив
	return result;
}

// Функция для вывода массива на экран
void print_array(double *array, int n)
{
	int i;
	printf("[");
	for (i = 0; i < n; i++)
	{
		printf("%.2f", array[i]);
		if (i < n - 1)
		{
			printf(", ");
		}
	}
	printf("]\n");
}

// Пример использования функции
int taylor()
{
	double x, tg = 0;
	printf("Введите в градусах x: ");
	scanf_s("%lf", &x,sizeof(x));
	int end=10,b = 2*end+1, fac = 6, n;
	x = x * M_PI / 180;
	double *array = bernoulli(b);
	print_array(array, b);
	for (n = 1; n < end; n++)
	{
		tg += pow(-1, n + 1) * pow(2, 2 * n) * (pow(2, 2 * n) - 1) * array[2 * n] * pow(x, 2 * n - 1) / factorial(2 * n);
		printf("n=%d;array[%d]=|%lf| \n", n, 2 * n, array[2 * n]);
	}
	if (fmod(x, M_PI / 2) == 0 && fmod(x / (M_PI / 2), 2) != 0)
	{
		printf("tangens не определен \n");
	}
	else
	{
		printf("tangens=%lf \n", tg);
	}
	//print_array(array, b);
	free(array); // Освобождаем память
	return 0;
}
