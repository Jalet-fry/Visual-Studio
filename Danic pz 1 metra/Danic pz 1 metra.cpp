// Danic pz 1 metra.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::nothrow;

bool check_number_input();
bool check_int_input(float input);
float get_value();
int get_int_value();
int get_array_length();
void create_empty_array(int** array, int array_length);
void fill_array(int* array, int array_length);
void print_array(int* array, int array_length);
double find_arithmetic_mean_of_squares(int* array, int array_length);

//Код файла Realisation.cpp

//#include "Prototypes.h"
bool check_number_input()//Проверка, что введено число
{
	if (cin.fail() == true)//Проверка, произошла ли ошибка ввода
	{
		cout << "Вы ввели не число, попробуйте ещё раз" << endl;//Вывод сообщения о некорректном вводе
		cin.clear();//Установка состояния по умолчанию
		cin.ignore(35000, '\n');//Игнорирование всех символов до перевода строки
		return false;//Возвращаем false, т.е произошла ошибка ввода
	}
	else
	{
		return true;//Возвращаем true, т.е ошибки ввода не произошло
	}
}
bool check_int_input(float input)//Проверка, что введено целое число
{
	if (((input - (int)input)) == 0)//Проверка разности 
	{
		return true;//Возвращаем true, т.е введённое число целое
	}
	else
	{
		cout << "Вы ввели не целое число, попробуйте ещё раз" << endl;//Вывод сообщения о некорректном вводе
		return false;//Возвращаем false, т.е введённое число не целое
	}
}
float get_value()//Получение числа
{
	float value;
	while (true)//Пока не будет получено число, работает цикл
	{
		cin >> value;
		if (check_number_input() == false)//Проверка, введено ли число
		{
			continue;//Если число не получено, попытка снова
		}
		else
		{
			break;//Если число получено, выход из цикла
		}
	}
	return value;//Возвращаем введённое число
}
int get_int_value()//Получение целого числа
{
	float value;
	while (true)//Пока не будет получено целое число, работает цикл 
	{
		value = get_value();//Получение числа
		if (check_int_input(value) == true)//Проверка, введедо ли целое число
		{
			break;//Если целое число получено, выход из цикла
		}
		else
		{
			cin.clear();//Очищаем буфер ошибок
			cin.ignore(35000, '\n');//Пропускаем символы в буфере ввода
			continue;//Если целое число не получено, попытка снова
		}
	}
	return value;//Возвращаем введённое число
}
int get_array_length()//Получение значения длины массива
{
	int N;//Переменная, отвечающая за длину массива
	cout << "Введите длину целочисленного массива. Границы: [0;100]" << endl;//Просьба ввести длину массива
	while (true)//Пока не будет получена длина, работает цикл
	{
		N = get_int_value();//Получение целого числа
		if (N > 100 || N < 0)//Проверка значения на соответствие границам
		{
			cout << "Длина выходит за границы, попробуйте снова" << endl;//Вывод сообщения о некорректном вводе 
			continue;//Если значение выходит за границы, попытка снова
		}
		else
		{
			break;//Если значение находится в границах, выход из цикла
		}
	}
	return N;//Возвращаем введённую длину массива
}
void create_empty_array(int** array,int array_length)//Создание пустого массива
{
	*array = new int[array_length];//Выделение динамической памяти
	if (*array == nullptr && array_length != 0)//Проверка выделения памяти
	{
		cout << "Ошибка выделения памяти под массив. Окончание работы программы" << endl;//Вывод сообщения об ошибке выделения памяти
		exit(-1);//Если память не была выделена, выход из программы
	}
	else
	{
		return;//Если память была выделена, выход из функции
	}
}
void fill_array(int* array,int array_length)//Заполнение пустого массива значениями
{
	for (int i = 0; i < array_length; i++)
	{
		cout << "Введите " << i + 1 << "-й элемент" << endl;//Просьба ввести i+1-ый элемент массива
		*(array + i) = get_int_value();//Получение значение i-го элемента
	}
}
void print_array(int* array, int array_length)//Вывод массива на экран
{
	cout << "Ваш массив:" << endl;//Оповещение, что выводятся элементы массива
	for (int i = 0; i < array_length; i++)
	{
		cout << *(array + i) << " ";//Вывод элементов массива
	}
	cout << endl;//Перевод строки
}
double find_arithmetic_mean_of_squares(int* array, int array_length)//Поиск среднего арифметического квадратов элементов массива
{
	double arithmetic_mean_of_squares = 0.0;//Переменная, отвечающая за среднее арифметическое квадратов элементов массива
	for (int i = 0; i < array_length; i++)
	{
		arithmetic_mean_of_squares += pow(*(array + i), 2) / array_length;//Возведение элемента массива в квадрат и деление на длину массива
	}
	return arithmetic_mean_of_squares;//Возвращаем найденное значение
}

//Код файла main.cpp

//#include "Prototypes.h"
int main()
{
	setlocale(LC_ALL, "Russian");//Установка русской локализации программы
	int N;//Длина массива
	int* array;//Указатель, т.е массив
	double arithmetic_mean_of_squares = 0;//Среднее арифметическое
	N = get_array_length();//Получение значения длины массива
	create_empty_array(&array, N);//Создание пустого массива из N элементов
	fill_array(array, N);//Заполнение массива
	print_array(array, N);//Вывод массива 
	arithmetic_mean_of_squares = find_arithmetic_mean_of_squares(array, N);//Поиск среднего арифметического квадратов элементов массива
	cout << "Искомое значение = " << arithmetic_mean_of_squares << endl;//Оповещение, что выводится искомое значение
	delete[] array;//Очистка динамической памяти
	array = nullptr;//Обнуление указателя
	cout << "Завершение работы" << endl;//Оповещение, что работа программы завершается
	return 0;//Возвращаем 0, т.е ошибок в работе программы не случилось  
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
