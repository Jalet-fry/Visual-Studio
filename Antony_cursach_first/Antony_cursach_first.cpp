//#include <iostream>
//#include <string>
//#include <vector>
//#include <memory>
//
//using namespace std; 
// 
//class Bus // объявление класса 
//{
//protected:
//    int seats, wheels;
//    char* route;
//public:
//
//    Bus(int numseats, int numwheels, char* nameroute)
//    {
//        route = nameroute;
//        seats = numseats;
//        wheels = numwheels;
//    }
//
//    Bus() {}
//    virtual ~Bus()
//    {
//        delete[] route;
//
//    }
//
//    virtual void print()
//    {
//        cout << "Маршрут: " << route << "   Сиденья: " << seats << "   Колёса: " << wheels << endl;
//    }
//};
// 
// 
//class CityBus : virtual public Bus
//{
//protected:
//    char* time_of_arrival_city;
//    char* time_of_depature_city;
//public:
//    CityBus(int numseats, int numwheels, char* nameroute, char* arrival, char* depature) : Bus(numseats, numwheels, nameroute)
//    {
//        time_of_arrival_city = arrival;
//        time_of_depature_city = depature;
//
//    }
//
//    CityBus()
//    {
//
//    }
//    ~CityBus()
//    {
//        delete[] time_of_arrival_city;
//        delete[] time_of_depature_city;
//
//    }
//
//    void print()
//    {
//        cout << "Маршрут: " << route << "   Сиденья: " << seats << "   Колёса: " << wheels << "  Время отправления: " << time_of_arrival_city << " Время прибытия: " << time_of_depature_city << endl;
//    }
//};
//  
//class RegionalBus : virtual public Bus
//{
//protected:
//    char* time_of_arrival_reg;
//    char* time_of_depature_reg;
//    char* stops;
//public:
//
//    RegionalBus(int numseats, int numwheels, char* nameroute, char* arrival, char* depature, char* stop_places) : Bus(numseats, numwheels, nameroute)
//    {
//        time_of_arrival_reg = arrival;
//        time_of_depature_reg = depature;
//        stops = stop_places;
//
//    }
//    RegionalBus()
//    {
//
//    }
//    ~RegionalBus()
//    {
//        delete[] time_of_arrival_reg;
//        delete[] time_of_depature_reg;
//        delete[] stops;
//
//    }
//
//    void print()
//    {
//        cout << "Маршрут: " << route << "   Сиденья: " << seats << "   Колёса: " << wheels << "  Время отправления: " << time_of_arrival_reg << "  Время прибытия: " << time_of_depature_reg << "   Остановки: " << stops << endl;
//    }
//};
// 
//class Mixed : public CityBus, public RegionalBus
//{
//    char* breakbus;
//public:
//    Mixed(int numseats, int numwheels, char* nameroute, char* arrival, char* depature, char* stop_places, char* breaks) : RegionalBus(numseats, numwheels, nameroute, arrival, depature, stop_places), CityBus(numseats, numwheels, nameroute, arrival, depature),
//        Bus(numseats, numwheels, nameroute)
//    {
//        breakbus = breaks;
//
//    }
//
//    Mixed()
//    {
//
//    }
//
//    ~Mixed()
//    {
//        delete[] breakbus;
//
//    }
//
//    void print()
//    {
//        cout << "Маршрут: " << route << "   Сиденья: " << seats << "   Колёса: " << wheels << "  Время отправления: " << time_of_arrival_reg << "  \nОсновной остановочный пункт: " << breakbus << "  Время прибытия: " << time_of_depature_reg << "   Остановки: " << stops << endl;
//    }
//};
// 
//Bus* enterBus()
//{
//    int seats, wheels;
//    char* route = new char[20];
//    cout << "Введите кол-во сидений: ";
//    cin >> seats;
//    cout << "Введите кол-во колёс: ";
//    cin >> wheels;
//    cout << "Введите маршрут: ";
//    rewind(stdin);
//    gets(route);
//    Bus* ptr = new Bus(seats, wheels, route);
//    return ptr;
//}
// 
// 
// 
//Bus* enterCityBus()
//{
//    int seats, wheels;
//    char* route = new char[20];
//    char* arrival = new char[20];
//    char* depature = new char[20];
//    cout << "Введите кол-во сидений: ";
//    cin >> seats;
//    cout << "Введите кол-во колёс: ";
//    cin >> wheels;
//    cout << "Введите маршрут: ";
//    rewind(stdin);
//    gets(route);
//    cout << "Введите время отправления: ";
//    rewind(stdin);
//    gets(arrival);
//    cout << "Введите время прибытия: ";
//    rewind(stdin);
//    gets(depature);
//    Bus* ptr = new CityBus(seats, wheels, route, arrival, depature);
//    return ptr;
//}
// 
//Bus* enterRegBus()
//{
//    int seats, wheels;
//    char* route = new char[20];
//    char* arrival = new char[20];
//    char* depature = new char[20];
//    char* stops = new char[20];
//    cout << "Введите кол-во сидений: ";
//    cin >> seats;
//    cout << "Введите кол-во колёс: ";
//    cin >> wheels;
//    cout << "Введите маршрут: ";
//    rewind(stdin);
//    gets(route);
//    cout << "Введите время отправления: ";
//    rewind(stdin);
//    gets(arrival);
//    cout << "Введите время прибытия: ";
//    rewind(stdin);
//    gets(depature);
//    cout << "Введите остановки: ";
//    rewind(stdin);
//    gets(stops);
//    Bus* ptr = new RegionalBus(seats, wheels, route, arrival, depature, stops);
//    return ptr;
//}
// 
//Bus* enterMix()
//{
//    int seats, wheels;
//    char* route = new char[20];
//    char* arrival = new char[20];
//    char* depature = new char[20];
//    char* stops = new char[20];
//    char* breakbus = new char[20];
//    cout << "Введите кол-во сидений: ";
//    cin >> seats;
//    cout << "Введите кол-во колёс: ";
//    cin >> wheels;
//    cout << "Введите маршрут: ";
//    rewind(stdin);
//    gets(route);
//    cout << "Введите время отправления: ";
//    rewind(stdin);
//    gets(arrival);
//    cout << "Введите время прибытия: ";
//    rewind(stdin);
//    gets(depature);
//    cout << "Введите остановки: ";
//    rewind(stdin);
//    gets(stops);
//    cout << "Введите пункт перекура: ";
//    rewind(stdin);
//    gets(breakbus);
//    Bus* ptr = new Mixed(seats, wheels, route, arrival, depature, stops, breakbus);
//    return ptr;
//}
// 
// 
//int main()
//{
//    setlocale(LC_ALL, "Rus");
//    int buses;
//    cout << "Введите кол-во автобусов: ";
//    cin >> buses;
//    Bus* ptr[buses];
//    cout << "Есть 4 типа автобусов: просто автобус(1), городской автобус(2), региональный (3) и совмещённый(4)" << endl;
//    for (int i = 0; i < buses; i++)
//    {
//        int type;
//        cout << "Введите тип автобуса №" << i + 1 << ": ";
//        do
//        {
//            cin >> type;
//            if (type < 0 || type > 4) cout << "Wrong num!" << endl;
//        } while (type < 0 || type > 4);
//
//
//        switch (type)
//        {
//
//        case 1:
//            ptr[i] = enterBus();
//            break;
//        case 2:
//            ptr[i] = enterCityBus();
//            break;
//        case 3:
//            ptr[i] = enterRegBus();
//            break;
//        case 4:
//            ptr[i] = enterMix();
//            break;
//        }
//
//    }
//
//    for (int i = 0; i < buses; i++)
//    {
//        cout << "Autobus " << i + 1 << endl;
//        ptr[i]->print();
//    }
//
//
//
//    for (int i = 0; i < buses; i++)
//    {
//        delete ptr[i];
//    }
//
//    return 0;
//}

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Bus {
protected:
    int seats, wheels;
    string route;
public:
    Bus(int numseats, int numwheels, const string& nameroute)
        : seats(numseats), wheels(numwheels), route(nameroute) {}

    Bus() {}

    virtual ~Bus() {}

    virtual void print() {
        cout << "Маршрут: " << route << "   Сиденья: " << seats << "   Колёса: " << wheels << endl;
    }
};

