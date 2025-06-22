#include "creature.h"
using namespace std;
// Реализация класса Animal

Animal::Animal(const string habitat, int age) : habitat(habitat), age(age) {
    if (!is_valid_name(habitat)) {
        throw Invalid_name_exception("Invalid habitat for Animal!");
    }
}
Animal::Animal(const Animal& other) : habitat(other.habitat), age(other.age) {}
Animal::Animal() : habitat("Unknown"), age(0) {}

string Animal::get_name() const { return "Animal"; }
string Animal::get_string() const { return habitat; }
int Animal::get_int() const { return age; }
int Animal::get_age() const { return age; }
string Animal::get_habitat() const { return habitat; }


void Animal::set_habitat(const string& new_habitat) { habitat = new_habitat; }
void Animal::set_age(int new_age) { age = new_age; }
void Animal::make_sound() const { cout << "Some animal sound" << endl; }

void Animal::change_habitat_or_age(int min, int max) {
    cout << "What would you like to change?" << endl;
    cout << "1. Habitat\n2. Age" << endl;
    cout << "Enter the number of the property to change (0 to cancel): ";
    int choice = correct("Choice: ", 0, 2);
    if (choice == 1) {
        set_habitat(validate_and_get_name("Enter new habitat: "));
    }
    else if (choice == 2) {
        set_age(correct("\tEnter new age in [" + to_string(min) + ":" + to_string(max) + "]:", min, max));
    }
}
void Animal::change_me() {
    change_habitat_or_age(1, 100);
}
void Animal::show_me() const {
    cout << "Name: " << get_name() << ", Habitat: " << habitat << ", Age: " << age << endl;
}

Creature* Animal::clone() const {
    return new Animal(get_string(), get_age());
}

void Animal::transfer_data(Creature& other) {
    Animal* otherAnimal = dynamic_cast<Animal*>(&other);
    if (otherAnimal) {
        this->set_habitat(otherAnimal->get_habitat());
        this->set_age(otherAnimal->get_age());
    }
}

// Реализация класса Lion

Lion::Lion(const string& habitat, int age) : Animal(habitat, age) {
    if (!is_valid_name(habitat)) {
        throw Invalid_name_exception("Invalid habitat for Lion!");
    }
    if (age < 0 || age > 25) throw Invalid_age_exception("Age for Lion must be at least [1;25]!");
}
Lion::Lion(const Lion& other) : Animal(other) {}
Lion::Lion() : Animal("Savanna", 5) {} 

string Lion::get_name() const { return "Lion"; }
string Lion::get_string() const { return Animal::get_habitat(); }
void Lion::make_sound() const { cout << "Roar" << endl; }
int Lion::get_int() const { return age; }
void Lion::change_me() {
    cout << "\tLion:" << endl;
    Animal::change_habitat_or_age(1, 25);
    //habitat = validate_and_get_name("Enter new habitat for Lion: ");
    //age = correct("Enter new age for Lion: ", 1, 25);
}

    Creature* Lion::clone() const {
        return new Lion(get_habitat(), get_age());  // Копируем текущий объект
    }
void Lion::show_me() const {
    cout << "Lion - Habitat: " << habitat << ", Age: " << age << endl;
}

void Lion::transfer_data(Creature& other) {
    Lion* otherLion = dynamic_cast<Lion*>(&other);
    if (otherLion) {
        this->set_habitat(otherLion->get_habitat());
        this->set_age(otherLion->get_age());
    }
}

// Реализация класса Eagle

Eagle::Eagle(const string habitat, int age) : Animal(habitat, age) {
    if (!is_valid_name(habitat)) {
        throw Invalid_name_exception("Invalid habitat for Eagle!");
    }
    if (age < 0 || age > 50) throw Invalid_age_exception("Age for Eagle must be at least [1;50]!");
}
Eagle::Eagle(const Eagle& other) : Animal(other) {}
Eagle::Eagle() : Animal("Mountain", 10) {}

string Eagle::get_name() const { return "Eagle"; }
string Eagle::get_string() const { return Animal::get_habitat(); }
int Eagle::get_int() const { return age; }


Creature* Eagle::clone() const {
    return new Eagle(get_habitat(), get_age());  // Копируем текущий объект
}

void Eagle::make_sound() const { cout << "Screech" << endl; }
void Eagle::change_me() {
    cout << "\tEagle:" << endl;
    Animal::change_habitat_or_age(1, 50);
    //habitat = validate_and_get_name("Enter new habitat for Eagle: ");
    //age = correct("Enter new age for Eagle: ", 1, 50);
}
void Eagle::show_me() const {
    cout << "Eagle - Habitat: " << habitat << ", Age: " << age << endl;
}

