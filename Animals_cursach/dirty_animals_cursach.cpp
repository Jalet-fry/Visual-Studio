//#include <iostream>
//#include <cstring>
//#include <string>
//
//class Creature {
//public:
//    virtual std::string getName() const = 0; // Чисто виртуальная функция для получения имени
//    virtual void makeSound() const = 0; // Чисто виртуальная функция для звука
//    virtual ~Creature() {}
//};
//
//class Animal : public Creature {
//public:
//    std::string habitat; // Новое поле: среда обитания
//
//    Animal(const std::string& habitat) : habitat(habitat) {}
//
//    std::string getName() const override {
//        return "Animal";
//    }
//
//    void makeSound() const override {
//        std::cout << "Some animal sound" << std::endl;
//    }
//};
//
//class Bird : public Animal {
//public:
//    Bird(const std::string& habitat) : Animal(habitat) {}
//
//    std::string getName() const override {
//        return "Bird";
//    }
//
//    void makeSound() const override {
//        std::cout << "Chirp" << std::endl;
//    }
//};
//
//class Mammal : public Animal {
//public:
//    Mammal(const std::string& habitat) : Animal(habitat) {}
//
//    std::string getName() const override {
//        return "Mammal";
//    }
//
//    void makeSound() const override {
//        std::cout << "Roar" << std::endl;
//    }
//};
//
//class Eagle : public Bird {
//public:
//    Eagle(const std::string& habitat) : Bird(habitat) {}
//
//    std::string getName() const override {
//        return "Eagle";
//    }
//
//    void makeSound() const override {
//        std::cout << "Screech" << std::endl;
//    }
//};
//
//class Lion : public Mammal {
//public:
//    int prideSize; // Новое поле: размер прайда
//
//    Lion(const std::string& habitat, int prideSize) : Mammal(habitat), prideSize(prideSize) {}
//
//    std::string getName() const override {
//        return "Lion";
//    }
//
//    void makeSound() const override {
//        std::cout << "Roar" << std::endl;
//    }
//};
//
//class Griffon : public Creature {
//public:
//    Lion lion;   // Экземпляр класса Lion
//    Eagle eagle; // Экземпляр класса Eagle
//    std::string wingSpan; // Новое поле: размах крыльев
//
//    Griffon(const Lion& lion, const Eagle& eagle, const std::string& wingSpan)
//        : lion(lion), eagle(eagle), wingSpan(wingSpan) {}
//
//    std::string getName() const override {
//        return "Griffon (Eagle + Lion)";
//    }
//
//    void makeSound() const override {
//        std::cout << "Griffon roar-screech" << std::endl;
//    }
//};
//
//class Spider : public Creature {
//public:
//    std::string webType; // Новое поле: тип паутины
//
//    Spider(const std::string& webType) : webType(webType) {}
//
//    std::string getName() const override {
//        return "Spider";
//    }
//
//    void makeSound() const override {
//        std::cout << "Hiss" << std::endl;
//    }
//};
//
//class Human : public Creature {
//public:
//    std::string profession; // Новое поле: профессия
//
//    Human(const std::string& profession) : profession(profession) {}
//
//    std::string getName() const override {
//        return "Human";
//    }
//
//    void makeSound() const override {
//        std::cout << "Speak" << std::endl;
//    }
//};
//
//class Assassin : public Creature {
//public:
//    Human human; // Экземпляр класса Human
//    Eagle eagle; // Экземпляр класса Eagle
//    std::string hiddenBlade; // Новое поле: скрытый клинок
//
//    Assassin(const Human& human, const Eagle& eagle, const std::string& hiddenBlade)
//        : human(human), eagle(eagle), hiddenBlade(hiddenBlade) {}
//
//    std::string getName() const override {
//        return "Assassin (Human + Eagle)";
//    }
//
//    void makeSound() const override {
//        std::cout << "Silent as the night!" << std::endl;
//    }
//
//    void showHiddenBlade() const {
//        std::cout << "Hidden Blade: " << hiddenBlade << std::endl;
//    }
//};
//
//class SpiderMan : public Creature {
//public:
//    Spider spider; // Экземпляр класса Spider
//    Human human;   // Экземпляр класса Human
//    char* uchenie;
//
//    SpiderMan(const char* uchenie)
//        : spider("Silk"), human("Superhero") {
//        this->uchenie = new char[strlen(uchenie) + 1];
//        strcpy(this->uchenie, uchenie);
//    }
//
//    ~SpiderMan() {
//        delete[] uchenie;
//    }
//
//    std::string getName() const override {
//        return "Spider-Man (Spider + Human)";
//    }
//
//    void makeSound() const override {
//        std::cout << "With great power comes great responsibility!" << std::endl;
//    }
//
//    void showUchenie() const {
//        std::cout << "Uchenie: " << uchenie << std::endl;
//    }
//};
//
//int main() {
//    // Создание объектов
//    Lion lion1("Savanna", 10);
//    Eagle eagle1("Mountain");
//    Griffon griffon1(lion1, eagle1, "Large wingspan");
//
//    Spider spider1("Orb-weaver");
//    Spider spider2("Tangle-web");
//    Human human1("Scientist");
//    Human human2("Artist");
//
//    Assassin assassin1(human1, eagle1, "Assassin's Blade");
//    Assassin assassin2(human2, eagle1, "Hidden Dagger");
//
//    SpiderMan spiderMan1("Наука и ответственность");
//    SpiderMan spiderMan2("Сила и мудрость");
//
//    // Массив для хранения объектов разных типов
//    Creature* creatures[] = {
//        &lion1,&eagle1,
//        &griffon1,
//        &spider1, &spider2,
//        &human1, &human2,
//        &assassin1, &assassin2,
//        &spiderMan1, &spiderMan2
//    };
//
//    // Вывод информации о существах
//    for (Creature* creature : creatures) {
//        std::cout << creature->getName() << ": ";
//        creature->makeSound();
//    }
//
//    // Вывод информации о SpiderMan и Assassin
//    spiderMan1.showUchenie();
//    spiderMan2.showUchenie();
//    assassin1.showHiddenBlade();
//    assassin2.showHiddenBlade();
//
//    return 0;
//}


////#include <iostream>
////#include <cstring>
////#include <string>
////
////class Creature {
////public:
////    virtual std::string getName() const = 0; // Чисто виртуальная функция
////    virtual void makeSound() const = 0; // Чисто виртуальная функция
////    virtual ~Creature() {}
////};
////
////class Animal : public Creature {
////public:
////    std::string habitat; // Среда обитания
////
////    Animal(const std::string& habitat) : habitat(habitat) {}
////
////    std::string getName() const override {
////        return "Animal";
////    }
////
////    void makeSound() const override {
////        std::cout << "Some animal sound" << std::endl;
////    }
////};
////
////class Bird : public Animal {
////public:
////    Bird(const std::string& habitat) : Animal(habitat) {}
////
////    std::string getName() const override {
////        return "Bird";
////    }
////
////    void makeSound() const override {
////        std::cout << "Chirp" << std::endl;
////    }
////};
////
////class Mammal : public Animal {
////public:
////    Mammal(const std::string& habitat) : Animal(habitat) {}
////
////    std::string getName() const override {
////        return "Mammal";
////    }
////
////    void makeSound() const override {
////        std::cout << "Roar" << std::endl;
////    }
////};
////
////class Eagle : public Bird {
////public:
////    Eagle(const std::string& habitat) : Bird(habitat) {}
////
////    std::string getName() const override {
////        return "Eagle";
////    }
////
////    void makeSound() const override {
////        std::cout << "Screech" << std::endl;
////    }
////};
////
////class Lion : public Mammal {
////public:
////    int prideSize; // Размер прайда
////
////    Lion(const std::string& habitat, int prideSize) : Mammal(habitat), prideSize(prideSize) {}
////
////    std::string getName() const override {
////        return "Lion";
////    }
////
////    void makeSound() const override {
////        std::cout << "Roar" << std::endl;
////    }
////};
////
////class Griffon : public Creature {
////public:
////    Lion lion;   // Экземпляр Lion
////    Eagle eagle; // Экземпляр Eagle
////    std::string wingSpan; // Размах крыльев
////
////    Griffon(const Lion& lion, const Eagle& eagle, const std::string& wingSpan)
////        : lion(lion), eagle(eagle), wingSpan(wingSpan) {}
////
////    std::string getName() const override {
////        return "Griffon (Eagle + Lion)";
////    }
////
////    void makeSound() const override {
////        std::cout << "Griffon roar-screech" << std::endl;
////    }
////};
////
////class Spider : public Creature {
////public:
////    std::string webType; // Тип паутины
////
////    Spider(const std::string& webType) : webType(webType) {}
////
////    std::string getName() const override {
////        return "Spider";
////    }
////
////    void makeSound() const override {
////        std::cout << "Hiss" << std::endl;
////    }
////};
////
////class Human : public Creature {
////public:
////    std::string profession; // Профессия
////
////    Human(const std::string& profession) : profession(profession) {}
////
////    std::string getName() const override {
////        return "Human";
////    }
////
////    void makeSound() const override {
////        std::cout << "Speak" << std::endl;
////    }
////};
////
////class Assassin : public Human, public Eagle {
////public:
////    std::string hiddenBlade; // Скрытый клинок
////
////    Assassin(const Human& human, const Eagle& eagle, const std::string& hiddenBlade)
////        : Human(human), Eagle(eagle), hiddenBlade(hiddenBlade) {}
////
////    std::string getName() const override {
////        return "Assassin (Human + Eagle)";
////    }
////
////    void makeSound() const override {
////        std::cout << "Silent as the night!" << std::endl;
////    }
////
////    void showHiddenBlade() const {
////        std::cout << "Hidden Blade: " << hiddenBlade << std::endl;
////    }
////};
////
////class SpiderMan : public Human, public Spider {
////public:
////    char* uchenie; // Учение
////
////    SpiderMan(const char* uchenie)
////        : Human("Superhero"), Spider("Silk") {
////        this->uchenie = new char[strlen(uchenie) + 1];
////        strcpy(this->uchenie, uchenie);
////    }
////
////    ~SpiderMan() {
////        delete[] uchenie;
////    }
////
////    std::string getName() const override {
////        return "Spider-Man (Spider + Human)";
////    }
////
////    void makeSound() const override {
////        std::cout << "With great power comes great responsibility!" << std::endl;
////    }
////
////    void showUchenie() const {
////        std::cout << "Uchenie: " << uchenie << std::endl;
////    }
////};
////
////int main() {
////    // Создание объектов
////    Lion lion1("Savanna", 10);
////    Eagle eagle1("Mountain");
////    Griffon griffon1(lion1, eagle1, "Large wingspan");
////
////    Spider spider1("Orb-weaver");
////    Spider spider2("Tangle-web");
////    Human human1("Scientist");
////    Human human2("Artist");
////
////    Assassin assassin1(human1, eagle1, "Assassin's Blade");
////    Assassin assassin2(human2, eagle1, "Hidden Dagger");
////
////    SpiderMan spiderMan1("Наука и ответственность");
////    SpiderMan spiderMan2("Сила и мудрость");
////
////    // Отдельные массивы для хранения объектов разных типов
////    Lion lions[] = { lion1 };
////    Eagle eagles[] = { eagle1 };
////    Griffon griffons[] = { griffon1 };
////    Spider spiders[] = { spider1, spider2 };
////    Human humans[] = { human1, human2 };
////    Assassin assassins[] = { assassin1, assassin2 };
////    SpiderMan spiderMen[] = { spiderMan1, spiderMan2 };
////
////    // Вывод информации о львах
////    for (const Lion& lion : lions) {
////        std::cout << lion.getName() << ": ";
////        lion.makeSound();
////    }
////
////    // Вывод информации о орлах
////    for (const Eagle& eagle : eagles) {
////        std::cout << eagle.getName() << ": ";
////        eagle.makeSound();
////    }
////
////    // Вывод информации о грифонах
////    for (const Griffon& griffon : griffons) {
////        std::cout << griffon.getName() << ": ";
////        griffon.makeSound();
////    }
////
////    // Вывод информации о пауках
////    for (const Spider& spider : spiders) {
////        std::cout << spider.getName() << ": ";
////        spider.makeSound();
////    }
////
////    // Вывод информации о людях
////    for (const Human& human : humans) {
////        std::cout << human.getName() << ": ";
////        human.makeSound();
////    }
////
////    // Вывод информации о ассасинах
////    for (const Assassin& assassin : assassins) {
////        std::cout << assassin.getName() << ": ";
////        assassin.makeSound();
////        assassin.showHiddenBlade();
////    }
////
////    // Вывод информации о Spider-Man
////    for (const SpiderMan& spiderMan : spiderMen) {
////        std::cout << spiderMan.getName() << ": ";
////        spiderMan.makeSound();
////        spiderMan.showUchenie();
////    }
////
////    return 0;
////}
////


//#include <iostream>
//#include <string>
//
//class Creature {
//public:
//    virtual std::string getName() const = 0; // Чисто виртуальная функция
//    virtual void makeSound() const = 0; // Чисто виртуальная функция
//    virtual ~Creature() {}
//};
//
//class Animal : public Creature {
//public:
//    std::string habitat; // Среда обитания
//    int* age; // Динамическое поле
//
//    Animal(const std::string& habitat) : habitat(habitat) {
//        age = new int(0); // По умолчанию равно 0
//    }
//
//    virtual ~Animal() {
//        delete age;
//    }
//
//    void setAge(int age) {
//        *this->age = age;
//    }
//
//    int getAge() const {
//        return *age;
//    }
//
//    std::string getName() const override {
//        return "Animal";
//    }
//
//    void makeSound() const override {
//        std::cout << "Some animal sound" << std::endl;
//    }
//};
//
//class Bird : public Animal {
//public:
//    Bird(const std::string& habitat) : Animal(habitat) {}
//    virtual ~Bird() {}
//
//    std::string getName() const override {
//        return "Bird";
//    }
//
//    void makeSound() const override {
//        std::cout << "Chirp" << std::endl;
//    }
//};
//
//class Mammal : public Animal {
//public:
//    Mammal(const std::string& habitat) : Animal(habitat) {}
//    virtual ~Mammal() {}
//
//    std::string getName() const override {
//        return "Mammal";
//    }
//
//    void makeSound() const override {
//        std::cout << "Roar" << std::endl;
//    }
//};
//
//class Eagle : public Bird {
//public:
//    Eagle(const std::string& habitat) : Bird(habitat) {}
//    virtual ~Eagle() {}
//
//    std::string getName() const override {
//        return "Eagle";
//    }
//
//    void makeSound() const override {
//        std::cout << "Screech" << std::endl;
//    }
//};
//
//class Lion : public Mammal {
//public:
//    int prideSize; // Размер прайда
//
//    Lion(const std::string& habitat, int prideSize) : Mammal(habitat), prideSize(prideSize) {}
//    virtual ~Lion() {}
//
//    std::string getName() const override {
//        return "Lion";
//    }
//
//    void makeSound() const override {
//        std::cout << "Roar" << std::endl;
//    }
//};
//
//class Griffon : public Creature {
//public:
//    Lion* lion;   // Указатель на Lion
//    Eagle* eagle; // Указатель на Eagle
//    std::string wingSpan; // Размах крыльев
//
//    Griffon(Lion* lion, Eagle* eagle, const std::string& wingSpan)
//        : lion(lion), eagle(eagle), wingSpan(wingSpan) {}
//    
//    virtual ~Griffon() {
//        delete lion;
//        delete eagle;
//    }
//
//    std::string getName() const override {
//        return "Griffon (Eagle + Lion)";
//    }
//
//    void makeSound() const override {
//        std::cout << "Griffon roar-screech" << std::endl;
//    }
//};
//
//class Spider : public Creature {
//public:
//    std::string webType; // Тип паутины
//    int* legCount; // Динамическое поле
//
//    Spider(const std::string& webType) : webType(webType) {
//        legCount = new int(0); // По умолчанию равно 0
//    }
//    
//    virtual ~Spider() {
//        delete legCount;
//    }
//
//    void setLegCount(int count) {
//        *legCount = count;
//    }
//
//    std::string getName() const override {
//        return "Spider";
//    }
//
//    void makeSound() const override {
//        std::cout << "Hiss" << std::endl;
//    }
//};
//
//class Human : public Creature {
//public:
//    std::string profession; // Профессия
//    int* intelligence; // Динамическое поле
//    int* age; // Динамическое поле
//
//    Human(const std::string& profession) : profession(profession) {
//        intelligence = new int(0); // По умолчанию равно 0
//        age = new int(0); // По умолчанию равно 0
//    }
//    
//    virtual ~Human() {
//        delete intelligence;
//        delete age;
//    }
//
//    void setIntelligence(int value) {
//        *intelligence = value;
//    }
//
//    void setAge(int age) {
//        *this->age = age;
//    }
//
//    int getAge() const {
//        return *age;
//    }
//
//    std::string getName() const override {
//        return "Human";
//    }
//
//    void makeSound() const override {
//        std::cout << "Speak" << std::endl;
//    }
//};
//
//class Assassin : public Human, public Eagle {
//public:
//    int hiddenBlade; // Скрытый клинок
//
//    Assassin(const Human& human, const Eagle& eagle, int hiddenBlade)
//        : Human(human), Eagle(eagle), hiddenBlade(hiddenBlade) {
//        // Инициализируем возраст из Human
//        this->age = new int(*human.age); // Копируем значение возраста
//    }
//    
//    virtual ~Assassin() {
//        // Освобождение памяти age, если оно было инициализировано
//        delete age;
//    }
//
//    void setAge(int age) {
//        Human::setAge(age); // Используем метод setAge из Human
//    }
//
//    std::string getName() const override {
//        return "Assassin (Human + Eagle)";
//    }
//
//    void makeSound() const override {
//        std::cout << "Silent as the night!" << std::endl;
//    }
//
//    void showHiddenBlade() const {
//        std::cout << "Hidden Blade: " << hiddenBlade << std::endl;
//    }
//};
//
//class SpiderMan : public Human, public Spider {
//public:
//    std::string uchenie; // Учение
//
//    SpiderMan(const std::string& uchenie)
//        : Human("Superhero"), Spider("Silk"), uchenie(uchenie) {}
//    
//    ~SpiderMan() {}
//
//    std::string getName() const override {
//        return "Spider-Man (Spider + Human)";
//    }
//
//    void makeSound() const override {
//        std::cout << "With great power comes great responsibility!" << std::endl;
//    }
//
//    void showUchenie() const {
//        std::cout << "Uchenie: " << uchenie << std::endl;
//    }
//};
//
//int main() {
//    // Динамическое создание объектов
//    Lion* lion1 = new Lion("Savanna", 10);
//    Eagle* eagle1 = new Eagle("Mountain");
//    Griffon* griffon1 = new Griffon(lion1, eagle1, "Large wingspan");
//
//    Spider* spider1 = new Spider("Orb-weaver");
//    Spider* spider2 = new Spider("Tangle-web");
//    Human* human1 = new Human("Scientist");
//    Human* human2 = new Human("Artist");
//
//    Assassin* assassin1 = new Assassin(*human1, *eagle1, 1);
//    Assassin* assassin2 = new Assassin(*human2, *eagle1, 2);
//
//    SpiderMan* spiderMan1 = new SpiderMan("Наука и ответственность");
//    SpiderMan* spiderMan2 = new SpiderMan("Сила и мудрость");
//
//    // Установка значений для динамических полей
//    lion1->setAge(5);
//    spider1->setLegCount(8);
//    human1->setIntelligence(120);
//    spiderMan1->setIntelligence(130);
//    human1->setAge(30);
//    human2->setAge(25);
//    assassin1->setAge(35);
//    assassin2->setAge(28);
//
//    // Вывод информации о львах
//    std::cout << lion1->getName() << ": ";
//    lion1->makeSound();
//
//    // Вывод информации о орлах
//    std::cout << eagle1->getName() << ": ";
//    eagle1->makeSound();
//
//    // Вывод информации о грифонах
//    std::cout << griffon1->getName() << ": ";
//    griffon1->makeSound();
//
//    // Вывод информации о пауках
//    std::cout << spider1->getName() << ": ";
//    spider1->makeSound();
//    
//    // Вывод информации о людях
//    std::cout << human1->getName() << ": ";
//    human1->makeSound();
//
//    // Вывод информации о ассасинах
//    std::cout << assassin1->getName() << ": ";
//    assassin1->makeSound();
//    assassin1->showHiddenBlade();
//
//    // Вывод информации о Spider-Man
//    std::cout << spiderMan1->getName() << ": ";
//    spiderMan1->makeSound();
//    spiderMan1->showUchenie();
//
//    // Освобождение памяти
//    delete griffon1; // Удалит lion1 и eagle1
//    delete spider1;
//    delete spider2;
//    delete human1;
//    delete human2;
//    delete assassin1;
//    delete assassin2;
//    delete spiderMan1;
//    delete spiderMan2;
//
//    return 0;
//}
//

//////////////////#include <iostream>
//////////////////#include <string>
//////////////////#include <vector>
//////////////////#include <memory>
//////////////////
//////////////////class Creature {
//////////////////public:
//////////////////    virtual std::string getName() const = 0; // Чисто виртуальная функция
//////////////////    virtual void makeSound() const = 0; // Чисто виртуальная функция
//////////////////    virtual ~Creature() {}
//////////////////};
//////////////////
//////////////////class Animal : public Creature {
//////////////////protected:
//////////////////    std::string habitat; // Среда обитания
//////////////////    int age; // Возраст
//////////////////
//////////////////public:
//////////////////    Animal(const std::string& habitat, int age = 0) : habitat(habitat), age(age) {}
//////////////////
//////////////////    virtual ~Animal() {}
//////////////////
//////////////////    void setAge(int age) {
//////////////////        this->age = age;
//////////////////    }
//////////////////
//////////////////    int getAge() const {
//////////////////        return age;
//////////////////    }
//////////////////
//////////////////    std::string getName() const override {
//////////////////        return "Animal";
//////////////////    }
//////////////////
//////////////////    void makeSound() const override {
//////////////////        std::cout << "Some animal sound" << std::endl;
//////////////////    }
//////////////////};
//////////////////
//////////////////class Bird : public Animal {
//////////////////public:
//////////////////    Bird(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
//////////////////    
//////////////////    std::string getName() const override {
//////////////////        return "Bird";
//////////////////    }
//////////////////
//////////////////    void makeSound() const override {
//////////////////        std::cout << "Chirp" << std::endl;
//////////////////    }
//////////////////};
//////////////////
//////////////////class Mammal : public Animal {
//////////////////public:
//////////////////    Mammal(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
//////////////////
//////////////////    std::string getName() const override {
//////////////////        return "Mammal";
//////////////////    }
//////////////////
//////////////////    void makeSound() const override {
//////////////////        std::cout << "Roar" << std::endl;
//////////////////    }
//////////////////};
//////////////////
//////////////////class Eagle : public Bird {
//////////////////public:
//////////////////    Eagle(const std::string& habitat, int age = 0) : Bird(habitat, age) {}
//////////////////
//////////////////    std::string getName() const override {
//////////////////        return "Eagle";
//////////////////    }
//////////////////
//////////////////    void makeSound() const override {
//////////////////        std::cout << "Screech" << std::endl;
//////////////////    }
//////////////////};
//////////////////
//////////////////class Lion : public Mammal {
//////////////////public:
//////////////////    Lion(const std::string& habitat, int age = 0) : Mammal(habitat, age) {}
//////////////////
//////////////////    std::string getName() const override {
//////////////////        return "Lion";
//////////////////    }
//////////////////
//////////////////    void makeSound() const override {
//////////////////        std::cout << "Roar" << std::endl;
//////////////////    }
//////////////////};
//////////////////
//////////////////class Hybrid : public Creature {
//////////////////private:
//////////////////    std::shared_ptr<Creature> parent1;
//////////////////    std::shared_ptr<Creature> parent2;
//////////////////
//////////////////public:
//////////////////    Hybrid(std::shared_ptr<Creature> p1, std::shared_ptr<Creature> p2)
//////////////////        : parent1(p1), parent2(p2) {}
//////////////////
//////////////////    std::string getName() const override {
//////////////////        return "Hybrid (" + parent1->getName() + " + " + parent2->getName() + ")";
//////////////////    }
//////////////////
//////////////////    void makeSound() const override {
//////////////////        std::cout << "Hybrid sound!" << std::endl;
//////////////////    }
//////////////////};
//////////////////
//////////////////class ZooPedia {
//////////////////private:
//////////////////    std::vector<std::shared_ptr<Creature>> creatures;
//////////////////
//////////////////public:
//////////////////    void addCreature(std::shared_ptr<Creature> creature) {
//////////////////        creatures.push_back(creature);
//////////////////    }
//////////////////
//////////////////    void showCreatures() const {
//////////////////        for (const auto& creature : creatures) {
//////////////////            std::cout << creature->getName() << " makes sound: ";
//////////////////            creature->makeSound();
//////////////////        }
//////////////////    }
//////////////////
//////////////////    void createHybrid(int index1, int index2) {
//////////////////        if (index1 < creatures.size() && index2 < creatures.size()) {
//////////////////            auto hybrid = std::make_shared<Hybrid>(creatures[index1], creatures[index2]);
//////////////////            std::cout << "Created a new " << hybrid->getName() << std::endl;
//////////////////            addCreature(hybrid);
//////////////////        } else {
//////////////////            std::cout << "Invalid indices for hybrid creation!" << std::endl;
//////////////////        }
//////////////////    }
//////////////////};
//////////////////
//////////////////int main() {
//////////////////    ZooPedia zoo;
//////////////////
//////////////////    // Добавляем животных
//////////////////    zoo.addCreature(std::make_shared<Lion>("Savanna", 5));
//////////////////    zoo.addCreature(std::make_shared<Eagle>("Mountain", 3));
//////////////////
//////////////////    std::cout << "Creatures in ZooPedia:" << std::endl;
//////////////////    zoo.showCreatures();
//////////////////
//////////////////    // Создаем гибрид
//////////////////    zoo.createHybrid(0, 1); // Lion + Eagle
//////////////////
//////////////////    std::cout << "After creating hybrid:" << std::endl;
//////////////////    zoo.showCreatures();
//////////////////
//////////////////    return 0;
//////////////////}
//////////////////

