/*
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>
using namespace std;
class Ticket {
protected:
	string name;
	string departureDate;
	string passportData;
	string time;
	string ticketCategory;
	int numberOfSeats;
	float price;
public:
	Ticket() : numberOfSeats(0), price(0.0f) {}
	virtual ~Ticket() {}
	string GetName() const { return name; }
	string GetDepartureDate() const { return departureDate; }
	string GetTime() const { return time; }
	string GetPassportData() const { return passportData; }
	string GetTicketCategory() const { return ticketCategory; }
	int GetNumberOfSeats() const { return numberOfSeats; }
	float GetPrice() const { return price; }
	void SetName(const string& newName) { name = newName; }
	void SetDepartureDate(const string& newDepartureDate) { departureDate = newDepartureDate; }
	void SetTime(const string& newTime) { time = newTime; }
	void SetPassportData(const string& newPassportData) { passportData = newPassportData; }
	void SetTicketCategory(const string& newTicketCategory) { ticketCategory = newTicketCategory; }
	void SetNumberOfSeats(int newNumberOfSeats) { numberOfSeats = newNumberOfSeats; }
	void SetPrice(float newPrice) { price = newPrice; }
};
class AirTicket : public Ticket {
protected:
 string placeOfDeparture;
string destination;
public:
 AirTicket() {}
virtual ~AirTicket() {}
 string GetPlaceOfDeparture() const { return placeOfDeparture; }
 string GetDestination() const { return destination; }
 void SetPlaceOfDeparture(const string& newPlaceOfDeparture) { placeOfDeparture =
newPlaceOfDeparture; }
 void SetDestination(const string& newDestination) { destination = newDestination; }
};
class Economical : public AirTicket {
protected:
 bool hasMeal;
int maxBaggageWeight;
public:
 Economical() : hasMeal(false), maxBaggageWeight(0) {}
virtual ~Economical() {}
 bool GetHasMeal() const { return hasMeal; }
 int GetMaxBaggageWeight() const { return maxBaggageWeight; }
 void SetHasMeal(bool newHasMeal) { hasMeal = newHasMeal; }
 void SetMaxBaggageWeight(int newMaxBaggageWeight) { maxBaggageWeight = newMaxBaggageWeight; }
};
class Business : public AirTicket {
protected:
 string services;
public:
 Business() {}
 virtual ~Business() {}
 string GetServices() const { return services; }
 void SetServices(const string& newServices) { services = newServices; }
};
class BoughtTicket {
public:
	string name;
	string passportData;
	string date;
	string route;
	string time;
	string category;
	string meal;
	string maxBaggage;
	string services;
	int seatsAvailable;
	float price;
};
class AirLine {
private:
	vector<Economical> eco;
	vector<Business> bus;
	vector<BoughtTicket> boughtTickets;
	string airlineName;
public:
	AirLine(string airLineName) {
		this->airlineName = airLineName;
	}
	~AirLine() {}
	void AddTicket(const string& filename); void BuyTicket(const string& filenameBought);
	void DeleteTicket(const string& filename);
	void FindBoughts(const string& filenameBought);
	void ReturnTicket(const string& filenameBought);
	void DisplayAllFlights();
	void readFile(const string& filename);
};
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>
using namespace std;

class Ticket {
protected:
    string name;
    string departureDate;
    string passportData;
    string time;
    string ticketCategory;
    int numberOfSeats;
    float price;
public:
    Ticket() : numberOfSeats(0), price(0.0f) {}
    virtual ~Ticket() {}
    string GetName() const { return name; }
    string GetDepartureDate() const { return departureDate; }
    string GetTime() const { return time; }
    string GetPassportData() const { return passportData; }
    string GetTicketCategory() const { return ticketCategory; }
    int GetNumberOfSeats() const { return numberOfSeats; }
    float GetPrice() const { return price; }
    void SetName(const string& newName) { name = newName; }
    void SetDepartureDate(const string& newDepartureDate) { departureDate = newDepartureDate; }
    void SetTime(const string& newTime) { time = newTime; }
    void SetPassportData(const string& newPassportData) { passportData = newPassportData; }
    void SetTicketCategory(const string& newTicketCategory) { ticketCategory = newTicketCategory; }
    void SetNumberOfSeats(int newNumberOfSeats) { numberOfSeats = newNumberOfSeats; }
    void SetPrice(float newPrice) { price = newPrice; }
};

class AirTicket : public Ticket {
protected:
    string placeOfDeparture;
    string destination;
public:
    AirTicket() {}
    virtual ~AirTicket() {}
    string GetPlaceOfDeparture() const { return placeOfDeparture; }
    string GetDestination() const { return destination; }
    void SetPlaceOfDeparture(const string& newPlaceOfDeparture) { placeOfDeparture = newPlaceOfDeparture; }
    void SetDestination(const string& newDestination) { destination = newDestination; }
};

class Economical : public AirTicket {
protected:
    bool hasMeal;
    int maxBaggageWeight;
public:
    Economical() : hasMeal(false), maxBaggageWeight(0) {}
    virtual ~Economical() {}
    bool GetHasMeal() const { return hasMeal; }
    int GetMaxBaggageWeight() const { return maxBaggageWeight; }
    void SetHasMeal(bool newHasMeal) { hasMeal = newHasMeal; }
    void SetMaxBaggageWeight(int newMaxBaggageWeight) { maxBaggageWeight = newMaxBaggageWeight; }
};

class Business : public AirTicket {
protected:
    string services;
public:
    Business() {}
    virtual ~Business() {}
    string GetServices() const { return services; }
    void SetServices(const string& newServices) { services = newServices; }
};

class BoughtTicket {
public:
    string name;
    string passportData;
    string date;
    string route;
    string time;
    string category;
    string meal;
    string maxBaggage;
    string services;
    int seatsAvailable;
    float price;
};

class AirLine {
private:
    vector<Economical> eco;
    vector<Business> bus;
    vector<BoughtTicket> boughtTickets;
    string airlineName;
public:
    AirLine(string airLineName);
    ~AirLine() {}
    void AddTicket(const string& filename);
    void BuyTicket(const string& filenameBought);
    void DeleteTicket(const string& filename);
    void FindBoughts(const string& filenameBought);
    void ReturnTicket(const string& filenameBought);
    void DisplayAllFlights();
    void readFile(const string& filename);
};