void Eagle::transfer_data(Creature& other) {
    Eagle* otherEagle = dynamic_cast<Eagle*>(&other);
    if (otherEagle) {
        this->set_habitat(otherEagle->get_habitat());
        this->set_age(otherEagle->get_age());
    }
}

// Реализация класса Spider

Spider::Spider(const string web_type, int leg_count) : web_type(web_type), leg_count(leg_count) {
    if (!is_valid_name(web_type)) {
        throw Invalid_name_exception("Invalid web_type for Spider!");
    }
    if (leg_count < 1 || leg_count > 8) throw Invalid_age_exception("Leg_count for Spider must be at least [1;8]!");
}
Spider::Spider(const Spider& other) : web_type(other.web_type), leg_count(other.leg_count) {}
Spider::Spider() : web_type("Sticky"), leg_count(8) {}

string Spider::get_name() const { return "Spider"; }
string Spider::get_string() const { return web_type; }
int Spider::get_int() const { return leg_count; }


string Spider::get_web_type() const { return web_type; }
void Spider::set_web_type(const string& new_web_type) { web_type = new_web_type; }

int Spider::get_leg_count() const { return leg_count; }
void Spider::set_leg_count(int new_leg_count) { leg_count = new_leg_count; }

void Spider::make_sound() const { cout << "Hiss" << endl; }
void Spider::change_me() {
    cout << "What would you like to change?" << endl;
    cout << "1. Type of web\n2. Counts of leg" << endl;
    cout << "Enter the number of the property to change (0 to cancel): ";
    int choice = correct("Choice: ", 0, 2);
    if (choice == 1) {
		set_web_type(validate_and_get_name("Enter new web type for Spider: "));
    }
    else if (choice == 2) {
        set_leg_count(correct("\tEnter new counts of leg for Spider in [" + to_string(1) + ":" + to_string(8) + "]:", 1, 8));
    }

    leg_count = correct("Enter new leg count for Spider: ", 1, 8);
}
void Spider::show_me() const {
    cout << "Spider - Web: " << web_type << ", Legs: " << leg_count << endl;
}

Creature* Spider::clone() const {
    return new Spider(get_web_type(), get_leg_count());
}

void Spider::transfer_data(Creature& other) {
    Spider* otherSpider = dynamic_cast<Spider*>(&other);
    if (otherSpider) {
        this->set_web_type(otherSpider->get_web_type());
        this->set_leg_count(otherSpider->get_leg_count());
    }
}

// Реализация класса Human

Human::Human(const string profession, int age) : profession(profession), age(age) {
    if (!is_valid_name(profession)) {
        throw Invalid_name_exception("Invalid profession for Human!");
    }
    if (age < 0 || age > 100) throw Invalid_age_exception("Age for Human must be at least [1;100]!");
}

Human::Human(const Human& other) : profession(other.profession), age(other.age) {}
Human::Human() : profession("Engineer"), age(30) {}

string Human::get_name() const { return "Human"; }
string Human::get_string() const { return profession; }
int Human::get_int() const { return age; }
void Human::make_sound() const { cout << "Hello, I am human!" << endl; }


string Human::get_profession() const { return profession; }
void Human::set_profession(const string new_profession) { profession = new_profession; }

int Human::get_age() const { return age; }
void Human::set_age(int new_age) { age = new_age; }

void Human::changes_for_human(int min, int max) {
    cout << "What would you like to change?" << endl;
    cout << "1. Profession\n2. Age" << endl;
    cout << "Enter the number of the property to change (0 to cancel): ";
    int choice = correct("Choice: ", 0, 2);
    if (choice == 1) {
        profession = validate_and_get_name("Enter new profession: ");
    }
    else if (choice == 2) {
        change_age(min, max);
    }
}
void Human::change_age(int min, int max) {
        set_age(correct("\tEnter new age in [" + to_string(min) + ":" + to_string(max) + "]:", min, max));
}
void Human::change_me() {
    changes_for_human(1, 100);
}
void Human::show_me() const {
    cout << "Human - Profession: " << profession << ", Age: " << age << endl;
}

Creature* Human::clone() const {
    return new Human(get_profession(), get_age());
}

void Human::transfer_data(Creature& other) {
    Human* otherHuman = dynamic_cast<Human*>(&other);
    if (otherHuman) {
        this->set_profession(otherHuman->get_profession());
        this->set_age(otherHuman->get_age());
    }
}

// Реализация класса Griffon

Griffon::Griffon(const string habitat, int age) : Animal(habitat, age), Eagle(habitat, age), Lion(habitat, age) {}

