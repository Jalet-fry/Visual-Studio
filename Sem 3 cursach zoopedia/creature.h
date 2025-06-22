#pragma once
#include "utils.h"
using namespace std;
class Creature {
public:
    virtual string get_name() const = 0;
    virtual string get_string() const = 0;
    virtual int get_int() const = 0;
    virtual void make_sound() const = 0;
    virtual void change_me() = 0;
    virtual void show_me() const = 0;
    virtual void transfer_data(Creature& other) = 0;
    virtual Creature* clone() const = 0;
    virtual ~Creature() {}
};

class Animal : public virtual Creature {
protected:
    string habitat;
    int age;
public:
    Animal(const string habitat, int age);
    Animal();
    Animal(const Animal& other);

    virtual Creature* clone() const override;
    string get_name() const override;
    string get_string() const override;
    int get_int() const override;
    void make_sound() const override;
    void change_me() override;
    void change_habitat_or_age(int min, int max);
    void show_me() const override;

    string get_habitat() const;
    void set_habitat(const string& new_habitat);

    int get_age() const;
    void set_age(int new_age);

    void transfer_data(Creature& other) override;
};

class Lion : public virtual Animal {
public:
    Lion(const string& habitat, int age);
    Lion(const Lion& other);
    Lion();
    virtual Creature* clone() const override;
    
    string get_name() const override;
    string get_string() const override;
    int get_int() const override;
    void make_sound() const override;
    void change_me() override;
    void show_me() const override;

    void transfer_data(Creature& other) override;
};

class Eagle : public virtual Animal {
public:
    Eagle(const string habitat, int age);
    Eagle(const Eagle& other);
    Eagle();
    virtual Creature* clone() const override;

    string get_name() const override;
    string get_string() const override;
    int get_int() const override;
    void make_sound() const override;
    void change_me() override;
    void show_me() const override;
    void transfer_data(Creature& other) override;
};

class Spider : public virtual Creature {
protected:
    string web_type;
    int leg_count;
public:
    Spider(const string web_type, int leg_count);
    Spider(const Spider& other);
    Spider();
    virtual Creature* clone() const override;

    string get_name() const override;
    string get_string() const override;
    int get_int() const override;
    void make_sound() const override;
    void change_me() override;
    void show_me() const override;

    string get_web_type() const;
    void set_web_type(const string& new_web_type);

    int get_leg_count() const;
    void set_leg_count(int new_leg_count);

    void transfer_data(Creature& other) override;
};

class Human : public virtual Creature {
protected:
    string profession;
    int age;
public:
    Human(const string profession, int age);
    Human(const Human& other);
    Human();
    virtual Creature* clone() const override;

    string get_name() const override;
    string get_string() const override;
    int get_int() const override;
    void make_sound() const override;
    void changes_for_human(int min, int max);
    void change_age(int min, int max);
    void change_me() override;
    void show_me() const override;

    string get_profession() const;
    void set_profession(const string new_profession);

    int get_age() const;
    void set_age(int new_age);

    void transfer_data(Creature& other) override;
};

class Griffon : public virtual Eagle, public virtual Lion {
public:
    Griffon(const string habitat, int age);
    Griffon(const Griffon& other);
    virtual Creature* clone() const override;
    Griffon();
    Griffon(Lion* human, Eagle* eagle);

    string get_name() const override;
    string get_string() const override;
    int get_int() const override;
    void make_sound() const override;
    void change_me() override;
    void show_me() const override;

    void transfer_data(Creature& other) override;
};

class SpiderMan : public virtual Spider, public virtual Human {
public:
    SpiderMan(string profession, string web_type, int age);
    SpiderMan(const SpiderMan& other);
    SpiderMan();
    SpiderMan(Human* creature1, Spider* creature2);
    virtual Creature* clone() const override;

    string get_name() const override;
    string get_string() const override;
    int get_int() const override;
    void make_sound() const override;
    void change_me() override;
    void show_me() const override;

    void transfer_data(Creature& other) override;
};

class Assassin : public virtual Eagle, public virtual Human {
public:
    Assassin(const string profession, const string habitat, int age);
    Assassin(const Assassin& other);
    Assassin();
    Assassin(Human* creature1, Eagle* creature2);
    virtual Creature* clone() const override;

    string get_name() const override;
    string get_string() const override;
    int get_int() const override;
    void make_sound() const override;
    void change_me() override;
    void show_me() const override;

    void transfer_data(Creature& other) override;
};
