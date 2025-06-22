#include "main.h"

//#include "functions.c"

void main() {
	char file_default[] = "C:\\Files_for_testing\\default_hash.bin", 
         file_user[] = "C:\\Files_for_testing\\user_hash.bin", 
         choice, *lost_car = NULL,
		*welcome = "\n\tMenu:\n\t1) Create new model\n\t2) Find models by name\n\t"
					"3) Delete by min_life cycle\n\t4) List of bodyType\n\t5) Print current model list\n\t"
					"6) Save current table\n\t7) delete by model\n\t8) Exit\n\tSelect the option:";
    Hashtable *hashtable = fill_our_hash(file_user);
	while (1) {
		switch (choice = correct(welcome)) {
		case 1:
			hashtable = add_car(hashtable);
			break;
		case 2:
			find_all_cars(hashtable);
			break;
		case 3:
			delete_by_min_life_cycle(hashtable);
			break;
		case 4:
			list_by_bodytype(hashtable);
			break;
		case 5:
			print_hashtable(hashtable);
			break;
		case 6:
			save_to_file(hashtable, file_user);
			break;
		case 7:
			delete_by_your_name_main(hashtable);
			break;
		case 8:
			printf("\n------------------------\n");
			hashtable = ht_delete(hashtable);
			print_hashtable(hashtable);
			exit(0);
			break;
		default:
			printf("\n\nIncorrect input");
			break;
		}
	}
}

