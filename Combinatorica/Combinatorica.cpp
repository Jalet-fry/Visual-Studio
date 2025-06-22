#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // для strtol
using namespace std;

int correct_int(const string& prompt) {
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

double correct_double(const string& prompt) {
    string input;
    double num;
    char* endptr;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (input.empty()) {
            return -1;
        }
        num = strtod(input.c_str(), &endptr);
        if (*endptr != '\n' && *endptr != '\0') {
            cout << "Это не число. Попробуйте еще раз." << endl;
        } else {
            return num;
        }
    }
}
vector<double> fill_array(int n) {
    vector<double> numbers;
    for (int i = 0; i < n; ++i) {
        cout << "Введите число " << i + 1 << ": ";
        double num = correct_double("");
        if (num == -1) {
            cout << "Некорректный ввод." << endl;
            exit(1);
        }
        numbers.push_back(num);
    }
    return numbers;
}
//Твой предел = 64, не более,65 = 64 типа
unsigned long long full_factorial(unsigned long long count_N) {
    if (count_N < 0) return 0; // Факториал отрицательного числа не существует

    unsigned long long factorial_i = 1, factorial_i_minus_1 = 1;

    for (unsigned long long i = 1; i <= count_N; i++) {
        factorial_i = factorial_i_minus_1 * i;
        if (factorial_i / i != factorial_i_minus_1) {
            return 0; // Произошло переполнение
        }
        factorial_i_minus_1 = factorial_i;
    }

    return factorial_i;
}

unsigned long long part_factorial(unsigned long long start, unsigned long long count_N) {
    if (start < 0 || count_N < 0 || start > count_N) return 0; // Неверные входные данные

    unsigned long long factorial_i = 1, factorial_i_minus_1 = 1;

    for (unsigned long long i = 1; i < start; i++) {
        factorial_i_minus_1 *= i;
    }

    for (unsigned long long i = start; i <= count_N; i++) {
        factorial_i = factorial_i_minus_1 * i;
        if (factorial_i / i != factorial_i_minus_1) {
            return 0; // Произошло переполнение
        }
        factorial_i_minus_1 = factorial_i;
    }

    return factorial_i;
}
//
//unsigned long long full_factorial(unsigned long long count_N) {
//    unsigned long long new_factorial_of_N = 1, old_factorial_of_N = 1;
//    //for (int i = 1; i <= count_N; i++) {
//    for (int i = count_N; i >= 1; i--) {
//        new_factorial_of_N *= i;
//        old_factorial_of_N *= i;
//    }
//    return new_factorial_of_N;
//}
//
//
//unsigned long long part_factorial(int start, int count_N) {
//    unsigned long long part_factorial_of_N = 1;
//    for (int i = start; i <= count_N; i++) {
//        part_factorial_of_N *= i;
//    }
//    return part_factorial_of_N;
//}

unsigned long long count_of_razmechenie(int to_k, int from_n) {
    unsigned long long start = from_n - to_k + 1, result = 1;
    for (int i = from_n; i >= start; i--) {
        result *= i;
    }
    return result;
}
unsigned long long count_of_sochetanie_zero_method(int to_k, int from_n) {
    int n_minus_k = from_n - to_k;
    return (full_factorial(from_n) / full_factorial(to_k) / full_factorial(n_minus_k));
}
unsigned long long count_of_sochetanie_first_method(int to_k, int from_n) {
    int n_minus_k = from_n - to_k;
    unsigned long long result = 1;
    (to_k > n_minus_k) ? result = part_factorial(to_k + 1, from_n) / full_factorial(n_minus_k) : result = part_factorial(n_minus_k + 1, from_n) / full_factorial(to_k);
    return result;
}


unsigned long long count_of_sochetanie_second_method(int to_k, int from_n) {
    int n_minus_k = from_n - to_k;
    int max_the_two_of_us = max(to_k, n_minus_k);
    int min_the_two_of_us = min(to_k, n_minus_k);

    vector<int> numerator;
    vector<int> denominator;

    for (int i = max_the_two_of_us + 1; i <= from_n; ++i) {
        numerator.push_back(i);
    }

    for (int i = 1; i <= min_the_two_of_us; ++i) {
        denominator.push_back(i);
    }

    for (auto& num : numerator) {
        for (auto den = denominator.begin(); den != denominator.end();) {
            if (num % *den == 0) {
                num /= *den;
                den = denominator.erase(den);
            }
            else {
                ++den;
            }
        }
    }

    unsigned long long result = 1;
    for (const auto& num : numerator) {
        result *= num;
    }

    for (const auto& denom : denominator) {
        result /= denom;
    }

    return result;
}

