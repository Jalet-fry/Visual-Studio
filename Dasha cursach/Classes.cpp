/*
#include "Classes.h"
void AirLine::AddTicket(const string& filename) {
	ofstream file;
	file.open(filename, ios::app);
	if (file.is_open()) {
		string newDeparture;
		string newDestination;
		string newDate;
		string newTime;
		string newTimeStart;
		string newTimeEnd;
		string newCategory;
		bool newMeal;
		string newMaxBaggage;
		string newServices;
		int newSeatsAvailable;
		float newPrice;
		Economical newTicketEc;
		Business newTicketBus;
		cout << "Enter departure city: ";
		cin >> newDeparture;
		cout << "Enter destination city: ";
		cin >> newDestination;
		cout << "Enter date: ";
		cin >> newDate;
		cout << "Enter time: ";
		cin >> newTimeStart >> newTimeEnd;
		newTime = newTimeStart + " - " + newTimeEnd;
		cout << "Enter category: ";
		cin >> newCategory;
		cout << "Enter the number of seats: ";
		cin >> newSeatsAvailable;
		cout << "Enter price: ";
		cin >> newPrice;
		if (newCategory == "Economical") {
			string mealInput;
			if (newCategory == "Economical") {
				string mealInput;
				cout << "Enter food availability: ";
				cin >> mealInput;
				newMeal = (mealInput == "Yes");
				cout << "Enter the maximum baggage value: ";
				cin >> newMaxBaggage;
				newTicketEc.SetPlaceOfDeparture(newDeparture);
				newTicketEc.SetDestination(newDestination);
				newTicketEc.SetDepartureDate(newDate);
				newTicketEc.SetTime(newTime);
				newTicketEc.SetTicketCategory(newCategory);
				newTicketEc.SetNumberOfSeats(newSeatsAvailable);
				newTicketEc.SetPrice(newPrice);
				newTicketEc.SetHasMeal(newMeal);
				newTicketEc.SetMaxBaggageWeight(stoi(newMaxBaggage));
				eco.push_back(newTicketEc);
			}
			else {
				cout << "Enter availability of additional services: ";
				cin.ignore();
				getline(cin, newServices);
				newTicketBus.SetPlaceOfDeparture(newDeparture);
				newTicketBus.SetDestination(newDestination);
				newTicketBus.SetDepartureDate(newDate);
				newTicketBus.SetTime(newTime);
				newTicketBus.SetTicketCategory(newCategory);
				newTicketBus.SetNumberOfSeats(newSeatsAvailable);
				newTicketBus.SetPrice(newPrice);
				newTicketBus.SetServices(newServices);
				bus.push_back(newTicketBus);
			}
			if (newCategory == "Economical") {
				file << endl << endl << newTicketEc.GetDepartureDate() << " " <<
					newTicketEc.GetPlaceOfDeparture() << "-" << newTicketEc.GetDestination() << ": " <<
					newTicketEc.GetTime() << "\n"
					<< " Category: Economical, Seats Available: " << newTicketEc.GetNumberOfSeats()
					<< ", Price: " << newTicketEc.GetPrice() << ", Meal: " << (newTicketEc.GetHasMeal() ? "Yes" :
						"No") << ", Max Baggage: " << newTicketEc.GetMaxBaggageWeight() << "kg";
				file.close();
				cout << "Ticket successfully purchased and recorded in file!\n";
			}
			else {
				file << endl << endl << newTicketBus.GetDepartureDate() << " " <<
					newTicketBus.GetPlaceOfDeparture() << "-" << newTicketBus.GetDestination() << ": " <<
					newTicketBus.GetTime() << "\n"
					<< " Category: Business, Seats Available: " << newTicketBus.GetNumberOfSeats()
					<< ", Price: " << newTicketBus.GetPrice() << ", Services: " << newTicketBus.GetServices();
				file.close();
				cout << "Ticket successfully purchased and recorded in file!\n";
			}
		}
		else {
			cerr << "Unable to open file for writing.\n";
		}
	}
	void AirLine::BuyTicket(const string & filenameBought) {
		string departurePlace;
		string destinationPlace;
		vector<Economical> foundEco;
		vector<Business> foundBus;
	a:
		cout << "Enter departure place: ";
		cin >> departurePlace;
		cout << "Enter destination place: ";
		cin >> destinationPlace;
		int i = 0, number = 0, numeco = 0;
		while (i < eco.size()) {
			if (eco[i].GetPlaceOfDeparture() == departurePlace && eco[i].GetDestination() ==
				destinationPlace)
			{
				number++;
				cout << "Economical ticket N" << number << ": "
					<< "From: " << eco[i].GetPlaceOfDeparture()
					<< ", To: " << eco[i].GetDestination()
					<< ", Date: " << eco[i].GetDepartureDate()
					cout << "Ticket successfully purchased and recorded in file!\n";
			}
			else {
				file << endl << endl << newTicketBus.GetDepartureDate() << " " <<
					newTicketBus.GetPlaceOfDeparture() << "-" << newTicketBus.GetDestination() << ": " <<
					newTicketBus.GetTime() << "\n"
					<< " Category: Business, Seats Available: " <<
					newTicketBus.GetNumberOfSeats() << ", Price: " << newTicketBus.GetPrice() << ", Services: " <<
					newTicketBus.GetServices();
				file.close();
				cout << "Ticket successfully purchased and recorded in file!\n";
			}
		}
	else {
		cerr << "Unable to open file for writing.\n";
	}
	}
	void AirLine::BuyTicket(const string & filenameBought) {
		string departurePlace;
		string destinationPlace;
		vector<Economical> foundEco;
		vector<Business> foundBus;
	a:
		cout << "Enter departure place: ";
		cin >> departurePlace;
		cout << "Enter destination place: ";
		cin >> destinationPlace;
		int i = 0, number = 0, numeco = 0;
		while (i < eco.size()) {
			if (eco[i].GetPlaceOfDeparture() == departurePlace && eco[i].GetDestination() ==
				destinationPlace)
			{
				number++;
				cout << "Economical ticket N" << number << ": "
					<< "From: " << eco[i].GetPlaceOfDeparture()
					<< ", To: " << eco[i].GetDestination()
					<< ", Date: " << eco[i].GetDepartureDate()
					<< ", Price: " << eco[i].GetPrice()
					<< ", Seats Available: " << eco[i].GetNumberOfSeats()
					<< ", Meal: " << (eco[i].GetHasMeal() ? "Yes" : "No")
					<< ", Max Baggage: " << eco[i].GetMaxBaggageWeight() << "kg\n";
				foundEco.push_back(eco[i]);
			}
			i++;
		}
		i = 0;
		numeco = number;
		while (i < bus.size()) {
			if (bus[i].GetPlaceOfDeparture() == departurePlace && bus[i].GetDestination() ==
				destinationPlace)
			{
				number++;
				cout << "Business ticket N" << number << ": "
					<< "From: " << bus[i].GetPlaceOfDeparture()
					<< ", To: " << bus[i].GetDestination()
					<< ", Date: " << bus[i].GetDepartureDate()
					<< ", Price: " << bus[i].GetPrice()
					<< ", Seats Available: " << bus[i].GetNumberOfSeats()
					<< ", Services: " << bus[i].GetServices() << "\n";
				foundBus.push_back(bus[i]);
			}
			i++;
		}
		if (number == 0) {
			cout << "Nothing found:(\n";
			cout << "Please try again!\n";
			goto a;
		}
		int choiсe = 0, choiseBuff = 0, category = 0;
		cout << "Enter number of ticket that you want: ";
		cin >> choiсe;
		if (choiсe <= numeco) {
			cout << "You took economical, ticket N" << choiсe << ": "
				<< "From: " << foundEco[choiсe - 1].GetPlaceOfDeparture()
				<< ", To: " << foundEco[choiсe - 1].GetDestination()
				<< ", Date: " << foundEco[choiсe - 1].GetDepartureDate()
				<< ", Price: " << foundEco[choiсe - 1].GetPrice()
				<< ", Seats Available: " << foundEco[choiсe - 1].GetNumberOfSeats()
				<< ", Meal: " << (foundEco[choiсe - 1].GetHasMeal() ? "Yes" : "No")
				<< ", Max Baggage: " << foundEco[choiсe - 1].GetMaxBaggageWeight() << "kg\n";
		}
		else {
			category = 1;
			choiseBuff = choiсe;
			choiсe = choiсe - numeco - 1;
			cout << "You took business, ticket N" << choiseBuff << ": "
				<< "From: " << foundBus[choiсe].GetPlaceOfDeparture()
				<< ", To: " << foundBus[choiсe].GetDestination()
				<< ", Date: " << foundBus[choiсe].GetDepartureDate()
				<< ", Price: " << foundBus[choiсe].GetPrice()
				<< ", Seats Available: " << foundBus[choiсe].GetNumberOfSeats()
				<< ", Services: " << foundBus[choiсe].GetServices() << "\n";
			choiсe = choiseBuff;
		}
		string name, familiya, otchestvo;
		string passportDetails;
		cout << "Enter your full name: ";
		cin >> name >> familiya >> otchestvo;
		cout << endl << "Enter your passport details: ";
		cin >> passportDetails;
		BoughtTicket boughtTicket;
		if (category == 0) {
			boughtTicket.name = name + " " + familiya + " " + otchestvo;
			boughtTicket.passportData = passportDetails;
			boughtTicket.route = foundEco[choiсe - 1].GetPlaceOfDeparture() + " - " +
				foundEco[choiсe - 1].GetDestination();
			boughtTicket.date = foundEco[choiсe - 1].GetDepartureDate();
			boughtTicket.price = foundEco[choiсe - 1].GetPrice();
			boughtTicket.seatsAvailable = foundEco[choiсe - 1].GetNumberOfSeats();
			boughtTicket.category = "Economical";
			boughtTicket.meal = (foundEco[choiсe - 1].GetHasMeal() ? "Yes" : "No");
			boughtTicket.maxBaggage = to_string(foundEco[choiсe - 1].GetMaxBaggageWeight()) +
				"kg";
		}
		else {
			boughtTicket.name = name + " " + familiya + " " + otchestvo;
			boughtTicket.passportData = passportDetails;
			boughtTicket.route = foundBus[choiсe - numeco - 1].GetPlaceOfDeparture() + " - " +
				foundBus[choiсe - numeco - 1].GetDestination();
			boughtTicket.date = foundBus[choiсe - numeco - 1].GetDepartureDate();
			boughtTicket.price = foundBus[choiсe - numeco - 1].GetPrice();
			boughtTicket.seatsAvailable = foundBus[choiсe - numeco - 1].GetNumberOfSeats();
			boughtTicket.category = "Business";
			boughtTicket.services = foundBus[choiсe - numeco - 1].GetServices();
		}
		// Добавление билета в вектор boughtTickets
		boughtTickets.push_back(boughtTicket);
		ofstream file;
		file.open(filenameBought, ios::app);
		if (file.is_open()) {
			file << "Passenger Name: " << boughtTicket.name << "\n"
				<< "Passport Data: " << boughtTicket.passportData << "\n"
				<< "Ticket Type: " << boughtTicket.category << "\n"
				<< "From: " << boughtTicket.route << "\n"
				<< "Date: " << boughtTicket.date << "\n"
				<< "Price: " << boughtTicket.price << "\n"
				<< "Seats Available: " << boughtTicket.seatsAvailable << "\n"
				<< "Meal: " << boughtTicket.meal << "\n"
				<< "Max Baggage: " << boughtTicket.maxBaggage << "\n"
				<< "Services: " << boughtTicket.services << "\n"
				<< "-----------------------------------\n";
			file.close();
			cout << "Ticket successfully purchased and recorded in file!\n";
		}
		else {
			cerr << "Unable to open file for writing.\n";
		}
	}
	void AirLine::DeleteTicket(const string & filename) {
		string departureCity, destinationCity, date, startTime, endTime;
		cout << "Enter departure city: ";
		cin >> departureCity;
		cout << "Enter destination city: ";
		cin >> destinationCity;
		cout << "Enter date (DD.MM.YYYY): ";
		cin >> date;
		cout << "Enter start time (HH:MM): ";
		cin >> startTime;
		cout << "Enter end time (HH:MM): ";
		cin >> endTime;
		ifstream inputFile(filename);
		ofstream tempFile("temp.txt");
		string line;
		bool ticketFound = false;
		while (getline(inputFile, line)) {
			if (line.find(date) != string::npos &&
				line.find(departureCity + "-" + destinationCity) != string::npos &&
				line.find(startTime) != string::npos && line.find(endTime) != string::npos) {
				ticketFound = true;
				while (getline(inputFile, line) && !line.empty()) {
				}
				tempFile << endl;
				continue;
			}
			tempFile << line << endl;
		}
		inputFile.close();
		tempFile.close();
		if (remove(filename.c_str()) != 0) {
			perror("Error deleting the file");
			return;
		}
		if (rename("temp.txt", filename.c_str()) != 0) {
			perror("Error renaming the file");
			return;
		}
		if (ticketFound) {
			cout << "Ticket successfully deleted." << endl;
		}
		else {
			cout << "Ticket not found." << endl;
		}
	}
	void AirLine::FindBoughts(const string & filenameBought) {
		string fullName, passportData;
		cout << "Enter your full name: ";
		cin.ignore();
		getline(cin, fullName);
		cout << "Enter your passport data: ";
		getline(cin, passportData);
		ifstream file(filenameBought);
		if (!file.is_open()) {
			cerr << "Unable to open file for reading.\n";
			return;
		}
		string line;
		bool ticketFound = false;
		while (getline(file, line)) {
			if (line.find(fullName) != string::npos && getline(file, line) &&
				line.find(passportData) != string::npos) {
				ticketFound = true;
				cout << line << endl;
				while (getline(file, line) && line != "-----------------------------------") {
					cout << line << endl;
				}
				cout << line << endl;
			}
		}
		file.close();
		if (!ticketFound) {
			cout << "No tickets found for the given name and passport data." << endl;
		}
	}
	void AirLine::ReturnTicket(const string & filenameBought) {
		string fullName, passportData;
		cout << "Enter your full name: ";
		cin.ignore();
		getline(cin, fullName);
		cout << "Enter your passport data: ";
		getline(cin, passportData);
		ifstream file(filenameBought);
		if (!file.is_open()) {
			cerr << "Unable to open file for reading.\n";
			return;
		}
		ofstream tempFile("temp.txt");
		if (!tempFile.is_open()) {
			cerr << "Unable to open temporary file for writing.\n";
			return;
		}
		string line;
		bool ticketFound = false;
		while (getline(file, line)) {
			if (line.find(fullName) != string::npos && getline(file, line) &&
				line.find(passportData) != string::npos) {
				ticketFound = true;
				while (getline(file, line) && line != "-----------------------------------") {
				}
				continue;
			}
			tempFile << line << endl;
		}
		file.close();
		tempFile.close();
		remove(filenameBought.c_str()); // Преобразуем в const char*
		rename("temp.txt", filenameBought.c_str());
		if (ticketFound) {
			cout << "Ticket successfully returned.\n";
		}
		else {
			cout << "No ticket found for the given name and passport data.\n";
		}
	}
	void AirLine::DisplayAllFlights() {
		cout << "Available flights:\n";
		// Выводим экономические билеты
		for (const auto& econTicket : eco) {
			cout << "Economical ticket: "
				<< "From: " << econTicket.GetPlaceOfDeparture()
				<< ", To: " << econTicket.GetDestination()
				<< ", Date: " << econTicket.GetDepartureDate()
				<< ", Price: " << econTicket.GetPrice()
				<< ", Seats Available: " << econTicket.GetNumberOfSeats()
				<< ", Meal: " << (econTicket.GetHasMeal() ? "Yes" : "No")
				<< ", Max Baggage: " << econTicket.GetMaxBaggageWeight() << "kg\n";
		}
		for (const auto& busTicket : bus) {
			cout << "Business ticket: "
				<< "From: " << busTicket.GetPlaceOfDeparture()
				<< ", To: " << busTicket.GetDestination()
				<< ", Date: " << busTicket.GetDepartureDate()
				<< ", Price: " << busTicket.GetPrice()
				<< ", Seats Available: " << busTicket.GetNumberOfSeats()
				<< ", Services: " << busTicket.GetServices() << "\n";
		}
		if (eco.empty() && bus.empty()) {
			cout << "No flights available.\n";
		}
	}
	void AirLine::readFile(const string & filename) {
		ifstream file(filename);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				if (line.empty()) {
					continue;
				}
				stringstream separator(line);
				string date, route, time;
				getline(separator, date, ' ');
				getline(separator, route, ':');
				string departure = route.substr(0, route.find('-'));
				string destination = route.substr(route.find('-') + 1);
				getline(separator, time);
				while (getline(file, line) && line.find("Category") != string::npos) {
					regex rgx("Category: (Economical|Business), Seats Available: (\\d+),
						Price: ([\\d.] + ), (Meal : (Yes | No), Max Baggage : (\\d + kg)) ? (Services : ([\\w, ] + )) ? ");
						smatch matches;
					if (regex_search(line, matches, rgx)) {
						string category = matches[1];
						int seatsAvailable = stoi(matches[2]);
						float price = stof(matches[3]);
						if (category == "Economical") {
							Economical econTicket;
							econTicket.SetDepartureDate(date);
							econTicket.SetTicketCategory(category);
							econTicket.SetNumberOfSeats(seatsAvailable);
							econTicket.SetPrice(price);
							econTicket.SetPlaceOfDeparture(departure);
							econTicket.SetDestination(destination);
							econTicket.SetHasMeal(matches[5] == "Yes");
							econTicket.SetMaxBaggageWeight(stoi(matches[6]));
							eco.push_back(econTicket);
						}
						if (category == "Business") {
							Business busTicket;
							busTicket.SetDepartureDate(date);
							busTicket.SetTicketCategory(category);
							busTicket.SetNumberOfSeats(seatsAvailable);
							busTicket.SetPrice(price);
							busTicket.SetPlaceOfDeparture(departure);
							busTicket.SetDestination(destination);
							busTicket.SetServices(matches[8]);
							bus.push_back(busTicket);
						}
					}
				}
			}
			file.close();
		}
		else {
			cerr << "Unable to open file" << endl;
		}
	}
}
*/
#include "Classes.h"

