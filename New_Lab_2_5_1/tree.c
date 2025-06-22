#include "header.h"
Car *create_car() {
    Car* temp = malloc(sizeof(Car));
    if (temp == NULL) {
        printf("Ошибка выделения памяти.\n");
        return;
    }
    printf("Введите название модели: ");
    temp->model = malloc(20 * sizeof(char));
    fgets(temp->model, 20, stdin);
    temp->model[strcspn(temp->model, "\n")] = 0;
    temp->configurations_count = correct("Введите число конфигураций: ");
    temp->configurations_count = (temp->configurations_count > 0) ? temp->configurations_count : 1;
    temp->configurations = malloc(temp->configurations_count * sizeof(Configuration));
    for (int j = 0; j < temp->configurations_count; j++) {
        printf("Введите тип кузова: ");
        temp->configurations[j].body_type = malloc(15 * sizeof(char));
        fgets(temp->configurations[j].body_type, 15, stdin);
        temp->configurations[j].body_type[strcspn(temp->configurations[j].body_type, "\n")] = 0;
        temp->configurations[j].engine_volume = correct("Введите объем двигателя: ");
        temp->configurations[j].production_start_year = correct("Введите год начала выпуска: ");
        temp->configurations[j].production_end_year = correct("Введите год окончания выпуска: ");
    }
    fflush(stdin);
    return temp;
}
void main() {
	char file_default[] = "C:\\Files_for_testing\\default_structure.bin", file_user[] = "C:\\Files_for_testing\\user_structure_new.bin", 
		file_tree_user[] = "C:\\Files_for_testing\\user_tree_new.bin", choice;
	Tree *user_tree = fill_our_tree(file_user);
	treePrint(user_tree);
	save_to_file(user_tree, file_tree_user, "wb", 0);
	find_model_by_life_cycle_main(user_tree);
	printf("А теперь чистка 1:\n");
	user_tree = delete_model_with_min_lifecycle(user_tree);
	printf("После удаления 1:\n");
	treePrint(user_tree);

	printf("А теперь чистка 2:\n");
	user_tree = delete_model_with_min_lifecycle(user_tree);
	printf("После удаления 2:\n");
	treePrint(user_tree);


	printf("А теперь чистка 3:\n");
	user_tree = delete_model_with_min_lifecycle(user_tree);
	printf("После удаления 3:\n");
	treePrint(user_tree);
	save_to_file(user_tree, file_tree_user, "wb", 0);

	while (1) {
		char* welcome = "\n\tMenu:\n\t1) Create new model\n\t2) Find model by minimum life cycle\n\t"
						"3) Delete by min_life cycle\n\t4) Delete by frame type\n\t5) Print current model list\n\t"
						"6) Save current tree\n\t7) delete by ind\n\t8) Exit\n\tSelect the option - ";
		switch (choice = correct(welcome)) {
		case 1:
			user_tree = add_Car_to_Tree(user_tree, create_Car());
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:
			treePrint(user_tree);
			break;
		case 6:
			save_to_file(user_tree, file_tree_user, "wb", 0);
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

	///while (1) {
	///	choice = correct("\n\tMenu:\n\t1) Create new model\n\t2) Find model by name\n\t3) Get year list\n\t4) Delete by frame type\n\t5) Print current model list\n\t6) Save current tree\n\t7) delete by ind\n\t8) Exit\n\tSelect the option:");
	///	switch (choice) {


	///		break;
	///	default:
	///		printf("\n\nIncorrect input");
	///		break;
	///	}
	///}
}