void print_array(const vector<double>& array) {
    cout << "[";
    for (double num : array) {
        cout << num << " ";
    }
    cout << "]" << endl;
}
// Функция для генерации всех перестановок
void generate_permutations(vector<double>& numbers, int l, int r) {
    if (l == r) {
        print_array(numbers);
    } else {
        for (int i = l; i <= r; ++i) {
            swap(numbers[l], numbers[i]);
            generate_permutations(numbers, l + 1, r);
            swap(numbers[l], numbers[i]); // backtrack
        }
    }
}
// Рекурсивная функция для генерации всех сочетаний
void generate_combinations(const vector<double>& numbers, vector<double>& combination, int start, int k) {
    if (k == 0) {
        print_array(combination);
        return;
    }
    for (int i = start; i <= numbers.size() - k; ++i) {
        combination.push_back(numbers[i]);
        generate_combinations(numbers, combination, i + 1, k - 1);
        combination.pop_back();
    }
}

void welcome_menu() {
    string  defis = "-----------------------------------------------------------------------------------------------------\n";
    char welcome[] =
        "Тема: Списки,список функции:\n"
        "-1 || sos || help || h = инструкция для вас\n"
        " 0 || exit или 0 = выход\n"
        " 1 || stek =  Сортировка стека по убыванию лишь стеками\n"
        " 2 || queue = Общежитие в виде очереди.\n";
    cout << defis << welcome << "Вызов функции: ";
    //printf("%s%sВызов функции: ", defis, welcome);
}

int main() {
    cout << "Hello World!\n";
    welcome_menu();
    int number = 6, new_number = 1, pretendent = 60, mesto = 3, big_boss = 65;
    unsigned long long result = 1, new_fact, old_fact = 1;
    cout << "Factoroal of " << number << " is " << full_factorial(number) << "\n";
    for (int i = 1; i < big_boss; i++) {
        old_fact = full_factorial(new_number);
		cout << "Factoroal of OLD " << new_number << " is " << old_fact << "\n";
        new_number++;
        result *= new_number;
        new_fact = full_factorial(new_number);
		cout << "Factoroal of NEW " << new_number << " is " << new_fact << "\n";
        if (new_fact >= old_fact) {
            //cout << "Factoroal of " << new_number << " is " << new_fact << "\n";
            //cout << "Factoroal of " << new_number << " is " << result << "\n";
            //cout << "Sochetanie for " << i << " in " << big_boss << " is " << count_of_sochetanie_first_method(i, big_boss) << "\n";
            //cout << "Sochetanie for " << i << " in " << big_boss << " is " << count_of_sochetanie_second_method(i, big_boss) << "\n";

        }
        else {
            cout << "Factoroal of " << new_number << " is " << new_fact << "\n";
            cout << "Problem in factorial of " << new_number << " is " << new_fact << endl;
            break;
        }
    }

    cout << "Perestaovki of " << pretendent << " for " << mesto << " is " << count_of_razmechenie(mesto, pretendent) << "\n";
    cout << "Sochetanie of " << pretendent << " for " << mesto << " is " << count_of_sochetanie_second_method(mesto, pretendent) << "\n";
    cout << "Sochetanie of " << pretendent << " for " << mesto << " is " << count_of_sochetanie_second_method(2,3) *  count_of_sochetanie_second_method(2,5) / count_of_sochetanie_second_method(4,8)<< "\n";

    vector<double> numbers = fill_array(correct_int("Введите количество чисел: "));
    cout << "Perestaovki of " << numbers.size() << " for " << numbers.size() << " is " << count_of_razmechenie(numbers.size(), numbers.size()) << "\n";
    cout << "Перестановки:\n";
    generate_permutations(numbers, 0, numbers.size() - 1);

    int k_in_n;
    cout << "Введите размер сочетаний: ";
    cin >> k_in_n;
    cin.ignore(); // Игнорируем оставшийся символ новой строки после cin

    vector<double> combination;
    cout << "Perestaovki of " << numbers.size() << " for " << k_in_n << " is " << count_of_razmechenie(k_in_n, numbers.size()) << "\n";
    cout << "Сочетания:\n";
    generate_combinations(numbers, combination, 0, k_in_n);

    return 0;
}