AirLine::AirLine(string airLineName) {
    this->airlineName = airLineName;
}

void AirLine::AddTicket(const string& filename) {
    ofstream file;
    file.open(filename, ios::app);
    if (file.is_open()) {
        string newDeparture, newDestination, newDate, newTimeStart, newTimeEnd, newCategory;
        bool newMeal;
        string newMaxBaggage, newServices;
        int newSeatsAvailable;
        float newPrice;
        Economical newTicketEc;
        Business newTicketBus;

        // Input details and populate ticket
        // The actual logic for ticket creation...

        file.close();
    }
    else {
        cerr << "Unable to open file for writing.\n";
    }
}

void AirLine::BuyTicket(const string& filenameBought) {
    // Code for buying a ticket
}

void AirLine::DeleteTicket(const string& filename) {
    // Code for deleting a ticket
}

void AirLine::FindBoughts(const string& filenameBought) {
    // Code to find bought tickets
}

void AirLine::ReturnTicket(const string& filenameBought) {
    // Code for returning a ticket
}

void AirLine::DisplayAllFlights() {
    // Code to display all flights
}

void AirLine::readFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            stringstream separator(line);
            string date, route, time;
            getline(separator, date, ' ');
            getline(separator, route, ':');
            // Parse and create ticket objects...
        }
    }
    else {
        cerr << "Unable to open file" << endl;
    }
}
