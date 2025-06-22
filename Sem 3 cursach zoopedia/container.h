#pragma once

#include "utils.h"
using namespace std;

enum class Operation {
    ADD,
    REMOVE,
    UPDATE
};
template <typename T>
class My_deque {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
    };
    struct Change {
        T value;
        int index;
        Operation op;

        Change(T v, int idx, Operation o) : value(v), index(idx), op(o) {}
    };
    Node* front;
    Node* rear;
    int size;
    deque<Change> history;
    bool is_undoing;


public:
    My_deque() : front(nullptr), rear(nullptr), size(0), is_undoing(false) {}
    
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
    void check_undo() {
        if (history.size() >= 3) {
            history.pop_front();
        }
    }
    void change_this_creature(int index) {
        Iterator it = get_at(index);
        check_undo();
        
        if (!is_undoing) {
            T old_value = (*it)->clone();
            history.push_back(Change(old_value, index, Operation::UPDATE));
        }
        (*it)->change_me();  
    }
    void undo() {
        if (history.empty()) {
            cout << "No actions to undo!" << endl;
            return;
        }
        
        is_undoing = true;
        Change last_change = history.back();
        history.pop_back();

        switch (last_change.op)
        {
        case Operation::ADD: {
            
            remove_at(last_change.index);
            break;
        }
        case Operation::REMOVE: {
            
            insert_at(last_change.index, last_change.value);
            break;
        }
        case Operation::UPDATE: {
            Iterator it = get_at(last_change.index);
            (*it)->transfer_data(*last_change.value);
            break;
        }
        }
        is_undoing = false;
    }

    void my_push_back(T value) {
        Node* new_node = new Node(value);
        if (is_empty()) {
            front = rear = new_node;
        }
        else {
            new_node->prev = rear;
            rear->next = new_node;
            rear = new_node;
        }
        size++;
        check_undo();
        if (!is_undoing) {
            history.push_back(Change(value, size, Operation::ADD));
        }
    }

    void my_pop_front() {
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
            return; 
        }
        
        if (node_to_remove == front) {
            front = node_to_remove->next;
            if (front) {
                front->prev = nullptr;
            }
        }
        
        else if (node_to_remove == rear) {
            rear = node_to_remove->prev;
            if (rear) {
                rear->next = nullptr;
            }
        }
        
        else {
            node_to_remove->prev->next = node_to_remove->next;
            node_to_remove->next->prev = node_to_remove->prev;
        }

        delete node_to_remove;
        size--;
    }

    void remove_at(int index) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range");
        }
        Iterator it = get_at(index);
        check_undo();
        if (!is_undoing) {
            history.push_back(Change(it.get_current()->data, index, Operation::REMOVE));
        }
        
        remove_node(it);
    }


    void clear() {
        history.clear();
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
        int index = 1;
        while (it != end()) {
            cout << index << ". ";
            (*it)->show_me();
            ++it;
            ++index;
        }
        cout << index << ". ";
        (*it)->show_me();
        cout << endl;
    }
    void save_to_file(string filename) const {
        ofstream file;
        try {
            if (is_empty()) {
                cout << "Deque is empty! Nothing to save." << endl;
                return;  
            }
            file.open(filename);
            if (!file.is_open()) {
                throw Invalid_name_exception("Не удалось открыть файл");
            }
            Iterator it = begin();
            while (it != end()) {
                Creature* creature = *it;
                
                file << creature->get_name() << "\n" << creature->get_string() << "\n" << creature->get_int() << std::endl;

                file << "----" << endl;  
                ++it;
            }
            if ((*it)) {
                file << (*it)->get_name() << "\n" << (*it)->get_string() << "\n" << (*it)->get_int() << std::endl;
                file << "----" << endl;  
            }
            file.close();
        }
        catch (const Invalid_name_exception& e) {
            cout << "Error while loading creature from file: " << e.what() << endl;
            
        }
    }
    void load_from_file(string filename) {
        ifstream file(filename);
        try {
            if (!file.is_open()) {
                throw Invalid_name_exception("Не удалось открыть файл");
                
            }

            string line, habitat, profession, web_type;
            int age, leg_count;
            is_undoing = true;
            while (std::getline(file, line)) {  
                try {
                    if (line == "Lion") {
                        getline(file, habitat);
                        file >> age;
                        file.ignore();  
                        my_push_back(new Lion(habitat, age));
                    }
                    else if (line == "Eagle") {
                        getline(file, habitat);
                        file >> age;
                        file.ignore();
                        my_push_back(new Eagle(habitat, age));
                    }
                    else if (line == "Spider") {
                        getline(file, web_type);
                        file >> leg_count;
                        file.ignore();
                        my_push_back(new Spider(web_type, leg_count));
                    }
                    else if (line == "Human") {
                        getline(file, profession);
                        file >> age;
                        file.ignore();
                        my_push_back(new Human(profession, age));
                    }
                    else if (line == "Griffon") {
                        getline(file, habitat);
                        file >> age;
                        file.ignore();
                        my_push_back(new Griffon(habitat, age));
                    }
                    else if (line == "SpiderMan") {
                        getline(file, profession);
                        getline(file, web_type);
                        file >> age;
                        file.ignore();
                        my_push_back(new SpiderMan(profession, web_type, age));
                    }
                    else if (line == "Assassin") {
                        getline(file, profession);
                        getline(file, habitat);
                        file >> age;
                        file.ignore();
                        my_push_back(new Assassin(profession, habitat, age));
                    }
                    
                    if (line == "----") {
                        continue;
                    }
                }
                catch (const Invalid_age_exception& e) {
                    cout << "Error while loading creature from file: " << e.what() << endl;
                }
                catch (const Invalid_name_exception& e) {
                    cout << "Error while loading creature from file: " << e.what() << endl;
                    
                }
                catch (const std::exception& e) {
                    cout << "Unexpected error while loading creature from file: " << e.what() << endl;
                }
            }
            is_undoing = false;
            file.close();
        }
        catch (const Invalid_name_exception& e) {
            cout << "Ошибка при чтении из файла: " << e.what() << endl;
            
        }
    }
    
    void insert_at(int index, T value) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range");
        }
        Node* new_node = new Node(value);
        if (index == 0) {
            
            if (is_empty()) {
                front = rear = new_node;
            }
            else {
                new_node->next = front;
                front->prev = new_node;
                front = new_node;
            }
        }
        else if (index == size) {
            
            my_push_back(value);
        }
        else {
            Iterator it = get_at(index);
            Node* current = it.get_current();
            new_node->prev = current->prev;
            new_node->next = current;
            if (current->prev) current->prev->next = new_node;
            current->prev = new_node;
        }
        size++;
    }

    
    Iterator get_at(int index) {
        if (index < 0 || index > size) {
            throw Invalid_input_exception("Индекс вне диапазона[1," + to_string(size) + "]");
        }

        Iterator it = (index < size / 2) ? begin() : end();

        
        if (index < size / 2) {
            
            for (int i = 1; i < index; ++i) {
                ++it;
            }
        }
        else {
            
            for (int i = size; i > index; --i) {
                --it;
            }
        }

        return it;
    }

    void search_creatures() {
        
        cout << "Choose the field to search by:" << endl;
        cout << "1. Habitat" << endl;
        cout << "2. Age" << endl;
        cout << "3. Web Type (for Spider and SpiderMan)" << endl;
        cout << "4. Leg Count (for Spider and SpiderMan)" << endl;
        cout << "5. Profession (for Human, SpiderMan, and Assassin)" << endl;

        int choice = correct("Enter your choice: ", 1, 5);  

        string search_string;
        int search_int, index = 1;

        switch (choice) {
        case 1: {  
            cout << "Enter habitat: ";
            getline(cin, search_string);
            
            Iterator it = begin();
            while (it != end()) {
                Creature* creature = *it;
                if (Animal* animal = dynamic_cast<Animal*>(creature)) {
                    if (animal->get_habitat() == search_string) {
                        cout << "Creature at index " << index << ":" << endl;
                        creature->show_me();
                    }
                }
                ++it;
                ++index;
            }
            break;
        }

        case 2: {  
            search_int = correct("Enter age: ", 0, 200);  

            
            Iterator it = begin();
            while (it != end()) {
                Creature* creature = *it;
                if (Animal* animal = dynamic_cast<Animal*>(creature)) {
                    if (animal->get_age() == search_int) {
                        cout << "Creature at index " << index << ":" << endl;
                        creature->show_me();
                    }
                }
                else if (Human* human = dynamic_cast<Human*>(creature)) {
                    if (human->get_age() == search_int) {
                        cout << "Creature at index " << index << ":" << endl;
                        creature->show_me();
                    }
                }
                ++it;
                ++index;
            }
            break;
        }

        case 3: {  
            cout << "Enter web type: ";
            getline(cin, search_string);

            
            Iterator it = begin();
            while (it != end()) {
                Creature* creature = *it;
                if (Spider* spider = dynamic_cast<Spider*>(creature)) {
                    if (spider->get_web_type() == search_string) {
                        cout << "Creature at index " << index << ":" << endl;
                        creature->show_me();
                    }
                }
                else if (SpiderMan* spiderMan = dynamic_cast<SpiderMan*>(creature)) {
                    if (spiderMan->get_web_type() == search_string) {
                        cout << "Creature at index " << index << ":" << endl;
                        creature->show_me();
                    }
                }
                ++it;
                ++index;
            }
            break;
        }

        case 4: {  
            search_int = correct("Enter leg count: ", 0, 20);  

            
            Iterator it = begin();
            while (it != end()) {
                Creature* creature = *it;
                if (Spider* spider = dynamic_cast<Spider*>(creature)) {
                    if (spider->get_leg_count() == search_int) {
                        cout << "Creature at index " << index << ":" << endl;
                        creature->show_me();
                    }
                }
                else if (SpiderMan* spiderMan = dynamic_cast<SpiderMan*>(creature)) {
                    
                    if (2 == search_int) {
                        cout << "Creature at index " << index << ":" << endl;
                        creature->show_me();
                    }
                }
                ++it;
                ++index;
            }
            break;
        }

        case 5: {  
            cout << "Enter profession: ";
            getline(cin, search_string);

            
            Iterator it = begin();
            while (it != end()) {
                Creature* creature = *it;
                if (Human* human = dynamic_cast<Human*>(creature)) {
                    if (human->get_profession() == search_string) {
                        cout << "Creature at index " << index << ":" << endl;
                        creature->show_me();
                    }
                }
                else if (SpiderMan* spiderMan = dynamic_cast<SpiderMan*>(creature)) {
                    if (spiderMan->get_profession() == search_string) {
                        cout << "Creature at index " << index << ":" << endl;
                        creature->show_me();
                    }
                }
                else if (Assassin* assassin = dynamic_cast<Assassin*>(creature)) {
                    if (assassin->get_profession() == search_string) {
                        cout << "Creature at index " << index << ":" << endl;
                        creature->show_me();
                    }
                }
                ++it;
                ++index;
            }
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }

    void time_to_child() {
        cout << "\n\t\tПравила скрещивания:\n\t\tДля человека и паука: паук должен иметь только 2 ноги;"
            << "\n\t\tДля человека и орла: треть суммы возрастов должны быть в [18;50];"
            << "\n\t\tДля льва и орла: это должны быть лев и орел соотвественно, "
            << "возраст грифона будет равен треть суммы возрастов льва и орла"
            << endl;
        display();
        int first = correct("Введите индекс 1-го существа: ", 1, get_size());
        int second = correct("Введите индекс 2-го существа: ", 1, get_size());
        if (first != second) {
            try {
                my_push_back(breed_creatures(*get_at(first), *get_at(second)));
            }
            catch (const Invalid_hybrid_exception& e) {
                cout << "Ошибка при скрещивании: " << e.what() << endl;
                
            }
            catch (const Invalid_age_exception& e) {
                cout << "Ошибка в числовых данных: " << e.what() << endl;
            }
        }
    }

    Creature* breed_creatures(Creature* first, Creature* second) {
        Lion* lion = dynamic_cast<Lion*>(first);
        Eagle* eagle = dynamic_cast<Eagle*>(second);
        if (lion && eagle) {
            return new Griffon(lion, eagle);
        }
        lion = dynamic_cast<Lion*>(second);
        eagle = dynamic_cast<Eagle*>(first);
        if (lion && eagle) {
            return new Griffon(lion, eagle);
        }
        Spider* spider = dynamic_cast<Spider*>(first);
        Human* human = dynamic_cast<Human*>(second);
        if (human && spider) {
            if (spider->get_leg_count() == 2) {
                return new SpiderMan(human, spider);
            }
            else {
                throw Invalid_age_exception("У паука должно быть только 2 ноги");
            }
        }
        spider = dynamic_cast<Spider*>(second);
        human = dynamic_cast<Human*>(first);
        if (human && spider) {
            if (spider->get_leg_count() == 2) {
                return new SpiderMan(human, spider);
            }
            else {
                throw Invalid_age_exception("У паука должно быть только 2 ноги");
            }
        }
        eagle = dynamic_cast<Eagle*>(first);
        human = dynamic_cast<Human*>(second);
        if (human && eagle) {
            int check_age = (human->get_age() + eagle->get_age()) / 2;
            if (check_age >= 18 && check_age <= 50) {
                return new Assassin(human, eagle);
            }
            else {
                throw Invalid_age_exception("По возрасту не подхоят");
            }
        }
        eagle = dynamic_cast<Eagle*>(second);
        human = dynamic_cast<Human*>(first);
        if (human && eagle) {
            int check_age = (human->get_age() + eagle->get_age()) / 2;
            if (check_age >= 18 && check_age <= 50) {
                return new Assassin(human, eagle);
            }
            else {
                throw Invalid_age_exception("По возрасту не подхоят");
            }
        }
        else {
            throw Invalid_hybrid_exception("Как ты ни крути, но они не пара, не пара");
        }
    }
};