Griffon::Griffon(const Griffon& other) : Animal(other), Eagle(other), Lion(other) {}
Griffon::Griffon() : Animal(), Eagle(), Lion() {}
/*
Griffon::Griffon(Creature* creature1, Creature* creature2) {
    if (dynamic_cast<Lion*>(creature1) && dynamic_cast<Eagle*>(creature2)) {
        // Логика для Lion и Eagle
        habitat = creature1->get_string();  // Habitat из Lion
        age = (creature1->get_int() + creature2->get_int()) / 2;  // Средний возраст
    }
    else if (dynamic_cast<Lion*>(creature2) && dynamic_cast<Eagle*>(creature1)) {
        // Логика для обратного порядка (Eagle + Lion)
        habitat = creature1->get_string();  // Habitat из Eagle
        age = (creature1->get_int() + creature2->get_int()) / 3;  // Средний возраст
    }
    else {
        throw Invalid_crossbreed_exception("Invalid combination for Griffon.");
    }

    // Теперь вызываем конструкторы базовых классов
    Animal::set_habitat(habitat);
    Animal::set_age(age);
    Eagle::set_habitat(habitat);
    Lion::set_habitat(habitat);
}
*/
Griffon::Griffon(Lion* lion, Eagle* eagle) : Animal(eagle->get_habitat(), (lion->get_age() + eagle->get_age()) / 3), 
                                               Eagle(eagle->get_habitat(), (lion->get_age() + eagle->get_age()) / 3),
                                               Lion(eagle->get_habitat(), (lion->get_age() + eagle->get_age()) / 3){
    cout << "Creating Griffon from Human and Eagle" << endl;
}

string Griffon::get_name() const { return "Griffon"; }
string Griffon::get_string() const {
    return Eagle::get_string();
}
int Griffon::get_int() const { return age; }

    Creature* Griffon::clone() const {
        return new Griffon(Eagle::get_habitat(), Lion::get_age());  // Копируем текущий объект
    }

void Griffon::make_sound() const { cout << "Griffon roar and screech!" << endl; }
void Griffon::change_me() {
    Eagle::change_habitat_or_age(1, 25);
}
void Griffon::show_me() const {
    cout << "Griffon - Habitat: " << habitat << ", Age: " << age << endl;
}

void Griffon::transfer_data(Creature& other) {
    Griffon* otherGriffon = dynamic_cast<Griffon*>(&other);
    if (otherGriffon) {
        this->set_habitat(otherGriffon->get_habitat());
        this->set_age(otherGriffon->get_age());
    }
}
// Реализация класса SpiderMan

SpiderMan::SpiderMan(string profession, string web_type, int age) : Human(profession, age), Spider(web_type, 2) {
    if (age < 15 || age > 100) throw Invalid_age_exception("Age for SpiderMan must be at least [15;100]!");
}

SpiderMan::SpiderMan(const SpiderMan& other) 
    : Human(other), Spider(other) {}
SpiderMan::SpiderMan() : Human(), Spider() {}
SpiderMan::SpiderMan(Human* human, Spider* spider) : Human(human->get_profession(), human->get_age()), 
                                                    Spider(spider->get_web_type(), spider->get_leg_count()) {
    // Проверка и инициализация происходит автоматически через базовые классы
    cout << "Creating SpiderMan from Human and Spider" << endl;
}
/*
SpiderMan::SpiderMan(Creature* creature1, Creature* creature2) {
    if (dynamic_cast<Human*>(creature1) && dynamic_cast<Spider*>(creature2)) {
        // Логика для Spider и Human
        profession = creature1->get_string();  // Profession из Human
        web_type = creature2->get_string();    // Web type из Spider
        age = (creature1->get_int() + creature2->get_int()) / 2;  // Средний возраст
    }
    else if (dynamic_cast<Spider*>(creature1) && dynamic_cast<Human*>(creature2)) {
        // Логика для обратного порядка (Human + Spider)
        profession = creature2->get_string();  // Profession из Human
        web_type = creature1->get_string();    // Web type из Spider
        age = (creature1->get_int() + creature2->get_int()) / 3;  // Средний возраст
    }
    else {
        throw Invalid_crossbreed_exception("Invalid combination for SpiderMan.");
    }

    // Теперь вызываем конструкторы базовых классов
    Human::set_profession(profession);
    Human::set_age(age);
    Spider::set_web_type(web_type);
    Spider::set_leg_count(2);  // Специальный случай для SpiderMan
}
*/

string SpiderMan::get_name() const { return "SpiderMan"; }
string SpiderMan::get_string() const { return profession + "\n" + web_type; }
int SpiderMan::get_int() const { return age; }