////////////////#include <iostream>
////////////////#include <string>
////////////////#include <vector>
////////////////#include <memory>
////////////////
////////////////class Creature {
////////////////public:
////////////////    virtual std::string getName() const = 0; // Чисто виртуальная функция
////////////////    virtual void makeSound() const = 0; // Чисто виртуальная функция
////////////////    virtual ~Creature() {}
////////////////};
////////////////
////////////////class Animal : public Creature {
////////////////protected:
////////////////    std::string habitat; // Среда обитания
////////////////    int age; // Возраст
////////////////
////////////////public:
////////////////    Animal(const std::string& habitat, int age = 0) : habitat(habitat), age(age) {}
////////////////
////////////////    virtual ~Animal() {}
////////////////
////////////////    void setAge(int age) {
////////////////        this->age = age;
////////////////    }
////////////////
////////////////    int getAge() const {
////////////////        return age;
////////////////    }
////////////////
////////////////    std::string getName() const override {
////////////////        return "Animal";
////////////////    }
////////////////
////////////////    void makeSound() const override {
////////////////        std::cout << "Some animal sound" << std::endl;
////////////////    }
////////////////};
////////////////
////////////////class Bird : public Animal {
////////////////public:
////////////////    Bird(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
////////////////    
////////////////    std::string getName() const override {
////////////////        return "Bird";
////////////////    }
////////////////
////////////////    void makeSound() const override {
////////////////        std::cout << "Chirp" << std::endl;
////////////////    }
////////////////};
////////////////
////////////////class Mammal : public Animal {
////////////////public:
////////////////    Mammal(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
////////////////
////////////////    std::string getName() const override {
////////////////        return "Mammal";
////////////////    }
////////////////
////////////////    void makeSound() const override {
////////////////        std::cout << "Roar" << std::endl;
////////////////    }
////////////////};
////////////////
////////////////class Eagle : public Bird {
////////////////public:
////////////////    Eagle(const std::string& habitat, int age = 0) : Bird(habitat, age) {}
////////////////
////////////////    std::string getName() const override {
////////////////        return "Eagle";
////////////////    }
////////////////
////////////////    void makeSound() const override {
////////////////        std::cout << "Screech" << std::endl;
////////////////    }
////////////////};
////////////////
////////////////class Lion : public Mammal {
////////////////public:
////////////////    Lion(const std::string& habitat, int age = 0) : Mammal(habitat, age) {}
////////////////
////////////////    std::string getName() const override {
////////////////        return "Lion";
////////////////    }
////////////////
////////////////    void makeSound() const override {
////////////////        std::cout << "Roar" << std::endl;
////////////////    }
////////////////};
////////////////
////////////////class Human : public Creature {
////////////////protected:
////////////////    std::string profession; // Профессия
////////////////    int age; // Возраст
////////////////
////////////////public:
////////////////    Human(const std::string& profession, int age = 0) : profession(profession), age(age) {}
////////////////
////////////////    virtual ~Human() {}
////////////////
////////////////    void setAge(int age) {
////////////////        this->age = age;
////////////////    }
////////////////
////////////////    int getAge() const {
////////////////        return age;
////////////////    }
////////////////
////////////////    std::string getName() const override {
////////////////        return "Human";
////////////////    }
////////////////
////////////////    void makeSound() const override {
////////////////        std::cout << "Speak" << std::endl;
////////////////    }
////////////////};
////////////////
////////////////class Assassin : public Human {
////////////////private:
////////////////    int hiddenBlade; // Скрытый клинок
////////////////
////////////////public:
////////////////    Assassin(const std::string& profession, int age, int hiddenBlade)
////////////////        : Human(profession, age), hiddenBlade(hiddenBlade) {}
////////////////
////////////////    ~Assassin() {}
////////////////
////////////////    std::string getName() const override {
////////////////        return "Assassin (Human)";
////////////////    }
////////////////
////////////////    void makeSound() const override {
////////////////        std::cout << "Silent as the night!" << std::endl;
////////////////    }
////////////////
////////////////    void showHiddenBlade() const {
////////////////        std::cout << "Hidden Blade: " << hiddenBlade << std::endl;
////////////////    }
////////////////};
////////////////
////////////////class Griffon : public Creature {
////////////////private:
////////////////    std::shared_ptr<Lion> lion;   // Указатель на Lion
////////////////    std::shared_ptr<Eagle> eagle; // Указатель на Eagle
////////////////    std::string wingSpan; // Размах крыльев
////////////////
////////////////public:
////////////////    Griffon(std::shared_ptr<Lion> lion, std::shared_ptr<Eagle> eagle, const std::string& wingSpan)
////////////////        : lion(lion), eagle(eagle), wingSpan(wingSpan) {}
////////////////
////////////////    ~Griffon() {}
////////////////
////////////////    std::string getName() const override {
////////////////        return "Griffon (Eagle + Lion)";
////////////////    }
////////////////
////////////////    void makeSound() const override {
////////////////        std::cout << "Griffon roar-screech" << std::endl;
////////////////    }
////////////////};
////////////////
////////////////class Hybrid : public Creature {
////////////////private:
////////////////    std::shared_ptr<Creature> parent1;
////////////////    std::shared_ptr<Creature> parent2;
////////////////
////////////////public:
////////////////    Hybrid(std::shared_ptr<Creature> p1, std::shared_ptr<Creature> p2)
////////////////        : parent1(p1), parent2(p2) {}
////////////////
////////////////    std::string getName() const override {
////////////////        return "Hybrid (" + parent1->getName() + " + " + parent2->getName() + ")";
////////////////    }
////////////////
////////////////    ~Hybrid() {}
////////////////    void makeSound() const override {
////////////////        std::cout << "Hybrid sound!" << std::endl;
////////////////    }
////////////////};
////////////////
////////////////class ZooPedia {
////////////////private:
////////////////    std::vector<std::shared_ptr<Creature>> creatures;
////////////////
////////////////public:
////////////////    void addCreature(std::shared_ptr<Creature> creature) {
////////////////        creatures.push_back(creature);
////////////////    }
////////////////
////////////////    void showCreatures() const {
////////////////        for (const auto& creature : creatures) {
////////////////            std::cout << creature->getName() << " makes sound: ";
////////////////            creature->makeSound();
////////////////        }
////////////////    }
////////////////
////////////////    void createHybrid(int index1, int index2) {
////////////////        if (index1 < creatures.size() && index2 < creatures.size()) {
////////////////            auto hybrid = std::make_shared<Hybrid>(creatures[index1], creatures[index2]);
////////////////            std::cout << "Created a new " << hybrid->getName() << std::endl;
////////////////            addCreature(hybrid);
////////////////        } else {
////////////////            std::cout << "Invalid indices for hybrid creation!" << std::endl;
////////////////        }
////////////////    }
////////////////};
////////////////
////////////////int main() {
////////////////    ZooPedia zoo;
////////////////
////////////////    // Добавляем животных
////////////////    auto lion1 = std::make_shared<Lion>("Savanna", 5);
////////////////    auto eagle1 = std::make_shared<Eagle>("Mountain", 3);
////////////////    auto griffon1 = std::make_shared<Griffon>(lion1, eagle1, "Large wingspan");
////////////////
////////////////    auto human1 = std::make_shared<Human>("Scientist", 30);
////////////////    auto assassin1 = std::make_shared<Assassin>("Assassin", 35, 1);
////////////////
////////////////    zoo.addCreature(lion1);
////////////////    zoo.addCreature(eagle1);
////////////////    zoo.addCreature(griffon1);
////////////////    zoo.addCreature(human1);
////////////////    zoo.addCreature(assassin1);
////////////////
////////////////    std::cout << "Creatures in ZooPedia:" << std::endl;
////////////////    zoo.showCreatures();
////////////////
////////////////    // Создаем гибрид
////////////////    zoo.createHybrid(0, 1); // Lion + Eagle
////////////////
////////////////    std::cout << "After creating hybrid:" << std::endl;
////////////////    zoo.showCreatures();
////////////////
////////////////    return 0;
////////////////}
////////////////



//#include <iostream>
//#include <string>
//#include <vector>
//#include <memory>

//class Creature { public: virtual std::string getName() const = 0; virtual void makeSound() const = 0; virtual ~Creature() {} }; class Animal : public Creature { protected: std::string habitat; int age; public: Animal(const std::string& habitat, int age = 0) : habitat(habitat), age(age) {} virtual ~Animal() {} void setAge(int age) { this->age = age; } int getAge() const { return age; } std::string getName() const override { return "Animal"; } void makeSound() const override { std::cout << "Some animal sound" << std::endl; } }; class Bird : public Animal { public: Bird(const std::string& habitat, int age = 0) : Animal(habitat, age) {} std::string getName() const override { return "Bird"; } ~Bird() {} void makeSound() const override { std::cout << "Chirp" << std::endl; } }; class Mammal : public Animal { public: Mammal(const std::string& habitat, int age = 0) : Animal(habitat, age) {} std::string getName() const override { return "Mammal"; } ~Mammal() {} void makeSound() const override { std::cout << "Roar" << std::endl; } }; class Eagle : public Bird { public: Eagle(const std::string& habitat, int age = 0) : Bird(habitat, age) {} std::string getName() const override { return "Eagle"; } ~Eagle() {} void makeSound() const override { std::cout << "Screech" << std::endl; } }; class Lion : public Mammal { public: Lion(const std::string& habitat, int age = 0) : Mammal(habitat, age) {} std::string getName() const override { return "Lion"; } ~Lion() {} void makeSound() const override { std::cout << "Roar" << std::endl; } }; class Human : public Creature { protected: std::string profession; int age; public: Human(const std::string& profession, int age = 0) : profession(profession), age(age) {} virtual ~Human() {} void setAge(int age) { this->age = age; } int getAge() const { return age; } std::string getName() const override { return "Human"; } void makeSound() const override { std::cout << "Speak" << std::endl; } }; class Assassin : public Human { private: int hiddenBlade; public: Assassin(const std::string& profession, int age, int hiddenBlade) : Human(profession, age), hiddenBlade(hiddenBlade) {} ~Assassin() {} std::string getName() const override { return "Assassin (Human)"; } void makeSound() const override { std::cout << "Silent as the night!" << std::endl; } void showHiddenBlade() const { std::cout << "Hidden Blade: " << hiddenBlade << std::endl; } }; class Griffon : public Creature { private: std::shared_ptr<Lion> lion; std::shared_ptr<Eagle> eagle; std::string wingSpan; public: Griffon(std::shared_ptr<Lion> lion, std::shared_ptr<Eagle> eagle, const std::string& wingSpan) : lion(lion), eagle(eagle), wingSpan(wingSpan) {} ~Griffon() {} std::string getName() const override { return "Griffon (Eagle + Lion)"; } void makeSound() const override { std::cout << "Griffon roar-screech" << std::endl; } }; class Hybrid : public Creature { private: std::shared_ptr<Creature> parent1; std::shared_ptr<Creature> parent2; public: Hybrid(std::shared_ptr<Creature> p1, std::shared_ptr<Creature> p2) : parent1(p1), parent2(p2) {} std::string getName() const override { return "Hybrid (" + parent1->getName() + " + " + parent2->getName() + ")"; } ~Hybrid() {} void makeSound() const override { std::cout << "Hybrid sound!" << std::endl; } }; class ZooPedia { private: std::vector<std::shared_ptr<Creature>> creatures; public: void addCreature(std::shared_ptr<Creature> creature) { creatures.push_back(creature); } void showCreatures() const { for (const auto& creature : creatures) { std::cout << creature->getName() << " makes sound: "; creature->makeSound(); } } ~ZooPedia() {} void createHybrid(int index1, int index2) { if (index1 < creatures.size() && index2 < creatures.size()) { auto hybrid = std::make_shared<Hybrid>(creatures[index1], creatures[index2]); std::cout << "Created a new " << hybrid->getName() << std::endl; addCreature(hybrid); } else { std::cout << "Invalid indices for hybrid creation!" << std::endl; } } }; int main() { ZooPedia zoo; auto lion1 = std::make_shared<Lion>("Savanna", 5); auto eagle1 = std::make_shared<Eagle>("Mountain", 3); auto griffon1 = std::make_shared<Griffon>(lion1, eagle1, "Large wingspan"); auto human1 = std::make_shared<Human>("Scientist", 30); auto assassin1 = std::make_shared<Assassin>("Assassin", 35, 1); zoo.addCreature(lion1); zoo.addCreature(eagle1); zoo.addCreature(griffon1); zoo.addCreature(human1); zoo.addCreature(assassin1); std::cout << "Creatures in ZooPedia:" << std::endl; zoo.showCreatures(); zoo.createHybrid(0, 1); std::cout << "After creating hybrid:" << std::endl; zoo.showCreatures(); return 0; } #include <iostream> #include <string> #include <vector> #include <memory> class Creature { public: virtual std::string getName() const = 0; virtual void makeSound() const = 0; virtual ~Creature() {} }; class Animal : public Creature { protected: std::string habitat; int age; public: Animal(const std::string& habitat, int age = 0) : habitat(habitat), age(age) {} virtual ~Animal() {} void setAge(int age) { this->age = age; } int getAge() const { return age; } std::string getName() const override { return "Animal"; } void makeSound() const override { std::cout << "Some animal sound" << std::endl; } }; class Bird : public Animal { public: Bird(const std::string& habitat, int age = 0) : Animal(habitat, age) {} std::string getName() const override { return "Bird"; } ~Bird() {} void makeSound() const override { std::cout << "Chirp" << std::endl; } }; class Mammal : public Animal { public: Mammal(const std::string& habitat, int age = 0) : Animal(habitat, age) {} std::string getName() const override { return "Mammal"; } ~Mammal() {} void makeSound() const override { std::cout << "Roar" << std::endl; } }; class Eagle : public Bird { public: Eagle(const std::string& habitat, int age = 0) : Bird(habitat, age) {} std::string getName() const override { return "Eagle"; } ~Eagle() {} void makeSound() const override { std::cout << "Screech" << std::endl; } }; class Lion : public Mammal { public: Lion(const std::string& habitat, int age = 0) : Mammal(habitat, age) {} std::string getName() const override { return "Lion"; } ~Lion() {} void makeSound() const override { std::cout << "Roar" << std::endl; } }; class Human : public Creature { protected: std::string profession; int age; public: Human(const std::string& profession, int age = 0) : profession(profession), age(age) {} virtual ~Human() {} void setAge(int age) { this->age = age; } int getAge() const { return age; } std::string getName() const override { return "Human"; } void makeSound() const override { std::cout << "Speak" << std::endl; } }; class Assassin : public Human { private: int hiddenBlade; public: Assassin(const std::string& profession, int age, int hiddenBlade) : Human(profession, age), hiddenBlade(hiddenBlade) {} ~Assassin() {} std::string getName() const override { return "Assassin (Human)"; } void makeSound() const override { std::cout << "Silent as the night!" << std::endl; } void showHiddenBlade() const { std::cout << "Hidden Blade: " << hiddenBlade << std::endl; } }; class Griffon : public Creature { private: std::shared_ptr<Lion> lion; std::shared_ptr<Eagle> eagle; std::string wingSpan; public: Griffon(std::shared_ptr<Lion> lion, std::shared_ptr<Eagle> eagle, const std::string& wingSpan) : lion(lion), eagle(eagle), wingSpan(wingSpan) {} ~Griffon() {} std::string getName() const override { return "Griffon (Eagle + Lion)"; } void makeSound() const override { std::cout << "Griffon roar-screech" << std::endl; } }; class Hybrid : public Creature { private: std::shared_ptr<Creature> parent1; std::shared_ptr<Creature> parent2; public: Hybrid(std::shared_ptr<Creature> p1, std::shared_ptr<Creature> p2) : parent1(p1), parent2(p2) {} std::string getName() const override { return "Hybrid (" + parent1->getName() + " + " + parent2->getName() + ")"; } ~Hybrid() {} void makeSound() const override { std::cout << "Hybrid sound!" << std::endl; } }; class ZooPedia { private: std::vector<std::shared_ptr<Creature>> creatures; public: void addCreature(std::shared_ptr<Creature> creature) { creatures.push_back(creature); } void showCreatures() const { for (const auto& creature : creatures) { std::cout << creature->getName() << " makes sound: "; creature->makeSound(); } } ~ZooPedia() {} void createHybrid(int index1, int index2) { if (index1 < creatures.size() && index2 < creatures.size()) { auto hybrid = std::make_shared<Hybrid>(creatures[index1], creatures[index2]); std::cout << "Created a new " << hybrid->getName() << std::endl; addCreature(hybrid); } else { std::cout << "Invalid indices for hybrid creation!" << std::endl; } } }; int main() { ZooPedia zoo; auto lion1 = std::make_shared<Lion>("Savanna", 5); auto eagle1 = std::make_shared<Eagle>("Mountain", 3); auto griffon1 = std::make_shared<Griffon>(lion1, eagle1, "Large wingspan"); auto human1 = std::make_shared<Human>("Scientist", 30); auto assassin1 = std::make_shared<Assassin>("Assassin", 35, 1); zoo.addCreature(lion1); zoo.addCreature(eagle1); zoo.addCreature(griffon1); zoo.addCreature(human1); zoo.addCreature(assassin1); std::cout << "Creatures in ZooPedia:" << std::endl; zoo.showCreatures(); zoo.createHybrid(0, 1);  std::cout << "After creating hybrid:" << std::endl; zoo.showCreatures(); return 0; } 


//#include <iostream>
//#include <string>
//#include <vector>
//#include <memory>
//
//class Creature {
//public:
//    virtual std::string getName() const = 0; // Чисто виртуальная функция
//    virtual void makeSound() const = 0; // Чисто виртуальная функция
//    virtual ~Creature() {}
//};
//
//class Animal : public Creature {
//protected:
//    std::string habitat; // Среда обитания
//    int age; // Возраст
//
//public:
//    Animal(const std::string& habitat, int age = 0) : habitat(habitat), age(age) {}
//
//    virtual ~Animal() {}
//
//    void setAge(int age) {
//        this->age = age;
//    }
//
//    int getAge() const {
//        return age;
//    }
//
//    std::string getName() const override {
//        return "Animal";
//    }
//
//    void makeSound() const override {
//        std::cout << "Some animal sound" << std::endl;
//    }
//};
//
//class Bird : public Animal {
//public:
//    Bird(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
//    
//    std::string getName() const override {
//        return "Bird";
//    }
//
//    void makeSound() const override {
//        std::cout << "Chirp" << std::endl;
//    }
//};
//
//class Mammal : public Animal {
//public:
//    Mammal(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
//
//    std::string getName() const override {
//        return "Mammal";
//    }
//
//    void makeSound() const override {
//        std::cout << "Roar" << std::endl;
//    }
//};
//
//class Eagle : public Bird {
//public:
//    Eagle(const std::string& habitat, int age = 0) : Bird(habitat, age) {}
//
//    std::string getName() const override {
//        return "Eagle";
//    }
//
//    void makeSound() const override {
//        std::cout << "Screech" << std::endl;
//    }
//};
//
//class Lion : public Mammal {
//public:
//    Lion(const std::string& habitat, int age = 0) : Mammal(habitat, age) {}
//
//    std::string getName() const override {
//        return "Lion";
//    }
//
//    void makeSound() const override {
//        std::cout << "Roar" << std::endl;
//    }
//};
//
//class Human : public Creature {
//protected:
//    std::string profession; // Профессия
//    int age; // Возраст
//
//public:
//    Human(const std::string& profession, int age = 0) : profession(profession), age(age) {}
//
//    virtual ~Human() {}
//
//    void setAge(int age) {
//        this->age = age;
//    }
//
//    int getAge() const {
//        return age;
//    }
//
//    std::string getName() const override {
//        return "Human";
//    }
//
//    void makeSound() const override {
//        std::cout << "Speak" << std::endl;
//    }
//};
//
//class Assassin : public Human {
//private:
//    int hiddenBlade; // Скрытый клинок
//
//public:
//    Assassin(const std::string& profession, int age, int hiddenBlade)
//        : Human(profession, age), hiddenBlade(hiddenBlade) {}
//
//    ~Assassin() {}
//
//    std::string getName() const override {
//        return "Assassin (Human)";
//    }
//
//    void makeSound() const override {
//        std::cout << "Silent as the night!" << std::endl;
//    }
//
//    void showHiddenBlade() const {
//        std::cout << "Hidden Blade: " << hiddenBlade << std::endl;
//    }
//};
//
//class Spider : public Creature {
//protected:
//    std::string webType; // Тип паутины
//    int legCount; // Количество ног
//
//public:
//    Spider(const std::string& webType, int legCount = 8) : webType(webType), legCount(legCount) {}
//
//    virtual ~Spider() {}
//
//    std::string getName() const override {
//        return "Spider";
//    }
//
//    void makeSound() const override {
//        std::cout << "Hiss" << std::endl;
//    }
//};
//
//class SpiderMan : public Human, public Spider {
//public:
//    std::string uchenie; // Учение
//
//    SpiderMan(const std::string& uchenie)
//        : Human("Superhero", 25), Spider("Silk"), uchenie(uchenie) {}
//    
//    ~SpiderMan() {}
//
//    std::string getName() const override {
//        return "Spider-Man (Spider + Human)";
//    }
//
//    void makeSound() const override {
//        std::cout << "With great power comes great responsibility!" << std::endl;
//    }
//
//    void showUchenie() const {
//        std::cout << "Uchenie: " << uchenie << std::endl;
//    }
//};
//
//class Griffon : public Creature {
//private:
//    Lion* lion;   // Указатель на Lion
//    Eagle* eagle; // Указатель на Eagle
//    std::string wingSpan; // Размах крыльев
//
//public:
//    Griffon(Lion* lion, Eagle* eagle, const std::string& wingSpan)
//        : lion(lion), eagle(eagle), wingSpan(wingSpan) {}
//    
//    virtual ~Griffon() {
//        delete lion;
//        delete eagle;
//    }
//
//    std::string getName() const override {
//        return "Griffon (Eagle + Lion)";
//    }
//
//    void makeSound() const override {
//        std::cout << "Griffon roar-screech" << std::endl;
//    }
//};
//
//int main() {
//    // Динамическое создание объектов
//    Lion* lion1 = new Lion("Savanna", 5);
//    Eagle* eagle1 = new Eagle("Mountain", 3);
//    Griffon* griffon1 = new Griffon(lion1, eagle1, "Large wingspan");
//
//    Human* human1 = new Human("Scientist", 30);
//    Assassin* assassin1 = new Assassin("Assassin", 35, 1);
//    SpiderMan* spiderMan1 = new SpiderMan("Наука и ответственность");
//
//    // Вывод информации
//    std::cout << lion1->getName() << ": ";
//    lion1->makeSound();
//
//    std::cout << eagle1->getName() << ": ";
//    eagle1->makeSound();
//
//    std::cout << griffon1->getName() << ": ";
//    griffon1->makeSound();
//
//    std::cout << human1->getName() << ": ";
//    human1->makeSound();
//
//    std::cout << assassin1->getName() << ": ";
//    assassin1->makeSound();
//    assassin1->showHiddenBlade();
//
//    std::cout << spiderMan1->getName() << ": ";
//    spiderMan1->makeSound();
//    spiderMan1->showUchenie();
//
//    // Освобождение памяти
//    delete griffon1; // Удалит lion1 и eagle1
//    delete human1;
//    delete assassin1;
//    delete spiderMan1;
//
//    return 0;
//}
//


/////#include <iostream>
/////#include <string>
/////#include <vector>
/////
/////class Creature {
/////public:
/////    virtual std::string getName() const = 0; // Pure virtual function
/////    virtual void makeSound() const = 0; // Pure virtual function
/////    virtual ~Creature() {}
/////};
/////
/////class Animal : public Creature {
/////protected:
/////    std::string habitat; // Habitat
/////    int age; // Age
/////
/////public:
/////    Animal(const std::string& habitat, int age = 0) : habitat(habitat), age(age) {}
/////
/////    virtual ~Animal() {}
/////
/////    void setAge(int age) {
/////        this->age = age;
/////    }
/////
/////    int getAge() const {
/////        return age;
/////    }
/////
/////    std::string getHabitat() const {
/////        return habitat;
/////    }
/////
/////    std::string getName() const override {
/////        return "Animal";
/////    }
/////
/////    void makeSound() const override {
/////        std::cout << "Some animal sound" << std::endl;
/////    }
/////};
/////
/////class Bird : public Animal {
/////public:
/////    Bird(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
/////
/////    std::string getName() const override {
/////        return "Bird";
/////    }
/////
/////    void makeSound() const override {
/////        std::cout << "Chirp" << std::endl;
/////    }
/////
/////    void fly() const {
/////        std::cout << "Flying in the sky!" << std::endl;
/////    }
/////};
/////
/////class Mammal : public Animal {
/////public:
/////    Mammal(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
/////
/////    std::string getName() const override {
/////        return "Mammal";
/////    }
/////
/////    void makeSound() const override {
/////        std::cout << "Roar" << std::endl;
/////    }
/////
/////    void run() const {
/////        std::cout << "Running swiftly!" << std::endl;
/////    }
/////};
/////
/////class Eagle : public Bird {
/////public:
/////    Eagle(const std::string& habitat, int age = 0) : Bird(habitat, age) {}
/////
/////    std::string getName() const override {
/////        return "Eagle";
/////    }
/////
/////    void makeSound() const override {
/////        std::cout << "Screech" << std::endl;
/////    }
/////
/////    void hunt() const {
/////        std::cout << "Eagle is hunting!" << std::endl;
/////    }
/////};
/////
/////class Lion : public Mammal {
/////public:
/////    Lion(const std::string& habitat, int age = 0) : Mammal(habitat, age) {}
/////
/////    std::string getName() const override {
/////        return "Lion";
/////    }
/////    
/////    void makeSound() const override {
/////        std::cout << "Roar" << std::endl;
/////    }
/////
/////    void roar() const {
/////        std::cout << "Lion is roaring!" << std::endl;
/////    }
/////};
/////
/////class Human : public Creature {
/////protected:
/////    std::string profession; // Profession
/////    int age; // Age
/////
/////public:
/////    Human(const std::string& profession, int age = 0) : profession(profession), age(age) {}
/////
/////    virtual ~Human() {}
/////
/////    void setAge(int age) {
/////        this->age = age;
/////    }
/////
/////    int getAge() const {
/////        return age;
/////    }
/////
/////    std::string getProfession() const {
/////        return profession;
/////    }
/////
/////    std::string getName() const override {
/////        return "Human";
/////    }
/////
/////    void makeSound() const override {
/////        std::cout << "Speak" << std::endl;
/////    }
/////
/////    void work() const {
/////        std::cout << "Working as a " << profession << "!" << std::endl;
/////    }
/////};
/////
/////class Assassin : public Human {
/////private:
/////    int hiddenBlade; // Hidden blade
/////
/////public:
/////    Assassin(const std::string& profession, int age, int hiddenBlade)
/////        : Human(profession, age), hiddenBlade(hiddenBlade) {}
/////
/////    ~Assassin() {}
/////
/////    std::string getName() const override {
/////        return "Assassin (Human)";
/////    }
/////
/////    void makeSound() const override {
/////        std::cout << "Silent as the night!" << std::endl;
/////    }
/////
/////    void showHiddenBlade() const {
/////        std::cout << "Hidden Blade: " << hiddenBlade << std::endl;
/////    }
/////
/////    void assassinate() const {
/////        std::cout << "Assassin is on a mission!" << std::endl;
/////    }
/////};
/////
/////class Spider : public Creature {
/////protected:
/////    std::string webType; // Web type
/////    int legCount; // Number of legs
/////
/////public:
/////    Spider(const std::string& webType, int legCount = 8) : webType(webType), legCount(legCount) {}
/////
/////    virtual ~Spider() {}
/////
/////    std::string getName() const override {
/////        return "Spider";
/////    }
/////
/////    void makeSound() const override {
/////        std::cout << "Hiss" << std::endl;
/////    }
/////
/////    void spinWeb() const {
/////        std::cout << "Spinning a " << webType << " web!" << std::endl;
/////    }
/////};
/////
/////class SpiderMan : public Human, public Spider {
/////public:
/////    std::string uchenie; // Teaching
/////
/////    SpiderMan(const std::string& uchenie)
/////        : Human("Superhero", 25), Spider("Silk"), uchenie(uchenie) {}
/////    
/////    ~SpiderMan() {}
/////
/////    std::string getName() const override {
/////        return "Spider-Man (Spider + Human)";
/////    }
/////
/////    void makeSound() const override {
/////        std::cout << "With great power comes great responsibility!" << std::endl;
/////    }
/////
/////    void showUchenie() const {
/////        std::cout << "Uchenie: " << uchenie << std::endl;
/////    }
/////
/////    void swing() const {
/////        std::cout << "Swinging through the city!" << std::endl;
/////    }
/////};
/////
/////class Griffon : public Creature {
/////private:
/////    Lion* lion;   // Pointer to Lion
/////    Eagle* eagle; // Pointer to Eagle
/////    std::string wingSpan; // Wingspan
/////
/////public:
/////    Griffon(Lion* lion, Eagle* eagle, const std::string& wingSpan)
/////        : lion(lion), eagle(eagle), wingSpan(wingSpan) {}
/////    
/////    virtual ~Griffon() {
/////        delete lion;
/////        delete eagle;
/////    }
/////
/////    std::string getName() const override {
/////        return "Griffon (Eagle + Lion)";
/////    }
/////
/////    void makeSound() const override {
/////        std::cout << "Griffon roar-screech" << std::endl;
/////    }
/////
/////    void soar() const {
/////        std::cout << "Soaring high with a wingspan of " << wingSpan << "!" << std::endl;
/////    }
/////};
/////
/////int main() {
/////    // Dynamic creation of objects
/////    Lion* lion1 = new Lion("Savanna", 5);
/////    Eagle* eagle1 = new Eagle("Mountain", 3);
/////    Griffon* griffon1 = new Griffon(lion1, eagle1, "Large wingspan");
/////
/////    Human* human1 = new Human("Scientist", 30);
/////    Assassin* assassin1 = new Assassin("Assassin", 35, 1);
/////    SpiderMan* spiderMan1 = new SpiderMan("Наука и ответственность");
/////
/////    // Output information
/////    std::cout << lion1->getName() << ": ";
/////    lion1->makeSound();
/////    lion1->run(); // Unique behavior
/////
/////    std::cout << eagle1->getName() << ": ";
/////    eagle1->makeSound();
/////    eagle1->fly(); // Unique behavior
/////
/////    std::cout << griffon1->getName() << ": ";
/////    griffon1->makeSound();
/////    griffon1->soar(); // Unique behavior
/////
/////    std::cout << human1->getName() << ": ";
/////    human1->makeSound();
/////    human1->work(); // Unique behavior
/////
/////    std::cout << assassin1->getName() << ": ";
/////    assassin1->makeSound();
/////    assassin1->showHiddenBlade();
/////    assassin1->assassinate(); // Unique behavior
/////
/////    std::cout << spiderMan1->getName() << ": ";
/////    spiderMan1->makeSound();
/////    spiderMan1->showUchenie();
/////    spiderMan1->swing(); // Unique behavior
/////
/////    // Freeing memory
/////    delete griffon1; // This will delete lion1 and eagle1 as well
/////    delete human1;
/////    delete assassin1;
/////    delete spiderMan1;
/////
/////    return 0;
/////}
/////



