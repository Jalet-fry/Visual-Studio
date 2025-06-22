#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

// Функция для безопасного ввода целого числа
int correct_int(const string& prompt) {
    string input;
    int num;
    while (true) {
        cout << prompt;
        getline(cin, input);

        if (input.empty()) {
            return -1; // если пользователь ничего не ввел, возвращаем -1
        }

        try {
            num = stoi(input); // преобразуем строку в число
            return num;
        } catch (invalid_argument& e) {
            cout << "Это не число. Попробуйте еще раз." << endl;
        } catch (out_of_range& e) {
            cout << "Число слишком велико. Попробуйте еще раз." << endl;
        }
    }
}

int main(int argc, char* argv[]) {
    int years = 0, months = 0, days = 0, hours = 0, minutes = 0, seconds = 0;

    if (argc == 7) {
        // Чтение из командной строки
        try {
            years = stoi(argv[1]);
            months = stoi(argv[2]);
            days = stoi(argv[3]);
            hours = stoi(argv[4]);
            minutes = stoi(argv[5]);
            seconds = stoi(argv[6]);
        } catch (const invalid_argument& e) {
            cout << "Ошибка: введены неверные данные через командную строку." << endl;
            return 1;
        } catch (const out_of_range& e) {
            cout << "Ошибка: одно из значений слишком велико." << endl;
            return 1;
        }
    } else {
        // Чтение с клавиатуры
        years = correct_int("Введите количество лет: ");
        months = correct_int("Введите количество месяцев: ");
        days = correct_int("Введите количество дней: ");
        hours = correct_int("Введите количество часов: ");
        minutes = correct_int("Введите количество минут: ");
        seconds = correct_int("Введите количество секунд: ");
    }

    // Перевод в секунды
    int total_seconds = years * 365 * 24 * 60 * 60
                        + months * 30 * 24 * 60 * 60
                        + days * 24 * 60 * 60
                        + hours * 60 * 60
                        + minutes * 60
                        + seconds;

    cout << "Общее количество секунд: " << total_seconds << endl;

    return 0;
}
