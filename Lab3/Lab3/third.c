#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#define N 100 // максимальный размер массива
extern void print_array();
extern void massive();

void parr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i * n + j]);
        }
    }
}
//Проверка адекватности ввода
double correct(char* c) {
    char input[100]; // массив для хранения ввода пользователя
    int valid = 0; // флаг для проверки корректности ввода
    double num; // переменная для хранения числа типа double
    valid = 0; // сбрасываем флаг корректности ввода
    while (!valid) // пока ввод некорректен
    {
        printf("%s\n",c); // выводим приглашение с обывательской нумерацией
        __try // начинаем защищенный раздел кода
        {
            scanf_s("%s", input, sizeof(input)); // считываем ввод пользователя
            fflush(stdin);
                num = atof(input); // преобразуем строку в число типа double
                if (num == 0 && strcmp(input, "0") != 0) // если число равно нулю, но строка не равна "0"
                {
                    printf("Это не число.Попробуйте еще раз.\n"); // выводим сообщение об ошибке
                }
                else // иначе
                {
                    valid = 1; // устанавливаем флаг корректности ввода
                    printf("Вы ввели число: %.2f\n", num); // выводим сообщение об успехе
                }
            }
            __except (1) // если произошло исключение
            {
                printf("Произошла ошибка при чтении или преобразовании ввода. Попробуйте еще раз.\n"); // выводим сообщение об ошибке
            }
        }
    return num;
}
//1_11_1:функция для подсчета количества элементов массива, лежащих в диапазоне от a до b
int count_elements_in_range(double *arr, int n, double a, double b) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= a && arr[i] <= b) {
            count++;
        }
    }
    return count;
}

