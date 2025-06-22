#include <iostream>
#include <cstring>
#include <string>

class Creature {
public:
    virtual std::string getName() const = 0; // Чисто виртуальная функция для получения имени
    virtual void makeSound() const = 0; // Чисто виртуальная функция для звука
    virtual ~Creature() {}
};

class Animal : public Creature {
public:
    std::string habitat; // Новое поле: среда обитания

    Animal(const std::string& habitat) : habitat(habitat) {}

    std::string getName() const override {
        return "Animal";
    }

    void makeSound() const override {
        std::cout << "Some animal sound" << std::endl;
    }
};

class Bird : public Animal {
public:
    Bird(const std::string& habitat) : Animal(habitat) {}

    std::string getName() const override {
        return "Bird";
    }

    void makeSound() const override {
        std::cout << "Chirp" << std::endl;
    }
};

class Mammal : public Animal {
public:
    Mammal(const std::string& habitat) : Animal(habitat) {}

    std::string getName() const override {
        return "Mammal";
    }

    void makeSound() const override {
        std::cout << "Roar" << std::endl;
    }
};

class Eagle : public Bird {
public:
    Eagle(const std::string& habitat) : Bird(habitat) {}

    std::string getName() const override {
        return "Eagle";
    }

    void makeSound() const override {
        std::cout << "Screech" << std::endl;
    }
};

class Lion : public Mammal {
public:
    int prideSize; // Новое поле: размер прайда

    Lion(const std::string& habitat, int prideSize) : Mammal(habitat), prideSize(prideSize) {}

    std::string getName() const override {
        return "Lion";
    }

    void makeSound() const override {
        std::cout << "Roar" << std::endl;
    }
};

class Griffon : public Creature {
public:
    Lion lion;   // Экземпляр класса Lion
    Eagle eagle; // Экземпляр класса Eagle
    std::string wingSpan; // Новое поле: размах крыльев

    Griffon(const Lion& lion, const Eagle& eagle, const std::string& wingSpan)
        : lion(lion), eagle(eagle), wingSpan(wingSpan) {}

    std::string getName() const override {
        return "Griffon (Eagle + Lion)";
    }

    void makeSound() const override {
        std::cout << "Griffon roar-screech" << std::endl;
    }
};

class Spider : public Creature {
public:
    std::string webType; // Новое поле: тип паутины

    Spider(const std::string& webType) : webType(webType) {}

    std::string getName() const override {
        return "Spider";
    }

    void makeSound() const override {
        std::cout << "Hiss" << std::endl;
    }
};

class Human : public Creature {
public:
    std::string profession; // Новое поле: профессия

    Human(const std::string& profession) : profession(profession) {}

    std::string getName() const override {
        return "Human";
    }

    void makeSound() const override {
        std::cout << "Speak" << std::endl;
    }
};

class Assassin : public Creature {
public:
    Human human; // Экземпляр класса Human
    Eagle eagle; // Экземпляр класса Eagle
    std::string hiddenBlade; // Новое поле: скрытый клинок

    Assassin(const Human& human, const Eagle& eagle, const std::string& hiddenBlade)
        : human(human), eagle(eagle), hiddenBlade(hiddenBlade) {}

    std::string getName() const override {
        return "Assassin (Human + Eagle)";
    }

    void makeSound() const override {
        std::cout << "Silent as the night!" << std::endl;
    }

    void showHiddenBlade() const {
        std::cout << "Hidden Blade: " << hiddenBlade << std::endl;
    }
};

class SpiderMan : public Creature {
public:
    Spider spider; // Экземпляр класса Spider
    Human human;   // Экземпляр класса Human
    char* uchenie;

    SpiderMan(const char* uchenie)
        : spider("Silk"), human("Superhero") {
        this->uchenie = new char[strlen(uchenie) + 1];
        strcpy(this->uchenie, uchenie);
    }

    ~SpiderMan() {
        delete[] uchenie;
    }

    std::string getName() const override {
        return "Spider-Man (Spider + Human)";
    }

    void makeSound() const override {
        std::cout << "With great power comes great responsibility!" << std::endl;
    }

    void showUchenie() const {
        std::cout << "Uchenie: " << uchenie << std::endl;
    }
};

int main() {
    // Создание объектов
    Lion lion1("Savanna", 10);
    Eagle eagle1("Mountain");
    Griffon griffon1(lion1, eagle1, "Large wingspan");

    Spider spider1("Orb-weaver");
    Spider spider2("Tangle-web");
    Human human1("Scientist");
    Human human2("Artist");

    Assassin assassin1(human1, eagle1, "Assassin's Blade");
    Assassin assassin2(human2, eagle1, "Hidden Dagger");

    SpiderMan spiderMan1("Наука и ответственность");
    SpiderMan spiderMan2("Сила и мудрость");

    // Массив для хранения объектов разных типов
    Creature* creatures[] = {
        &lion1,&eagle1,
        &griffon1,
        &spider1, &spider2,
        &human1, &human2,
        &assassin1, &assassin2,
        &spiderMan1, &spiderMan2
    };

    // Вывод информации о существах
    for (Creature* creature : creatures) {
        std::cout << creature->getName() << ": ";
        creature->makeSound();
    }

    // Вывод информации о SpiderMan и Assassin
    spiderMan1.showUchenie();
    spiderMan2.showUchenie();
    assassin1.showHiddenBlade();
    assassin2.showHiddenBlade();

    return 0;
}

