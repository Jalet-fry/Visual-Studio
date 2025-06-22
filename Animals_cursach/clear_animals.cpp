#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <cctype>

using namespace std;

// Классы обработки исключений
class Base_exception : public exception {
protected:
    string message;
public:
    Base_exception(const string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class Invalid_input_exception : public Base_exception {
public:
    Invalid_input_exception(const string& msg) : Base_exception(msg) {}
};

class Invalid_name_exception : public Base_exception {
public:
    Invalid_name_exception(const string& msg) : Base_exception(msg) {}
};

class Invalid_age_exception : public Base_exception {
public:
    Invalid_age_exception(const string& msg) : Base_exception(msg) {}
};

// Функция для безопасного ввода числа
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


// Базовый класс Creature
class Creature {
public:
    virtual string get_name() const = 0;
    virtual string get_string() const = 0;
    virtual int get_int() const = 0;
    virtual void make_sound() const = 0;
    virtual void change_me() = 0;
    virtual void show_me() const = 0;
    virtual ~Creature() {}
};

// Классы животных
class Animal : public virtual Creature {
protected:
    string habitat;
    int age;
public:
    Animal(const string habitat, int age) : habitat(habitat), age(age) {}
    Animal() : habitat("Unknown"), age(0) {}

    virtual string get_name() const override { return "Animal"; }

    virtual string get_string() const override { return habitat; }
    virtual int get_int() const override { return age; }

    virtual void make_sound() const override { cout << "Some animal sound" << endl; }
    virtual void change_me() override {
        habitat = validate_and_get_name("Enter new habitat for Animal: ");
        age = correct("Enter new age for Animal: ", 1, 100);
    }
    virtual void show_me() const override {
        cout << "Name: " << get_name() << ", Habitat: " << habitat << ", Age: " << age << endl;
    }
};

class Lion : public virtual Animal {
public:
    Lion(const string& habitat, int age) : Animal(habitat, age) {}
    virtual string get_name() const override { return "Lion"; }
    virtual string get_string() const override { return habitat; }
    virtual int get_int() const override { return age; }
    virtual void make_sound() const override { cout << "Roar" << endl; }
    virtual void change_me() override {
        string newHabitat = validate_and_get_name("Enter new habitat for Lion: ");
        int newAge = correct("Enter new age for Lion: ", 1, 100);
        this->habitat = newHabitat;
        this->age = newAge;
    }
    virtual void show_me() const override {
        cout << "Lion - Habitat: " << habitat << ", Age: " << age << endl;
    }
};

class Eagle : public virtual Animal {
public:
    Eagle(const string habitat, int age) : Animal(habitat, age) {}
    virtual string get_name() const override { return "Eagle"; }
    virtual string get_string() const override { return habitat; }
    virtual int get_int() const override { return age; }
    virtual void make_sound() const override { cout << "Screech" << endl; }
    virtual void change_me() override {
        habitat = validate_and_get_name("Enter new habitat for Eagle: ");
        age = correct("Enter new age for Eagle: ", 1, 100);
    }
    virtual void show_me() const override {
        cout << "Eagle - Habitat: " << habitat << ", Age: " << age << endl;
    }
};

class Spider : public virtual Creature {
protected:
    string web_type;
    int leg_count;
public:
    Spider(const string web_type, int leg_count) : web_type(web_type), leg_count(leg_count) {}
    virtual string get_name() const override { return "Spider"; }
    virtual string get_string() const override { return web_type; }
    virtual int get_int() const override { return leg_count; }
    virtual void make_sound() const override { cout << "Hiss" << endl; }
    virtual void change_me() override {
        web_type = validate_and_get_name("Enter new web type for Spider: ");
        leg_count = correct("Enter new leg count for Spider: ", 1, 20);
    }
    virtual void show_me() const override {
        cout << "Spider - Web: " << web_type << ", Legs: " << leg_count << endl;
    }
};

class Human : public virtual Creature {
protected:
    string profession;
    int age;
public:
    Human(const string profession, int age) : profession(profession), age(age) {}
    virtual string get_name() const override { return "Human"; }
    virtual string get_string() const override { return profession; }
    virtual int get_int() const override { return age; }
    virtual void make_sound() const override { cout << "Hello, I am human!" << endl; }
    virtual void change_me() override {
        profession = validate_and_get_name("Enter new profession for Human: ");
        age = correct("Enter new age for Human: ", 1, 100);
    }
    virtual void show_me() const override {
        cout << "Human - Profession: " << profession << ", Age: " << age << endl;
    }
};

// Применение множественного наследования для Griffon
class Griffon : public virtual Eagle, public virtual Lion {
public:
    Griffon(const string habitat, int age) : Animal(habitat, age), Eagle(habitat, age), Lion(habitat, age) {
        if (age < 0 || age > 50) throw Invalid_age_exception("Age for Griffon must be at least [1;50]!");
    }
    virtual string get_name() const override { return "Griffon"; }
    virtual string get_string() const override {
        //return Eagle::get_string() + "\n" + Lion::get_string();  // Объединяем строки
        return Eagle::get_string();  // Объединяем строки
    }
    virtual int get_int() const override { return age; }
    virtual void make_sound() const override { cout << "Griffon roar and screech!" << endl; }
    virtual void change_me() override {
        string new_habitat = validate_and_get_name("Enter new habitat for Griffon: ");
        int new_age = correct("Enter new age for Griffon: ", 1, 50);
        this->habitat = new_habitat;
        this->age = new_age;
    }
    virtual void show_me() const override {
        cout << "Griffon - Habitat: " << habitat << ", Age: " << age << endl;
    }
};

// Применение множественного наследования для SpiderMan
class SpiderMan : public virtual Spider, public virtual Human {
public:
    SpiderMan(string profession, string web_type, int age) : Human(profession, age), Spider(web_type, 2) {
        if (age < 15 || age > 100) throw Invalid_age_exception("Age for SpiderMan must be at least [15;100]!");
    }
    virtual string get_name() const override { return "SpiderMan"; }
    virtual string get_string() const override { return profession + "\n" + web_type; }
    virtual int get_int() const override { return age; }
    virtual void make_sound() const override { cout << "I am SpiderMan!" << endl; }
    virtual void change_me() override {
        profession = validate_and_get_name("Enter new profession for SpiderMan: ");
        age = correct("Enter new age for SpiderMan: ", 15, 100);
    }
    virtual void show_me() const override {
        cout << "SpiderMan - Profession: " << profession << ", Age: " << age << ", Web: " << web_type << endl;
    }
};

// Применение множественного наследования для Assassin
class Assassin : public virtual Eagle, public virtual Human {
public:
    Assassin(const string profession, const string habitat, int age) : Human(profession, age), Eagle(habitat, age) {
        if (age < 18 || age > 100) throw Invalid_age_exception("Age for Assassin must be at least [18;100]!");
    }
    virtual string get_name() const override { return "Assassin"; }
    virtual string get_string() const override { return profession + "\n" + habitat; }
    virtual int get_int() const override { return Human::age; }
    virtual void make_sound() const override { cout << "Silent assassin!" << endl; }
    virtual void change_me() override {
        profession = validate_and_get_name("Enter new profession for Assassin: ");
        Eagle::age = correct("Enter new age for Assassin: ", 18, 100);
        Human::age = Eagle::age;
    }
    virtual void show_me() const override {
        cout << "Assassin - Profession: " << profession << ", Age: " << Human::age << endl;
    }
};

// Основная программа

template <typename T>
class My_deque {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
    };
    Node* front;
    Node* rear;
    int size;

public:
    My_deque() : front(nullptr), rear(nullptr), size(0) {}
    ~My_deque() { clear(); }

    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}