//#include <iostream>
//#include <string>
//#include <vector>
//#include <stdexcept>
//
//// Исключение для некорректного ввода числа
//class InvalidInputException : public std::exception {
//public:
//    const char* what() const noexcept override {
//        return "Ошибка ввода! Введено некорректное значение.";
//    }
//};
//
//// Исключение для некорректного ввода возраста
//class InvalidAgeException : public std::exception {
//public:
//    const char* what() const noexcept override {
//        return "Возраст должен быть положительным числом!";
//    }
//};
//
//// Исключение для некорректного ввода профессии
//class InvalidProfessionException : public std::exception {
//public:
//    const char* what() const noexcept override {
//        return "Профессия не может быть пустой!";
//    }
//};
//
//// Шаблон функции для корректного ввода числа
//template <typename T>
//T getInput(const std::string& prompt) {
//    std::string input;
//    T value;
//    char* endptr;
//
//    while (true) {
//        std::cout << prompt;
//        std::getline(std::cin, input);
//
//        if (input.empty()) {
//            throw InvalidInputException();
//        }
//
//        value = static_cast<T>(strtol(input.c_str(), &endptr, 10));
//        if (*endptr != '\n' && *endptr != '\0') {
//            std::cout << "Это не число. Попробуйте еще раз." << std::endl;
//        } else {
//            break;
//        }
//    }
//
//    return value;
//}
//
//// Шаблон функции для корректного ввода строки
//template <typename T>
//T getStringInput(const std::string& prompt) {
//    std::string input;
//
//    std::cout << prompt;
//    std::getline(std::cin, input);
//
//    if (input.empty()) {
//        throw InvalidProfessionException();
//    }
//
//    return input;
//}
//
//// Абстрактный класс Creature
//class Creature {
//public:
//    virtual std::string getName() const = 0;
//    virtual void makeSound() const = 0;
//    virtual ~Creature() {}
//};
//
//// Класс Animal
//class Animal : public Creature {
//protected:
//    std::string habitat;
//    int age;
//
//public:
//    Animal(const std::string& habitat, int age = 0) : habitat(habitat), age(age) {}
//
//    virtual ~Animal() {}
//
//    void setAge(int age) {
//        if (age < 0) throw InvalidAgeException();
//        this->age = age;
//    }
//
//    int getAge() const {
//        return age;
//    }
//
//    std::string getHabitat() const {
//        return habitat;
//    }
//
//    std::string getName() const override {
//        return "Animal";
//    }
//
//    void makeSound() const override {
//        std::cout << "Some animal sound" << std::endl;
//    }
//};
//
//// Класс Bird
//class Bird : public Animal {
//public:
//    Bird(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
//
//    std::string getName() const override {
//        return "Bird";
//    }
//
//    void makeSound() const override {
//        std::cout << "Chirp" << std::endl;
//    }
//
//    void fly() const {
//        std::cout << "Flying in the sky!" << std::endl;
//    }
//};
//
//// Класс Mammal
//class Mammal : public Animal {
//public:
//    Mammal(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
//
//    std::string getName() const override {
//        return "Mammal";
//    }
//
//    void makeSound() const override {
//        std::cout << "Roar" << std::endl;
//    }
//
//    void run() const {
//        std::cout << "Running swiftly!" << std::endl;
//    }
//};
//
//// Класс Lion
//class Lion : public Mammal {
//public:
//    Lion(const std::string& habitat, int age = 0) : Mammal(habitat, age) {}
//
//    std::string getName() const override {
//        return "Lion";
//    }
//
//    void makeSound() const override {
//        std::cout << "Roar" << std::endl;
//    }
//
//    void roar() const {
//        std::cout << "Lion is roaring!" << std::endl;
//    }
//};
//
//// Класс Eagle
//class Eagle : public Bird {
//public:
//    Eagle(const std::string& habitat, int age = 0) : Bird(habitat, age) {}
//
//    std::string getName() const override {
//        return "Eagle";
//    }
//
//    void makeSound() const override {
//        std::cout << "Screech" << std::endl;
//    }
//
//    void hunt() const {
//        std::cout << "Eagle is hunting!" << std::endl;
//    }
//};
//
//// Класс Human
//class Human : public Creature {
//protected:
//    std::string profession;
//    int age;
//
//public:
//    Human(const std::string& profession, int age = 0) : profession(profession), age(age) {}
//
//    virtual ~Human() {}
//
//    void setAge(int age) {
//        if (age < 0) throw InvalidAgeException();
//        this->age = age;
//    }
//
//    int getAge() const {
//        return age;
//    }
//
//    std::string getProfession() const {
//        return profession;
//    }
//
//    std::string getName() const override {
//        return "Human";
//    }
//
//    void makeSound() const override {
//        std::cout << "Speak" << std::endl;
//    }
//
//    void work() const {
//        std::cout << "Working as a " << profession << "!" << std::endl;
//    }
//};
//
//// Класс Assassin
//class Assassin : public Human {
//private:
//    int hiddenBlade;
//
//public:
//    Assassin(const std::string& profession, int age, int hiddenBlade)
//        : Human(profession, age), hiddenBlade(hiddenBlade) {}
//
//    ~Assassin() {}
//
//    std::string getName() const override {
//        return "Assassin (Human)";
//    }
//
//    void makeSound() const override {
//        std::cout << "Silent as the night!" << std::endl;
//    }
//
//    void showHiddenBlade() const {
//        std::cout << "Hidden Blade: " << hiddenBlade << std::endl;
//    }
//
//    void assassinate() const {
//        std::cout << "Assassin is on a mission!" << std::endl;
//    }
//};
//
//// Класс SpiderMan
//class SpiderMan : public Human {
//public:
//    std::string uchenie;
//
//    SpiderMan(const std::string& uchenie)
//        : Human("Superhero", 25), uchenie(uchenie) {}
//
//    ~SpiderMan() {}
//
//    std::string getName() const override {
//        return "Spider-Man (Spider + Human)";
//    }
//
//    void makeSound() const override {
//        std::cout << "With great power comes great responsibility!" << std::endl;
//    }
//
//    void showUchenie() const {
//        std::cout << "Uchenie: " << uchenie << std::endl;
//    }
//
//    void swing() const {
//        std::cout << "Swinging through the city!" << std::endl;
//    }
//};
//
//// Функция main
//int main() {
//    try {
//        // User input for Lion
//        std::string lionHabitat = getStringInput<std::string>("Введите место обитания льва: ");
//        int lionAge = getInput<int>("Введите возраст льва: ");
//        Lion* lion1 = new Lion(lionHabitat, lionAge);
//
//        // User input for Eagle
//        std::string eagleHabitat = getStringInput<std::string>("Введите место обитания орла: ");
//        int eagleAge = getInput<int>("Введите возраст орла: ");
//        Eagle* eagle1 = new Eagle(eagleHabitat, eagleAge);
//
//        // Create Griffon
//        Griffon* griffon1 = new Griffon(lion1, eagle1, "Large wingspan");
//
//        // User input for Human
//        std::string profession = getStringInput<std::string>("Введите профессию человека: ");
//        int humanAge = getInput<int>("Введите возраст человека: ");
//        Human* human1 = new Human(profession, humanAge);
//
//        // User input for Assassin
//        std::string assassinProfession = getStringInput<std::string>("Введите профессию ассасина: ");
//        int assassinAge = getInput<int>("Введите возраст ассасина: ");
//        int hiddenBlade = getInput<int>("Введите количество скрытых лезвий: ");
//        Assassin* assassin1 = new Assassin(assassinProfession, assassinAge, hiddenBlade);
//
//        // User input for Spider-Man
//        std::string uchenie = getStringInput<std::string>("Введите учение для Человека-Паука: ");
//        SpiderMan* spiderMan1 = new SpiderMan(uchenie);
//
//        // Output information
//        std::cout << lion1->getName() << ": ";
//        lion1->makeSound();
//        lion1->run(); 
//
//        std::cout << eagle1->getName() << ": ";
//        eagle1->makeSound();
//        eagle1->fly(); 
//
//        std::cout << griffon1->getName() << ": ";
//        griffon1->makeSound();
//        griffon1->soar(); 
//
//        std::cout << human1->getName() << ": ";
//        human1->makeSound();
//        human1->work(); 
//
//        std::cout << assassin1->getName() << ": ";
//        assassin1->makeSound();
//        assassin1->showHiddenBlade();
//        assassin1->assassinate(); 
//
//        std::cout << spiderMan1->getName() << ": ";
//        spiderMan1->makeSound();
//        spiderMan1->showUchenie();
//        spiderMan1->swing(); 
//
//        // Freeing memory
//        delete griffon1; // This will delete lion1 and eagle1 as well
//        delete human1;
//        delete assassin1;
//        delete spiderMan1;
//
//    } catch (const std::exception& e) {
//        std::cout << "Произошла ошибка: " << e.what() << std::endl;
//    }
//
//    return 0;
//}







//#include <iostream>
//#include <string>
//#include <vector>
//#include <memory>  // Для использования умных указателей
//
//// Абстрактный класс Creature
//class Creature {
//public:
//    virtual std::string getName() const = 0; // Чисто виртуальная функция
//    virtual void makeSound() const = 0; // Чисто виртуальная функция
//    virtual ~Creature() = default; // Виртуальный деструктор
//};
//
//// Базовый класс Animal
//class Animal : public Creature {
//protected:
//    std::string habitat; // Место обитания
//    int age; // Возраст
//
//public:
//    Animal(const std::string& habitat = "Unknown", int age = 0)
//        : habitat(habitat), age(age) {}
//
//    void setAge(int age) {
//        this->age = age;
//    }
//
//    int getAge() const {
//        return age;
//    }
//
//    std::string getHabitat() const {
//        return habitat;
//    }
//
//    std::string getName() const override {
//        return "Animal";
//    }
//
//    void makeSound() const override {
//        std::cout << "Some animal sound" << std::endl;
//    }
//};
//
//// Производный класс Bird
//class Bird : public Animal {
//public:
//    Bird(const std::string& habitat = "Sky", int age = 0) : Animal(habitat, age) {}
//
//    std::string getName() const override {
//        return "Bird";
//    }
//
//    void makeSound() const override {
//        std::cout << "Chirp" << std::endl;
//    }
//
//    void fly() const {
//        std::cout << "Flying in the sky!" << std::endl;
//    }
//};
//
//// Производный класс Mammal
//class Mammal : public Animal {
//public:
//    Mammal(const std::string& habitat = "Land", int age = 0) : Animal(habitat, age) {}
//
//    std::string getName() const override {
//        return "Mammal";
//    }
//
//    void makeSound() const override {
//        std::cout << "Roar" << std::endl;
//    }
//
//    void run() const {
//        std::cout << "Running swiftly!" << std::endl;
//    }
//};
//
//// Класс Eagle (орел)
//class Eagle : public Bird {
//public:
//    Eagle(const std::string& habitat = "Mountains", int age = 0) : Bird(habitat, age) {}
//
//    std::string getName() const override {
//        return "Eagle";
//    }
//
//    void makeSound() const override {
//        std::cout << "Screech" << std::endl;
//    }
//
//    void hunt() const {
//        std::cout << "Eagle is hunting!" << std::endl;
//    }
//};
//
//// Класс Lion (лев)
//class Lion : public Mammal {
//public:
//    Lion(const std::string& habitat = "Savannah", int age = 0) : Mammal(habitat, age) {}
//
//    std::string getName() const override {
//        return "Lion";
//    }
//
//    void makeSound() const override {
//        std::cout << "Roar" << std::endl;
//    }
//
//    void roar() const {
//        std::cout << "Lion is roaring!" << std::endl;
//    }
//};
//
//// Класс Human (человек)
//class Human : public Creature {
//protected:
//    std::string profession; // Профессия
//    int age; // Возраст
//
//public:
//    Human(const std::string& profession = "Unknown", int age = 0) 
//        : profession(profession), age(age) {}
//
//    std::string getProfession() const {
//        return profession;
//    }
//
//    std::string getName() const override {
//        return "Human";
//    }
//
//    void makeSound() const override {
//        std::cout << "Speak" << std::endl;
//    }
//
//    void work() const {
//        std::cout << "Working as a " << profession << "!" << std::endl;
//    }
//};
//
//// Класс Assassin (ассасин)
//class Assassin : public Human {
//private:
//    int hiddenBlade; // Количество скрытых лезвий
//
//public:
//    Assassin(const std::string& profession, int age, int hiddenBlade)
//        : Human(profession, age), hiddenBlade(hiddenBlade) {}
//
//    std::string getName() const override {
//        return "Assassin (Human)";
//    }
//
//    void makeSound() const override {
//        std::cout << "Silent as the night!" << std::endl;
//    }
//
//    void showHiddenBlade() const {
//        std::cout << "Hidden Blade: " << hiddenBlade << std::endl;
//    }
//
//    void assassinate() const {
//        std::cout << "Assassin is on a mission!" << std::endl;
//    }
//};
//
//// Класс Spider (паук)
//class Spider : public Creature {
//protected:
//    std::string webType; // Тип паутины
//    int legCount; // Количество ног
//
//public:
//    Spider(const std::string& webType = "Silk", int legCount = 8)
//        : webType(webType), legCount(legCount) {}
//
//    std::string getName() const override {
//        return "Spider";
//    }
//
//    void makeSound() const override {
//        std::cout << "Hiss" << std::endl;
//    }
//
//    void spinWeb() const {
//        std::cout << "Spinning a " << webType << " web!" << std::endl;
//    }
//};
//
//// Класс SpiderMan (Человек-Паук)
//class SpiderMan : public Human, public Spider {
//public:
//    std::string uchenie; // Учение
//
//    SpiderMan(const std::string& uchenie)
//        : Human("Superhero", 25), Spider("Silk"), uchenie(uchenie) {}
//
//    std::string getName() const override {
//        return "Spider-Man (Spider + Human)";
//    }
//
//    void makeSound() const override {
//        std::cout << "With great power comes great responsibility!" << std::endl;
//    }
//
//    void showUchenie() const {
//        std::cout << "Uchenie: " << uchenie << std::endl;
//    }
//
//    void swing() const {
//        std::cout << "Swinging through the city!" << std::endl;
//    }
//};
//
//// Класс Griffon (Грифон) с умными указателями
//class Griffon : public Creature {
//private:
//    std::shared_ptr<Lion> lion;   // Умный указатель на льва
//    std::shared_ptr<Eagle> eagle; // Умный указатель на орла
//    std::string wingSpan; // Размах крыльев
//
//public:
//    Griffon(std::shared_ptr<Lion> lion, std::shared_ptr<Eagle> eagle, const std::string& wingSpan)
//        : lion(lion), eagle(eagle), wingSpan(wingSpan) {}
//
//    std::string getName() const override {
//        return "Griffon (Eagle + Lion)";
//    }
//
//    void makeSound() const override {
//        std::cout << "Griffon roar-screech" << std::endl;
//    }
//
//    void soar() const {
//        std::cout << "Soaring high with a wingspan of " << wingSpan << "!" << std::endl;
//    }
//};
//
//// Функция для проверки правильности ввода числа
//int correct(const std::string& prompt) {
//    std::string input;
//    int num;
//    while (true) {
//        std::cout << prompt;
//        std::getline(std::cin, input);
//        if (input.empty()) return -1; // Ввод отменен
//        try {
//            num = std::stoi(input);
//            return num;
//        } catch (...) {
//            std::cout << "Это не число. Попробуйте еще раз." << std::endl;
//        }
//    }
//}
//
//// Функция для ввода строки
//std::string inputString(const std::string& prompt) {
//    std::string input;
//    std::cout << prompt;
//    std::getline(std::cin, input);
//    return input;
//}
//
//int main() {
//    // Ввод данных и создание объектов
//    std::string lionHabitat = inputString("Введите место обитания льва: ");
//    int lionAge = correct("Введите возраст льва: ");
//    auto lion1 = std::make_shared<Lion>(lionHabitat, lionAge);
//
//    std::string eagleHabitat = inputString("Введите место обитания орла: ");
//    int eagleAge = correct("Введите возраст орла: ");
//    auto eagle1 = std::make_shared<Eagle>(eagleHabitat, eagleAge);
//
//    auto griffon1 = std::make_shared<Griffon>(lion1, eagle1, "Large wingspan");
//
//    std::string profession = inputString("Введите профессию человека: ");
//    int humanAge = correct("Введите возраст человека: ");
//    auto human1 = std::make_shared<Human>(profession, humanAge);
//
//    std::string assassinProfession = inputString("Введите профессию ассасина: ");
//    int assassinAge = correct("Введите возраст ассасина: ");
//    int hiddenBlade = correct("Введите количество скрытых лезвий: ");
//    auto assassin1 = std::make_shared<Assassin>(assassinProfession, assassinAge, hiddenBlade);
//
//    std::string uchenie = inputString("Введите учение для Человека-Паука: ");
//    auto spiderMan1 = std::make_shared<SpiderMan>(uchenie);
//
//    // Вывод информации
//    std::cout << lion1->getName() << ": ";
//    lion1->makeSound();
//    lion1->run();
//
//    std::cout << eagle1->getName() << ": ";
//    eagle1->makeSound();
//    eagle1->fly();
//
//    std::cout << griffon1->getName() << ": ";
//    griffon1->makeSound();
//    griffon1->soar();
//
//    std::cout << human1->getName() << ": ";
//    human1->makeSound();
//    human1->work();
//
//    std::cout << assassin1->getName() << ": ";
//    assassin1->makeSound();
//    assassin1->showHiddenBlade();
//    assassin1->assassinate();
//
//    std::cout << spiderMan1->getName() << ": ";
//    spiderMan1->makeSound();
//    spiderMan1->showUchenie();
//    spiderMan1->swing();
//
//    return 0;
//}
//




//#include <iostream>
//#include <vector>
//#include <memory> // Для unique_ptr, если решим использовать
//
//// Класс Creature — базовый для всех существ
//class Creature {
//public:
//    virtual std::string getName() const = 0; // Чисто виртуальная функция
//    virtual void makeSound() const = 0; // Чисто виртуальная функция
//    virtual ~Creature() {}
//};
//
//// Класс Animal — наследуется от Creature
//class Animal : public Creature {
//protected:
//    std::string habitat; // Среда обитания
//    int age; // Возраст
//
//public:
//    Animal(const std::string& habitat, int age = 0) : habitat(habitat), age(age) {}
//
//    virtual ~Animal() {}
//
//    std::string getName() const override {
//        return "Animal";
//    }
//
//    void makeSound() const override {
//        std::cout << "Some animal sound" << std::endl;
//    }
//};
//
//// Класс Bird — наследуется от Animal
//class Bird : public Animal {
//public:
//    Bird(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
//
//    std::string getName() const override {
//        return "Bird";
//    }
//
//    void makeSound() const override {
//        std::cout << "Chirp" << std::endl;
//    }
//
//    void fly() const {
//        std::cout << "Flying in the sky!" << std::endl;
//    }
//};
//
//// Класс Lion — наследуется от Animal
//class Lion : public Animal {
//public:
//    Lion(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
//
//    std::string getName() const override {
//        return "Lion";
//    }
//
//    void makeSound() const override {
//        std::cout << "Roar" << std::endl;
//    }
//};
//
//// Класс CreatureContainer — контейнер для существ
//class CreatureContainer {
//private:
//    std::vector<Creature*> creatures; // Вектор указателей на существ
//
//public:
//    ~CreatureContainer() {
//        // Освобождаем память, выделенную для объектов
//        for (Creature* creature : creatures) {
//            delete creature;
//        }
//    }
//
//    // Добавить существо в контейнер
//    void addCreature(Creature* creature) {
//        creatures.push_back(creature);
//    }
//
//    // Удалить существо из контейнера по индексу
//    void removeCreature(size_t index) {
//        if (index < creatures.size()) {
//            delete creatures[index]; // Освобождаем память
//            creatures.erase(creatures.begin() + index); // Удаляем из вектора
//        }
//    }
//
//    // Показать всех существ в контейнере
//    void showCreatures() const {
//        for (const auto& creature : creatures) {
//            std::cout << creature->getName() << ": ";
//            creature->makeSound();
//        }
//    }
//
//    size_t size() const {
//        return creatures.size();
//    }
//};
//
//int main() {
//    CreatureContainer container;
//
//    // Добавляем различных существ
//    container.addCreature(new Lion("Savanna", 5));
//    container.addCreature(new Bird("Forests", 2));
//
//    // Показываем всех существ
//    std::cout << "All creatures:" << std::endl;
//    container.showCreatures();
//
//    // Удаляем первое существо (например, Lion)
//    container.removeCreature(0);
//
//    // Показываем оставшихся существ
//    std::cout << "\nAfter removing the first creature:" << std::endl;
//    container.showCreatures();
//
//    return 0;
//}
//


////////////#include <iostream>
////////////#include <vector>
////////////#include <string>
////////////
////////////
////////////
////////////static int correct(const std::string& prompt) {
////////////    std::string input;
////////////    int num;
////////////    char* endptr;
////////////    while (true) {
////////////        std::cout << prompt;
////////////        std::getline(std::cin, input);
////////////        if (input.empty()) {
////////////            return -1; // Indicate no input
////////////        }
////////////        num = strtol(input.c_str(), &endptr, 10);
////////////        if (*endptr != '\n' && *endptr != '\0') {
////////////            std::cout << "Это не число. Попробуйте еще раз." << std::endl;
////////////        } else {
////////////            return num;
////////////        }
////////////    }
////////////}
////////////
////////////// Function to get a string input
////////////static std::string inputString(const std::string& prompt) {
////////////    std::string input;
////////////    std::cout << prompt;
////////////    std::getline(std::cin, input);
////////////    return input;
////////////}
////////////class Creature {
////////////public:
////////////    virtual std::string getName() const = 0; 
////////////    virtual void makeSound() const = 0; 
////////////    virtual ~Creature() {}
////////////};
////////////
////////////class Animal : public Creature {
////////////protected:
////////////    std::string habitat; // Среда обитания
////////////    int age; 
////////////
////////////public:
////////////    Animal(const std::string& habitat, int age = 0) : habitat(habitat), age(age) {}
////////////
////////////    virtual ~Animal() {}
////////////
////////////    std::string getName() const override {
////////////        return "Animal";
////////////    }
////////////
////////////    void makeSound() const override {
////////////        std::cout << "Some animal sound" << std::endl;
////////////    }
////////////};
////////////
////////////class Bird : public Animal {
////////////public:
////////////    Bird(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
////////////
////////////    std::string getName() const override {
////////////        return "Bird";
////////////    }
////////////
////////////    void makeSound() const override {
////////////        std::cout << "Chirp" << std::endl;
////////////    }
////////////
////////////    void fly() const {
////////////        std::cout << "Flying in the sky!" << std::endl;
////////////    }
////////////};
////////////
////////////class Lion : public Animal {
////////////public:
////////////    Lion(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
////////////
////////////    std::string getName() const override {
////////////        return "Lion";
////////////    }
////////////
////////////    void makeSound() const override {
////////////        std::cout << "Roar" << std::endl;
////////////    }
////////////};
////////////
////////////// Класс CreatureContainer — контейнер для существ
////////////class CreatureContainer {
////////////private:
////////////    std::vector<Creature*> creatures; // Вектор указателей на существ
////////////
////////////public:
////////////    // Деструктор, который удаляет все объекты из контейнера
////////////    ~CreatureContainer() {
////////////        for (Creature* creature : creatures) {
////////////            delete creature; 
////////////        }
////////////        creatures.clear(); 
////////////    }
////////////
////////////    void addCreature(Creature* creature) {
////////////        creatures.push_back(creature); // Добавляем указатель в вектор
////////////    }
////////////
////////////    // Удалить существо из контейнера по индексу
////////////    void removeCreature(size_t index) {
////////////        if (index < creatures.size()) {
////////////            delete creatures[index]; 
////////////            creatures.erase(creatures.begin() + index); // Удаляем указатель из вектора
////////////        }
////////////    }
////////////
////////////    void showCreatures() const {
////////////        for (const auto& creature : creatures) {
////////////            std::cout << creature->getName() << ": ";
////////////            creature->makeSound();
////////////        }
////////////    }
////////////
////////////    size_t size() const {
////////////        return creatures.size();
////////////    }
////////////};
////////////
////////////int main() {
////////////
////////////
////////////    CreatureContainer container;
////////////    container.addCreature(new Lion("Savanna", correct("Введите возраст льва")));
////////////    container.addCreature(new Bird(inputString("Введите место обитания птицы"), 2));
////////////
////////////    std::cout << "All creatures:" << std::endl;
////////////    container.showCreatures();
////////////
////////////    container.removeCreature(0);
////////////
////////////    std::cout << "\nAfter removing the first creature:" << std::endl;
////////////    container.showCreatures();
////////////
////////////    return 0;
////////////}









