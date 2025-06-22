#include "main_header.h"
using namespace std;


int main() {
    try {
        My_deque<Creature*> container;
        string filename = "C:\\Files_for_testing\\sem_3\\animals.txt",
        welcome = "\n1. Add creature\n2. Remove creature\n3. Show creatures"
                  "\n4. Modify creature\n5. Undo\n6. Save to file"
				  "\n7. Find by your parametr\n8. Create new creature by two exists"
			      "\n9. Exit\n",
        to_add = "Select creature to add:\n1. Lion\n2. Eagle\n3. Spider\n4. Human\n5. Griffon\n6. SpiderMan\n7. Assassin\n";
        container.load_from_file(filename);
        while (true) {
            int choice = correct(welcome, 1, 9);
            if (choice == 1) {
                int type = correct(to_add, 1, 7);
                switch (type) {
                case 1: {
                    container.my_push_back(new Lion(validate_and_get_name("Enter habitat for Lion: "), correct("Enter age for Lion: ", 1, 25)));
                    break;
                }
                case 2: {
                    container.my_push_back(new Eagle(validate_and_get_name("Enter habitat for Eagle: "), correct("Enter age for Eagle: ", 1, 50)));
                    break;
                }
                case 3: {
                    container.my_push_back(new Spider(validate_and_get_name("Enter habitat for Spider: "), correct("Enter leg's count for Spider: ", 1, 8)));
                    break;
                }
                case 4: {
                    container.my_push_back(new Human(validate_and_get_name("Enter profession for Human: "), correct("Enter age for Human: ", 1, 100)));
                    break;
                }
                case 5: {
                    container.my_push_back(new Griffon(validate_and_get_name("Enter habitat for Griffon: "), correct("Enter age for Griffon: ", 1, 25)));
                    break;
                }
                case 6: {
                    container.my_push_back(new SpiderMan(validate_and_get_name("Enter profession for SpiderMan: "), validate_and_get_name("Enter web_type for Spider: "), correct("Enter age for SpiderMan: ", 15, 100)));
                    break;
                }
                case 7: {
                    container.my_push_back(new Assassin(validate_and_get_name("Enter profession for Assassin: "), validate_and_get_name("Enter habitat for Assassin: "), correct("Enter age for Assassin: ", 18, 50)));
                    break;
                }
                default:
                    cout << "Invalid selection!" << endl;
                    break;
                }
            }
            else if (choice == 2) {
                container.display();
                int index = correct("Enter index of creature to remove: ", 1, container.get_size());
                container.remove_at(index);
            }
            else if (choice == 3) {
                container.display();
            }
            else if (choice == 4) {
                container.display();
                int index = correct("Enter index of creature to modify: ", 1, container.get_size());
                auto it = container.get_at(index);
                container.change_this_creature(index);
            }
            else if (choice == 5) {
                container.undo();
            }
            else if (choice == 6) {
				container.save_to_file(filename);
                cout << "Succesful" << endl;
            }
            else if (choice == 7) {
                container.search_creatures();
            }
            else if (choice == 8) {
                container.time_to_child();
            }
            else if (choice == 9) {
                container.clear();
                container.display();
                break;
            }
        }
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}

