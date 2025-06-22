#ifndef UTILS_H
#define UTILS_H

// Общие библиотеки
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cctype>
#include <deque>

// Обработка исключений
class Base_exception : public std::exception {
protected:
    std::string message;
public:
    Base_exception(const std::string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class Invalid_input_exception : public Base_exception {
public:
    Invalid_input_exception(const std::string& msg) : Base_exception(msg) {}
};

class Invalid_name_exception : public Base_exception {
public:
    Invalid_name_exception(const std::string& msg) : Base_exception(msg) {}
};

class Invalid_age_exception : public Base_exception {
public:
    Invalid_age_exception(const std::string& msg) : Base_exception(msg) {}
};
class Invalid_hybrid_exception : public Base_exception {
public:
    Invalid_hybrid_exception(const std::string& msg) : Base_exception(msg) {}
};

int correct(const std::string& prompt, int min, int max);
bool is_valid_name(const std::string& name);
std::string validate_and_get_name(const std::string& prompt);

#endif 