        T& operator*() { return current->data; }
        T* operator->() { return &current->data; }

        Iterator& operator++() {
            if (current != nullptr) {
                current = current->next;
            }
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            if (current != nullptr) {
                current = current->next;
            }
            return temp;
        }

        Iterator& operator--() {
            if (current != nullptr) {
                current = current->prev;
            }
            return *this;
        }

        Iterator operator--(int) {
            Iterator temp = *this;
            if (current != nullptr) {
                current = current->prev;
            }
            return temp;
        }

        bool operator!=(const Iterator& other) const { return current != other.current; }
        bool operator==(const Iterator& other) const { return current == other.current; }

        Node* get_current() const { return current; }
    };

    void push_back(T value) {
        Node* new_node = new Node(value);
        if (is_empty()) {
            front = rear = new_node;
        } else {
            new_node->prev = rear;
            rear->next = new_node;
            rear = new_node;
        }
        size++;
    }

    void pop_front() {
        if (is_empty()) throw runtime_error("Deque is empty");
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        else front->prev = nullptr;
        delete temp;
        size--;
    }

    bool is_empty() const { return size == 0; }
    int get_size() const { return size; }

    void remove_node(Iterator it) {
        Node* node_to_remove = it.get_current();

        if (node_to_remove == nullptr) {
            return; // Если итератор указывает на пустоту
        }

        // Если узел - это первый элемент
        if (node_to_remove == front) {
            front = node_to_remove->next;
            if (front) {
                front->prev = nullptr;
            }
        }
        // Если узел - это последний элемент
        else if (node_to_remove == rear) {
            rear = node_to_remove->prev;
            if (rear) {
                rear->next = nullptr;
            }
        }
        // Удаляем элемент, который не является первым или последним
        else {
            node_to_remove->prev->next = node_to_remove->next;
            node_to_remove->next->prev = node_to_remove->prev;
        }

        delete node_to_remove;  // Освобождаем память
        size--;
    }

    void remove_at(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }

        Iterator it = (index < size / 2) ? begin() : end();

        // Идем к нужному элементу
        if (index < size / 2) {
            // Если индекс ближе к началу
            for (int i = 1; i < index; ++i) {
                ++it;
            }
        }
        else {
            // Если индекс ближе к концу
            for (int i = size; i > index; --i) {
                --it;
            }
        }

        // Удаляем узел
        remove_node(it);
    }

    void clear() {
        Iterator it = Iterator(rear);
        while (it != Iterator(nullptr)) {
            Iterator temp = it;
            --it;
            delete temp.get_current();
        }
        front = rear = nullptr;
        size = 0;
    }

    Iterator begin() const { return Iterator(front); }
    Iterator end() const { return Iterator(rear); }

    void display() const {
        if (is_empty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        Iterator it = begin();
        int index = 1;  // Индекс, начиная с 1
        while (it != end()) {
            cout << index << ". ";  // Выводим индекс перед вызовом show_me()
            (*it)->show_me();  // Вызываем метод show_me()
            ++it;
            ++index;  // Увеличиваем индекс
        }
        cout << index << ". ";  // Выводим индекс перед вызовом show_me()
        (*it)->show_me();  // Вызываем метод show_me()
        cout << endl;
    }
    void save_to_file(string filename) const {
        ofstream file;
        file.open(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Не удалось открыть файл для записи!");
        }

        Iterator it = begin();
        while (it != end()) {
            Creature* creature = *it;
            // Запись данных в зависимости от типа существа
            file << creature->get_name() << "\n" << creature->get_string() << "\n" << creature->get_int() << std::endl;

            file << "----" << endl;  // Разделитель
            ++it;
        }

        file << (*it)->get_name() << "\n" << (*it)->get_string() << "\n" << (*it)->get_int() << std::endl;

        file << "----" << endl;  // Разделитель
        file.close();
    }
    void load_from_file(string filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Не удалось открыть файл для чтения!");
        }

        string line, habitat, profession, web_type;
        int age, leg_count;
        while (std::getline(file, line)) {  // Правильный вызов getline
            if (line == "Lion") {
                getline(file, habitat);
                file >> age;
                file.ignore();  // Игнорируем символ новой строки
                push_back(new Lion(habitat, age));
            }
            else if (line == "Eagle") {
                getline(file, habitat);
                file >> age;
                file.ignore();
                push_back(new Eagle(habitat, age));
            }
            else if (line == "Spider") {
                getline(file, web_type);
                file >> leg_count;
                file.ignore();
                push_back(new Spider(web_type, leg_count));
            }
            else if (line == "Human") {
                getline(file, profession);
                file >> age;
                file.ignore();
                push_back(new Human(profession, age));
            }
            else if (line == "Griffon") {
                getline(file, habitat);
                file >> age;
                file.ignore();
                push_back(new Griffon(habitat, age));
            }
            else if (line == "SpiderMan") {
                getline(file, profession);
                getline(file, web_type);
                file >> age;
                file.ignore();
                push_back(new SpiderMan(profession, web_type, age));
            }
            else if (line == "Assassin") {
                getline(file, profession);
                getline(file, habitat);
                file >> age;
                file.ignore();
                push_back(new Assassin(profession, habitat, age));
            }

            // Пропускаем разделитель
            if (line == "----") {
                continue;
            }
        }


        file.close();
    }
    // Вставка элемента по индексу
    void insert_at(int index, T value) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range");
        }

        Node* new_node = new Node(value);
        
        if (index == 0) {
            // Вставляем в начало
            if (is_empty()) {
                front = rear = new_node;
            } else {
                new_node->next = front;
                front->prev = new_node;
                front = new_node;
            }
        } else if (index == size) {
            // Вставляем в конец
            push_back(value);
        } else {
            Iterator it = (index < size / 2) ? begin() : end();

            // Идем к нужному элементу
            if (index < size / 2) {
                // Если индекс ближе к началу
                for (int i = 0; i < index; ++i) {
                    ++it;
                }
            }
            else {
                // Если индекс ближе к концу
                for (int i = size; i > index; --i) {
                    --it;
                }
            }

            Node* current = it.get_current();
            new_node->prev = current->prev;
            new_node->next = current;
            if (current->prev) current->prev->next = new_node;
            current->prev = new_node;
        }

        size++;
    }

    // Получение элемента по индексу
    Iterator get_at(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }

        Iterator it = (index < size / 2) ? begin() : end();

        // Идем к нужному элементу
        if (index < size / 2) {
            // Если индекс ближе к началу
            for (int i = 1; i < index; ++i) {
                ++it;
            }
        }
        else {
            // Если индекс ближе к концу
            for (int i = size; i > index; --i) {
                --it;
            }
        }

        return it;
    }

};

