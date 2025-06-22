/*
#include "Classes.h"
#include <windows.h>
int main() {
	system("color F0");
	int choice;
	string filename = "infFlights.txt";
	string filenameBought = "infoBoughtTicket.txt";
	AirLine airLine("BelLine");
	airLine.readFile(filename);
	do {
		cout << "Demonstration of work:" << endl
			<< " Choose an action: " << endl
			<< "1. Buy a ticket" << endl
			<< "2. Return ticket" << endl
			<< "3. Find purchased tickets" << endl
			<< "4. Add ticket" << endl
			<< "5. Delete ticket" << endl
			<< "6. Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			airLine.BuyTicket(filenameBought);
			break;
		case 2:
			airLine.ReturnTicket(filenameBought);
			break;
		case 3:
			airLine.FindBoughts(filenameBought);
			break;
		case 4:
			airLine.AddTicket(filename);
			break;
		case 5:
			airLine.DeleteTicket(filename);
			break;
		case 6:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	} while (choice != 6);
	return 0;
}
*/
#include "Classes.h"
#include <windows.h>

int main() {
    system("color F0");
    int choice;
    string filename = "C:\\bilet.txt";
    string filenameBought = "infoBoughtTicket.txt";
    AirLine airLine("BelLine");
    airLine.readFile(filename);
    do {
        cout << "Demonstration of work:" << endl
             << " Choose an action: " << endl
             << "1. Buy a ticket" << endl
             << "2. Return ticket" << endl
             << "3. Find purchased tickets" << endl
             << "4. Add ticket" << endl
             << "5. Delete ticket" << endl
             << "6. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                airLine.BuyTicket(filenameBought);
                break;
            case 2:
                airLine.ReturnTicket(filenameBought);
                break;
            case 3:
                airLine.FindBoughts(filenameBought);
                break;
            case 4:
                airLine.AddTicket(filename);
                break;
            case 5:
                airLine.DeleteTicket(filename);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 6);
    return 0;
}
