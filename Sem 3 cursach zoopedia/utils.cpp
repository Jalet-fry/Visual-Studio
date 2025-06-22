#include "utils.h"
using namespace std;


int correct(const string& prompt, int min, int max) {
    string input;
    int num;
    while (true) {
        try {
            cout << prompt;
            getline(cin, input);

            if (input.empty()) {
                return -1;
            }

            try {
                size_t pos;
                num = stoi(input, &pos);
                if (pos != input.size()) {
                    throw Invalid_input_exception("Введено не число. Попробуйте еще раз.");
                }
            } catch (const invalid_argument&) {
                throw Invalid_input_exception("Это не число. Попробуйте еще раз.");
            } catch (const out_of_range&) {
                throw Invalid_input_exception("Число слишком большое. Попробуйте еще раз.");
            }

            if (num < min || num > max) {
                throw Invalid_input_exception("Число должно быть в диапазоне от " + to_string(min) + " до " + to_string(max) + ". Попробуйте еще раз.");
            }

            return num;
        } catch (const Invalid_input_exception& e) {
            cout << e.what() << endl;
        } catch (const exception& e) {
            cout << "Произошла ошибка: " << e.what() << endl;
        }
    }
}

// Проверка корректности имени
bool is_valid_name(const string& name) {
    if (name.empty()) {
        return false;
    }
    if (!isupper(name[0])) {
        return false; // Имя должно начинаться с большой буквы
    }
    for (char c : name) {
        if (!isalpha(c)) {
            return false; // Все символы должны быть буквами
        }
    }
    return true;
}

// Ввод имени с проверкой
string validate_and_get_name(const string& prompt) {
    string name;
    while (true) {
        cout << prompt;
        getline(cin, name);
        if (is_valid_name(name)) {
            return name;
        } else {
            cout << "Invalid name format! The name must start with an uppercase letter and contain only letters." << endl;
        }
    }
}