int main() {
    try {
        My_deque<Creature*> container;
		container.load_from_file("C:\\Files_for_testing\\sem_3\\animals.txt");
        while (true) {
            int choice = correct("\n1. Add creature\n2. Remove creature\n3. Show creatures\n4. Modify creature\n5. Exit\n", 1, 5);
            if (choice == 1) {
                int type = correct("Select creature to add:\n1. Lion\n2. Eagle\n3. Spider\n4. Human\n5. Griffon\n6. SpiderMan\n7. Assassin\n", 1, 7);
                string vvod_1, vvod_2;
                int age;

                switch (type) {
                    case 1: {
                        vvod_1 = validate_and_get_name("Enter name for Lion: ");
                        age = correct("Enter age for Lion: ", 1, 25);
                        container.push_back(new Lion(vvod_1, age));
                        break;
                    }
                    case 2: {
                        vvod_1 = validate_and_get_name("Enter name for Eagle: ");
                        age = correct("Enter age for Eagle: ", 1, 50);
                        container.push_back(new Eagle(vvod_1, age));
                        break;
                    }
                    case 3: {
                        vvod_1 = validate_and_get_name("Enter habitat for Spider: ");
                        age = correct("Enter leg's count for Spider: ", 1, 8);
                        container.push_back(new Spider(vvod_1, age));
                        break;
                    }
                    case 4: {
                        vvod_1 = validate_and_get_name("Enter name for Human: ");
                        age = correct("Enter age for Human: ", 1, 100);
                        container.push_back(new Human(vvod_1, age));
                        break;
                    }
                    case 5: {
                        vvod_1 = validate_and_get_name("Enter name for Griffon: ");
                        age = correct("Enter age for Griffon: ", 1, 50);
                        container.push_back(new Griffon(vvod_1, age));
                        break;
                    }
                    case 6: {
                        vvod_1 = validate_and_get_name("Enter name for SpiderMan: ");
                        vvod_2 = validate_and_get_name("Enter web_type for Spider: ");
                        age = correct("Enter age for SpiderMan: ", 15, 100);
                        container.push_back(new SpiderMan(vvod_1, vvod_2, age));
                        break;
                    }
                    case 7: {
                        vvod_1 = validate_and_get_name("Enter profession for Assassin: ");
                        vvod_2 = validate_and_get_name("Enter habitat for Assassin: ");
                        age = correct("Enter age for Assassin: ", 18, 100);
                        container.push_back(new Assassin(vvod_1, vvod_2, age));
                        break;
                    }
                    default:
                        cout << "Invalid selection!" << endl;
                        break;
                }
            } else if (choice == 2) {
                container.display();
                int index = correct("Enter index of creature to remove: ", 1, container.get_size());
                container.remove_at(index);
            } else if (choice == 3) {
                container.display();
            } else if (choice == 4) {
                container.display();
                int index = correct("Enter index of creature to modify: ", 1, container.get_size());
                auto it = container.begin();
                for (int i = 1; i < index; ++i) {
                    ++it;
                }
                (*it)->change_me();
            } else if (choice == 5) {
                container.save_to_file("C:\\Files_for_testing\\sem_3\\animals.txt");
                container.clear();
                container.display();
                container.load_from_file("C:\\Files_for_testing\\sem_3\\animals_test.txt");
                container.display();
                container.clear();
                break;
            }
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}

            //if (name == "Lion") {
            //    file << creature->get_name() << "\n" << creature->get_string() << "\n" << creature->get_int() << std::endl;
            //}
            //else if (name == "Eagle") {
            //    file << creature->get_name() << "\n" << creature->get_string() << "\n" << creature->get_int() << std::endl;
            //}
            //else if (name == "Spider") {
            //    file << creature->get_name() << "\n" << creature->get_string() << "\n" << std::endl;
            //}
            //else if (name == "Human") {
            //    file << creature->get_name() << "\n" << creature->get_string() << "\n" << creature->get_int() << std::endl;
            //}
            //else if (name == "Griffon") {
            //    file << creature->get_name() << "\n" << creature->get_string() << "\n" << creature->get_int() << std::endl;
            //}
            //else if (name == "SpiderMan") {
            //    file << creature->get_name() << "\n" << creature->get_string() << "\n" << creature->get_int() << std::endl;
            //}
            //else if (name == "Assassin") {
            //    file << creature->get_name() << "\n" << creature->get_string() << "\n" << creature->get_int() << std::endl;
            //}

// Базовый класс Creature

/*
* It was mine code:
class Creature {
public:
    virtual string get_name() const = 0;
    virtual string get_string() const = 0;
    virtual int get_age() const = 0;
    virtual void make_sound() const = 0;
    virtual void change_me() = 0;
    virtual void show_me() const = 0;
    virtual ~Creature() {}
};

// Классы животных
class Animal : public virtual Creature {
protected:
    string habitat;
    int age;
public:
    Animal(const string& habitat, int age) : habitat(habitat), age(age) {}
    Animal() : habitat("Unknown"), age(0) {}

    virtual string get_name() const override { return "Animal"; }
    virtual string get_string() const override { return habitat; }
    virtual int get_age() const override { return age; }

    virtual void make_sound() const override { cout << "Some animal sound" << endl; }
    virtual void change_me() override {
        habitat = validate_and_get_name("Enter new habitat for Animal: ");
        age = correct("Enter new age for Animal: ", 1, 100);
    }
    virtual void show_me() const override {
        cout << "Name: " << get_name() << ", Habitat: " << habitat << ", Age: " << age << endl;
    }
};

class Lion : public virtual Animal {
public:
    Lion(const string& habitat, int age) : Animal(habitat, age) {}
    virtual string get_name() const override { return "Lion"; }
    virtual void make_sound() const override { cout << "Roar" << endl; }
    virtual void change_me() override {
        string newHabitat = validate_and_get_name("Enter new habitat for Lion: ");
        int newAge = correct("Enter new age for Lion: ", 1, 100);
        this->habitat = newHabitat;
        this->age = newAge;
    }
    virtual void show_me() const override {
        cout << "Lion - Habitat: " << habitat << ", Age: " << age << endl;
    }
};

class Eagle : public virtual Animal {
public:
    Eagle(const string& habitat, int age) : Animal(habitat, age) {}
    virtual string get_name() const override { return "Eagle"; }
    virtual void make_sound() const override { cout << "Screech" << endl; }
    virtual void change_me() override {
        habitat = validate_and_get_name("Enter new habitat for Eagle: ");
        age = correct("Enter new age for Eagle: ", 1, 100);
    }
    virtual void show_me() const override {
        cout << "Eagle - Habitat: " << habitat << ", Age: " << age << endl;
    }
};

class Spider : public virtual Creature {
protected:
    string web_type;
    int legCount;
public:
    Spider(const string& webType, int legCount = 8) : web_type(webType), legCount(legCount) {}
    virtual string get_name() const override { return "Spider"; }
    virtual string get_string() const override { return web_type; }
    virtual void make_sound() const override { cout << "Hiss" << endl; }
    virtual void change_me() override {
        web_type = validate_and_get_name("Enter new web type for Spider: ");
        legCount = correct("Enter new leg count for Spider: ", 1, 20);
    }
    virtual void show_me() const override {
        cout << "Spider - Web: " << web_type << ", Legs: " << legCount << endl;
    }
};

class Human : public virtual Creature {
protected:
    string profession;
    int age;
public:
    Human(const string& profession, int age) : profession(profession), age(age) {}
    virtual string get_name() const override { return "Human"; }
    virtual string get_string() const override { return profession; }
    virtual void make_sound() const override { cout << "Hello, I am human!" << endl; }
    virtual void change_me() override {
        profession = validate_and_get_name("Enter new profession for Human: ");
        age = correct("Enter new age for Human: ", 1, 100);
    }
    virtual void show_me() const override {
        cout << "Human - Profession: " << profession << ", Age: " << age << endl;
    }
};


class Griffon : public virtual Eagle, public virtual Lion {
public:
    Griffon(const string& habitat, int age) :Animal(habitat, age),  Eagle(habitat, age), Lion(habitat, age) {
        if (age < 0 || age > 50) throw Invalid_age_exception("Age for Griffon must be at least [1;50]!");
    }
    virtual string get_name() const override { return "Griffon"; }
    virtual string get_string() const override { return this->habitat; }
    virtual void make_sound() const override { cout << "Griffon roar and screech!" << endl; }
    virtual void change_me() override {
        string newHabitat = validate_and_get_name("Enter new habitat for Griffon: ");
        int newAge = correct("Enter new age for Griffon: ", 1, 50);
        this->habitat = newHabitat;
        this->age = newAge;
    }
    virtual void show_me() const override {
        cout << "Griffon - Habitat: " << habitat << ", Age: " << age << endl;
    }
};

class SpiderMan : public virtual Spider, public virtual Human {
public:
    SpiderMan(const string& profession, int age) : Human(profession, age), Spider("Silk") {
        if (age < 15 || age > 100) throw Invalid_age_exception("Age for SpiderMan must be at least [15;100]!");
    }
    virtual string get_name() const override { return "SpiderMan"; }
    virtual string get_string() const override { return profession + "\n" + web_type; }
    virtual void make_sound() const override { cout << "I am SpiderMan!" << endl; }
    virtual void change_me() override {
        profession = validate_and_get_name("Enter new profession for SpiderMan: ");
        age = correct("Enter new age for SpiderMan: ", 15, 100);
    }
    virtual void show_me() const override {
        cout << "SpiderMan - Profession: " << profession << ", Age: " << age << ", Web: " << web_type << endl;
    }
};

class Assassin : public virtual Eagle, public virtual Human {
public:
    Assassin(const string& profession, const string habitat, int age) : Human(profession, age), Eagle(habitat, age) {
        if (age < 18 || age > 100) throw Invalid_age_exception("Age for Assassin must be at least [18;100]!");
    }
    virtual string get_name() const override { return "Assassin"; }
    virtual string get_string() const override { return profession + "\n" + habitat; }
    virtual void make_sound() const override { cout << "Silent assassin!" << endl; }
    virtual void change_me() override {
        profession = validate_and_get_name("Enter new profession for Assassin: ");
        Eagle::age = correct("Enter new age for Assassin: ", 18, 100);
        Human::age = Eagle::age;
    }
    virtual void show_me() const override {
        cout << "Assassin - Profession: " << profession << ", Age: " << Human::age << endl;
    }
};
*/
