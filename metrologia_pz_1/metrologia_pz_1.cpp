#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
using namespace std;

class Array {
public:
    // Конструктор класса Array
    Array(int size) : size(size), array(size) {}

    // Заполнение массива с пользовательским вводом
    void fill() {
        for (int i = 0; i < size; ++i) {
            array[i] = correct("arr[" + to_string(i) + "]: ");
        }
    }

    // Печать массива
    void print() const {
        cout << "[";
        for (int i = 0; i < size - 1; ++i) {
            cout << array[i] << ", ";
        }
        cout << array[size - 1] << "]\n";
    }

    // Поиск максимального нечетного элемента
    int max_odd() const {
        int maxOdd = INT_MIN;
        for (int num : array) {
            if (num % 2 != 0 && num > maxOdd) {
                maxOdd = num;
            }
        }
        return maxOdd == INT_MIN ? 0 : maxOdd;
    }

    // Проверка корректности ввода
    static int correct(const string& prompt) {
        string input;
        int num;
        char* endptr;
        while (true) {
            cout << prompt;
            getline(cin, input);
            if (input.empty()) {
                return -1;
            }
            num = strtol(input.c_str(), &endptr, 10);
            if (*endptr != '\n' && *endptr != '\0') {
                cout << "Это не число. Попробуйте еще раз." << endl;
            }
            else {
                return num;
            }
        }
    }

private:
    int size;
    vector<int> array;
};

int main() {
    // Ввод размера массива
    int size = Array::correct("Введите длину массива (0 ≤ N ≤ 100): ");
    if (size < 0 || size > 100) {
        cout << "Неверное значение N." << endl;
        return 1;
    }
    Array handler(size);
    if (size > 0) {
        cout << "Введите элементы массива: ";
        handler.fill();
        handler.print();
    }

    // Поиск и вывод максимального нечетного элемента
    int maxOdd = handler.max_odd();
    cout << "Максимальный нечетный элемент: " << maxOdd << endl;

    return 0;
}