class CityBus : public Bus {
protected:
    string time_of_arrival_city;
    string time_of_depature_city;
public:
    CityBus(int numseats, int numwheels, const string& nameroute, const string& arrival, const string& depature)
        : Bus(numseats, numwheels, nameroute), time_of_arrival_city(arrival), time_of_depature_city(depature) {}

    CityBus() {}

    void print() override {
        cout << "Маршрут: " << route << "   Сиденья: " << seats << "   Колёса: " << wheels 
             << "  Время отправления: " << time_of_arrival_city << " Время прибытия: " << time_of_depature_city << endl;
    }
};

class RegionalBus : public Bus {
protected:
    string time_of_arrival_reg;
    string time_of_depature_reg;
    string stops;
public:
    RegionalBus(int numseats, int numwheels, const string& nameroute, const string& arrival, const string& depature, const string& stop_places)
        : Bus(numseats, numwheels, nameroute), time_of_arrival_reg(arrival), time_of_depature_reg(depature), stops(stop_places) {}

    RegionalBus() {}

    void print() override {
        cout << "Маршрут: " << route << "   Сиденья: " << seats << "   Колёса: " << wheels 
             << "  Время отправления: " << time_of_arrival_reg << "  Время прибытия: " << time_of_depature_reg 
             << "   Остановки: " << stops << endl;
    }
};

