#include <iostream>
#include <string>
#include <cstring>
int correct_int(const std::string& prompt) {
    std::string input;
    int num;
    char* endptr;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty()) {
            return -1; 
        }
        num = std::strtol(input.c_str(), &endptr, 10);
        if (*endptr != '\n' && *endptr != '\0') {
            std::cout << "Это не число. Попробуйте еще раз." << std::endl;
        } else {
            return num;
        }
    }
}
float correct_float(const std::string& prompt) {
    std::string input;
    float num;
    char* endptr;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty()) {
            return -1.0f; 
        }
        num = std::strtof(input.c_str(), &endptr);
        if (*endptr != '\n' && *endptr != '\0') {
            std::cout << "Это не число. Попробуйте еще раз." << std::endl;
        } else {
            return num;
        }
    }
}
class Date {
public:
    int day = -1, month = -1, year = -999999;
    void getDate() {
        while (day < 1 || day > 31) {
            day = correct_int("Введите день: ");
        }
        //std::cin >> day;
        //std::cout << "Введите месяц: ";
        while (month < 1 || day > 29 && month == 2  || month > 12 ) {
            month = correct_int("Введите месяц:");
        }
        //std::cin >> month;
        //std::cout << "Введите год: ";
        while (year < -297976) {
            year = correct_int("Введите год:");
        }
        //std::cin >> year;
    }
    void putDate() const {
        std::cout << day << "/" << month << "/" << year;
    }
};
// Перечисление для статуса сотрудника
enum class Etype { LABORANT, SECRETARY, MANAGER };
class Employee {
private:
    int empNumber;
    float salary;
    Date hireDate;
    Etype empType;
public:
    void getEmploy() {
        //std::cout << "Введите номер сотрудника: ";
        //std::cin >> empNumber;
        //std::cout << "Введите оклад сотрудника: ";
        //std::cin >> salary;
        empNumber = correct_int("Введите номер сотрудника: ");
        salary = correct_float("Введите оклад сотрудника: ");
        std::cout << "Дата приема на работу:" << std::endl;
        hireDate.getDate();
        int type = correct_int("Введите тип сотрудника (0 - Лаборант, 1 - Секретарь, 2 - Менеджер): ");
        //std::cout << "Введите тип сотрудника (0 - Лаборант, 1 - Секретарь, 2 - Менеджер): ";
        //std::cin >> type;
        empType = static_cast<Etype>(type);
    }
    void putEmploy() const {
        std::cout << "Номер сотрудника: " << empNumber << "\n"
                  << "Оклад: " << salary << "\n"
                  << "Дата приема на работу: ";
        hireDate.putDate();
        std::cout << "\nСтатус сотрудника: ";
        switch (empType) {
            case Etype::LABORANT: std::cout << "Лаборант"; break;
            case Etype::SECRETARY: std::cout << "Секретарь"; break;
            case Etype::MANAGER: std::cout << "Менеджер"; break;
        }
        std::cout << std::endl;
    }
    Employee operator + (const Employee& e) const {
        Employee result;
        result.empNumber = empNumber + e.empNumber;
        result.salary = salary + e.salary;
        result.hireDate.day = hireDate.day + e.hireDate.day;
        result.hireDate.month = hireDate.month + e.hireDate.month;
        result.hireDate.year = hireDate.year + e.hireDate.year;
        result.empType = static_cast<Etype>((static_cast<int>(empType) + static_cast<int>(e.empType)) % 3);
        return result;
    }
    Employee operator & (const Employee& e) const {
        Employee result;
        result.empNumber = empNumber & e.empNumber;
        result.salary = static_cast<int>(salary) & static_cast<int>(e.salary);
        result.hireDate.day = hireDate.day & e.hireDate.day;
        result.hireDate.month = hireDate.month & e.hireDate.month;
        result.hireDate.year = hireDate.year & e.hireDate.year;
        result.empType = static_cast<Etype>(static_cast<int>(empType) & static_cast<int>(e.empType));
        return result;
    }
};

class MyString {
private:
    char* str;
public:
    MyString(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }
    ~MyString() {
        delete[] str;
    }
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }
    MyString operator+(const MyString& other) const {
        MyString result;
        result.str = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }
    MyString& operator+=(const MyString& other) {
        *this = *this + other;
        return *this;
    }
    bool operator==(const MyString& other) const {
        return strcmp(str, other.str) == 0;
    }
    bool operator!=(const MyString& other) const {
        return !(*this == other);
    }
    char& operator[](size_t index) {
        return str[index];
    }
    MyString operator()(int start, int length) const {
        MyString result;
        result.str = new char[length + 1];
        strncpy(result.str, str + start, length);
        result.str[length] = '\0';
        return result;
    }
    void display() const {
        std::cout << str << std::endl;
    }
    friend int length(const MyString& str1);
};
int length(const MyString& str1) {
    return static_cast<int>(strlen(str1.str));
}
MyString createString(const std::string& prompt) {
    std::cout << prompt;
    char buffer[1000];
    std::cin.getline(buffer, 1000);
    return MyString(buffer);
}
int main() {
   // Employee emp1, emp2;
   // emp1.getEmploy();
   // std::cout << std::endl;
   // emp2.getEmploy();
   // 
   // Employee emp3 = emp1 + emp2;
   // std::cout << "emp3 = " << std::endl;
   // emp3.putEmploy();

   // Employee emp4 = emp1 & emp2;
   // std::cout << "emp4 = " << std::endl;
   // emp4.putEmploy();
   // std::cout << "\n" << std::endl;
   // 
    MyString str1 = createString("Введите строку 1:");
    MyString str2 = createString("Введите строку 2:");
    std::cout << "Строка 1: ";
    str1.display();
    std::cout << "Строка 2: ";
    str2.display();

    MyString str3 = str1 + str2;
    std::cout << "Результат сложения: ";
    str3.display();
    
    str2 += str1;
    std::cout << "Результат +=: ";
    str2.display();
    
    std::cout << "Сравнение строк (==): " << (str1 == str2) << std::endl;
    std::cout << "Сравнение строк (!=): " << (str1 != str2) << std::endl;
    int index = -1;
    while (index < 0 || index >= length(str1)) {
        std::cout << "lenght = " << length(str1) << std::endl;
        index = correct_int("Введите index для str1:");
    }
    std::cout << "Третий символ первой строки: " << str1[2] << std::endl;
    
    int start = -1, end = -2;
    while (start < 0 || end < 0 || start >= length(str1) || end >= length(str1) || start > end) {
        std::cout << "lenght = " << length(str1) << std::endl;
        start = correct_int("Введите start для str1:");
        end = correct_int("Введите end для str1:");
    }
    MyString substr = str1(start, end - start + 1);
    std::cout << "Подстрока: ";
    substr.display();
    return 0;
}