///////////////////////////////#include <iostream>
///////////////////////////////#include <string>
///////////////////////////////#include <vector>
///////////////////////////////
///////////////////////////////class Creature {
///////////////////////////////public:
///////////////////////////////    virtual std::string getName() const = 0; // Pure virtual function
///////////////////////////////    virtual void makeSound() const = 0; // Pure virtual function
///////////////////////////////    virtual ~Creature() {}
///////////////////////////////};
///////////////////////////////
///////////////////////////////class Animal : public Creature {
///////////////////////////////protected:
///////////////////////////////    std::string habitat; // Habitat
///////////////////////////////    int age; // Age
///////////////////////////////
///////////////////////////////public:
///////////////////////////////    Animal(const std::string& habitat, int age = 0) : habitat(habitat), age(age) {}
///////////////////////////////
///////////////////////////////    virtual ~Animal() {}
///////////////////////////////
///////////////////////////////    void setAge(int age) {
///////////////////////////////        this->age = age;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    int getAge() const {
///////////////////////////////        return age;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    std::string getHabitat() const {
///////////////////////////////        return habitat;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    std::string getName() const override {
///////////////////////////////        return "Animal";
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void makeSound() const override {
///////////////////////////////        std::cout << "Some animal sound" << std::endl;
///////////////////////////////    }
///////////////////////////////};
///////////////////////////////
///////////////////////////////class Bird : public Animal {
///////////////////////////////public:
///////////////////////////////    Bird(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
///////////////////////////////
///////////////////////////////    std::string getName() const override {
///////////////////////////////        return "Bird";
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void makeSound() const override {
///////////////////////////////        std::cout << "Chirp" << std::endl;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void fly() const {
///////////////////////////////        std::cout << "Flying in the sky!" << std::endl;
///////////////////////////////    }
///////////////////////////////};
///////////////////////////////
///////////////////////////////class Mammal : public Animal {
///////////////////////////////public:
///////////////////////////////    Mammal(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
///////////////////////////////
///////////////////////////////    std::string getName() const override {
///////////////////////////////        return "Mammal";
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void makeSound() const override {
///////////////////////////////        std::cout << "Roar" << std::endl;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void run() const {
///////////////////////////////        std::cout << "Running swiftly!" << std::endl;
///////////////////////////////    }
///////////////////////////////};
///////////////////////////////
///////////////////////////////class Eagle : public Bird {
///////////////////////////////public:
///////////////////////////////    Eagle(const std::string& habitat, int age = 0) : Bird(habitat, age) {}
///////////////////////////////
///////////////////////////////    std::string getName() const override {
///////////////////////////////        return "Eagle";
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void makeSound() const override {
///////////////////////////////        std::cout << "Screech" << std::endl;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void hunt() const {
///////////////////////////////        std::cout << "Eagle is hunting!" << std::endl;
///////////////////////////////    }
///////////////////////////////};
///////////////////////////////
///////////////////////////////class Lion : public Mammal {
///////////////////////////////public:
///////////////////////////////    Lion(const std::string& habitat, int age = 0) : Mammal(habitat, age) {}
///////////////////////////////
///////////////////////////////    std::string getName() const override {
///////////////////////////////        return "Lion";
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void makeSound() const override {
///////////////////////////////        std::cout << "Roar" << std::endl;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void roar() const {
///////////////////////////////        std::cout << "Lion is roaring!" << std::endl;
///////////////////////////////    }
///////////////////////////////};
///////////////////////////////
///////////////////////////////class Human : public Creature {
///////////////////////////////protected:
///////////////////////////////    std::string profession; // Profession
///////////////////////////////    int age; // Age
///////////////////////////////
///////////////////////////////public:
///////////////////////////////    Human(const std::string& profession, int age = 0) : profession(profession), age(age) {}
///////////////////////////////
///////////////////////////////    virtual ~Human() {}
///////////////////////////////
///////////////////////////////    void setAge(int age) {
///////////////////////////////        this->age = age;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    int getAge() const {
///////////////////////////////        return age;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    std::string getProfession() const {
///////////////////////////////        return profession;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    std::string getName() const override {
///////////////////////////////        return "Human";
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void makeSound() const override {
///////////////////////////////        std::cout << "Speak" << std::endl;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void work() const {
///////////////////////////////        std::cout << "Working as a " << profession << "!" << std::endl;
///////////////////////////////    }
///////////////////////////////};
///////////////////////////////
///////////////////////////////class Assassin : public Human {
///////////////////////////////private:
///////////////////////////////    int hiddenBlade; // Hidden blade
///////////////////////////////
///////////////////////////////public:
///////////////////////////////    Assassin(const std::string& profession, int age, int hiddenBlade)
///////////////////////////////        : Human(profession, age), hiddenBlade(hiddenBlade) {}
///////////////////////////////
///////////////////////////////    ~Assassin() {}
///////////////////////////////
///////////////////////////////    std::string getName() const override {
///////////////////////////////        return "Assassin (Human)";
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void makeSound() const override {
///////////////////////////////        std::cout << "Silent as the night!" << std::endl;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void showHiddenBlade() const {
///////////////////////////////        std::cout << "Hidden Blade: " << hiddenBlade << std::endl;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void assassinate() const {
///////////////////////////////        std::cout << "Assassin is on a mission!" << std::endl;
///////////////////////////////    }
///////////////////////////////};
///////////////////////////////
///////////////////////////////class Spider : public Creature {
///////////////////////////////protected:
///////////////////////////////    std::string webType; // Web type
///////////////////////////////    int legCount; // Number of legs
///////////////////////////////
///////////////////////////////public:
///////////////////////////////    Spider(const std::string& webType, int legCount = 8) : webType(webType), legCount(legCount) {}
///////////////////////////////
///////////////////////////////    virtual ~Spider() {}
///////////////////////////////
///////////////////////////////    std::string getName() const override {
///////////////////////////////        return "Spider";
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void makeSound() const override {
///////////////////////////////        std::cout << "Hiss" << std::endl;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void spinWeb() const {
///////////////////////////////        std::cout << "Spinning a " << webType << " web!" << std::endl;
///////////////////////////////    }
///////////////////////////////};
///////////////////////////////
///////////////////////////////class SpiderMan : public Human, public Spider {
///////////////////////////////public:
///////////////////////////////    std::string uchenie; // Teaching
///////////////////////////////
///////////////////////////////    SpiderMan(const std::string& uchenie)
///////////////////////////////        : Human("Superhero", 25), Spider("Silk"), uchenie(uchenie) {}
///////////////////////////////    
///////////////////////////////    ~SpiderMan() {}
///////////////////////////////
///////////////////////////////    std::string getName() const override {
///////////////////////////////        return "Spider-Man (Spider + Human)";
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void makeSound() const override {
///////////////////////////////        std::cout << "With great power comes great responsibility!" << std::endl;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void showUchenie() const {
///////////////////////////////        std::cout << "Uchenie: " << uchenie << std::endl;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void swing() const {
///////////////////////////////        std::cout << "Swinging through the city!" << std::endl;
///////////////////////////////    }
///////////////////////////////};
///////////////////////////////
///////////////////////////////class Griffon : public Creature {
///////////////////////////////private:
///////////////////////////////    Lion* lion;   // Pointer to Lion
///////////////////////////////    Eagle* eagle; // Pointer to Eagle
///////////////////////////////    std::string wingSpan; // Wingspan
///////////////////////////////
///////////////////////////////public:
///////////////////////////////    Griffon(Lion* lion, Eagle* eagle, const std::string& wingSpan)
///////////////////////////////        : lion(lion), eagle(eagle), wingSpan(wingSpan) {}
///////////////////////////////    
///////////////////////////////    virtual ~Griffon() {
///////////////////////////////        delete lion;
///////////////////////////////        delete eagle;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    std::string getName() const override {
///////////////////////////////        return "Griffon (Eagle + Lion)";
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void makeSound() const override {
///////////////////////////////        std::cout << "Griffon roar-screech" << std::endl;
///////////////////////////////    }
///////////////////////////////
///////////////////////////////    void soar() const {
///////////////////////////////        std::cout << "Soaring high with a wingspan of " << wingSpan << "!" << std::endl;
///////////////////////////////    }
///////////////////////////////};
///////////////////////////////
///////////////////////////////// Function to check for a valid number input
///////////////////////////////static int correct(const std::string& prompt) {
///////////////////////////////    std::string input;
///////////////////////////////    int num;
///////////////////////////////    char* endptr;
///////////////////////////////    while (true) {
///////////////////////////////        std::cout << prompt;
///////////////////////////////        std::getline(std::cin, input);
///////////////////////////////        if (input.empty()) {
///////////////////////////////            return -1; // Indicate no input
///////////////////////////////        }
///////////////////////////////        num = strtol(input.c_str(), &endptr, 10);
///////////////////////////////        if (*endptr != '\n' && *endptr != '\0') {
///////////////////////////////            std::cout << "Это не число. Попробуйте еще раз." << std::endl;
///////////////////////////////        } else {
///////////////////////////////            return num;
///////////////////////////////        }
///////////////////////////////    }
///////////////////////////////}
///////////////////////////////
///////////////////////////////// Function to get a string input
///////////////////////////////static std::string inputString(const std::string& prompt) {
///////////////////////////////    std::string input;
///////////////////////////////    std::cout << prompt;
///////////////////////////////    std::getline(std::cin, input);
///////////////////////////////    return input;
///////////////////////////////}
///////////////////////////////
///////////////////////////////int main() {
///////////////////////////////    // User input for Lion
///////////////////////////////    std::string lionHabitat = inputString("Введите место обитания льва: ");
///////////////////////////////    int lionAge = correct("Введите возраст льва: ");
///////////////////////////////    Lion* lion1 = new Lion(lionHabitat, lionAge);
///////////////////////////////
///////////////////////////////    // User input for Eagle
///////////////////////////////    std::string eagleHabitat = inputString("Введите место обитания орла: ");
///////////////////////////////    int eagleAge = correct("Введите возраст орла: ");
///////////////////////////////    Eagle* eagle1 = new Eagle(eagleHabitat, eagleAge);
///////////////////////////////
///////////////////////////////    // Create Griffon
///////////////////////////////    Griffon* griffon1 = new Griffon(lion1, eagle1, "Large wingspan");
///////////////////////////////
///////////////////////////////    // User input for Human
///////////////////////////////    std::string profession = inputString("Введите профессию человека: ");
///////////////////////////////    int humanAge = correct("Введите возраст человека: ");
///////////////////////////////    Human* human1 = new Human(profession, humanAge);
///////////////////////////////
///////////////////////////////    // User input for Assassin
///////////////////////////////    std::string assassinProfession = inputString("Введите профессию ассасина: ");
///////////////////////////////    int assassinAge = correct("Введите возраст ассасина: ");
///////////////////////////////    int hiddenBlade = correct("Введите количество скрытых лезвий: ");
///////////////////////////////    Assassin* assassin1 = new Assassin(assassinProfession, assassinAge, hiddenBlade);
///////////////////////////////
///////////////////////////////    // User input for Spider-Man
///////////////////////////////    std::string uchenie = inputString("Введите учение для Человека-Паука: ");
///////////////////////////////    SpiderMan* spiderMan1 = new SpiderMan(uchenie);
///////////////////////////////
///////////////////////////////    // Output information
///////////////////////////////    std::cout << lion1->getName() << ": ";
///////////////////////////////    lion1->makeSound();
///////////////////////////////    lion1->run(); 
///////////////////////////////
///////////////////////////////    std::cout << eagle1->getName() << ": ";
///////////////////////////////    eagle1->makeSound();
///////////////////////////////    eagle1->fly(); 
///////////////////////////////
///////////////////////////////    std::cout << griffon1->getName() << ": ";
///////////////////////////////    griffon1->makeSound();
///////////////////////////////    griffon1->soar(); 
///////////////////////////////
///////////////////////////////    std::cout << human1->getName() << ": ";
///////////////////////////////    human1->makeSound();
///////////////////////////////    human1->work(); 
///////////////////////////////
///////////////////////////////    std::cout << assassin1->getName() << ": ";
///////////////////////////////    assassin1->makeSound();
///////////////////////////////    assassin1->showHiddenBlade();
///////////////////////////////    assassin1->assassinate(); 
///////////////////////////////
///////////////////////////////    std::cout << spiderMan1->getName() << ": ";
///////////////////////////////    spiderMan1->makeSound();
///////////////////////////////    spiderMan1->showUchenie();
///////////////////////////////    spiderMan1->swing(); 
///////////////////////////////
///////////////////////////////    // Freeing memory
///////////////////////////////    delete griffon1; // This will delete lion1 and eagle1 as well
///////////////////////////////    delete human1;
///////////////////////////////    delete assassin1;
///////////////////////////////    delete spiderMan1;
///////////////////////////////
///////////////////////////////    return 0;
///////////////////////////////}






///////#include <iostream>
///////#include <vector>
///////#include <string>
///////
///////// Класс Creature — базовый для всех существ
///////class Creature {
///////public:
///////    virtual std::string getName() const = 0; // Чисто виртуальная функция
///////    virtual void makeSound() const = 0; // Чисто виртуальная функция
///////    virtual ~Creature() {}
///////};
///////
///////// Класс Animal — наследуется от Creature
///////class Animal : public Creature {
///////protected:
///////    std::string habitat; // Среда обитания
///////    int age; // Возраст
///////
///////public:
///////    Animal(const std::string& habitat, int age = 0) : habitat(habitat), age(age) {}
///////
///////    virtual ~Animal() {}
///////
///////    std::string getName() const override {
///////        return "Animal";
///////    }
///////
///////    void makeSound() const override {
///////        std::cout << "Some animal sound" << std::endl;
///////    }
///////};
///////
///////// Класс Bird — наследуется от Animal
///////class Bird : public Animal {
///////public:
///////    Bird(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
///////
///////    std::string getName() const override {
///////        return "Bird";
///////    }
///////
///////    void makeSound() const override {
///////        std::cout << "Chirp" << std::endl;
///////    }
///////
///////    void fly() const {
///////        std::cout << "Flying in the sky!" << std::endl;
///////    }
///////};
///////
///////// Класс Mammal — наследуется от Animal
///////class Mammal : public Animal {
///////public:
///////    Mammal(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
///////
///////    std::string getName() const override {
///////        return "Mammal";
///////    }
///////
///////    void makeSound() const override {
///////        std::cout << "Roar" << std::endl;
///////    }
///////
///////    void run() const {
///////        std::cout << "Running swiftly!" << std::endl;
///////    }
///////};
///////
///////// Класс Eagle — наследуется от Bird
///////class Eagle : public Bird {
///////public:
///////    Eagle(const std::string& habitat, int age = 0) : Bird(habitat, age) {}
///////
///////    std::string getName() const override {
///////        return "Eagle";
///////    }
///////
///////    void makeSound() const override {
///////        std::cout << "Screech" << std::endl;
///////    }
///////
///////    void hunt() const {
///////        std::cout << "Eagle is hunting!" << std::endl;
///////    }
///////};
///////
///////// Класс Lion — наследуется от Mammal
///////class Lion : public Mammal {
///////public:
///////    Lion(const std::string& habitat, int age = 0) : Mammal(habitat, age) {}
///////
///////    std::string getName() const override {
///////        return "Lion";
///////    }
///////
///////    void makeSound() const override {
///////        std::cout << "Roar" << std::endl;
///////    }
///////
///////    void roar() const {
///////        std::cout << "Lion is roaring!" << std::endl;
///////    }
///////};
///////
///////// Класс Human — наследуется от Creature
///////class Human : public Creature {
///////protected:
///////    std::string profession; // Профессия
///////    int age; // Возраст
///////
///////public:
///////    Human(const std::string& profession, int age = 0) : profession(profession), age(age) {}
///////
///////    virtual ~Human() {}
///////
///////    void setAge(int age) {
///////        this->age = age;
///////    }
///////
///////    int getAge() const {
///////        return age;
///////    }
///////
///////    std::string getProfession() const {
///////        return profession;
///////    }
///////
///////    std::string getName() const override {
///////        return "Human";
///////    }
///////
///////    void makeSound() const override {
///////        std::cout << "Speak" << std::endl;
///////    }
///////
///////    void work() const {
///////        std::cout << "Working as a " << profession << "!" << std::endl;
///////    }
///////};
///////
///////// Класс Assassin — наследуется от Human
///////class Assassin : public Human {
///////private:
///////    int hiddenBlade; // Скрытый нож
///////
///////public:
///////    Assassin(const std::string& profession, int age, int hiddenBlade)
///////        : Human(profession, age), hiddenBlade(hiddenBlade) {}
///////
///////    ~Assassin() {}
///////
///////    std::string getName() const override {
///////        return "Assassin (Human)";
///////    }
///////
///////    void makeSound() const override {
///////        std::cout << "Silent as the night!" << std::endl;
///////    }
///////
///////    void showHiddenBlade() const {
///////        std::cout << "Hidden Blade: " << hiddenBlade << std::endl;
///////    }
///////
///////    void assassinate() const {
///////        std::cout << "Assassin is on a mission!" << std::endl;
///////    }
///////};
///////
///////// Класс Spider — наследуется от Creature
///////class Spider : public Creature {
///////protected:
///////    std::string webType; // Тип паутины
///////    int legCount; // Количество ног
///////
///////public:
///////    Spider(const std::string& webType, int legCount = 8) : webType(webType), legCount(legCount) {}
///////
///////    virtual ~Spider() {}
///////
///////    std::string getName() const override {
///////        return "Spider";
///////    }
///////
///////    void makeSound() const override {
///////        std::cout << "Hiss" << std::endl;
///////    }
///////
///////    void spinWeb() const {
///////        std::cout << "Spinning a " << webType << " web!" << std::endl;
///////    }
///////};
///////
///////// Класс SpiderMan — наследуется от Human и Spider
///////class SpiderMan : public Human, public Spider {
///////public:
///////    std::string uchenie; // Учение
///////
///////    SpiderMan(const std::string& uchenie)
///////        : Human("Superhero", 25), Spider("Silk"), uchenie(uchenie) {}
///////    
///////    ~SpiderMan() {}
///////
///////    std::string getName() const override {
///////        return "Spider-Man (Spider + Human)";
///////    }
///////
///////    void makeSound() const override {
///////        std::cout << "With great power comes great responsibility!" << std::endl;
///////    }
///////
///////    void showUchenie() const {
///////        std::cout << "Uchenie: " << uchenie << std::endl;
///////    }
///////
///////    void swing() const {
///////        std::cout << "Swinging through the city!" << std::endl;
///////    }
///////};
///////
///////// Класс Griffon — наследуется от Creature
///////class Griffon : public Creature {
///////private:
///////    Lion* lion;   // Указатель на Lion
///////    Eagle* eagle; // Указатель на Eagle
///////    std::string wingSpan; // Размах крыльев
///////
///////public:
///////    Griffon(Lion* lion, Eagle* eagle, const std::string& wingSpan)
///////        : lion(lion), eagle(eagle), wingSpan(wingSpan) {}
///////    
///////    virtual ~Griffon() {
///////        delete lion;   // Освобождаем память для Lion
///////        delete eagle;  // Освобождаем память для Eagle
///////    }
///////
///////    std::string getName() const override {
///////        return "Griffon (Eagle + Lion)";
///////    }
///////
///////    void makeSound() const override {
///////        std::cout << "Griffon roar-screech" << std::endl;
///////    }
///////
///////    void soar() const {
///////        std::cout << "Soaring high with a wingspan of " << wingSpan << "!" << std::endl;
///////    }
///////};
///////
///////// Класс CreatureContainer — контейнер для существ
///////class CreatureContainer {
///////private:
///////    std::vector<Creature*> creatures; // Вектор указателей на существ
///////
///////public:
///////    // Деструктор, который удаляет все объекты из контейнера
///////    ~CreatureContainer() {
///////        for (Creature* creature : creatures) {
///////            delete creature; // Освобождаем память для каждого объекта
///////        }
///////        creatures.clear(); // Очищаем вектор
///////    }
///////
///////    // Добавить существо в контейнер
///////    void addCreature(Creature* creature) {
///////        creatures.push_back(creature); // Добавляем указатель в вектор
///////    }
///////
///////    // Удалить существо из контейнера по индексу
///////    void removeCreature(size_t index) {
///////        if (index < creatures.size()) {
///////            delete creatures[index]; // Освобождаем память
///////            creatures.erase(creatures.begin() + index); // Удаляем указатель из вектора
///////        }
///////    }
///////
///////    // Показать всех существ в контейнере
///////    void showCreatures() const {
///////        for (const auto& creature : creatures) {
///////            std::cout << creature->getName() << ": ";
///////            creature->makeSound();
///////        }
///////    }
///////
///////    size_t size() const {
///////        return creatures.size();
///////    }
///////};
///////
///////// Функция для получения корректного числа от пользователя
///////static int correct(const std::string& prompt) {
///////    std::string input;
///////    int num;
///////    char* endptr;
///////    while (true) {
///////        std::cout << prompt;
///////        std::getline(std::cin, input);
///////        if (input.empty()) {
///////            return -1; // Возвращаем -1, если нет ввода
///////        }
///////        num = strtol(input.c_str(), &endptr, 10);
///////        if (*endptr != '\n' && *endptr != '\0') {
///////            std::cout << "Это не число. Попробуйте еще раз." << std::endl;
///////        } else {
///////            return num;
///////        }
///////    }
///////}
///////
///////// Функция для получения строки от пользователя
///////static std::string inputString(const std::string& prompt) {
///////    std::string input;
///////    std::cout << prompt;
///////    std::getline(std::cin, input);
///////    return input;
///////}
///////
///////int main() {
///////    CreatureContainer container;
///////
///////    // Создаём и добавляем существа
///////    container.addCreature(new Lion("Savanna", 5));
///////    container.addCreature(new Eagle("Mountain", 3));
///////    container.addCreature(new Human("Doctor", 30));
///////    container.addCreature(new Assassin("Assassin", 25, 2));
///////    //container.addCreature(new SpiderMan("Spider-Man"));
///////
///////    // Показываем всех существ
///////    std::cout << "All creatures:" << std::endl;
///////    container.showCreatures();
///////
///////    // Удаляем первое существо (например, Lion)
///////    container.removeCreature(0);
///////
///////    // Показываем оставшихся существ
///////    std::cout << "\nAfter removing the first creature:" << std::endl;
///////    container.showCreatures();
///////
///////    // Контейнер автоматически удалит все объекты при завершении работы
///////    return 0;
///////}



////#include <iostream>
////#include <vector>
////#include <memory>
////#include <string>
////#include <stdexcept>
////
////// Функция для получения корректного числа от пользователя
////int correct(const std::string& prompt) {
////    std::string input;
////    int num;
////    char* endptr;
////    while (true) {
////        std::cout << prompt;
////        std::getline(std::cin, input);
////        if (input.empty()) {
////            return -1; // Возвращаем -1, если нет ввода
////        }
////        num = strtol(input.c_str(), &endptr, 10);
////        if (*endptr != '\n' && *endptr != '\0') {
////            std::cout << "Это не число. Попробуйте еще раз." << std::endl;
////        } else {
////            return num;
////        }
////    }
////}
////
////// Функция для получения строки от пользователя
////std::string inputString(const std::string& prompt) {
////    std::string input;
////    std::cout << prompt;
////    std::getline(std::cin, input);
////    return input;
////}
////
////// Базовый класс Creature — все существа наследуют его
////class Creature {
////public:
////    virtual std::string getName() const = 0;
////    virtual void makeSound() const = 0;
////    virtual ~Creature() {} 
////};
////
////// Класс Animal
////class Animal : public virtual Creature {
////protected:
////    std::string habitat;
////    int age;
////public:
////    Animal(const std::string& habitat, int age = 0) : habitat(habitat), age(age) {}
////    virtual std::string getName() const override { return "Animal"; }
////    virtual void makeSound() const override { std::cout << "Some animal sound" << std::endl; }
////};
////
////// Класс Spider
////class Spider : public virtual Creature {
////protected:
////    std::string webType;
////    int legCount;
////public:
////    Spider(const std::string& webType, int legCount = 8) : webType(webType), legCount(legCount) {}
////    virtual std::string getName() const override { return "Spider"; }
////    virtual void makeSound() const override { std::cout << "Hiss" << std::endl; }
////    void spinWeb() const { std::cout << "Spinning a " << webType << " web!" << std::endl; }
////};
////
////// Класс Human
////class Human : public virtual Creature {
////protected:
////    std::string profession;
////    int age;
////public:
////    Human(const std::string& profession, int age = 0) : profession(profession), age(age) {}
////    virtual std::string getName() const override { return "Human"; }
////    virtual void makeSound() const override { std::cout << "Hello, I am human!" << std::endl; }
////    void talk() const { std::cout << "Talking like a human!" << std::endl; }
////};
////
////// Класс SpiderMan — наследуется от Human и Spider с использованием виртуального наследования
////class SpiderMan : public Human, public Spider {
////public:
////    std::string uchenie;
////    SpiderMan(const std::string& uchenie)
////        : Human("Superhero", correct("Введите возраст SpiderMan:")), Spider("Silk"), uchenie(uchenie) {}
////    virtual std::string getName() const override { return "Spider-Man (Spider + Human)"; }
////    virtual void makeSound() const override { std::cout << "With great power comes great responsibility!" << std::endl; }
////    void showUchenie() const { std::cout << "Uchenie: " << uchenie << std::endl; }
////    void swing() const { std::cout << "Swinging through the city!" << std::endl; }
////};
////
////// Класс CreatureContainer — контейнер для существ
////template <typename T>
////class CreatureContainer {
////private:
////    std::vector<std::unique_ptr<T>> creatures;
////
////public:
////    void addCreature(std::unique_ptr<T> creature) {
////        creatures.push_back(std::move(creature));
////    }
////
////    void removeCreature(size_t index) {
////        if (index < creatures.size()) {
////            creatures.erase(creatures.begin() + index);
////        } else {
////            throw std::out_of_range("Invalid index");
////        }
////    }
////
////    void showCreatures() const {
////        if (creatures.empty()) {
////            std::cout << "No creatures in the container.\n";
////            return;
////        }
////        for (size_t i = 0; i < creatures.size(); ++i) {
////            std::cout << i + 1 << ". " << creatures[i]->getName() << ": ";
////            creatures[i]->makeSound();
////        }
////    }
////};
////
////int main() {
////    CreatureContainer<Creature> container;
////
////    try {
////        while (true) {
////            int choice = correct("\n1. Add creature\n2. Remove creature\n3. Show creatures\n4. Exit\n");
////            if (choice == 1) {
////                int type = correct("Select creature to add:\n1. Lion\n2. Eagle\n3. Spider\n4. Human\n5. SpiderMan\n");
////                switch (type) {
////                    case 1:
////                        container.addCreature(std::make_unique<Animal>("Savanna", correct("Enter age of the lion:")));
////                        break;
////                    case 2:
////                        container.addCreature(std::make_unique<Animal>("Mountain", correct("Enter age of the eagle:")));
////                        break;
////                    case 3:
////                        container.addCreature(std::make_unique<Spider>("Silk"));
////                        break;
////                    case 4:
////                        container.addCreature(std::make_unique<Human>("Doctor", correct("Enter age of the human:")));
////                        break;
////                    case 5:
////                        container.addCreature(std::make_unique<SpiderMan>("Great Power"));
////                        break;
////                    default:
////                        std::cout << "Invalid selection!" << std::endl;
////                        break;
////                }
////            } else if (choice == 2) {
////                container.showCreatures();
////                int index = correct("Enter index of creature to remove:") - 1;
////                container.removeCreature(index);
////            } else if (choice == 3) {
////                container.showCreatures();
////            } else if (choice == 4) {
////                break;
////            }
////        }
////    } catch (const std::exception& e) {
////        std::cout << "Error: " << e.what() << std::endl;
////    }
////
////    return 0;
////}


//#include <iostream>
//#include <vector>
//#include <memory>
//#include <string>
//#include <fstream>
//#include <stdexcept>
//
//// Базовый класс Creature — все существа наследуют его
//class Creature {
//public:
//    virtual std::string getName() const = 0; // Чисто виртуальная функция
//    virtual void makeSound() const = 0; // Чисто виртуальная функция
//    virtual ~Creature() {}
//};
//
//// Класс Animal — наследуется от Creature
//class Animal : public Creature {
//protected:
//    std::string habitat; // Среда обитания
//    int age; // Возраст
//
//public:
//    Animal(const std::string& habitat, int age = 0) : habitat(habitat), age(age) {}
//
//    virtual std::string getName() const override {
//        return "Animal";
//    }
//
//    virtual void makeSound() const override {
//        std::cout << "Some animal sound" << std::endl;
//    }
//};
//
//// Класс Bird — наследуется от Animal
//class Bird : public Animal {
//public:
//    Bird(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
//
//    virtual std::string getName() const override {
//        return "Bird";
//    }
//
//    virtual void makeSound() const override {
//        std::cout << "Chirp" << std::endl;
//    }
//
//    void fly() const {
//        std::cout << "Flying in the sky!" << std::endl;
//    }
//};
//
//// Класс Mammal — наследуется от Animal
//class Mammal : public Animal {
//public:
//    Mammal(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
//
//    virtual std::string getName() const override {
//        return "Mammal";
//    }
//
//    virtual void makeSound() const override {
//        std::cout << "Roar" << std::endl;
//    }
//
//    void run() const {
//        std::cout << "Running swiftly!" << std::endl;
//    }
//};
//
//// Класс Lion — наследуется от Mammal
//class Lion : public Mammal {
//public:
//    Lion(const std::string& habitat, int age = 0) : Mammal(habitat, age) {}
//
//    virtual std::string getName() const override {
//        return "Lion";
//    }
//
//    virtual void makeSound() const override {
//        std::cout << "Roar" << std::endl;
//    }
//
//    void roar() const {
//        std::cout << "Lion is roaring!" << std::endl;
//    }
//};
//
//// Класс Eagle — наследуется от Bird
//class Eagle : public Bird {
//public:
//    Eagle(const std::string& habitat, int age = 0) : Bird(habitat, age) {}
//
//    virtual std::string getName() const override {
//        return "Eagle";
//    }
//
//    virtual void makeSound() const override {
//        std::cout << "Screech" << std::endl;
//    }
//
//    void hunt() const {
//        std::cout << "Eagle is hunting!" << std::endl;
//    }
//};
//
//// Класс Spider — наследуется от Creature
//class Spider : public Creature {
//protected:
//    std::string webType; // Тип паутины
//    int legCount; // Количество ног
//
//public:
//    Spider(const std::string& webType, int legCount = 8) : webType(webType), legCount(legCount) {}
//
//    virtual std::string getName() const override {
//        return "Spider";
//    }
//
//    virtual void makeSound() const override {
//        std::cout << "Hiss" << std::endl;
//    }
//
//    void spinWeb() const {
//        std::cout << "Spinning a " << webType << " web!" << std::endl;
//    }
//};
//
//// Класс SpiderMan — наследуется от Human и Spider
//class SpiderMan : public Spider {
//public:
//    std::string uchenie; // Учение
//
//    SpiderMan(const std::string& uchenie) : Spider("Silk"), uchenie(uchenie) {}
//
//    virtual std::string getName() const override {
//        return "Spider-Man (Spider + Human)";
//    }
//
//    virtual void makeSound() const override {
//        std::cout << "With great power comes great responsibility!" << std::endl;
//    }
//
//    void showUchenie() const {
//        std::cout << "Uchenie: " << uchenie << std::endl;
//    }
//
//    void swing() const {
//        std::cout << "Swinging through the city!" << std::endl;
//    }
//};
//
//// Класс CreatureContainer — контейнер для существ
//class CreatureContainer {
//private:
//    std::vector<std::unique_ptr<Creature>> creatures;
//
//public:
//    // Добавить существо в контейнер
//    void addCreature(std::unique_ptr<Creature> creature) {
//        creatures.push_back(std::move(creature));
//    }
//
//    // Удалить существо из контейнера по индексу
//    void removeCreature(size_t index) {
//        if (index < creatures.size()) {
//            creatures.erase(creatures.begin() + index);
//        } else {
//            throw std::out_of_range("Invalid index");
//        }
//    }
//
//    // Показать всех существ в контейнере
//    void showCreatures() const {
//        if (creatures.empty()) {
//            std::cout << "No creatures in the container.\n";
//            return;
//        }
//        for (size_t i = 0; i < creatures.size(); ++i) {
//            std::cout << i + 1 << ". " << creatures[i]->getName() << ": ";
//            creatures[i]->makeSound();
//        }
//    }
//
//    // Сохранить существа в файл
//   // void saveToFile(const std::string& filename) const {
//   //     std::ofstream outFile(filename);
//   //     if (!outFile) {
//   //         throw std::ios_base::failure("Failed to open file for writing.");
//   //     }
//
//   //     for (const auto& creature : creatures) {
//   //         outFile << creature->getName() << "\n";
//   //     }
//   // }
//
//   // // Загрузить существа из файла
//   // void loadFromFile(const std::string& filename) {
//   //     std::ifstream inFile(filename);
//   //     if (!inFile) {
//   //         throw std::ios_base::failure("Failed to open file for reading.");
//   //     }
//
//   //     std::string name;
//   //     while (std::getline(inFile, name)) {
//   //         if (name == "Lion") {
//   //             addCreature(std::make_unique<Lion>("Savanna", 5));
//   //         } else if (name == "Eagle") {
//   //             addCreature(std::make_unique<Eagle>("Mountain", 3));
//   //         } else if (name == "Spider-Man (Spider + Human)") {
//   //             addCreature(std::make_unique<SpiderMan>("Great Power"));
//   //         }
//   //     }
//   // }
//};
//
//// Функция для получения корректного числа от пользователя
//int correct(const std::string& prompt) {
//    std::string input;
//    int num;
//    char* endptr;
//    while (true) {
//        std::cout << prompt;
//        std::getline(std::cin, input);
//        if (input.empty()) {
//            return -1; // Возвращаем -1, если нет ввода
//        }
//        num = strtol(input.c_str(), &endptr, 10);
//        if (*endptr != '\n' && *endptr != '\0') {
//            std::cout << "Это не число. Попробуйте еще раз." << std::endl;
//        } else {
//            return num;
//        }
//    }
//}
//
//// Функция для получения строки от пользователя
//std::string inputString(const std::string& prompt) {
//    std::string input;
//    std::cout << prompt;
//    std::getline(std::cin, input);
//    return input;
//}
//
//int main() {
//    CreatureContainer container;
//
//    try {
//        while (true) {
//            std::cout << "\n1. Add creature\n2. Remove creature\n3. Show creatures\n4. Exit\n";
//            int choice;
//            std::cin >> choice;
//            std::cin.ignore(); // Очищаем буфер ввода
//
//            if (choice == 1) {
//                std::cout << "Select creature to add:\n1. Lion\n2. Eagle\n3. SpiderMan\n";
//                int type;
//                std::cin >> type;
//                std::cin.ignore(); // Очищаем буфер ввода
//
//                switch (type) {
//                    case 1:
//                        container.addCreature(std::make_unique<Lion>("Savanna", correct("Введите возраст льва:")));
//                        break;
//                    case 2:
//                        container.addCreature(std::make_unique<Eagle>("Mountain", correct("Введите возраст орла:")));
//                        break;
//                    case 3:
//                        container.addCreature(std::make_unique<SpiderMan>("Great Power"));
//                        break;
//                    default:
//                        std::cout << "Invalid selection!" << std::endl;
//                        break;
//                }
//            } else if (choice == 2) {
//                container.showCreatures();
//                int index;
//                std::cout << "Enter index of creature to remove: ";
//                std::cin >> index;
//                container.removeCreature(index - 1); // Индексы в контейнере начинаются с 0
//            } else if (choice == 3) {
//                container.showCreatures();
//            } else if (choice == 4) {
//                break;
//            } else {
//                std::cout << "Invalid choice, try again!" << std::endl;
//            }
//        }
//    } catch (const std::exception& e) {
//        std::cout << "Error: " << e.what() << std::endl;
//    }
//
//    return 0;
//}
//


//#include <iostream>
//#include <vector>
//#include <memory>
//#include <string>
//#include <stdexcept>
//
//
//// Функция для получения корректного числа от пользователя
//int correct(const std::string& prompt) {
//    std::string input;
//    int num;
//    char* endptr;
//    while (true) {
//        std::cout << prompt;
//        std::getline(std::cin, input);
//        if (input.empty()) {
//            return -1; // Возвращаем -1, если нет ввода
//        }
//        num = strtol(input.c_str(), &endptr, 10);
//        if (*endptr != '\n' && *endptr != '\0') {
//            std::cout << "Это не число. Попробуйте еще раз." << std::endl;
//        } else {
//            return num;
//        }
//    }
//}
//
//// Функция для получения строки от пользователя
//std::string inputString(const std::string& prompt) {
//    std::string input;
//    std::cout << prompt;
//    std::getline(std::cin, input);
//    return input;
//}
//// Базовый класс Creature — все существа наследуют его
//class Creature {
//public:
//    virtual std::string getName() const = 0; 
//    virtual void makeSound() const = 0; 
//    virtual ~Creature() {}
//};
//
//class Animal : public Creature {
//protected:
//    std::string habitat; // Среда обитания
//    int age; // Возраст
//public:
//    Animal(const std::string& habitat, int age = 0) : habitat(habitat), age(age) {}
//    virtual std::string getName() const override { return "Animal"; }
//    virtual void makeSound() const override { std::cout << "Some animal sound" << std::endl; }
//};
//
//class Bird : public Animal {
//public:
//    Bird(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
//    virtual std::string getName() const override { return "Bird"; }
//    virtual void makeSound() const override { std::cout << "Chirp" << std::endl; }
//    void fly() const { std::cout << "Flying in the sky!" << std::endl; }
//};
//
//class Mammal : public Animal {
//public:
//    Mammal(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
//    virtual std::string getName() const override { return "Mammal"; }
//    virtual void makeSound() const override { std::cout << "Roar" << std::endl; }
//    void run() const { std::cout << "Running swiftly!" << std::endl; }
//};
//
//class Lion : public Mammal {
//public:
//    Lion(const std::string& habitat, int age = 0) : Mammal(habitat, age) {}
//    virtual std::string getName() const override { return "Lion"; }
//    virtual void makeSound() const override { std::cout << "Roar" << std::endl; }
//    void roar() const { std::cout << "Lion is roaring!" << std::endl; }
//};
//
//class Eagle : public Bird {
//public:
//    Eagle(const std::string& habitat, int age = 0) : Bird(habitat, age) {}
//    virtual std::string getName() const override { return "Eagle"; }
//    virtual void makeSound() const override { std::cout << "Screech" << std::endl; }
//    void hunt() const { std::cout << "Eagle is hunting!" << std::endl; }
//};
//
//class Spider : public Creature {
//protected:
//    std::string webType; // Тип паутины
//    int legCount; // Количество ног
//public:
//    Spider(const std::string& webType, int legCount = 8) : webType(webType), legCount(legCount) {}
//    virtual std::string getName() const override { return "Spider"; }
//    virtual void makeSound() const override { std::cout << "Hiss" << std::endl; }
//    void spinWeb() const { std::cout << "Spinning a " << webType << " web!" << std::endl; }
//};
//
//// Класс Human — просто класс человека
//class Human : public Creature {
//public:
//    virtual std::string getName() const override { return "Human"; }
//    virtual void makeSound() const override { std::cout << "Hello, I am human!" << std::endl; }
//    void talk() const { std::cout << "Talking like a human!" << std::endl; }
//};
//
//// Класс CreatureContainer — контейнер для существ
//class CreatureContainer {
//private:
//    std::vector<std::unique_ptr<Creature>> creatures;
//
//public:
//    void addCreature(std::unique_ptr<Creature> creature) {
//        creatures.push_back(std::move(creature));
//    }
//
//    void removeCreature(size_t index) {
//        if (index < creatures.size()) {
//            creatures.erase(creatures.begin() + index);
//        } else {
//            throw std::out_of_range("Invalid index");
//        }
//    }
//
//    void showCreatures() const {
//        if (creatures.empty()) {
//            std::cout << "No creatures in the container.\n";
//            return;
//        }
//        for (size_t i = 0; i < creatures.size(); ++i) {
//            std::cout << i + 1 << ". " << creatures[i]->getName() << ": ";
//            creatures[i]->makeSound();
//        }
//    }
//};
//
//
//int main() {
//    CreatureContainer container;
//
//    try {
//        while (true) {
//            int choice = correct("\n1. Add creature\n2. Remove creature\n3. Show creatures\n4. Exit\n");
//            if (choice == 1) {
//                int type = correct("Select creature to add:\n1. Lion\n2. Eagle\n3. Spider\n4. Human\n");
//                switch (type) {
//                    case 1:
//                        container.addCreature(std::make_unique<Lion>("Savanna", correct("Введите возраст льва:")));
//                        break;
//                    case 2:
//                        container.addCreature(std::make_unique<Eagle>("Mountain", correct("Введите возраст орла:")));
//                        break;
//                    case 3:
//                        container.addCreature(std::make_unique<Spider>("Silk"));
//                        break;
//                    case 4:
//                        container.addCreature(std::make_unique<Human>());
//                        break;
//                    default:
//                        std::cout << "Invalid selection!" << std::endl;
//                        break;
//                }
//            } else if (choice == 2) {
//                container.showCreatures();
//                int index = correct("Enter index of creature to remove: ");
//                container.removeCreature(index - 1); // Индексы в контейнере начинаются с 0
//            } else if (choice == 3) {
//                container.showCreatures();
//            } else if (choice == 4) {
//                break;
//            } else {
//                std::cout << "Invalid choice, try again!" << std::endl;
//            }
//        }
//    } catch (const std::exception& e) {
//        std::cout << "Error: " << e.what() << std::endl;
//    }
//
//    return 0;
//}
//




//#include <iostream>
//#include <vector>
//#include <memory>
//#include <string>
//#include <stdexcept>
//
//// Функция для получения корректного числа от пользователя
//int correct(const std::string& prompt) {
//    std::string input;
//    int num;
//    char* endptr;
//    while (true) {
//        std::cout << prompt;
//        std::getline(std::cin, input);
//        if (input.empty()) {
//            return -1; // Возвращаем -1, если нет ввода
//        }
//        num = strtol(input.c_str(), &endptr, 10);
//        if (*endptr != '\n' && *endptr != '\0') {
//            std::cout << "Это не число. Попробуйте еще раз." << std::endl;
//        } else {
//            return num;
//        }
//    }
//}
//
//// Функция для получения строки от пользователя
//std::string inputString(const std::string& prompt) {
//    std::string input;
//    std::cout << prompt;
//    std::getline(std::cin, input);
//    return input;
//}
//
//// Базовый класс Creature — все существа наследуют его
//class Creature {
//public:
//    virtual std::string getName() const = 0;
//    virtual void makeSound() const = 0;
//    virtual ~Creature() {} 
//};
//
//class Animal : public Creature {
//protected:
//    std::string habitat; // Среда обитания
//    int age; // Возраст
//public:
//    Animal(const std::string& habitat, int age = 0) : habitat(habitat), age(age) {}
//    virtual std::string getName() const override { return "Animal"; }
//    virtual void makeSound() const override { std::cout << "Some animal sound" << std::endl; }
//};
//
//class Bird : public Animal {
//public:
//    Bird(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
//    virtual std::string getName() const override { return "Bird"; }
//    virtual void makeSound() const override { std::cout << "Chirp" << std::endl; }
//    void fly() const { std::cout << "Flying in the sky!" << std::endl; }
//};
//
//class Mammal : public Animal {
//public:
//    Mammal(const std::string& habitat, int age = 0) : Animal(habitat, age) {}
//    virtual std::string getName() const override { return "Mammal"; }
//    virtual void makeSound() const override { std::cout << "Roar" << std::endl; }
//    void run() const { std::cout << "Running swiftly!" << std::endl; }
//};
//
//class Lion : public Mammal {
//public:
//    Lion(const std::string& habitat, int age = 0) : Mammal(habitat, age) {}
//    virtual std::string getName() const override { return "Lion"; }
//    virtual void makeSound() const override { std::cout << "Roar" << std::endl; }
//    void roar() const { std::cout << "Lion is roaring!" << std::endl; }
//};
//
//class Eagle : public Bird {
//public:
//    Eagle(const std::string& habitat, int age = 0) : Bird(habitat, age) {}
//    virtual std::string getName() const override { return "Eagle"; }
//    virtual void makeSound() const override { std::cout << "Screech" << std::endl; }
//    void hunt() const { std::cout << "Eagle is hunting!" << std::endl; }
//};
//
//class Spider : public Creature {
//protected:
//    std::string webType; // Тип паутины
//    int legCount; // Количество ног
//public:
//    Spider(const std::string& webType, int legCount = 8) : webType(webType), legCount(legCount) {}
//    virtual std::string getName() const override { return "Spider"; }
//    virtual void makeSound() const override { std::cout << "Hiss" << std::endl; }
//    void spinWeb() const { std::cout << "Spinning a " << webType << " web!" << std::endl; }
//};
//
//// Класс Human — просто класс человека
//class Human : public Creature {
//protected:
//    std::string profession; // Профессия
//    int age; // Возраст
//public:
//    Human(const std::string& profession, int age = 0) : profession(profession), age(age) {}
//    virtual std::string getName() const override { return "Human"; }
//    virtual void makeSound() const override { std::cout << "Hello, I am human!" << std::endl; }
//    void talk() const { std::cout << "Talking like a human!" << std::endl; }
//};
//
//// Класс Assassin — наследуется от Human
//class Assassin : public Human {
//private:
//    int hiddenBlade; // Скрытый нож
//public:
//    Assassin(const std::string& profession, int age, int hiddenBlade)
//        : Human(profession, age), hiddenBlade(hiddenBlade) {}
//    virtual std::string getName() const override { return "Assassin (Human)"; }
//    virtual void makeSound() const override { std::cout << "Silent as the night!" << std::endl; }
//    void showHiddenBlade() const { std::cout << "Hidden Blade: " << hiddenBlade << std::endl; }
//    void assassinate() const { std::cout << "Assassin is on a mission!" << std::endl; }
//};
//
//// Класс SpiderMan — наследуется от Human и Spider
//class SpiderMan : public Human, public Spider {
//public:
//    std::string uchenie; // Учение
//    SpiderMan(const std::string& uchenie)
//        : Human("Superhero", 25), Spider("Silk"), uchenie(uchenie) {}
//    virtual std::string getName() const override { return "Spider-Man (Spider + Human)"; }
//    virtual void makeSound() const override { std::cout << "With great power comes great responsibility!" << std::endl; }
//    void showUchenie() const { std::cout << "Uchenie: " << uchenie << std::endl; }
//    void swing() const { std::cout << "Swinging through the city!" << std::endl; }
//};
//
//// Класс CreatureContainer — контейнер для существ
//class CreatureContainer {
//private:
//    std::vector<std::unique_ptr<Creature>> creatures; // Вектор для хранения умных указателей
//
//public:
//    void addCreature(std::unique_ptr<Creature> creature) {
//        creatures.push_back(std::move(creature));
//    }
//
//    void removeCreature(size_t index) {
//        if (index < creatures.size()) {
//            creatures.erase(creatures.begin() + index);
//        } else {
//            throw std::out_of_range("Invalid index");
//        }
//    }
//
//    void showCreatures() const {
//        if (creatures.empty()) {
//            std::cout << "No creatures in the container.\n";
//            return;
//        }
//        for (size_t i = 0; i < creatures.size(); ++i) {
//            std::cout << i + 1 << ". " << creatures[i]->getName() << ": ";
//            creatures[i]->makeSound();
//        }
//    }
//};
//
//int main() {
//    CreatureContainer container;
//
//    try {
//        while (true) {
//            int choice = correct("\n1. Add creature\n2. Remove creature\n3. Show creatures\n4. Exit\n");
//            if (choice == 1) {
//                int type = correct("Select creature to add:\n1. Lion\n2. Eagle\n3. Spider\n4. Human\n");
//                switch (type) {
//                    case 1:
//                        container.addCreature(std::make_unique<Lion>("Savanna", correct("Введите возраст льва:")));
//                        break;
//                    case 2:
//                        container.addCreature(std::make_unique<Eagle>("Mountain", correct("Введите возраст орла:")));
//                        break;
//                    case 3:
//                        container.addCreature(std::make_unique<Spider>("Silk"));
//                        break;
//                    case 4:
//                        container.addCreature(std::make_unique<Human>("Doctor", correct("Введите возраст человека:")));
//                        break;
//                    default:
//                        std::cout << "Invalid selection!" << std::endl;
//                        break;
//                }
//            } else if (choice == 2) {
//                container.showCreatures();
//                int index = correct("Enter index of creature to remove:") - 1;
//                container.removeCreature(index);
//            } else if (choice == 3) {
//                container.showCreatures();
//            } else if (choice == 4) {
//                break;
//            }
//        }
//    } catch (const std::exception& e) {
//        std::cout << "Error: " << e.what() << std::endl;
//    }
//
//    return 0;
//}
//


//Listen, it was in clear:

//////////#include <iostream>
//////////#include <memory>
//////////#include <stdexcept>
//////////#include <string>
//////////#include <deque>
//////////using namespace std;
//////////
//////////int correct(const string& prompt) {
//////////    string input;
//////////    int num;
//////////    char* endptr;
//////////    while (true) {
//////////        cout << prompt;
//////////        getline(cin, input);
//////////        if (input.empty()) {
//////////            return -1;
//////////        }
//////////        num = strtol(input.c_str(), &endptr, 10);
//////////        if (*endptr != '\n' && *endptr != '\0') {
//////////            cout << "Это не число. Попробуйте еще раз." << endl;
//////////        } else {
//////////            return num;
//////////        }
//////////    }
//////////}
//////////
//////////
//////////class Creature {
//////////public:
//////////    virtual string get_name() const = 0;
//////////    virtual void make_sound() const = 0;
//////////    virtual ~Creature() {}
//////////};
//////////
//////////class Animal : public Creature {
//////////protected:
//////////    string habitat;
//////////    int age;
//////////public:
//////////    Animal(const string& habitat, int age = 0) : habitat(habitat), age(age) {}
//////////    virtual string get_name() const override { return "Animal"; }
//////////    virtual void make_sound() const override { cout << "Some animal sound" << endl; }
//////////};
//////////
//////////class Bird : public Animal {
//////////public:
//////////    Bird(const string& habitat, int age = 0) : Animal(habitat, age) {}
//////////    virtual string get_name() const override { return "Bird"; }
//////////    virtual void make_sound() const override { cout << "Chirp" << endl; }
//////////    void fly() const { cout << "Flying in the sky!" << endl; }
//////////};
//////////
//////////class Felidae : public Animal {
//////////public:
//////////    Felidae(const string& habitat, int age = 0) : Animal(habitat, age) {}
//////////    virtual string get_name() const override { return "Felidae"; }
//////////    virtual void make_sound() const override { cout << "Roar" << endl; }
//////////    void run() const { cout << "Running swiftly!" << endl; }
//////////};
//////////
//////////class Lion : public Felidae {
//////////public:
//////////    Lion(const string& habitat, int age = 0) : Felidae(habitat, age) {}
//////////    virtual string get_name() const override { return "Lion"; }
//////////    virtual void make_sound() const override { cout << "Roar" << endl; }
//////////    void roar() const { cout << "Lion is roaring!" << endl; }
//////////};
//////////
//////////class Eagle : public Bird {
//////////public:
//////////    Eagle(const string& habitat, int age = 0) : Bird(habitat, age) {}
//////////    virtual string get_name() const override { return "Eagle"; }
//////////    virtual void make_sound() const override { cout << "Screech" << endl; }
//////////    void hunt() const { cout << "Eagle is hunting!" << endl; }
//////////};
//////////
//////////class Spider : public virtual Creature {
//////////protected:
//////////    string webType;
//////////    int legCount;
//////////public:
//////////    Spider(const string& webType, int legCount = 8) : webType(webType), legCount(legCount) {}
//////////    virtual string get_name() const override { return "Spider"; }
//////////    virtual void make_sound() const override { cout << "Hiss" << endl; }
//////////    void spinWeb() const { cout << "Spinning a " << webType << " web!" << endl; }
//////////    string get_web() { return webType; }
//////////    int get_leg() { return legCount; }
//////////};
//////////
//////////
//////////class Human : public virtual Creature {
//////////protected:
//////////    string profession;
//////////    int age;
//////////public:
//////////    Human(const string& profession, int age = 0) : profession(profession), age(age) {}
//////////    virtual string get_name() const override { return "Human"; }
//////////    virtual void make_sound() const override { cout << "Hello, I am human!" << endl; }
//////////    void talk() const { cout << "Talking like a human!" << endl; }
//////////    int get_age() { return age; }
//////////};
//////////
//////////
//////////class Assassin : public Human {
//////////private:
//////////    int hiddenBlade;
//////////public:
//////////    class Silent_assasin {
//////////
//////////    };
//////////    Assassin(const string& profession, int age, int hiddenBlade)
//////////        : Human(profession, age), hiddenBlade(hiddenBlade) {}
//////////    virtual string get_name() const override { return "Assassin (Human)"; }
//////////    virtual void make_sound() const override { throw new Silent_assasin(); }
//////////    void showHiddenBlade() const { cout << "Hidden Blade: " << hiddenBlade << endl; }
//////////    void assassinate() const { cout << "Assassin is on a mission!" << endl; }
//////////};
//////////
//////////
//////////class SpiderMan : public Human, public Spider {
//////////public:
//////////    string uchenie;
//////////    SpiderMan(const string& uchenie) : Human("Superhero", 25), Spider("Silk"), uchenie(uchenie) {}
//////////    SpiderMan(Human hu, Spider spi, const string& uchenie) : Human("Superhero", hu.get_age()), Spider(spi.get_web()), uchenie(uchenie) {}
//////////    virtual string get_name() const override { return "Spider-Man (Spider + Human)"; }
//////////    virtual void make_sound() const override { cout << "With great power comes great responsibility!" << endl; }
//////////    void showUchenie() const { cout << "Uchenie: " << uchenie << endl; }
//////////    void swing() const { cout << "Swinging through the city!" << endl; }
//////////};
//////////
//////////// Кастомный deque
//////////template <typename T>
//////////class My_deque {
//////////public:
//////////
//////////    My_deque() : head(nullptr), tail(nullptr), size(0) {}
//////////    //My_deque(const T& elem) : element(elem), prev(nullptr), next(nullptr), head(elem), tail(elem), size(1) {}
//////////
//////////    class Iterator<T> {
//////////    public:
//////////        Iterator<T>(My_deque* node) : current(node) {}
//////////
//////////        T& operator*() {
//////////            if (!current) throw out_of_range("Iterator<T> out of range");
//////////            return current->element;
//////////        }
//////////
//////////        Iterator<T>& operator++() {
//////////            if (current) current = current->next;
//////////            return *this;
//////////        }
//////////
//////////        Iterator<T>& operator--() {
//////////            if (current) current = current->prev;
//////////            return *this;
//////////        }
//////////
//////////        bool operator!=(const Iterator<T>& other) const {
//////////            return current != other.current;
//////////        }
//////////
//////////        bool operator==(const Iterator<T>& other) const {
//////////            return current == other.current;
//////////        }
//////////
//////////    private:
//////////        My_deque* current;
//////////    };
//////////
//////////
//////////    ~My_deque() {
//////////        clear();
//////////    }
//////////
//////////    void push_back(const T& value) {
//////////        My_deque* new_node = new My_deque(value);
//////////        if (tail) {
//////////            tail->next = new_node;
//////////            new_node->prev = tail;
//////////            tail = new_node;
//////////        } else {
//////////            head = tail = new_node;
//////////        }
//////////        ++size;
//////////    }
//////////
//////////    void push_front(const T& value) {
//////////        My_deque* new_node = new My_deque(value);
//////////        if (head) {
//////////            head->prev = new_node;
//////////            new_node->next = head;
//////////            head = new_node;
//////////        } else {
//////////            head = tail = new_node;
//////////        }
//////////        ++size;
//////////    }
//////////
//////////    void pop_back() {
//////////        if (tail) {
//////////            My_deque* temp = tail;
//////////            tail = tail->prev;
//////////            if (tail) tail->next = nullptr;
//////////            delete temp;
//////////            --size;
//////////        }
//////////    }
//////////
//////////    void pop_front() {
//////////        if (head) {
//////////            My_deque* temp = head;
//////////            head = head->next;
//////////            if (head) head->prev = nullptr;
//////////            delete temp;
//////////            --size;
//////////        }
//////////    }
//////////
//////////    T& operator[](size_t index) {
//////////        if (index >= size) throw out_of_range("Index out of range");
//////////        My_deque* current = head;
//////////        for (size_t i = 0; i < index; ++i) {
//////////            current = current->next;
//////////        }
//////////        return current->element;
//////////    }
//////////
//////////    Iterator<T> iterator() {
//////////        return Iterator<T>(head);
//////////    }
//////////
//////////    size_t get_size() const {
//////////        return size;
//////////    }
//////////
//////////    void clear() {
//////////        while (head) {
//////////            pop_front();
//////////        }
//////////    }
//////////
//////////private:
//////////    My_deque* head;
//////////    My_deque* tail;
//////////    size_t size;
//////////    T element;
//////////    My_deque* prev;
//////////    My_deque* next;
//////////};
//////////
//////////// Контейнер для существ
//////////template <typename T>
//////////class CreatureContainer {
//////////private:
//////////    My_deque<unique_ptr<T>> creatures;
//////////
//////////public:
//////////    void addCreature(unique_ptr<T> creature) {
//////////        creatures.push_back(move(creature));
//////////    }
//////////
//////////    void removeCreature(size_t index) {
//////////        if (index >= creatures.get_size()) {
//////////            throw out_of_range("Invalid index");
//////////        }
//////////
//////////        // Удаляем существо по индексу
//////////       // My_deque<unique_ptr<T>> temp;
//////////       // size_t i = 0;
//////////       // for (auto it = creatures.begin(); it != creatures.end(); ++it) {
//////////       //     if (i == index) {
//////////       //         it = creatures.erase(it); // Удаляем элемент
//////////       //         break;
//////////       //     }
//////////       //     ++i;
//////////       // }
//////////    }
//////////
//////////   // void showCreatures() const {
//////////   //     if (creatures.get_size() == 0) {
//////////   //         cout << "No creatures in the container.\n";
//////////   //         return;
//////////   //     }
//////////   //     size_t i = 0;
//////////   //     for (auto& creature : creatures) {
//////////   //         cout << i++ << ". " << creature->get_name() << ": ";
//////////   //         creature->make_sound();
//////////   //     }
//////////   // }
//////////};
//////////
//////////int test() {
//////////
//////////    /*
//////////    3:изучить принципы и получить практические навыки при 
//////////использовании наследования классов; разработать иерархию насследования 
//////////классов; изучить вызов конструкторов и деструкторов при наследовании классов; 
//////////дополнительно: рассмотреть случаи, когда необходимо использовать 
//////////виртуальное наследование. 
//////////    4: изучить принципы и получить практические навыки при использовании шаблонов классов и функций; научиться использовать шаблоны функций для создания группы однотипных функций, а также шаблоны классов 
//////////для создания группы связанных типов классов; продемонстрировать работу 
//////////написанной прораммы.
//////////    5:Содержание работы: Разработка собственных классов обработки 
//////////    исключений. Обработчики исключительных ситуаций. Перенаправление 
//////////    исключительных ситуаций. Исключения стандартной библиотекиПонять, как обрабатываются исключения. Использовать 
//////////    try, throw и catch для отслеживания, индикации и обработки исключений. 
//////////    Написать свои функции для проверки правильности ввода. 
//////////    6:Изучить стандартную библиотеку iostream. Научиться 
//////////    работать с файлами. Записать/прочитать данные в текстовом и бинарном виде.
//////////    7:Цель работы: Научиться разрабатывать свои классы-контейнеры, разделяя их на контейнеры, итераторы и алгоритм
//////////
//////////// 
//////////// 
//////////// 
//////////// 
//////////// 
//////////// 
//////////    */ 
//////////    std::deque<int> example;
//////////    CreatureContainer<Creature> container;
//////////    container.addCreature(make_unique<Lion>("Savanna", 5));
//////////    container.addCreature(make_unique<Eagle>("Mountain", 12));
//////////    container.addCreature(make_unique<Spider>("Silk"));
//////////    container.addCreature(make_unique<Human>("Doctor", 21));
//////////    container.addCreature(make_unique<Assassin>("Ciller", 21));
//////////    container.addCreature(make_unique<SpiderMan>("Ben Parker"));
//////////    
//////////
//////////    return 0;
//////////}
//////////
//////////
//////////
//////////
//////////int main(int argc, char** argv) {
//////////    if (argc > 1 && !strcmp("test", argv[1])) {
//////////        test();
//////////        return 0;
//////////    }
//////////    CreatureContainer<Creature> container;
//////////
//////////    try {
//////////        while (true) {
//////////            int choice = correct("\n1. Add creature\n2. Remove creature\n3. Show creatures\n4. Exit\n");
//////////            if (choice == 1) {
//////////                int type = correct("Select creature to add:\n1. Lion\n2. Eagle\n3. Spider\n4. Human\n5. SpiderMan\n");
//////////                switch (type) {
//////////                    case 1:
//////////                        container.addCreature(make_unique<Lion>("Savanna", correct("Введите возраст льва:")));
//////////                        break;
//////////                    case 2:
//////////                        container.addCreature(make_unique<Eagle>("Mountain", correct("Введите возраст орла:")));
//////////                        break;
//////////                    case 3:
//////////                        container.addCreature(make_unique<Spider>("Silk"));
//////////                        break;
//////////                    case 4:
//////////                        container.addCreature(make_unique<Human>("Doctor", correct("Введите возраст человека:")));
//////////                        break;
//////////                    case 5:
//////////                        container.addCreature(make_unique<SpiderMan>("Ben Parker"));
//////////                        break;
//////////                    default:
//////////                        cout << "Invalid selection!" << endl;
//////////                        break;
//////////                }
//////////            } else if (choice == 2) {
//////////                //container.showCreatures();
//////////                int index = correct("Enter index of creature to remove:") - 1;
//////////                container.removeCreature(index);
//////////            } else if (choice == 3) {
//////////                //container.showCreatures();
//////////            } else if (choice == 4) {
//////////                break;
//////////            }
//////////        }
//////////    } catch (const exception& e) {
//////////        cout << "Error: " << e.what() << endl;
//////////    }
//////////
//////////    return 0;
//////////}
//////
//////
//////
//////
//////////////////////#include <iostream>
//////////////////////#include <memory>
//////////////////////#include <stdexcept>
//////////////////////#include <string>
//////////////////////#include <cstring> // для strcmp
//////////////////////using namespace std;
//////////////////////
//////////////////////// Функция для корректного ввода чисел
//////////////////////int correct(const string& prompt) {
//////////////////////    string input;
//////////////////////    int num;
//////////////////////    char* endptr;
//////////////////////    while (true) {
//////////////////////        cout << prompt;
//////////////////////        getline(cin, input);
//////////////////////        if (input.empty()) {
//////////////////////            return -1;
//////////////////////        }
//////////////////////        num = strtol(input.c_str(), &endptr, 10);
//////////////////////        if (*endptr != '\n' && *endptr != '\0') {
//////////////////////            cout << "Это не число. Попробуйте еще раз." << endl;
//////////////////////        } else {
//////////////////////            return num;
//////////////////////        }
//////////////////////    }
//////////////////////}
//////////////////////
//////////////////////// Абстрактный класс Creature
//////////////////////class Creature {
//////////////////////public:
//////////////////////    virtual string get_name() const = 0;
//////////////////////    virtual void make_sound() const = 0;
//////////////////////    virtual ~Creature() {}
//////////////////////};
//////////////////////
//////////////////////// Классы-наследники для различных существ
//////////////////////class Animal : public Creature {
//////////////////////protected:
//////////////////////    string habitat;
//////////////////////    int age;
//////////////////////public:
//////////////////////    Animal(const string& habitat, int age = 0) : habitat(habitat), age(age) {}
//////////////////////    virtual string get_name() const override { return "Animal"; }
//////////////////////    virtual void make_sound() const override { cout << "Some animal sound" << endl; }
//////////////////////};
//////////////////////
//////////////////////class Bird : public Animal {
//////////////////////public:
//////////////////////    Bird(const string& habitat, int age = 0) : Animal(habitat, age) {}
//////////////////////    virtual string get_name() const override { return "Bird"; }
//////////////////////    virtual void make_sound() const override { cout << "Chirp" << endl; }
//////////////////////    void fly() const { cout << "Flying in the sky!" << endl; }
//////////////////////};
//////////////////////
//////////////////////class Felidae : public Animal {
//////////////////////public:
//////////////////////    Felidae(const string& habitat, int age = 0) : Animal(habitat, age) {}
//////////////////////    virtual string get_name() const override { return "Felidae"; }
//////////////////////    virtual void make_sound() const override { cout << "Roar" << endl; }
//////////////////////    void run() const { cout << "Running swiftly!" << endl; }
//////////////////////};
//////////////////////
//////////////////////class Lion : public Felidae {
//////////////////////public:
//////////////////////    Lion(const string& habitat, int age = 0) : Felidae(habitat, age) {}
//////////////////////    virtual string get_name() const override { return "Lion"; }
//////////////////////    virtual void make_sound() const override { cout << "Roar" << endl; }
//////////////////////    void roar() const { cout << "Lion is roaring!" << endl; }
//////////////////////};
//////////////////////
//////////////////////class Eagle : public Bird {
//////////////////////public:
//////////////////////    Eagle(const string& habitat, int age = 0) : Bird(habitat, age) {}
//////////////////////    virtual string get_name() const override { return "Eagle"; }
//////////////////////    virtual void make_sound() const override { cout << "Screech" << endl; }
//////////////////////    void hunt() const { cout << "Eagle is hunting!" << endl; }
//////////////////////};
//////////////////////
//////////////////////class Spider : public virtual Creature {
//////////////////////protected:
//////////////////////    string webType;
//////////////////////    int legCount;
//////////////////////public:
//////////////////////    Spider(const string& webType, int legCount = 8) : webType(webType), legCount(legCount) {}
//////////////////////    virtual string get_name() const override { return "Spider"; }
//////////////////////    virtual void make_sound() const override { cout << "Hiss" << endl; }
//////////////////////    void spinWeb() const { cout << "Spinning a " << webType << " web!" << endl; }
//////////////////////    string get_web() { return webType; }
//////////////////////    int get_leg() { return legCount; }
//////////////////////};
//////////////////////
//////////////////////class Human : public virtual Creature {
//////////////////////protected:
//////////////////////    string profession;
//////////////////////    int age;
//////////////////////public:
//////////////////////    Human(const string& profession, int age = 0) : profession(profession), age(age) {}
//////////////////////    virtual string get_name() const override { return "Human"; }
//////////////////////    virtual void make_sound() const override { cout << "Hello, I am human!" << endl; }
//////////////////////    void talk() const { cout << "Talking like a human!" << endl; }
//////////////////////    int get_age() { return age; }
//////////////////////};
//////////////////////
//////////////////////class Assassin : public Human {
//////////////////////private:
//////////////////////    int hiddenBlade;
//////////////////////public:
//////////////////////    class Silent_assasin {};
//////////////////////    Assassin(const string& profession, int age, int hiddenBlade)
//////////////////////        : Human(profession, age), hiddenBlade(hiddenBlade) {}
//////////////////////    virtual string get_name() const override { return "Assassin (Human)"; }
//////////////////////    virtual void make_sound() const override { throw new Silent_assasin(); }
//////////////////////    void showHiddenBlade() const { cout << "Hidden Blade: " << hiddenBlade << endl; }
//////////////////////    void assassinate() const { cout << "Assassin is on a mission!" << endl; }
//////////////////////};
//////////////////////
//////////////////////class SpiderMan : public Human, public Spider {
//////////////////////public:
//////////////////////    string uchenie;
//////////////////////    SpiderMan(const string& uchenie) : Human("Superhero", 25), Spider("Silk"), uchenie(uchenie) {}
//////////////////////    virtual string get_name() const override { return "Spider-Man (Spider + Human)"; }
//////////////////////    virtual void make_sound() const override { cout << "With great power comes great responsibility!" << endl; }
//////////////////////    void showUchenie() const { cout << "Uchenie: " << uchenie << endl; }
//////////////////////    void swing() const { cout << "Swinging through the city!" << endl; }
//////////////////////};
//////////////////////
//////////////////////// Кастомный deque
//////////////////////template <typename T>
//////////////////////class My_deque {
//////////////////////public:
//////////////////////    My_deque() : head(nullptr), tail(nullptr), size(0) {}
//////////////////////
//////////////////////    class Iterator<T> {
//////////////////////    public:
//////////////////////        Iterator<T>(My_deque* node) : current(node) {}
//////////////////////
//////////////////////        T& operator*() {
//////////////////////            if (!current) throw out_of_range("Iterator<T> out of range");
//////////////////////            return current->element;
//////////////////////        }
//////////////////////
//////////////////////        Iterator<T>& operator++() {
//////////////////////            if (current) current = current->next;
//////////////////////            return *this;
//////////////////////        }
//////////////////////
//////////////////////        Iterator<T>& operator--() {
//////////////////////            if (current) current = current->prev;
//////////////////////            return *this;
//////////////////////        }
//////////////////////
//////////////////////        bool operator!=(const Iterator<T>& other) const {
//////////////////////            return current != other.current;
//////////////////////        }
//////////////////////
//////////////////////        bool operator==(const Iterator<T>& other) const {
//////////////////////            return current == other.current;
//////////////////////        }
//////////////////////
//////////////////////    private:
//////////////////////        My_deque* current;
//////////////////////    };
//////////////////////
//////////////////////    ~My_deque() {
//////////////////////        clear();
//////////////////////    }
//////////////////////
//////////////////////    void push_back(const T& value) {
//////////////////////        My_deque* new_node = new My_deque(value);
//////////////////////        if (tail) {
//////////////////////            tail->next = new_node;
//////////////////////            new_node->prev = tail;
//////////////////////            tail = new_node;
//////////////////////        } else {
//////////////////////            head = tail = new_node;
//////////////////////        }
//////////////////////        ++size;
//////////////////////    }
//////////////////////
//////////////////////    void push_front(const T& value) {
//////////////////////        My_deque* new_node = new My_deque(value);
//////////////////////        if (head) {
//////////////////////            head->prev = new_node;
//////////////////////            new_node->next = head;
//////////////////////            head = new_node;
//////////////////////        } else {
//////////////////////            head = tail = new_node;
//////////////////////        }
//////////////////////        ++size;
//////////////////////    }
//////////////////////
//////////////////////    void pop_back() {
//////////////////////        if (tail) {
//////////////////////            My_deque* temp = tail;
//////////////////////            tail = tail->prev;
//////////////////////            if (tail) tail->next = nullptr;
//////////////////////            delete temp;
//////////////////////            --size;
//////////////////////        }
//////////////////////    }
//////////////////////
//////////////////////    void pop_front() {
//////////////////////        if (head) {
//////////////////////            My_deque* temp = head;
//////////////////////            head = head->next;
//////////////////////            if (head) head->prev = nullptr;
//////////////////////            delete temp;
//////////////////////            --size;
//////////////////////        }
//////////////////////    }
//////////////////////
//////////////////////    T& operator[](size_t index) {
//////////////////////        if (index >= size) throw out_of_range("Index out of range");
//////////////////////        My_deque* current = head;
//////////////////////        for (size_t i = 0; i < index; ++i) {
//////////////////////            current = current->next;
//////////////////////        }
//////////////////////        return current->element;
//////////////////////    }
//////////////////////
//////////////////////    Iterator<T> begin() {
//////////////////////        return Iterator<T>(head);
//////////////////////    }
//////////////////////
//////////////////////    Iterator<T> end() {
//////////////////////        return Iterator<T>(nullptr);
//////////////////////    }
//////////////////////
//////////////////////    size_t get_size() const {
//////////////////////        return size;
//////////////////////    }
//////////////////////
//////////////////////    void clear() {
//////////////////////        while (head) {
//////////////////////            pop_front();
//////////////////////        }
//////////////////////    }
//////////////////////
//////////////////////private:
//////////////////////    My_deque* head;
//////////////////////    My_deque* tail;
//////////////////////    size_t size;
//////////////////////    T element;
//////////////////////    My_deque* prev;
//////////////////////    My_deque* next;
//////////////////////};
//////////////////////
//////////////////////// Контейнер для существ
//////////////////////template <typename T>
//////////////////////class CreatureContainer {
//////////////////////private:
//////////////////////    deque<unique_ptr<T>> creatures;
//////////////////////
//////////////////////public:
//////////////////////    void addCreature(unique_ptr<T> creature) {
//////////////////////        creatures.push_back(move(creature));
//////////////////////    }
//////////////////////
//////////////////////    void removeCreature(size_t index) {
//////////////////////        if (index >= creatures.get_size()) {
//////////////////////            throw out_of_range("Invalid index");
//////////////////////        }
//////////////////////
//////////////////////        My_deque<unique_ptr<T>> temp;
//////////////////////        size_t i = 0;
//////////////////////        for (auto it = creatures.begin(); it != creatures.end(); ++it) {
//////////////////////            if (i == index) {
//////////////////////                it = creatures.erase(it); // Удаляем элемент
//////////////////////                break;
//////////////////////            }
//////////////////////            ++i;
//////////////////////        }
//////////////////////    }
//////////////////////
//////////////////////    void showCreatures() const {
//////////////////////        if (creatures.get_size() == 0) {
//////////////////////            cout << "No creatures in the container.\n";
//////////////////////            return;
//////////////////////        }
//////////////////////        size_t i = 0;
//////////////////////        for (auto& creature : creatures) {
//////////////////////            cout << i++ << ". " << creature->get_name() << ": ";
//////////////////////            creature->make_sound();
//////////////////////        }
//////////////////////    }
//////////////////////};
//////////////////////
//////////////////////// Тестирование программы
//////////////////////int test() {
//////////////////////    CreatureContainer<Creature> container;
//////////////////////    container.addCreature(make_unique<Lion>("Savanna", 5));
//////////////////////    container.addCreature(make_unique<Eagle>("Mountain", 12));
//////////////////////    container.addCreature(make_unique<Spider>("Silk"));
//////////////////////    container.addCreature(make_unique<Human>("Doctor", 21));
//////////////////////    container.addCreature(make_unique<Assassin>("Ciller", 21));
//////////////////////    container.addCreature(make_unique<SpiderMan>("Ben Parker"));
//////////////////////
//////////////////////    container.showCreatures();
//////////////////////
//////////////////////    return 0;
//////////////////////}
//////////////////////
//////////////////////// Главная функция
//////////////////////int main(int argc, char** argv) {
//////////////////////    if (argc > 1 && !strcmp("test", argv[1])) {
//////////////////////        test();
//////////////////////        return 0;
//////////////////////    }
//////////////////////
//////////////////////    CreatureContainer<Creature> container;
//////////////////////
//////////////////////    try {
//////////////////////        while (true) {
//////////////////////            int choice = correct("\n1. Add creature\n2. Remove creature\n3. Show creatures\n4. Exit\n");
//////////////////////            if (choice == 1) {
//////////////////////                int type = correct("Select creature to add:\n1. Lion\n2. Eagle\n3. Spider\n4. Human\n5. SpiderMan\n");
//////////////////////                switch (type) {
//////////////////////                    case 1:
//////////////////////                        container.addCreature(make_unique<Lion>("Savanna", correct("Введите возраст льва:")));
//////////////////////                        break;
//////////////////////                    case 2:
//////////////////////                        container.addCreature(make_unique<Eagle>("Mountain", correct("Введите возраст орла:")));
//////////////////////                        break;
//////////////////////                    case 3:
//////////////////////                        container.addCreature(make_unique<Spider>("Silk"));
//////////////////////                        break;
//////////////////////                    case 4:
//////////////////////                        container.addCreature(make_unique<Human>("Doctor", correct("Введите возраст человека:")));
//////////////////////                        break;
//////////////////////                    case 5:
//////////////////////                        container.addCreature(make_unique<SpiderMan>("Ben Parker"));
//////////////////////                        break;
//////////////////////                    default:
//////////////////////                        cout << "Invalid selection!" << endl;
//////////////////////                        break;
//////////////////////                }
//////////////////////            } else if (choice == 2) {
//////////////////////                int index = correct("Enter index of creature to remove:") - 1;
//////////////////////                container.removeCreature(index);
//////////////////////            } else if (choice == 3) {
//////////////////////                container.showCreatures();
//////////////////////            } else if (choice == 4) {
//////////////////////                break;
//////////////////////            }
//////////////////////        }
//////////////////////    } catch (const exception& e) {
//////////////////////        cout << "Error: " << e.what() << endl;
//////////////////////    }
//////////////////////
//////////////////////    return 0;
//////////////////////}
//////////////////////
//////
//////
//////
//////
//////
//////#include <iostream>
//////#include <memory>
//////#include <stdexcept>
//////#include <string>
//////#include <deque>
//////#include <vector>
//////using namespace std;
//////
//////int correct(const string& prompt) {
//////    string input;
//////    int num;
//////    char* endptr;
//////    while (true) {
//////        cout << prompt;
//////        getline(cin, input);
//////        if (input.empty()) {
//////            return -1;
//////        }
//////        num = strtol(input.c_str(), &endptr, 10);
//////        if (*endptr != '\n' && *endptr != '\0') {
//////            cout << "Это не число. Попробуйте еще раз." << endl;
//////        } else {
//////            return num;
//////        }
//////    }
//////}
//////
//////class Creature {
//////public:
//////    virtual string get_name() const = 0;
//////    virtual void make_sound() const = 0;
//////    virtual ~Creature() {}
//////};
//////
//////class Animal : public Creature {
//////protected:
//////    string habitat;
//////    int age;
//////public:
//////    Animal(const string& habitat, int age = 0) : habitat(habitat), age(age) {}
//////    virtual string get_name() const override { return "Animal"; }
//////    virtual void make_sound() const override { cout << "Some animal sound" << endl; }
//////};
//////
//////class Bird : public Animal {
//////public:
//////    Bird(const string& habitat, int age = 0) : Animal(habitat, age) {}
//////    virtual string get_name() const override { return "Bird"; }
//////    virtual void make_sound() const override { cout << "Chirp" << endl; }
//////    void fly() const { cout << "Flying in the sky!" << endl; }
//////};
//////
//////class Felidae : public Animal {
//////public:
//////    Felidae(const string& habitat, int age = 0) : Animal(habitat, age) {}
//////    virtual string get_name() const override { return "Felidae"; }
//////    virtual void make_sound() const override { cout << "Roar" << endl; }
//////    void run() const { cout << "Running swiftly!" << endl; }
//////};
//////
//////class Lion : public Felidae {
//////public:
//////    Lion(const string& habitat, int age = 0) : Felidae(habitat, age) {}
//////    virtual string get_name() const override { return "Lion"; }
//////    virtual void make_sound() const override { cout << "Roar" << endl; }
//////    void roar() const { cout << "Lion is roaring!" << endl; }
//////};
//////
//////class Eagle : public Bird {
//////public:
//////    Eagle(const string& habitat, int age = 0) : Bird(habitat, age) {}
//////    virtual string get_name() const override { return "Eagle"; }
//////    virtual void make_sound() const override { cout << "Screech" << endl; }
//////    void hunt() const { cout << "Eagle is hunting!" << endl; }
//////};
//////
//////class Spider : public virtual Creature {
//////protected:
//////    string webType;
//////    int legCount;
//////public:
//////    Spider(const string& webType, int legCount = 8) : webType(webType), legCount(legCount) {}
//////    virtual string get_name() const override { return "Spider"; }
//////    virtual void make_sound() const override { cout << "Hiss" << endl; }
//////    void spinWeb() const { cout << "Spinning a " << webType << " web!" << endl; }
//////    string get_web() { return webType; }
//////    int get_leg() { return legCount; }
//////};
//////
//////class Human : public virtual Creature {
//////protected:
//////    string profession;
//////    int age;
//////public:
//////    Human(const string& profession, int age = 0) : profession(profession), age(age) {}
//////    virtual string get_name() const override { return "Human"; }
//////    virtual void make_sound() const override { cout << "Hello, I am human!" << endl; }
//////    void talk() const { cout << "Talking like a human!" << endl; }
//////    int get_age() { return age; }
//////};
//////
//////class Assassin : public Human {
//////private:
//////    int hiddenBlade;
//////public:
//////    class Silent_assasin {};
//////
//////    Assassin(const string& profession, int age, int hiddenBlade)
//////        : Human(profession, age), hiddenBlade(hiddenBlade) {}
//////    virtual string get_name() const override { return "Assassin (Human)"; }
//////    virtual void make_sound() const override { throw new Silent_assasin(); }
//////    void showHiddenBlade() const { cout << "Hidden Blade: " << hiddenBlade << endl; }
//////    void assassinate() const { cout << "Assassin is on a mission!" << endl; }
//////};
//////
//////class SpiderMan : public Human, public Spider {
//////public:
//////    string uchenie;
//////    SpiderMan(const string& uchenie) : Human("Superhero", 25), Spider("Silk"), uchenie(uchenie) {}
//////    virtual string get_name() const override { return "Spider-Man (Spider + Human)"; }
//////    virtual void make_sound() const override { cout << "With great power comes great responsibility!" << endl; }
//////    void showUchenie() const { cout << "Uchenie: " << uchenie << endl; }
//////    void swing() const { cout << "Swinging through the city!" << endl; }
//////};
//////
//////template <typename T>
//////class My_deque {
//////public:
//////    My_deque() : head(nullptr), tail(nullptr), size(0) {}
//////
//////	template <typename T>
//////    class Node {
//////    public:
//////        T& element;
//////        Node<T> *prev;
//////        Node<T> *next;
//////        Node<T>(T& elem) : element(elem) {}
//////    };
//////	template <typename T>
//////    class Iterator {
//////    public:
//////        Iterator(Node<T>* node) : current(node) {}
//////
//////        T& operator*() {
//////            return current->element;
//////        }
//////
//////        Iterator<T>& operator++() {
//////            if(current){
//////                current = current->next;
//////            }
//////            return *this;
//////        }
//////
//////        Iterator<T>& operator--() {
//////            if(current){
//////                current = current->prev;
//////            }
//////            return *this;
//////        }
//////
//////        bool operator!=(const Iterator<T>& other) const {
//////            return this != other;
//////        }
//////
//////        bool operator==(const Iterator<T>& other) const {
//////            return this == other;
//////        }
//////        bool has() {
//////            return this->current != NULL;
//////        }
//////
//////    private:
//////        Node<T> *current;
//////    };
//////
//////    ~My_deque() {
//////        clear();
//////    }
//////
//////    void push_back(T& value) {
//////        Node<T>* new_node = new Node<T>(value);
//////        if (tail) {
//////            tail->next = new_node;
//////            new_node->prev = tail;
//////            tail = new_node;
//////        } else {
//////            head = tail = new_node;
//////        }
//////        size++;
//////    }
//////
//////    void push_front(const T& value) {
//////        Node<T>* new_node = new Node<T>(value);
//////        if (head) {
//////            head->prev = new_node;
//////            new_node->next = head;
//////            head = new_node;
//////        } else {
//////            head = tail = new_node;
//////        }
//////        ++size;
//////    }
//////
//////    void pop_back() {
//////        if (tail) {
//////            Node<T>* temp = tail;
//////            tail = tail->prev;
//////            if (tail) tail->next = nullptr;
//////            delete temp;
//////            size--;
//////        }
//////    }
//////
//////    void pop_front() {
//////        if (head) {
//////            Node<T>* temp = head;
//////            head = head->next;
//////            if (head) head->prev = nullptr;
//////            delete temp;
//////            size--;
//////        }
//////    }
//////
//////    T& operator[](size_t index) {
//////        if (index >= size) throw out_of_range("Index out of range");
//////        Node<T>* current = head;
//////        for (size_t i = 0; i < index; ++i) {
//////            current = current->next;
//////        }
//////        return new Iterator<T>(current);
//////    }
//////
//////    Iterator<T> iterator() {
//////        return Iterator<T>(head);
//////    }
//////
//////    size_t get_size() const {
//////        return size;
//////    }
//////
//////    void clear() {
//////        while (head) {
//////            pop_front();
//////        }
//////    }
//////
//////private:
//////    Node<T>* head;
//////    Node<T>* tail;
//////    size_t size;
//////};
//////
////////template <typename T>
////////class CreatureContainer {
////////private:
////////    My_deque<unique_ptr<T>> creatures;
////////
////////public:
////////    void addCreature(unique_ptr<T> creature) {
////////        creatures.push_back(move(creature));
////////    }
////////
////////    void removeCreature(size_t index) {
////////        if (index >= creatures.get_size()) {
////////            throw out_of_range("Invalid index");
////////        }
////////
////////        My_deque<unique_ptr<T>> temp;
////////        size_t i = 0;
////////        for (auto it = creatures.iterator(); it != creatures.end(); ++it) {
////////            if (i == index) {
////////                it = creatures.erase(it); 
////////                break;
////////            }
////////            ++i;
////////        }
////////    }
////////    void showCreatures() {
////////        size_t i = 0;
////////        for (auto& creature : creatures) {
////////            cout << i + 1 << ". " << creature->get_name() << endl;
////////            ++i;
////////        }
////////    }
////////};
//////
//////int test() {
//////    Lion lev = Lion("Savanna", 14);
//////    My_deque<Creature> container;
//////    container.push_back(lev);
//////    Lion levs = Lion("Savanna", 15);
//////    container.push_back(levs);
//////    for (My_deque<Creature>::Iterator<Creature> it = container.iterator(); it.has(); ++it) {
//////        cout << (*it).get_name();
//////
//////    }
//////	//container.push_back(Lion("Savanna", 15));
//////    //CreatureContainer<Creature> container;
//////   // container.addCreature(make_unique<Lion>("Savanna", 5));
//////   // container.addCreature(make_unique<Eagle>("Mountain", 12));
//////   // container.addCreature(make_unique<Spider>("Silk"));
//////   // container.addCreature(make_unique<Human>("Doctor", 21));
//////   // container.addCreature(make_unique<Assassin>("Ciller", 21));
//////   // container.addCreature(make_unique<SpiderMan>("Ben Parker"));
//////
//////    return 0;
//////}
//////
//////int main() {
//////    test();
////////    CreatureContainer<Creature> container;
////////
////////    try {
////////        while (true) {
////////            int choice = correct("\n1. Add creature\n2. Remove creature\n3. Show creatures\n4. Exit\n");
////////            if (choice == 1) {
////////                int type = correct("Select creature to add:\n1. Lion\n2. Eagle\n3. Spider\n4. Human\n5. SpiderMan\n");
////////                switch (type) {
////////                    case 1:
////////                        container.addCreature(make_unique<Lion>("Savanna", correct("Enter Lion age:")));
////////                        break;
////////                    case 2:
////////                        container.addCreature(make_unique<Eagle>("Mountain", correct("Enter Eagle age:")));
////////                        break;
////////                    case 3:
////////                        container.addCreature(make_unique<Spider>("Silk"));
////////                        break;
////////                    case 4:
////////                        container.addCreature(make_unique<Human>("Doctor", correct("Enter Human age:")));
////////                        break;
////////                    case 5:
////////                        container.addCreature(make_unique<SpiderMan>("Ben Parker"));
////////                        break;
////////                    default:
////////                        std::cout << "Invalid selection!" << std::endl;
////////                        break;
////////                }
////////            } else if (choice == 2) {
////////                container.showCreatures();
////////                int index = correct("Enter index of creature to remove:") - 1;
////////                container.removeCreature(index);
////////            } else if (choice == 3) {
////////                container.showCreatures();
////////            } else if (choice == 4) {
////////                break;
////////            }
////////        }
////////    } catch (const std::exception& e) {
////////        std::cout << "Error: " << e.what() << std::endl;
////////    }
////////
//////    return 0;
//////}
//////
//////
//////// C++ Program to Implement Double Ended Queue
//////#include <iostream>
//////#include <stdexcept>
//////using namespace std;
//////// Template class for a doubly linked list based Deque
//////template <typename T> class Deque {
//////private:
//////    // Node structure representing each element in the Deque
//////    struct Node {
//////        // Data held by the node
//////        T data;
//////        // Pointer to the previous node
//////        Node* prev;
//////        // Pointer to the next node
//////        Node* next;
//////
//////        // Constructor to initialize a Node with a given
//////        // value
//////        Node(T value)
//////            : data(value)
//////            , prev(nullptr)
//////            , next(nullptr)
//////        {
//////        }
//////    };
//////    // Pointer to the front of the Deque
//////    Node* front;
//////    // Pointer to the rear of the Deque
//////    Node* rear;
//////    // Number of elements in the Deque
//////    int size;
//////
//////public:
//////    // Constructor to initialize an empty Deque
//////    Deque()
//////        : front(nullptr)
//////        , rear(nullptr)
//////        , size(0)
//////    {
//////    }
//////
//////    // Destructor to clean up memory by removing all
//////    // elements
//////    ~Deque()
//////    {
//////        while (!is_empty()) {
//////            pop_front();
//////        }
//////    }
//////
//////    // Function to add an element to the front of the Deque
//////    void push_front(T value)
//////    {
//////        // Create a new node
//////        Node* new_node = new Node(value);
//////        // If Deque is empty, both front and rear point to
//////        // the new node
//////        if (is_empty()) {
//////            front = rear = new_node;
//////        }
//////        else {
//////            // Link the new node to the current front
//////            new_node->next = front;
//////            // Link the current front to the new node
//////            front->prev = new_node;
//////            // Update front to the new node
//////            front = new_node;
//////        }
//////        // Increment the size of the Deque
//////        size++;
//////    }
//////
//////    // Function to add an element to the back of the Deque
//////    void push_back(T value)
//////    {
//////        Node* new_node
//////            = new Node(value); // Create a new node
//////        if (is_empty()) {
//////            // If Deque is empty, both front  and rear point
//////            // to the new node
//////            front = rear = new_node;
//////        }
//////        else {
//////            // Link the new node to the current rear
//////            new_node->prev = rear;
//////            // Link the current rear to the new node
//////            rear->next = new_node;
//////            // Update rear to the new node
//////            rear = new_node;
//////        }
//////        // Increment the size of the Deque
//////        size++;
//////    }
//////
//////    // Function to remove an element from the front of the
//////    // Deque
//////    void pop_front()
//////    {
//////        if (is_empty()) {
//////            // Throw an error if Deque is empty
//////            throw runtime_error("Deque is empty");
//////        }
//////        // Temporarily hold the front node
//////        Node* temp = front;
//////        // Move front to the next node
//////        front = front->next;
//////        if (front == nullptr) {
//////            // If Deque is now empty, set rear to null
//////            rear = nullptr;
//////        }
//////        else {
//////            // Otherwise, unlink the old front node
//////            front->prev = nullptr;
//////        }
//////        // Free the memory of the old front node
//////        delete temp;
//////        // Decrement the size of the Deque
//////        size--;
//////    }
//////
//////    // Function to remove an element from the back of the
//////    // Deque
//////    void pop_back()
//////    {
//////        if (is_empty()) {
//////            // Throw an error if Deque is empty
//////            throw runtime_error("Deque is empty");
//////        }
//////        // Temporarily hold the rear node
//////        Node* temp = rear;
//////        // Move rear to the previous node
//////        rear = rear->prev;
//////        if (rear == nullptr) {
//////            // If Deque is now empty, set front to null
//////            front = nullptr;
//////        }
//////        else {
//////            // Otherwise, unlink the old rear node
//////            rear->next = nullptr;
//////        }
//////        // Free the memory of the old rear node
//////        delete temp;
//////        // Decrement the size of the Deque
//////        size--;
//////    }
//////
//////    // Function to get the element at the front of the Deque
//////    T get_front()
//////    {
//////        if (is_empty()) {
//////            // Throw an error if Deque is empty
//////            throw runtime_error("Deque is empty");
//////        }
//////        // Return the data of the front node
//////        return front->data;
//////    }
//////
//////    // Function to get the element at the rear of the Deque
//////    T get_rear()
//////    {
//////        if (is_empty()) {
//////            // Throw an error if Deque is empty
//////            throw runtime_error("Deque is empty");
//////        }
//////        // Return the data of the rear node
//////        return rear->data;
//////    }
//////
//////    // Function to check if the Deque is empty
//////    bool is_empty()
//////    {
//////        // Deque is empty if size is 0
//////        return size == 0;
//////    }
//////
//////    // Function to get the number of elements in the Deque
//////    int get_size()
//////    {
//////        // Return the current size of the Deque
//////        return size;
//////    }
//////
//////    // Function to display the elements of the Deque
//////    void display()
//////    {
//////        // Start from the front node
//////        Node* current = front;
//////        while (current != nullptr) {
//////            // Print the data of the current node
//////            cout << current->data << " ";
//////            // Move to the next node
//////            current = current->next;
//////        }
//////        cout << endl;
//////    }
//////};
//////
//////int main()
//////{
//////    // Create a Deque of integers
//////    Deque<int> deque;
//////
//////    // Push elements to the front and back
//////    deque.push_front(10);
//////    deque.push_back(20);
//////    deque.push_front(5);
//////    deque.push_back(30);
//////
//////    // Display the Deque after pushes
//////    cout << "Deque after pushes: ";
//////    deque.display();
//////
//////    // Get and display the front and rear elements
//////    cout << "Front element: " << deque.get_front() << endl;
//////    cout << "Rear element: " << deque.get_rear() << endl;
//////
//////    // Pop elements from the front and back
//////    deque.pop_front();
//////    deque.pop_back();
//////
//////    // Display the Deque after pops
//////    cout << "Deque after pops: ";
//////    deque.display();
//////
//////    // Display the size of the Deque
//////    cout << "Size of deque: " << deque.get_size() << endl;
//////
//////    return 0;
//////}



/*#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
using namespace std;

class Creature {
public:
    virtual string get_name() const = 0;
    virtual void make_sound() const = 0;
    virtual ~Creature() {}
};

class Animal : public Creature {
protected:
    string habitat;
    int age;
public:
    Animal(const string& habitat, int age = 0) : habitat(habitat), age(age) {}
    virtual string get_name() const override { return "Animal"; }
    virtual void make_sound() const override { cout << "Some animal sound" << endl; }
};

class Bird : public Animal {
public:
    Bird(const string& habitat, int age = 0) : Animal(habitat, age) {}
    virtual string get_name() const override { return "Bird"; }
    virtual void make_sound() const override { cout << "Chirp" << endl; }
    void fly() const { cout << "Flying in the sky!" << endl; }
};

class Felidae : public Animal {
public:
    Felidae(const string& habitat, int age = 0) : Animal(habitat, age) {}
    virtual string get_name() const override { return "Felidae"; }
    virtual void make_sound() const override { cout << "Roar" << endl; }
    void run() const { cout << "Running swiftly!" << endl; }
};

class Lion : public Felidae {
public:
    Lion(const string& habitat, int age = 0) : Felidae(habitat, age) {}
    virtual string get_name() const override { return "Lion"; }
    virtual void make_sound() const override { cout << "Roar" << endl; }
    void roar() const { cout << "Lion is roaring!" << endl; }
};

class Eagle : public Bird {
public:
    Eagle(const string& habitat, int age = 0) : Bird(habitat, age) {}
    virtual string get_name() const override { return "Eagle"; }
    virtual void make_sound() const override { cout << "Screech" << endl; }
    void hunt() const { cout << "Eagle is hunting!" << endl; }
};

class Spider : public virtual Creature {
protected:
    string webType;
    int legCount;
public:
    Spider(const string& webType, int legCount = 8) : webType(webType), legCount(legCount) {}
    virtual string get_name() const override { return "Spider"; }
    virtual void make_sound() const override { cout << "Hiss" << endl; }
    void spinWeb() const { cout << "Spinning a " << webType << " web!" << endl; }
    string get_web() { return webType; }
    int get_leg() { return legCount; }
};

class Human : public virtual Creature {
protected:
    string profession;
    int age;
public:
    Human(const string& profession, int age = 0) : profession(profession), age(age) {}
    virtual string get_name() const override { return "Human"; }
    virtual void make_sound() const override { cout << "Hello, I am human!" << endl; }
    void talk() const { cout << "Talking like a human!" << endl; }
    int get_age() { return age; }
};

class Assassin : public Human {
private:
    int hiddenBlade;
public:
    class Silent_assasin {};

    Assassin(const string& profession, int age, int hiddenBlade)
        : Human(profession, age), hiddenBlade(hiddenBlade) {}
    virtual string get_name() const override { return "Assassin (Human)"; }
    virtual void make_sound() const override { throw new Silent_assasin(); }
    void showHiddenBlade() const { cout << "Hidden Blade: " << hiddenBlade << endl; }
    void assassinate() const { cout << "Assassin is on a mission!" << endl; }
};

class SpiderMan : public Human, public Spider {
public:
    string uchenie;
    SpiderMan(const string& uchenie) : Human("Superhero", 25), Spider("Silk"), uchenie(uchenie) {}
    virtual string get_name() const override { return "Spider-Man (Spider + Human)"; }
    virtual void make_sound() const override { cout << "With great power comes great responsibility!" << endl; }
    void showUchenie() const { cout << "Uchenie: " << uchenie << endl; }
    void swing() const { cout << "Swinging through the city!" << endl; }
};

// Реализация класса Deque с итератором
template <typename T> 
class Deque {
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
    Deque() : front(nullptr), rear(nullptr), size(0) {}
    ~Deque() { while (!is_empty()) pop_front(); }

    void push_front(T value) {
        Node* new_node = new Node(value);
        if (is_empty()) {
            front = rear = new_node;
        } else {
            new_node->next = front;
            front->prev = new_node;
            front = new_node;
        }
        size++;
    }

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

    void pop_back() {
        if (is_empty()) throw runtime_error("Deque is empty");
        Node* temp = rear;
        rear = rear->prev;
        if (rear == nullptr) front = nullptr;
        else rear->next = nullptr;
        delete temp;
        size--;
    }

    T get_front() {
        if (is_empty()) throw runtime_error("Deque is empty");
        return front->data;
    }

    T get_rear() {
        if (is_empty()) throw runtime_error("Deque is empty");
        return rear->data;
    }

    bool is_empty() { return size == 0; }
    int get_size() { return size; }

    void display() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data->get_name() << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Итератор
    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}

        T& operator*() { return current->data; }
        Iterator& operator++() {
            current = current->next;
            return *this;
        }
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() { return Iterator(front); }
    Iterator end() { return Iterator(nullptr); }
};

// Пример использования
int test() {
    Lion lev("Savanna", 14);
    Deque<Creature*> container;
    container.push_back(&lev);  // Добавляем в Deque указатель на объект Lion
    Lion levs("Savanna", 15);
    container.push_back(&levs);
    container.push_back(new SpiderMan("Ben"));

    // Используем итератор для обхода элементов в Deque
    for (Deque<Creature*>::Iterator it = container.begin(); it != container.end(); ++it) {
        cout << (*it)->get_name() << endl;  // Выводим имя каждого существа
        (*it)->make_sound();  // Выводим имя каждого существа
    }

    return 0;
}

int main() {
    test();
    return 0;
}

*/





/*
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <fstream>
using namespace std;

class InvalidInputException : public runtime_error {
public:
    InvalidInputException(const string& message) : runtime_error(message) {}
};

// Функция для получения корректного целого числа с проверкой диапазона
int correct(const string& prompt, int min, int max) {
    string input;
    int num;
    char* endptr;

    while (true) {
        try {
            cout << prompt;
            getline(cin, input);

            // Если ввод пустой, возвращаем -1
            if (input.empty()) {
                return -1;
            }

            // Преобразуем строку в число
            num = strtol(input.c_str(), &endptr, 10);

            // Если введённое значение не является числом
            if (*endptr != '\0') {
                throw InvalidInputException("Это не число. Попробуйте еще раз.");
            }

            // Проверка на диапазон
            if (num < min || num > max) {
                throw InvalidInputException("Число должно быть в диапазоне от " + to_string(min) + " до " + to_string(max) + ". Попробуйте еще раз.");
            }

            // Если все проверки пройдены, возвращаем число
            return num;

        } catch (const InvalidInputException& e) {
            cout << e.what() << endl;
        } catch (const exception& e) {
            // Поймать любые другие исключения
            cout << "Произошла ошибка: " << e.what() << endl;
        }
    }
}



// 1. Основные классы и наследование
class Creature {
public:
    virtual string get_name() const = 0;
    virtual void make_sound() const = 0;
    virtual ~Creature() {}
};

class Animal : public Creature {
protected:
    string habitat;
    int age;
public:
    Animal(const string& habitat, int age = 0) : habitat(habitat), age(age) {}
    virtual string get_name() const override { return "Animal"; }
    virtual void make_sound() const override { cout << "Some animal sound" << endl; }
};

class Bird : public Animal {
public:
    Bird(const string& habitat, int age = 0) : Animal(habitat, age) {}
    virtual string get_name() const override { return "Bird"; }
    virtual void make_sound() const override { cout << "Chirp" << endl; }
    void fly() const { cout << "Flying in the sky!" << endl; }
};

class Felidae : public Animal {
public:
    Felidae(const string& habitat, int age = 0) : Animal(habitat, age) {}
    virtual string get_name() const override { return "Felidae"; }
    virtual void make_sound() const override { cout << "Roar" << endl; }
    void run() const { cout << "Running swiftly!" << endl; }
};

class Lion : public Felidae {
public:
    Lion(const string& habitat, int age = 0) : Felidae(habitat, age) {}
    virtual string get_name() const override { return "Lion"; }
    virtual void make_sound() const override { cout << "Roar" << endl; }
    void roar() const { cout << "Lion is roaring!" << endl; }
};

class Eagle : public Bird {
public:
    Eagle(const string& habitat, int age = 0) : Bird(habitat, age) {}
    virtual string get_name() const override { return "Eagle"; }
    virtual void make_sound() const override { cout << "Screech" << endl; }
    void hunt() const { cout << "Eagle is hunting!" << endl; }
};

// 2. Виртуальное наследование (Пример с несколькими базовыми классами)
class Spider : public virtual Creature {
protected:
    string webType;
    int legCount;
public:
    Spider(const string& webType, int legCount = 8) : webType(webType), legCount(legCount) {}
    virtual string get_name() const override { return "Spider"; }
    virtual void make_sound() const override { cout << "Hiss" << endl; }
    void spinWeb() const { cout << "Spinning a " << webType << " web!" << endl; }
    string get_web() { return webType; }
    int get_leg() { return legCount; }
};

class Human : public virtual Creature {
protected:
    string profession;
    int age;
public:
    Human(const string& profession, int age = 0) : profession(profession), age(age) {}
    virtual string get_name() const override { return "Human"; }
    virtual void make_sound() const override { cout << "Hello, I am human!" << endl; }
    void talk() const { cout << "Talking like a human!" << endl; }
    int get_age() { return age; }
};

// 3. Шаблонный класс контейнера
template <typename T> 
class Deque {
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
    Deque() : front(nullptr), rear(nullptr), size(0) {}
    ~Deque() { while (!is_empty()) pop_front(); }

    void push_front(T value) {
        Node* new_node = new Node(value);
        if (is_empty()) {
            front = rear = new_node;
        } else {
            new_node->next = front;
            front->prev = new_node;
            front = new_node;
        }
        size++;
    }

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

    void pop_back() {
        if (is_empty()) throw runtime_error("Deque is empty");
        Node* temp = rear;
        rear = rear->prev;
        if (rear == nullptr) front = nullptr;
        else rear->next = nullptr;
        delete temp;
        size--;
    }

    T get_front() {
        if (is_empty()) throw runtime_error("Deque is empty");
        return front->data;
    }

    T get_rear() {
        if (is_empty()) throw runtime_error("Deque is empty");
        return rear->data;
    }

    bool is_empty() { return size == 0; }
    int get_size() { return size; }

    void display() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data->get_name() << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Итератор
    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}

        T& operator*() { return current->data; }
        Iterator& operator++() {
            current = current->next;
            return *this;
        }
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() { return Iterator(front); }
    Iterator end() { return Iterator(nullptr); }
};

// 4. Исключения и обработка ошибок
class CustomException : public exception {
public:
    const char* what() const noexcept override {
        return "Custom exception occurred!";
    }
};

// Функция для проверки ввода
int get_integer_input() {
    int x;
    cin >> x;
    if (!cin) {
        throw runtime_error("Invalid input!");
    }
    return x;
}

// Пример использования программы
int test() {
    try {
        Deque<Creature*> container;
        Lion lev("Savanna", 14);
        container.push_back(&lev);
        Lion levs("Savanna", 15);
        container.push_back(&levs);
        container.push_back(new Eagle("Mountains"));

        for (Deque<Creature*>::Iterator it = container.begin(); it != container.end(); ++it) {
            cout << (*it)->get_name() << endl;
            (*it)->make_sound();
        }

        int age = get_integer_input();
        cout << "Age entered: " << age << endl;

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

int main() {
    test();
    return 0;
}

//// Класс CreatureContainer — контейнер для существ
//class CreatureContainer {
//private:
//    std::vector<std::unique_ptr<Creature>> creatures; // Вектор для хранения умных указателей
//
//public:
//    void addCreature(std::unique_ptr<Creature> creature) {
//        creatures.push_back(std::move(creature));
//    }
//
//    void removeCreature(size_t index) {
//        if (index < creatures.size()) {
//            creatures.erase(creatures.begin() + index);
//        } else {
//            throw std::out_of_range("Invalid index");
//        }
//    }
//
//    void showCreatures() const {
//        if (creatures.empty()) {
//            std::cout << "No creatures in the container.\n";
//            return;
//        }
//        for (size_t i = 0; i < creatures.size(); ++i) {
//            std::cout << i + 1 << ". " << creatures[i]->getName() << ": ";
//            creatures[i]->makeSound();
//        }
//    }
//};
//
//int main() {
//    CreatureContainer container;
//
//    try {
//        while (true) {
//            int choice = correct("\n1. Add creature\n2. Remove creature\n3. Show creatures\n4. Exit\n");
//            if (choice == 1) {
//                int type = correct("Select creature to add:\n1. Lion\n2. Eagle\n3. Spider\n4. Human\n");
//                switch (type) {
//                    case 1:
//                        container.addCreature(std::make_unique<Lion>("Savanna", correct("Введите возраст льва:")));
//                        break;
//                    case 2:
//                        container.addCreature(std::make_unique<Eagle>("Mountain", correct("Введите возраст орла:")));
//                        break;
//                    case 3:
//                        container.addCreature(std::make_unique<Spider>("Silk"));
//                        break;
//                    case 4:
//                        container.addCreature(std::make_unique<Human>("Doctor", correct("Введите возраст человека:")));
//                        break;
//                    default:
//                        std::cout << "Invalid selection!" << std::endl;
//                        break;
//                }
//            } else if (choice == 2) {
//                container.showCreatures();
//                int index = correct("Enter index of creature to remove:") - 1;
//                container.removeCreature(index);
//            } else if (choice == 3) {
//                container.showCreatures();
//            } else if (choice == 4) {
//                break;
//            }
//        }
//    } catch (const std::exception& e) {
//        std::cout << "Error: " << e.what() << std::endl;
//    }
//
//    return 0;
//}
//

//////////    /*
//////////    3:изучить принципы и получить практические навыки при 
//////////использовании наследования классов; разработать иерархию насследования 
//////////классов; изучить вызов конструкторов и деструкторов при наследовании классов; 
//////////дополнительно: рассмотреть случаи, когда необходимо использовать 
//////////виртуальное наследование. 
//////////    4: изучить принципы и получить практические навыки при использовании шаблонов классов и функций; научиться использовать шаблоны функций для создания группы однотипных функций, а также шаблоны классов 
//////////для создания группы связанных типов классов; продемонстрировать работу 
//////////написанной прораммы.
//////////    5:Содержание работы: Разработка собственных классов обработки 
//////////    исключений. Обработчики исключительных ситуаций. Перенаправление 
//////////    исключительных ситуаций. Исключения стандартной библиотекиПонять, как обрабатываются исключения. Использовать 
//////////    try, throw и catch для отслеживания, индикации и обработки исключений. 
//////////    Написать свои функции для проверки правильности ввода. 
//////////    6:Изучить стандартную библиотеку iostream. Научиться 
//////////    работать с файлами. Записать/прочитать данные в текстовом и бинарном виде.
//////////    7:Цель работы: Научиться разрабатывать свои классы-контейнеры, разделяя их на контейнеры, итераторы и алгоритм
//////////
//////////// 
//////////// 
//////////// 
//////////// 
//////////// 
//////////// 
//////////     
*/




//#include <iostream>
//#include <memory>
//#include <stdexcept>
//#include <string>
//#include <fstream>
//
//using namespace std;
//
//class InvalidInputException : public runtime_error {
//public:
//    InvalidInputException(const string& message) : runtime_error(message) {}
//};
//
//// Функция для получения корректного целого числа с проверкой диапазона
//int correct(const string& prompt, int min, int max) {
//    string input;
//    int num;
//    char* endptr;
//
//    while (true) {
//        try {
//            cout << prompt;
//            getline(cin, input);
//
//            // Если ввод пустой, возвращаем -1
//            if (input.empty()) {
//                return -1;
//            }
//
//            // Преобразуем строку в число
//            num = strtol(input.c_str(), &endptr, 10);
//
//            // Если введённое значение не является числом
//            if (*endptr != '\0') {
//                throw InvalidInputException("Это не число. Попробуйте еще раз.");
//            }
//
//            // Проверка на диапазон
//            if (num < min || num > max) {
//                throw InvalidInputException("Число должно быть в диапазоне от " + to_string(min) + " до " + to_string(max) + ". Попробуйте еще раз.");
//            }
//
//            // Если все проверки пройдены, возвращаем число
//            return num;
//
//        } catch (const InvalidInputException& e) {
//            cout << e.what() << endl;
//        } catch (const exception& e) {
//            // Поймать любые другие исключения
//            cout << "Произошла ошибка: " << e.what() << endl;
//        }
//    }
//}
//
//// 1. Основные классы и наследование
//class Creature {
//public:
//    virtual string get_name() const = 0;
//    virtual void make_sound() const = 0;
//    virtual ~Creature() {}
//};
//
//class Animal : public virtual Creature {
//protected:
//    string habitat;
//    int age;
//public:
//    Animal(const string& habitat, int age = 0) : habitat(habitat), age(age) {}
//    virtual string get_name() const override { return "Animal"; }
//    virtual void make_sound() const override { cout << "Some animal sound" << endl; }
//};
//
//class Lion : public virtual Animal {
//public:
//    Lion(const string& habitat, int age = 0) : Animal(habitat, age) {}
//    virtual string get_name() const override { return "Lion"; }
//    virtual void make_sound() const override { cout << "Roar" << endl; }
//    void roar() const { cout << "Lion is roaring!" << endl; }
//};
//
//class Eagle : public virtual Animal {
//public:
//    Eagle(const string& habitat, int age = 0) : Animal(habitat, age) {}
//    virtual string get_name() const override { return "Eagle"; }
//    virtual void make_sound() const override { cout << "Screech" << endl; }
//    void hunt() const { cout << "Eagle is hunting!" << endl; }
//};
//
//// 2. Виртуальное наследование (Пример с несколькими базовыми классами)
//class Spider : public virtual Creature {
//protected:
//    string webType;
//    int legCount;
//public:
//    Spider(const string& webType, int legCount = 8) : webType(webType), legCount(legCount) {}
//    virtual string get_name() const override { return "Spider"; }
//    virtual void make_sound() const override { cout << "Hiss" << endl; }
//    void spinWeb() const { cout << "Spinning a " << webType << " web!" << endl; }
//    string get_web() { return webType; }
//    int get_leg() { return legCount; }
//};
//
//class Human : public virtual Creature {
//protected:
//    string profession;
//    int age;
//public:
//    Human(const string& profession, int age = 0) : profession(profession), age(age) {}
//    virtual string get_name() const override { return "Human"; }
//    virtual void make_sound() const override { cout << "Hello, I am human!" << endl; }
//    void talk() const { cout << "Talking like a human!" << endl; }
//    int get_age() { return age; }
//};
//
//// Новые классы
//class Griffon : public virtual Eagle, public virtual Lion {
//public:
//    Griffon(const string& habitat, int age = 0) : Eagle(habitat, age), Lion(habitat, age) {}
//    virtual string get_name() const override { return "Griffon"; }
//    virtual void make_sound() const override { cout << "Griffon roar and screech!" << endl; }
//    void fly_and_roar() const {
//        hunt();
//        roar();
//    }
//};
//
//class SpiderMan : public virtual Spider, public virtual Human {
//public:
//    SpiderMan(const string& profession, int age = 0) : Human(profession, age), Spider("Silk") {}
//    virtual string get_name() const override { return "SpiderMan"; }
//    virtual void make_sound() const override { cout << "I am SpiderMan!" << endl; }
//    void swing() const { cout << "Swinging from web!" << endl; }
//};
//
//class Assassin : public virtual Eagle, public virtual Human {
//public:
//    Assassin(const string& profession, int age = 0) : Human(profession, age), Eagle("Rooftops") {}
//    virtual string get_name() const override { return "Assassin"; }
//    virtual void make_sound() const override { cout << "Silent assassin!" << endl; }
//    void sneak_attack() const { cout << "Performing a sneak attack!" << endl; }
//};
//
//// 3. Шаблонный класс контейнера
//template <typename T>
//class Deque {
//private:
//    struct Node {
//        T data;
//        Node* prev;
//        Node* next;
//        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
//    };
//    Node* front;
//    Node* rear;
//    int size;
//public:
//    Deque() : front(nullptr), rear(nullptr), size(0) {}
//    ~Deque() { while (!is_empty()) pop_front(); }
//
//    void push_front(T value) {
//        Node* new_node = new Node(value);
//        if (is_empty()) {
//            front = rear = new_node;
//        } else {
//            new_node->next = front;
//            front->prev = new_node;
//            front = new_node;
//        }
//        size++;
//    }
//
//    void push_back(T value) {
//        Node* new_node = new Node(value);
//        if (is_empty()) {
//            front = rear = new_node;
//        } else {
//            new_node->prev = rear;
//            rear->next = new_node;
//            rear = new_node;
//        }
//        size++;
//    }
//
//    void pop_front() {
//        if (is_empty()) throw runtime_error("Deque is empty");
//        Node* temp = front;
//        front = front->next;
//        if (front == nullptr) rear = nullptr;
//        else front->prev = nullptr;
//        delete temp;
//        size--;
//    }
//
//    void pop_back() {
//        if (is_empty()) throw runtime_error("Deque is empty");
//        Node* temp = rear;
//        rear = rear->prev;
//        if (rear == nullptr) front = nullptr;
//        else rear->next = nullptr;
//        delete temp;
//        size--;
//    }
//
//    T get_front() {
//        if (is_empty()) throw runtime_error("Deque is empty");
//        return front->data;
//    }
//
//    T get_rear() {
//        if (is_empty()) throw runtime_error("Deque is empty");
//        return rear->data;
//    }
//
//    bool is_empty() { return size == 0; }
//    int get_size() { return size; }
//
//    void display() {
//        Node* current = front;
//        while (current != nullptr) {
//            cout << current->data->get_name() << " ";
//            current = current->next;
//        }
//        cout << endl;
//    }
//
//    // Итератор
//    class Iterator {
//    private:
//        Node* current;
//    public:
//        Iterator(Node* node) : current(node) {}
//
//        T& operator*() { return current->data; }
//        Iterator& operator++() {
//            current = current->next;
//            return *this;
//        }
//        bool operator!=(const Iterator& other) const {
//            return current != other.current;
//        }
//    };
//
//    Iterator begin() { return Iterator(front); }
//    Iterator end() { return Iterator(nullptr); }
//};
//
//// Пример использования программы
//int main() {
//    try {
//        Deque<Creature*> container;
//        while (true) {
//            int choice = correct("\n1. Add creature\n2. Remove creature\n3. Show creatures\n4. Exit\n", 1, 4);
//            if (choice == 1) {
//                int type = correct("Select creature to add:\n1. Lion\n2. Eagle\n3. Spider\n4. Human\n5. Griffon\n6. SpiderMan\n7. Assassin\n", 1, 7);
//                switch (type) {
//                    case 1: {
//                        container.push_back(new Lion("Savanna"));
//                        break;
//                    }
//                    case 2: {
//                        container.push_back(new Eagle("Mountain"));
//                        break;
//                    }
//                    case 3: {
//                        container.push_back(new Spider("Silk"));
//                        break;
//                    }
//                    case 4: {
//                        container.push_back(new Human("Doctor"));
//                        break;
//                    }
//                    case 5: {
//                        container.push_back(new Griffon("Sky"));
//                        break;
//                    }
//                    case 6: {
//                        container.push_back(new SpiderMan("Engineer"));
//                        break;
//                    }
//                    case 7: {
//                        container.push_back(new Assassin("Assassin"));
//                        break;
//                    }
//                    default:
//                        cout << "Invalid selection!" << endl;
//                        break;
//                }
//            } else if (choice == 2) {
//                container.display();
//                int index = correct("Enter index of creature to remove: ", 1, container.get_size()) - 1;
//                container.pop_front();
//            } else if (choice == 3) {
//                container.display();
//            } else if (choice == 4) {
//                break;
//            }
//        }
//    } catch (const exception& e) {
//        cout << "Error: " << e.what() << endl;
//    }
//    return 0;
//}


/*
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Creature {
public:
    virtual string get_name() const = 0;
    virtual void make_sound() const = 0;
    virtual ~Creature() {}
};

class Animal : public virtual Creature {
protected:
    string habitat;
    int age;
public:
    Animal(const string& habitat, int age = 0) : habitat(habitat), age(age) {}
    Animal() : habitat("Unknown"), age(0) {}

    virtual string get_name() const override { return "Animal"; }
    virtual void make_sound() const override { cout << "Some animal sound" << endl; }
};

class Lion : public virtual Animal {
public:
    Lion(const string& habitat, int age = 0) : Animal(habitat, age) {}
    virtual string get_name() const override { return "Lion"; }
    virtual void make_sound() const override { cout << "Roar" << endl; }
};

class Eagle : public virtual Animal {
public:
    Eagle(const string& habitat, int age = 0) : Animal(habitat, age) {}
    virtual string get_name() const override { return "Eagle"; }
    virtual void make_sound() const override { cout << "Screech" << endl; }
};

class Assassin : public virtual Eagle, public virtual Animal {
public:
    Assassin(const string& profession, int age = 0) 
        : Eagle("Rooftops", age), Animal("Unknown", age) {}  // Явный вызов конструкторов базовых классов

    virtual string get_name() const override { return "Assassin"; }
    virtual void make_sound() const override { cout << "Silent assassin!" << endl; }
    void sneak_attack() const { cout << "Performing a sneak attack!" << endl; }
};

template <typename T>
class Deque {
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
    Deque() : front(nullptr), rear(nullptr), size(0) {}
    ~Deque() { while (!is_empty()) pop_front(); }

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

    bool is_empty() { return size == 0; }
    int get_size() { return size; }

    void display() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data->get_name() << endl;
            current = current->next;
        }
    }
};

int main() {
    Deque<Creature*> container;

    container.push_back(new Assassin("Assassin", 30));
    container.push_back(new Lion("Savanna"));
    container.push_back(new Eagle("Mountain"));

    container.display();
    return 0;
}   */

//Жалко удалять пока что:
// #include <iostream>
//#include <memory>
//#include <stdexcept>
//#include <string>
//#include <fstream>
//
//using namespace std;
//
//class InvalidInputException : public runtime_error {
//public:
//    InvalidInputException(const string& message) : runtime_error(message) {}
//};
//
//// Функция для получения корректного целого числа с проверкой диапазона
//int correct(const string& prompt, int min, int max) {
//    string input;
//    int num;
//    char* endptr;
//
//    while (true) {
//        try {
//            cout << prompt;
//            getline(cin, input);
//
//            // Если ввод пустой, возвращаем -1
//            if (input.empty()) {
//                return -1;
//            }
//
//            // Преобразуем строку в число
//            num = strtol(input.c_str(), &endptr, 10);
//
//            // Если введённое значение не является числом
//            if (*endptr != '\0') {
//                throw InvalidInputException("Это не число. Попробуйте еще раз.");
//            }
//
//            // Проверка на диапазон
//            if (num < min || num > max) {
//                throw InvalidInputException("Число должно быть в диапазоне от " + to_string(min) + " до " + to_string(max) + ". Попробуйте еще раз.");
//            }
//
//            // Если все проверки пройдены, возвращаем число
//            return num;
//
//        } catch (const InvalidInputException& e) {
//            cout << e.what() << endl;
//        } catch (const exception& e) {
//            // Поймать любые другие исключения
//            cout << "Произошла ошибка: " << e.what() << endl;
//        }
//    }
//}
//
//// 1. Основные классы и наследование
//class Creature {
//public:
//    virtual string get_name() const = 0;
//    virtual void make_sound() const = 0;
//    virtual ~Creature() {}
//};
//
//class Animal : public virtual Creature {
//protected:
//    string habitat;
//    int age;
//public:
//    // Конструктор с параметрами
//    Animal(const string& habitat, int age) : habitat(habitat), age(age) {}
//
//    // Конструктор по умолчанию
//    Animal() : habitat("Unknown"), age(0) {}
//
//    virtual string get_name() const override { return "Animal"; }
//    virtual void make_sound() const override { cout << "Some animal sound" << endl; }
//};
//
//class Lion : public virtual Animal {
//public:
//    Lion(const string& habitat, int age) : Animal(habitat, age) {}
//    virtual string get_name() const override { return "Lion"; }
//    virtual void make_sound() const override { cout << "Roar" << endl; }
//    void roar() const { cout << "Lion is roaring!" << endl; }
//};
//
//class Eagle : public virtual Animal {
//public:
//    // Конструктор с параметрами
//    Eagle(const string& habitat, int age) : Animal(habitat, age) {}
//
//    // Конструктор по умолчанию (если требуется)
//    Eagle() : Animal() {}
//
//    virtual string get_name() const override { return "Eagle"; }
//    virtual void make_sound() const override { cout << "Screech" << endl; }
//
//    void hunt() const { cout << "Eagle is hunting!" << endl; }
//};
//
//class Spider : public virtual Creature {
//protected:
//    string webType;
//    int legCount;
//public:
//    Spider(const string& webType, int legCount = 8) : webType(webType), legCount(legCount) {}
//    virtual string get_name() const override { return "Spider"; }
//    virtual void make_sound() const override { cout << "Hiss" << endl; }
//    void spinWeb() const { cout << "Spinning a " << webType << " web!" << endl; }
//    string get_web() { return webType; }
//    int get_leg() { return legCount; }
//};
//
//class Human : public virtual Creature {
//protected:
//    string profession;
//    int age;
//public:
//    Human(const string& profession, int age) : profession(profession), age(age) {}
//    virtual string get_name() const override { return "Human"; }
//    virtual void make_sound() const override { cout << "Hello, I am human!" << endl; }
//    void talk() const { cout << "Talking like a human!" << endl; }
//    int get_age() { return age; }
//};
//
//// Новые классы
//class Griffon : public virtual Eagle, public virtual Lion {
//public:
//    Griffon(const string& habitat, int age) : Eagle(habitat, age), Lion(habitat, age) {}
//    virtual string get_name() const override { return "Griffon"; }
//    virtual void make_sound() const override { cout << "Griffon roar and screech!" << endl; }
//    void fly_and_roar() const {
//        hunt();
//        roar();
//    }
//};
//
//class SpiderMan : public virtual Spider, public virtual Human {
//public:
//    SpiderMan(const string& profession, int age) : Human(profession, age), Spider("Silk") {}
//    virtual string get_name() const override { return "SpiderMan"; }
//    virtual void make_sound() const override { cout << "I am SpiderMan!" << endl; }
//    void swing() const { cout << "Swinging from web!" << endl; }
//};
//
//class Assassin : public virtual Eagle, public virtual Human {
//public:
//    Assassin(const string& profession, int age) : Human(profession, age), Eagle("Rooftops", 2) {}
//    virtual string get_name() const override { return "Assassin"; }
//    virtual void make_sound() const override { cout << "Silent assassin!" << endl; }
//    void sneak_attack() const { cout << "Performing a sneak attack!" << endl; }
//};
//
//// 3. Шаблонный класс контейнера
//template <typename T>
//class Deque {
//private:
//    struct Node {
//        T data;
//        Node* prev;
//        Node* next;
//        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
//    };
//    Node* front;
//    Node* rear;
//    int size;
//
//public:
//    Deque() : front(nullptr), rear(nullptr), size(0) {}
//    ~Deque() { while (!is_empty()) pop_front(); }
//
//    void push_back(T value) {
//        Node* new_node = new Node(value);
//        if (is_empty()) {
//            front = rear = new_node;
//        } else {
//            new_node->prev = rear;
//            rear->next = new_node;
//            rear = new_node;
//        }
//        size++;
//    }
//
//    void pop_front() {
//        if (is_empty()) throw runtime_error("Deque is empty");
//        Node* temp = front;
//        front = front->next;
//        if (front == nullptr) rear = nullptr;
//        else front->prev = nullptr;
//        delete temp;
//        size--;
//    }
//
//    void pop_at(int index) {
//        if (index < 0 || index >= size) throw runtime_error("Invalid index");
//        Node* current = front;
//        for (int i = 0; i < index; ++i) {
//            current = current->next;
//        }
//        if (current->prev) current->prev->next = current->next;
//        if (current->next) current->next->prev = current->prev;
//        if (current == front) front = current->next;
//        if (current == rear) rear = current->prev;
//        delete current;
//        size--;
//    }
//
//    bool is_empty() { return size == 0; }
//    int get_size() { return size; }
//
//    void display() {
//        if (is_empty()) {
//            cout << "Deque is empty!" << endl;
//            return;
//        }
//        Node* current = front;
//        while (current != nullptr) {
//            cout << current->data->get_name() << " ";
//            current = current->next;
//        }
//        cout << endl;
//    }
//};
//
//int main() {
//    try {
//        Deque<Creature*> container;
//        while (true) {
//            int choice = correct("\n1. Add creature\n2. Remove creature\n3. Show creatures\n4. Exit\n", 1, 4);
//            if (choice == 1) {
//                int type = correct("Select creature to add:\n1. Lion\n2. Eagle\n3. Spider\n4. Human\n5. Griffon\n6. SpiderMan\n7. Assassin\n", 1, 7);
//                switch (type) {
//                    case 1: {
//                        container.push_back(new Lion("Savanna", 20));
//                        break;
//                    }
//                    case 2: {
//                        container.push_back(new Eagle("Mountain", 21));
//                        break;
//                    }
//                    case 3: {
//                        container.push_back(new Spider("Silk", 22));
//                        break;
//                    }
//                    case 4: {
//                        container.push_back(new Human("Doctor", 23));
//                        break;
//                    }
//                    case 5: {
//                        container.push_back(new Griffon("Sky", 24));
//                        break;
//                    }
//                    case 6: {
//                        container.push_back(new SpiderMan("Engineer", 25));
//                        break;
//                    }
//                    case 7: {
//                        container.push_back(new Assassin("Assassin", 26));
//                        break;
//                    }
//                    default:
//                        cout << "Invalid selection!" << endl;
//                        break;
//                }
//            } else if (choice == 2) {
//                container.display();
//                int index = correct("Enter index of creature to remove: ", 1, container.get_size()) - 1;
//                container.pop_at(index);
//            } else if (choice == 3) {
//                container.display();
//            } else if (choice == 4) {
//                break;
//            }
//        }
//    } catch (const exception& e) {
//        cout << "Error: " << e.what() << endl;
//    }
//    return 0;
//}


/*
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <cctype>

using namespace std;

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

// Функция для безопасного ввода числа в диапазоне
int correct(const string& prompt, int min, int max) {
    string input;
    int num;
    char* endptr;

    while (true) {
        try {
            cout << prompt;
            getline(cin, input);

            if (input.empty()) {
                return -1;
            }

            num = strtol(input.c_str(), &endptr, 10);

            if (*endptr != '\0') {
                throw Invalid_input_exception("Это не число. Попробуйте еще раз.");
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

// Функция для безопасного ввода строки с проверкой имени
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

// Функция для получения и проверки имени
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

// Проверка возраста
void check_age(int age, int min_age) {
    if (age < min_age) {
        throw Invalid_age_exception("Возраст должен быть не меньше " + to_string(min_age) + " лет!");
    }
}

// Базовый класс Creature
class Creature {
public:
    virtual string get_name() const = 0;
    virtual void make_sound() const = 0;
    virtual ~Creature() {}
};

// 1. Классы животных
class Animal : public virtual Creature {
protected:
    string habitat;
    int age;
public:
    Animal(const string& habitat, int age) : habitat(habitat), age(age) {}
    Animal() : habitat("Unknown"), age(0) {}

    virtual string get_name() const override { return "Animal"; }
    virtual void make_sound() const override { cout << "Some animal sound" << endl; }
};

class Lion : public virtual Animal {
public:
    Lion(const string& habitat, int age) : Animal(habitat, age) {}
    virtual string get_name() const override { return "Lion"; }
    virtual void make_sound() const override { cout << "Roar" << endl; }
    void roar() const { cout << "Lion is roaring!" << endl; }
};

class Eagle : public virtual Animal {
public:
    Eagle(const string& habitat, int age) : Animal(habitat, age) {}
    Eagle() : Animal() {}

    virtual string get_name() const override { return "Eagle"; }
    virtual void make_sound() const override { cout << "Screech" << endl; }

    void hunt() const { cout << "Eagle is hunting!" << endl; }
};

class Spider : public virtual Creature {
protected:
    string webType;
    int legCount;
public:
    Spider(const string& webType, int legCount = 8) : webType(webType), legCount(legCount) {}
    virtual string get_name() const override { return "Spider"; }
    virtual void make_sound() const override { cout << "Hiss" << endl; }
    void spinWeb() const { cout << "Spinning a " << webType << " web!" << endl; }
    string get_web() { return webType; }
    int get_leg() { return legCount; }
};

class Human : public virtual Creature {
protected:
    string profession;
    int age;
public:
    Human(const string& profession, int age) : profession(profession), age(age) {}
    virtual string get_name() const override { return "Human"; }
    virtual void make_sound() const override { cout << "Hello, I am human!" << endl; }
    void talk() const { cout << "Talking like a human!" << endl; }
    int get_age() { return age; }
};

class Griffon : public virtual Eagle, public virtual Lion {
public:
    Griffon(const string& habitat, int age) : Eagle(habitat, age), Lion(habitat, age) {}
    virtual string get_name() const override { return "Griffon"; }
    virtual void make_sound() const override { cout << "Griffon roar and screech!" << endl; }
    void fly_and_roar() const {
        hunt();
        roar();
    }
};

class SpiderMan : public virtual Spider, public virtual Human {
public:
    SpiderMan(const string& profession, int age) : Human(profession, age), Spider("Silk") {
        check_age(age, 15); // Проверка на возраст для SpiderMan (не менее 15 лет)
    }
    virtual string get_name() const override { return "SpiderMan"; }
    virtual void make_sound() const override { cout << "I am SpiderMan!" << endl; }
    void swing() const { cout << "Swinging from web!" << endl; }
};

class Assassin : public virtual Eagle, public virtual Human {
public:
    Assassin(const string& profession, int age) : Human(profession, age), Eagle("Rooftops", 2) {
        check_age(age, 18); // Проверка на возраст для Assassin (не менее 18 лет)
    }
    virtual string get_name() const override { return "Assassin"; }
    virtual void make_sound() const override { cout << "Silent assassin!" << endl; }
    void sneak_attack() const { cout << "Performing a sneak attack!" << endl; }
};

// Основной код с меню
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
    ~My_deque() { while (!is_empty()) pop_front(); }

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

    void display() const {
        if (is_empty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        Iterator it = begin();
        while (it != end()) {
            cout << (*it)->get_name() << ";";
            ++it;
        }
        cout << endl;
    }

    Iterator begin() const { return Iterator(front); }
    Iterator end() const { return Iterator(nullptr); }
};

int main() {
    try {
        My_deque<Creature*> container;
        while (true) {
            int choice = correct("\n1. Add creature\n2. Remove creature\n3. Show creatures\n4. Exit\n", 1, 4);
            if (choice == 1) {
                int type = correct("Select creature to add:\n1. Lion\n2. Eagle\n3. Spider\n4. Human\n5. Griffon\n6. SpiderMan\n7. Assassin\n", 1, 7);
                string name;
                int age;

                switch (type) {
                    case 1: {
                        name = validate_and_get_name("Enter name for Lion: ");
                        age = correct("Enter age for Lion: ", 1, 100);
                        container.push_back(new Lion(name, age));
                        break;
                    }
                    case 2: {
                        name = validate_and_get_name("Enter name for Eagle: ");
                        age = correct("Enter age for Eagle: ", 1, 100);
                        container.push_back(new Eagle(name, age));
                        break;
                    }
                    case 3: {
                        name = validate_and_get_name("Enter name for Spider: ");
                        age = correct("Enter age for Spider: ", 1, 100);
                        container.push_back(new Spider(name, age));
                        break;
                    }
                    case 4: {
                        name = validate_and_get_name("Enter name for Human: ");
                        age = correct("Enter age for Human: ", 1, 100);
                        container.push_back(new Human(name, age));
                        break;
                    }
                    case 5: {
                        name = validate_and_get_name("Enter name for Griffon: ");
                        age = correct("Enter age for Griffon: ", 1, 100);
                        container.push_back(new Griffon(name, age));
                        break;
                    }
                    case 6: {
                        name = validate_and_get_name("Enter name for SpiderMan: ");
                        age = correct("Enter age for SpiderMan: ", 1, 100);
                        container.push_back(new SpiderMan(name, age));
                        break;
                    }
                    case 7: {
                        name = validate_and_get_name("Enter name for Assassin: ");
                        age = correct("Enter age for Assassin: ", 1, 100);
                        container.push_back(new Assassin(name, age));
                        break;
                    }
                    default:
                        cout << "Invalid selection!" << endl;
                        break;
                }
            } else if (choice == 2) {
                container.display();
                int index = correct("Enter index of creature to remove: ", 1, container.get_size()) - 1;
                container.pop_front();
            } else if (choice == 3) {
                container.display();
            } else if (choice == 4) {
                break;
            }
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
*/

