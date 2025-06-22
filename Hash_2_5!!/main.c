#include "main.h"
#include "functions.c"

void main() {
	char file_default[] = "C:\\Files_for_testing\\default_hash.bin", 
         file_user[] = "C:\\Files_for_testing\\user_hash.bin", 
         choice;

    Hashtable *hashtable = fill_our_hash(file_user);
	while (1) {
		char* welcome = "\n\tMenu:\n\t1) Create new model\n\t2) Find models by name\n\t"
						"3) Delete by min_life cycle\n\t4) List of bodyType\n\t5) Print current model list\n\t"
						"6) Save current tree\n\t7) delete by ind\n\t8) Exit\n\tSelect the option - ";
		switch (choice = correct(welcome)) {
		case 1:
            Car *new_car = create_car();
            ht_set(hashtable, new_car->model, new_car);
            new_car = NULL;
			break;
		case 2:
            char *lost_car = input_name("What is your car:");
            ht_get(hashtable, lost_car);
			break;
		case 3:

			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			printf("\n------------------------\n");
			exit(0);
			break;
		default:
			printf("\n\nIncorrect input");
			break;
		}
	}

}