// 1_11_2:функции для подсчета суммы элементов массива, расположенных после последнего максимального элемента
// функция для нахождения индекса последнего максимального элемента массива
int find_last_max_index(double *arr, int n) {
    int max_index = 0;
    double max_value = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] >= max_value) {
            max_value = arr[i];
            max_index = i;
        }
    }
    return max_index;
}
double sum_elements_after_last_max(double *arr, int n) {
    double sum = 0.0;
    int last_max_index = find_last_max_index(arr, n);
    for (int i = last_max_index+1; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}


// 2_2:после каждого четного элемента вставить 0
void even(double* arr, int n)
{
    // Объявляем переменную k, которая будет хранить количество вставленных нулей, и присваиваем ей значение 0
    int k = 0;

    // Объявляем переменные i и j, которые будут использоваться для индексации массива
    int i, j;

    // Проходим по массиву с помощью цикла for от 0 до n + k - 1
    for (i = 0; i < n + k; i++)
    {
        // Если текущий элемент массива четный, то выполняем следующие действия:
        if ((int)arr[i] % 2 == 0)
        {
            // Увеличиваем k на 1
            k++;

            // Сдвигаем все элементы массива, начиная с i + 1 до size + k - 1, на одну позицию вправо с помощью цикла for от конца к началу
            for (j = n + k - 1; j > i + 1; j--)
            {
                // Присваиваем каждому элементу значение предыдущего элемента
                arr[j] = arr[j - 1];
            }

            // Вставляем 0 на позицию i + 1
            arr[i + 1] = 0;

            // Увеличиваем i на 1, чтобы пропустить вставленный ноль
            i++;
        }
    }
    printf("Новый ");
    print_array(arr, n + k);
}

// Функция, которая возвращает наиболее редко встречающееся нечетное число в массиве
double find_rarest_odd(double arr[], int n) {
    // Переменные для хранения текущего и наименее частого нечетного числа и их частот
    int current, rarest, freq, min_freq;
    // Инициализация переменных
    current = rarest = 0;
    freq = min_freq = INT_MAX;
    // Сортировка массива по возрастанию
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // Проход по отсортированному массиву
    for (int i = 0; i < n; i++) {
        // Если текущий элемент нечетный
        if ((int)arr[i] % 2 != 0) {
            // Если он равен предыдущему, увеличиваем частоту
            if (arr[i] == current) {
                freq++;
            }
            // Иначе, обновляем текущий элемент и его частоту
            else {
                current = arr[i];
                freq = 1;
            }
            // Если частота текущего элемента меньше минимальной частоты
            if (freq < min_freq) {
                // Обновляем наименее частое нечетное число и его частоту
                rarest = current;
                min_freq = freq;
            }
        }
    }
    // Возвращаем наименее частое нечетное число
    return rarest;
}

//3.11:2 способ
// Функция для разделения массива на две части по опорному элементу
int partition(double arr[], int low, int high) {
    // Выбираем последний элемент в качестве опорного
    double pivot = arr[high];
    // Инициализируем индекс для разделения
    int i = low - 1;
    // Проходим по массиву от low до high - 1
    for (int j = low; j < high; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            // Увеличиваем индекс разделения
            i++;
            // Меняем местами элементы i и j
            double temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Меняем местами элементы i + 1 и high (опорный)
    double temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    // Возвращаем индекс разделения
    return i + 1;
}
// Функция для быстрой сортировки массива
void quick_sort(double arr[], int low, int high) {
    // Если low меньше high
    if (low < high) {
        // Находим индекс разделения
        int severance = partition(arr, low, high);
        // Рекурсивно сортируем левую и правую часть относительно разделения
        quick_sort(arr, low, severance - 1);
        quick_sort(arr, severance + 1, high);
    }
}
// Функция для поиска наиболее редкого нечетного числа в массиве
double find_rarest_number(double arr[], int n) {
    // Переменные для хранения наиболее редкого нечетного числа и его частоты
    double rarest_odd = 0;
    int rarest_freq = INT_MAX;
    // Сортируем массив по возрастанию с помощью быстрой сортировки
    quick_sort(arr, 0, n - 1);
    // Проходим по отсортированному массиву
    for (int i = 0; i < n; i++) {
        // Если текущий элемент нечетный
        if ((int)arr[i] % 2 != 0) {
            // Создадим переменные для хранения текущего нечетного числа и его частоты
            double current_odd = arr[i];
            int current_freq = 1;
            // Пока следующий элемент равен текущему, увеличиваем частоту и индекс
            while (i + 1 < n && arr[i + 1] == current_odd) {
                current_freq++;
                i++;
            }
            // Если частота текущего нечетного числа меньше частоты наиболее редкого нечетного числа
            if (current_freq < rarest_freq) {
                // Обновляем наиболее редкое нечетное число и его частоту
                rarest_odd = current_odd;
                rarest_freq = current_freq;
            }
        }
    }
    // Возвращаем наиболее редкое нечетное число или ноль, если такого числа нет
    return rarest_odd;
}




void  main() {
    //    SetConsoleOutputCP(1251);
    //    SetConsoleCP(1251);
    printf("%.2f\n",13.3/2);
    int array[4][4] = { {1,2,3,4}, {1,2,3,4}, {1,2,3,4}, {1,2,3,4} };
    parr((int*)array, 4);
    printf("\n");
    char standart[100]; // объявляем строку без инициализации
    snprintf(standart, sizeof(standart), "Введите количество элементов в массиве (не больше %d): ", 100); // записываем в строку отформатированный текст с подстановкой значения N
    char welcome[700] = "Тема:одномерные массивы,список функции:\n"
        "-1)sos or help or h = инструкция для вас\n"
        "0)exit или 0 = выход\n"
        "1)range_sum = Найдем количество элементов в диапазоне от А до В и сумму расположенных после последнего максимального элемента\n"
        "2)even=после каждого четного элемента вставить 0\n"
        "3)rarity=Найдем наиболее редко встречающееся нечетное число.\n";
    printf("%s", welcome);
    // Бесконечный цикл
    while (1) {
        double arr[N]; 
        printf("Вызов функции:");
        char choice[30];// Строка для хранения выбора пользователя
        scanf_s("%s", choice, sizeof(choice));
        fflush(stdin);
        if (strcmp(choice, "exit") == 0 || strcmp(choice, "0") == 0) {
            printf("С вами была компания NOmicrosoft, До Новых Встреч!\n");
            printf("%s", choice);
            break; // Выход из цикла
        }
        else if (strcmp(choice, "range_sum") == 0 || strcmp(choice, "1") == 0) {
            int n = (int)correct(standart);
            massive(arr, n);
            print_array(arr, n);
            double a = correct("Введите a(нижняя граница):");
            double b = correct("Введите b(верхняя граница):");// границы диапазона
            int count = count_elements_in_range(arr, n, a, b);
            printf("Количество элементов в диапазоне [%.2f;%.2f]: %d\n", a, b, count);
            double sum = sum_elements_after_last_max(arr, n);
            printf("Сумма элементов после последнего максимального: %.2f\n", sum);
        }
        else if (strcmp(choice, "sos") == 0 || strcmp(choice, "help") == 0 || strcmp(choice, "h") == 0 || strcmp(choice, "-1") == 0) {
            printf("\n**************\n%s", welcome);
        }
        else if (strcmp(choice, "even") == 0 || !strcmp(choice, "2")) {
            int n = (int)correct(standart);
            massive(arr,n);
            for (int i = 0; i < n; i++) {
                arr[i] = (int)arr[i];
            }
            print_array(arr, n);
            even(arr, n);
        }   
        else if (strcmp(choice, "rarity") == 0 || !strcmp(choice, "3")) {
            int n = (int)correct(standart);
            massive(arr,n);
            for (int i = 0; i < n; i++) {
                arr[i] = (int)arr[i];
            } 
             
            print_array(arr, n);
            double rarest_odd = find_rarest_number(arr, n);
            printf("Наиболее редко встречающееся нечетное число: %.2f\n", rarest_odd);
        }
        else { printf("%s", choice); }
    }
}