class Mixed : public CityBus, public RegionalBus {
    string breakbus;
public:
    Mixed(int numseats, int numwheels, const string& nameroute, const string& arrival, const string& depature, const string& stop_places, const string& breaks)
        : CityBus(numseats, numwheels, nameroute, arrival, depature), RegionalBus(numseats, numwheels, nameroute, arrival, depature, stop_places), breakbus(breaks) {}

    Mixed() {}

    void print() override {
        cout << "Маршрут: " << route << "   Сиденья: " << seats << "   Колёса: " << wheels 
             << "  Время отправления: " << time_of_arrival_reg << "  \nОсновной остановочный пункт: " 
             << breakbus << "  Время прибытия: " << time_of_depature_reg << "   Остановки: " << stops << endl;
    }
};

Bus* enterBus() {
    int seats, wheels;
    string route;
    cout << "Введите кол-во сидений: ";
    cin >> seats;
    cout << "Введите кол-во колёс: ";
    cin >> wheels;
    cout << "Введите маршрут: ";
    cin.ignore(); // Ignore the newline left in the input buffer
    getline(cin, route);
    return new Bus(seats, wheels, route);
}

Bus* enterCityBus() {
    int seats, wheels;
    string route, arrival, depature;
    cout << "Введите кол-во сидений: ";
    cin >> seats;
    cout << "Введите кол-во колёс: ";
    cin >> wheels;
    cout << "Введите маршрут: ";
    cin.ignore();
    getline(cin, route);
    cout << "Введите время отправления: ";
    getline(cin, arrival);
    cout << "Введите время прибытия: ";
    getline(cin, depature);
    return new CityBus(seats, wheels, route, arrival, depature);
}

Bus* enterRegBus() {
    int seats, wheels;
    string route, arrival, depature, stops;
    cout << "Введите кол-во сидений: ";
    cin >> seats;
    cout << "Введите кол-во колёс: ";
    cin >> wheels;
    cout << "Введите маршрут: ";
    cin.ignore();
    getline(cin, route);
    cout << "Введите время отправления: ";
    getline(cin, arrival);
    cout << "Введите время прибытия: ";
    getline(cin, depature);
    cout << "Введите остановки: ";
    getline(cin, stops);
    return new RegionalBus(seats, wheels, route, arrival, depature, stops);
}

Bus* enterMix() {
    int seats, wheels;
    string route, arrival, depature, stops, breakbus;
    cout << "Введите кол-во сидений: ";
    cin >> seats;
    cout << "Введите кол-во колёс: ";
    cin >> wheels;
    cout << "Введите маршрут: ";
    cin.ignore();
    getline(cin, route);
    cout << "Введите время отправления: ";
    getline(cin, arrival);
    cout << "Введите время прибытия: ";
    getline(cin, depature);
    cout << "Введите остановки: ";
    getline(cin, stops);
    cout << "Введите пункт перекура: ";
    getline(cin, breakbus);
    return new Mixed(seats, wheels, route, arrival, depature, stops, breakbus);
}

int main() {
    setlocale(LC_ALL, "Rus");
    int buses;
    cout << "Введите кол-во автобусов: ";
    cin >> buses;
    vector<Bus*> ptr(buses);
    cout << "Есть 4 типа автобусов: просто автобус(1), городской автобус(2), региональный (3) и совмещённый(4)" << endl;
    for (int i = 0; i < buses; i++) {
        int type;
        cout << "Введите тип автобуса №" << i + 1 << ": ";
        do {
            cin >> type;
            if (type < 1 || type > 4) cout << "Wrong num!" << endl;
        } while (type < 1 || type > 4);

        switch (type) {
            case 1:
                ptr[i] = enterBus();
                break;
            case 2:
                ptr[i] = enterCityBus();
                break;
            case 3:
                ptr[i] = enterRegBus();
                break;
            case 4:
                ptr[i] = enterMix();
                break;
        }
    }

    for (int i = 0; i < buses; i++) {
        cout << "Автобус " << i + 1 << endl;
        ptr[i]->print();
    }

    for (int i = 0; i < buses; i++) {
        delete ptr[i];
    }

    return 0;
}