void SpiderMan::make_sound() const { cout << "Thwip!" << endl; }
void SpiderMan::change_me() {
    cout << "What would you like to change?" << endl;
    cout << "\t1. Profession or age\n\t2. Type of web\n\t" << endl;
    cout << "Enter the number of the property to change (0 to cancel): ";
    int choice = correct("Choice: ", 0, 2);
    if (choice == 1) {
        Human::changes_for_human(18, 100);
    }
    else if (choice == 2) {
		set_web_type(validate_and_get_name("Enter new web type for Spider: "));
    }
}
void SpiderMan::show_me() const {
    cout << "SpiderMan - Profession: " << profession << ", Web: " << web_type << ", Age: " << age << ", Counts of leg: " << leg_count << endl;
}

Creature* SpiderMan::clone() const {
    return new SpiderMan(get_profession(), get_web_type(), get_age());
}

void SpiderMan::transfer_data(Creature& other) {
    SpiderMan* otherSpiderMan = dynamic_cast<SpiderMan*>(&other);
    if (otherSpiderMan) {
        this->set_profession(otherSpiderMan->get_profession());
        this->set_age(otherSpiderMan->get_age());
        this->set_web_type(otherSpiderMan->get_web_type());
    }
}

// Реализация класса Assassin

Assassin::Assassin(const string profession, const string habitat, int age): Animal(habitat, age), Human(profession, age), Eagle(habitat, age) {
    if (age < 18 || age > 100) throw Invalid_age_exception("Age for Assassin must be at least [18;100]!");
}

/*
Assassin::Assassin(Creature* creature1, Creature* creature2) {
    string new_profession, new_habitat;
    int new_age;
    if (dynamic_cast<Human*>(creature1) && dynamic_cast<Eagle*>(creature2)) {
        // Логика для Human и Eagle
        new_profession = creature1->get_string();  // Profession из Human
        new_habitat = creature2->get_string();    // Habitat из Eagle
        new_age = (creature1->get_int() + creature2->get_int()) / 2;  // Средний возраст
        Human::profession = creature1->get_string();  // Profession из Human
        Eagle::habitat = creature2->get_string();    // Habitat из Eagle
        Human::age = (creature1->get_int() + creature2->get_int()) / 2;  // Средний возраст
        Eagle::age = Human::age;
    }
    else if (dynamic_cast<Eagle*>(creature1) && dynamic_cast<Human*>(creature2)) {
        // Логика для обратного порядка (Eagle + Human)
        new_profession = creature2->get_string();  // Profession из Human
        new_habitat = creature1->get_string();    // Habitat из Eagle
        new_age = (creature1->get_int() + creature2->get_int()) / 2;  // Средний возраст
    }
    else {
        throw Invalid_crossbreed_exception("Invalid combination for Assassin.");
    }

    // Теперь вызываем конструкторы базовых классов
    Human::set_profession(new_profession);
    Human::set_age(new_age);
    Eagle::set_habitat(new_habitat);
    Eagle::set_age(new_age);  // Устанавливаем возраст для Eagle
}
*/

Assassin::Assassin(const Assassin& other) : Human(other), Eagle(other) {}
Assassin::Assassin() : Human(), Eagle() {}

Assassin::Assassin(Human* human, Eagle* eagle) : Animal(eagle->get_habitat(), (human->get_age() + eagle->get_age()) / 2),
                                                         Human(human->get_profession(), (human->get_age() + eagle->get_age()) / 2),
                                                         Eagle(eagle->get_habitat(), (human->get_age() + eagle->get_age()) / 2) {

}
string Assassin::get_name() const { return "Assassin"; }
string Assassin::get_string() const { return profession + "\n" + habitat; }
int Assassin::get_int() const { return Human::age; }

void Assassin::make_sound() const { cout << "Silent footsteps" << endl; }
void Assassin::change_me() {
    cout << "What would you like to change?" << endl;
    cout << "\t1. Profession or age\n\t2. Habitat or age\n\t" << endl;
    cout << "Enter the number of the property to change (0 to cancel): ";
    int choice = correct("Choice: ", 0, 2);
    if (choice == 1) {
        Human::changes_for_human(18, 50);
        Eagle::age = Human::age;
    }
    else if (choice == 2) {
		Animal::change_habitat_or_age(18, 50);
        Human::age = Eagle::age;
    }
}
void Assassin::show_me() const {
    cout << "Assassin - Profession: " << profession << ", Habitat: " << habitat << ", Age: " << Human::age << endl;
}

Creature* Assassin::clone() const {
    return new Assassin(get_profession(), habitat, Human::get_age());
}

void Assassin::transfer_data(Creature& other) {
    Assassin* otherAssassin = dynamic_cast<Assassin*>(&other);
    if (otherAssassin) {
        this->set_profession(otherAssassin->get_profession());
        this->set_habitat(otherAssassin->get_habitat());
        this->Human::set_age(otherAssassin->Human::get_age());
        this->Eagle::set_age(otherAssassin->Eagle::get_age());
    }
}
