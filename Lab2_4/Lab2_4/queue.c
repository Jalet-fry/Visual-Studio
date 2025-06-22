#include "header.h"
#include "functions.h"
#include "queue.h"
#define FLOOR 5
#define PEOPLE_IN_ROOM 4
#define ROOMS 5

void update_spaces_after_relocation(Floor* first_floor, Floor* target_floor) {
    if (first_floor != target_floor) {
        first_floor->free_spaces++;
        target_floor->free_spaces--;
    }
}

Room_mate* input_room_mate_name() {
    char temp_buffer[1024]; 
    printf("Введите имя: ");
	fgets(temp_buffer, sizeof(temp_buffer) / sizeof(char), stdin);
    temp_buffer[strcspn(temp_buffer, "\n")] = '\0';
    char* name = (char*)malloc(strlen(temp_buffer)); 
    if (name == NULL) {
        fprintf(stderr, "Ошибка выделения памяти.\n");
        return NULL;
    }
    strcpy(name, temp_buffer);
    Room_mate* new_mate = (Room_mate*)malloc(sizeof(Room_mate));
    if (new_mate == NULL) {
        fprintf(stderr, "Ошибка выделения памяти для Room_mate.\n");
        free(name); 
        return NULL;
    }
    new_mate->name = name;
    new_mate->next = NULL;
    new_mate->prev = NULL;

    return new_mate;
}

Floor* find_not_full_floor(Floor* floors) {
    Floor* actual_floor = floors;
    while (actual_floor) {
        if (actual_floor->free_spaces) {
            return actual_floor;
        }
        actual_floor = actual_floor->next;
    }
    return NULL;
}
Room* find_free_room(Floor* free_floor) {
    if (free_floor) {
        Room* room = free_floor->rooms;
        while (room) {
            if (count_people(room->room_mate) < PEOPLE_IN_ROOM) {
                return room;
            }
            room = room->next;
        }
    }
    return NULL;
}
Floor* find_floor(Floor* queue, char *floor_number) {
    if (queue == NULL || floor_number == NULL) {
        return NULL;
    }
    Floor* actual_floor = queue;
    while (actual_floor) {
        if (actual_floor->floor == (*floor_number)) {
            return actual_floor;
        }
        actual_floor = actual_floor->next;
    }
    return NULL;
}
Floor* find_max_floor(Floor* queue) {
    if (queue == NULL) {
        return NULL;
    }
    Floor* actual_floor = queue;
    while (actual_floor->next) {
        actual_floor = actual_floor->next;
    }
    return actual_floor;
}
Floor* find_min_floor(Floor* queue) {
    if (queue == NULL) {
        return NULL;
    }
    Floor *actual_floor = queue;
    while (actual_floor->prev) {
        actual_floor = actual_floor->prev;
    }
    return actual_floor;
}

Room* find_room(Floor* queue, char* room_number) {
    if (room_number == NULL || queue == NULL) {
        return NULL;
    }
    Room *actual_room = queue->rooms;
    while (actual_room) {
        if (actual_room->number == *room_number) {
            return actual_room;
        }
        actual_room = actual_room->next;
    }
    return NULL;
}
void print_flors(Floor *flors) {
    Floor* actual_floor = flors;
    while (actual_floor) {
        printf("\n\t\t\t  FLOOR = %d\n", actual_floor->floor);
        printf("\n\t\t\t  TOTAL = %d;FREE = %d\n", actual_floor->total_spaces, actual_floor->free_spaces);
        Room* room = actual_floor->rooms;
        while (room) {
			printf("\t\t  ROOM = %d\tPeople = %d\n  ", room->number, count_people(room->room_mate));
            print_people(room->room_mate);
            room = room->next;
        }
        actual_floor = actual_floor->next;
    }
}

void print_people(Room_mate* room_mate) {
    if (room_mate == NULL) {
        printf("\t\t{}\n");
        return;
    }
    Room_mate* current = room_mate;
    printf("\t\t{");
    int count = 0;
    do {
        count++;
        printf("   %d)%s", count, current->name);
        current = current->next;

        if (current != room_mate) {
            printf(",");
        }
    } while (current != room_mate);

    printf("}\n");
}
int count_people(Room_mate* room_mate) {
    if (room_mate == NULL) {
        return 0;
    }
    Room_mate* current = room_mate;
    int count = 0;
    do {
        count++;
        current = current->next;
    } while (current != room_mate);

    return count;
}
void delete_room_mate_in_room(Room* room, Room_mate* delete_person, char delete_mate) {
    if (room == NULL || delete_person == NULL) {
        return;
    }
    if (room->room_mate == delete_person) {
        if (delete_person->next == delete_person) {
            if (delete_mate) {
                free(delete_person);
            }
            room->room_mate = NULL;
            return;
        }
        room->room_mate = delete_person->next;
    }

    delete_person->prev->next = delete_person->next;
    delete_person->next->prev = delete_person->prev;

    if (delete_mate) {
        free(delete_person);
    }
}

void printCharsFromFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        printf("Character: %c, ASCII value: %d\n", ch, ch);
    }
    fclose(file);
}
void saver(Floor *floors, char *path_to_bin_file) {
    char end_marker = 0;
    FILE *file = fopen(path_to_bin_file, "wb");
    if (!file) {
        perror("Ошибка открытия файла");
        return;
    }
    for (Floor *f = floors; f != NULL; f = f->next) {
        fwrite(&(f->floor), sizeof(f->floor), 1, file);
        fwrite(&(f->total_spaces), sizeof(f->total_spaces), 1, file);
        fwrite(&(f->free_spaces), sizeof(f->free_spaces), 1, file);
        for (Room *r = f->rooms; r != NULL; r = r->next) {
            fwrite(&(r->number), sizeof(r->number), 1, file);
            Room_mate *current = r->room_mate;
            if (current) {
                do {
                    fwrite(current->name, strlen(current->name) + 1, 1, file);
                    current = current->next;
                } while (current != r->room_mate);
            }
            fwrite(&end_marker, sizeof(end_marker), 1, file); // Конец списка имен
        }
        fwrite(&end_marker, sizeof(end_marker), 1, file); // Конец списка комнат
    }
    fclose(file);
}


Floor* read_from_binary_file(char* path_to_bin_file) {
    FILE* file = fopen(path_to_bin_file, "rb");
    if (!file) {
        perror("Ошибка открытия файла");
        return NULL;
    }
    Floor* floors = NULL, *current_floor = NULL;
    Room* current_room = NULL;
    char end_marker, * name = NULL, size_name = 0;
    while (fread(&end_marker, sizeof(end_marker), 1, file) == 1 && end_marker != 0) {
        Floor* new_floor = (Floor*)malloc(sizeof(Floor));
        new_floor->floor = end_marker;
        fread(&(new_floor->total_spaces), sizeof(new_floor->total_spaces), 1, file);
        fread(&(new_floor->free_spaces), sizeof(new_floor->free_spaces), 1, file);
        new_floor->rooms = NULL;
        new_floor->next = NULL;
        if (current_floor) {
            current_floor->next = new_floor;
            new_floor->prev = current_floor;
        } else {
            floors = new_floor;
            floors->prev = NULL;
        }
        current_floor = new_floor;
        while (fread(&end_marker, sizeof(end_marker), 1, file) == 1 && end_marker != 0) {
            Room* new_room = (Room*)malloc(sizeof(Room));
            new_room->number = end_marker; // Первое значение - номер комнаты
            new_room->room_mate = NULL;
            new_room->next = NULL;
            if (current_floor->rooms) {
                current_room->next = new_room;
            } else {
                current_floor->rooms = new_room;
            }
            current_room = new_room;
            while (1) {
                name = read_binary_string(file, 1);
                if (!name[0]) {
                    free(name);
                    break;
                }
                Room_mate* last_mate = (Room_mate*)malloc(sizeof(Room_mate));
                last_mate->name = name;
                last_mate->next = NULL;
                last_mate->prev = NULL;

                if (current_room->room_mate) {
                    last_mate->next = current_room->room_mate;
                    last_mate->prev = current_room->room_mate->prev;
                    current_room->room_mate->prev->next = last_mate;
                    current_room->room_mate->prev = last_mate;

                }
                else {
                    current_room->room_mate = last_mate;
                    last_mate->next = last_mate;
                    last_mate->prev = last_mate;
                }
            }
            size_name = 0;
        }
    }
    fclose(file);
    return floors;
}

Room *find_names_room_in_queue(Floor* queue, char* delete_name) {
    Floor* actual_floor = queue;
    while (actual_floor) {
        Room* room = actual_floor->rooms;
        while (room) {
            Room_mate* actual_room_mate = room->room_mate;
            while (actual_room_mate) {
                if (strcmp(actual_room_mate->name, delete_name) == 0) {
                    return room;
                }
                actual_room_mate = actual_room_mate->next;
                if (actual_room_mate == room->room_mate) {
                    break;
                }
            }
            room = room->next;
        }
        actual_floor = actual_floor->next;
    }
    return NULL;
}
Room_mate* find_name_in_queue(Floor* queue, Floor** find_floor, Room** find_room, char* delete_name) {
    Floor* actual_floor = queue;
    while (actual_floor) {
        Room* room = actual_floor->rooms;
        while (room) {
            Room_mate* actual_room_mate = room->room_mate;
            while (actual_room_mate) {
                if (strcmp(actual_room_mate->name, delete_name) == 0) {
                    *find_floor = actual_floor;
                    *find_room = room;
                    printf("Нашли комнату и имя:|%d|=|%d|  |%s|", room->number, (*find_room)->number, actual_room_mate->name);
                    return actual_room_mate;
                }
                actual_room_mate = actual_room_mate->next;
                if (actual_room_mate == room->room_mate) {
                    break;
                }
            }
            room = room->next;
        }
        actual_floor = actual_floor->next;
    }
    return NULL;
}
Room_mate* find_name_in_room(Room *our_room, char* delete_name) {
    Room_mate* actual_room_mate = our_room->room_mate;
    while (actual_room_mate) {
        if (strcmp(actual_room_mate->name, delete_name) == 0) {
            return actual_room_mate;
        }
        actual_room_mate = actual_room_mate->next;
        if (actual_room_mate == our_room->room_mate) {
            break;
        }
    }
    return NULL;
}
void change_floor_number(Floor *diying_floor) {
    Floor* actual_floor = diying_floor;
    while (actual_floor) {
        actual_floor->floor--;
        actual_floor = actual_floor->next;
    }

}
void delete_floor_main(Floor** queue) {
    char delete_floor_numer = correct("Введите номер удаляемого этажа:"), user_choice = 15;
    Floor* delete_floor = find_floor(*queue, &delete_floor_numer);
    if (delete_floor) {
        while (delete_floor->free_spaces != delete_floor->total_spaces && user_choice != 1 && user_choice != 0) {
            user_choice = correct("Что делать с жильцами:\n0)Сразу всех на мороз\n1)Попытаться спасти часть:");
        }
		change_floor_number(delete_floor);
        if (*queue == delete_floor) {
            *queue = delete_floor->next;
        }
        delete_floor_in_queue(delete_floor, user_choice);
    }
    else {
        printf("Такого этажа не существует\n");
    }
}
void delete_floor_withiut_questions(Floor** queue, char *delete_floor_numer) {
    char user_choice = 0;
    Floor* delete_floor = find_floor(*queue, &delete_floor_numer);
    if (delete_floor) {
		change_floor_number(delete_floor);
        if (*queue == delete_floor) {
            *queue = delete_floor->next;
        }
        delete_floor_in_queue(delete_floor, user_choice);
    }
    else {
        printf("Такого этажа не существует\n");
    }
}
void delete_all_room_in_floor(Floor *delete_floor){
    Room* actual_room = delete_floor->rooms;
    while (actual_room->next) {
        Room* next_room = actual_room->next;
        free(actual_room);
        actual_room = next_room;
    }
    free(actual_room);
    delete_floor->rooms = NULL;
}
void delete_floor_in_queue(Floor *delete_floor, char user_choice){
    if (user_choice) {
        relocate_floor(delete_floor, &delete_floor->floor);
    }
    if (delete_floor->free_spaces != delete_floor->total_spaces) {
        eviction_floor(delete_floor, &delete_floor->floor);
    }
    if (delete_floor->next != NULL) {
        delete_floor->next->prev = delete_floor->prev;
    }
    if (delete_floor->prev != NULL) {
        delete_floor->prev->next = delete_floor->next;
    }
    delete_all_room_in_floor(delete_floor);
    free(delete_floor);
    delete_floor = NULL;
}
void delete_all_queue(Floor** queue) {
    Floor *actual_floor = find_max_floor(*queue), *next;
    while (actual_floor && actual_floor != (*queue)) {
        next = actual_floor->prev;
        delete_floor_in_queue(actual_floor, 0);
        actual_floor = next;
    }
    eviction_floor(*queue, &((*queue)->floor));
    delete_all_room_in_floor(*queue);
    free(*queue);
    *queue = NULL;

}
void add_floor_main(Floor** queue) {
    Floor *last_floor = find_max_floor(*queue), *min_floor = find_min_floor(*queue);
    char new_floor = correct("Введите номер добавляемого этажа:"), count_room = correct("Введите количество комнат на этаже:");
    while(new_floor > last_floor->floor + 1 || new_floor < min_floor->floor - 1){
        new_floor = correct("Введите корректный номер добавляемого этажа:"); 
    }
    while (count_room <= 0) {
		count_room = correct("Введите корректное количество комнат на этаже:");
    }
    add_floor(queue, last_floor, min_floor, new_floor, count_room);
}
void init_new_floor(Floor* new_floor, char new_floor_number, char count_room) {
    new_floor->floor = new_floor_number;
    new_floor->total_spaces = new_floor->free_spaces = PEOPLE_IN_ROOM * count_room;
    new_floor->rooms = new_floor->next = new_floor->prev = NULL;
}
void create_rooms_for_floor(Floor* floor, char count_room) {
    Room* actual_room = NULL;
    for (int x = 1; x <= count_room; x++) {
        Room* new_room = (Room*)malloc(sizeof(Room));
        new_room->number = x;
        new_room->room_mate = NULL;
        new_room->next = NULL;
        if (!actual_room) {
            floor->rooms = new_room;
        }
        else {
            actual_room->next = new_room;
        }
        actual_room = new_room;
    }
}

char insert_floor(Floor** queue, Floor* new_floor, Floor* before, Floor *current, Floor* after) {
    if (before) {
        before->next = new_floor;
        new_floor->next = NULL;
		new_floor->prev = before;
    }
    if (after) {
        after->prev = new_floor;
		new_floor->next = after;
    }
    if (!before) {
        new_floor->next = *queue;
        (*queue)->prev = new_floor;
        new_floor->prev = NULL;
        *queue = new_floor;
    }
    if (!after) {
        return 0;
    }
    return 1;
}

void update_floor_numbers(Floor* start) {
    while (start) {
        start->floor++;
        start = start->next;
    }
}
void add_floor(Floor** queue, Floor *last_floor, Floor *min_floor, char new_floor_number, char count_room) {
    char before_new_number = new_floor_number - 1, after_new_number = new_floor_number;
    Floor* new_floor = (Floor*)malloc(sizeof(Floor));
    if (!new_floor) {
        return; 
    }
    init_new_floor(new_floor, new_floor_number, count_room);
    create_rooms_for_floor(new_floor, count_room);
    Floor *before = find_floor(*queue, &before_new_number), *after = find_floor(*queue, &after_new_number), *current = find_floor(*queue, &new_floor_number);
    if (insert_floor(queue, new_floor, before, current, after)) {
        update_floor_numbers(new_floor->next);
    }
}
void change_queue(Floor** queue, char* exit_flag) {
    int user_choice;
    char file_comand[] =
        "Выберите действие:\n"
        "0. Возврат в главное меню\n"
        "1. Добавить этаж\n"
        "2. Удалить этаж\n"
        "3. Сохранить общагу в user_que.bin\n"
        "4. Вывести всю общагу с комнатами и людьми\n"
        "5. Работа с жильцами\n"
        "6. Возврат в предыдущее меню\n",
        file_user[] = "C:\\Files_for_testing\\user_que.bin";
    while (!*exit_flag) {
        printf("%s", file_comand);
        user_choice = correct("Ваш выбор:");
        switch (user_choice) {
        case 1:
            add_floor_main(queue);
            break;
        case 2:
            delete_floor_main(queue);
            break;
        case 3:
            promptForSave(*queue, file_user);
            //saver(*queue, file_user);

            break;
        case 4:
            print_flors(*queue);
            break;
        case 0:
            *exit_flag = 1;
            break;
        case 5:
            control_people(*queue, exit_flag);
            break;
        case 6:
            return;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    }
}
void menu_files() {
    Floor* queue = NULL; 
    char file_welcome[] =
        "Доступные команды: \n"
        "0) Выход\n"
        "1) queue.bin (только чтение)\n"
        "2) user_que.bin (чтение и запись)\n";
	char file_default[] = "C:\\Files_for_testing\\queue.bin", file_user[] = "C:\\Files_for_testing\\user_que.bin",
	user_choice, exit_flag = 0;
    while (!exit_flag) {          
        printf("%s", file_welcome);
        user_choice = correct("Ваш выбор:");
        switch (user_choice) {
        case 1:
            queue = read_from_binary_file(file_default);
			menu_queue(&queue, &exit_flag);
            break;
        case 2:
            queue = read_from_binary_file(file_user);
			menu_queue(&queue, &exit_flag);
            break;
        case 0:
            exit_flag = 1; // Выход из функции
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    }
	promptForSave(queue, file_user);
    delete_all_queue(&queue);
}

void menu_queue(Floor** queue, char* exit_flag) {
    int user_choice;
    char file_comand[] =
        "Выберите действие:\n"
        "0. Возврат в главное меню\n"
        "1. Капитальный ремонт общежития\n"
        "2. Сохранить общагу в user_que.bin\n"
        "3. Возврат в предыдущее меню\n"
        "4. Вывести всю общагу с комнатами и людьми\n"
        "5. Работа с жильцами\n"
        "6. Возврат в предыдущее меню\n",
        file_user[] = "C:\\Files_for_testing\\user_que.bin";
    while (!*exit_flag) {
        printf("%s", file_comand);
        user_choice = correct("Ваш выбор:");
        switch (user_choice) {
        case 1:
            change_queue(queue, exit_flag);
            break;
        case 2:
            promptForSave(*queue, file_user);
            saver(*queue, file_user);
            break;
        case 3:
            return;
            break;
        case 4:
            print_flors(*queue);
            break;
        case 0:
            *exit_flag = 1;
            break;
        case 5:
            control_people(*queue, exit_flag);
            break;
        case 6:
            return;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    }
}
void control_people(Floor* queue, char* exit_flag) {
    Floor* free_floor = NULL;
    char file_comand[] =
        "Выберите действие:\n"
        "0. Возврат в главное меню\n"
        "1. Сохранить общагу в user_que.bin\n"
        "2. Поиск свободного места\n"
        "3. Заселение\n"
        "4. Вывести всю общагу с комнатами и людьми\n"
        "5. Переселение людей\n"
        "6. Выселение\n"
        "7. Возврат в предыдущее меню\n",
        file_user[] = "C:\\Files_for_testing\\user_que.bin", user_choice;
    while (!*exit_flag) {
        printf("%s", file_comand);
        user_choice = correct("Ваш выбор:");
        switch (user_choice) {
        case 1:
            promptForSave(queue, file_user);
            saver(queue, file_user);
            break;
        case 2:
            free_floor = find_not_full_floor(queue);
            (free_floor) ? printf("Есть свободное место на %d этаже в %d комнате\n", free_floor->floor, find_free_room(free_floor)->number) : printf("Свободных мест нету\n");
            break;
        case 3:
            settle(queue, NULL, NULL, NULL);
            break;
        case 4:
            print_flors(queue);
            break;
        case 0:
            *exit_flag = 1;
            break;
        case 5:
            change_in_room(queue);
            break;
        case 6:
            eviction(queue);
            break;
        case 7:
            return;
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    }
}


Room_mate* find_person_in_room(Room* our_room) {
    print_people(our_room->room_mate);
    char* find_name, answer = correct("Выберите человека одним из способов:\n1)по ФИО\n2)По индексу\nВаш выбор: ");
    switch (answer) {
    case 1:
        find_name = input_name("Введите ФИО:");
        return find_name_in_room(our_room, find_name);
        break;
    case 2:
        return(find_room_mate_by_index(our_room->room_mate, correct("Введите индекс человека:")));

        break;
    }
}
void find_free_space(Floor* queue, char* current_floor_number, char* current_room_number, Floor** target_floor, Room** target_room) {
    Floor* actual_floor = queue;
    if (current_floor_number != NULL && current_room_number != NULL) {
        printf("Ты передал в find_free_place %d этаж и %d комнату\n", *current_floor_number, *current_room_number);
    }
    while (actual_floor && !(*target_floor)) {
        if (current_floor_number == NULL || (*current_floor_number) != actual_floor->floor) {
            Room* room = actual_floor->rooms;
            while (room && !(*target_room)) {
                if (current_room_number == NULL || (*current_floor_number) != actual_floor->floor && (*current_room_number) != room->number) {
                    if (count_people(room->room_mate) < PEOPLE_IN_ROOM) {
                        *(target_floor) = actual_floor;
                        (*target_floor)->rooms = actual_floor->rooms;
                        *(target_room) = room;
                        (*target_room)->room_mate = room->room_mate;
                        printf("Мы нашли %d этаж и %d команатa\n", (*target_floor)->floor, (*target_room)->number);
                        break;
                    }
                }
                room = room->next;
            }
        }
        actual_floor = actual_floor->next;
    }
}
void find_free_for_name(Floor* queue, Floor* exclude_floor, Room* exclude_room, Floor** target_floor, Room** target_room) {
    Floor* actual_floor = queue;
    while (actual_floor) {
        if (actual_floor == exclude_floor) {
            actual_floor = actual_floor->next;
            continue;
        }
		Room* room = actual_floor->rooms;
        while (room && actual_floor->free_spaces) {
            if (room == exclude_room) {
                room = room->next;
                continue;
            }
            if (count_people(room->room_mate) < PEOPLE_IN_ROOM) {
                *(target_floor) = actual_floor;
                (*target_floor)->rooms = actual_floor->rooms;
                *(target_room) = room;
                (*target_room)->room_mate = room->room_mate;
                //printf("Мы нашли %d этаж и %d комнату\n", (*target_floor)->floor, (*target_room)->number);
                return;
            }
            room = room->next;
        }
		actual_floor = actual_floor->next;
    }
    *(target_floor) = *(target_room) = NULL;

}
void relocate_floor(Floor* queue, char* current_floor_number) {
    Floor* first_floor = find_floor(queue, current_floor_number), *target_floor = NULL;
    Room *target_room = NULL, *actual_room = (first_floor)  ? first_floor->rooms : NULL;
    Room_mate* well_done_android = NULL;
    char flag = 0;
    do{
        if (actual_room->room_mate) {
            flag = 1;
            well_done_android = relocate_room(queue, first_floor, actual_room, NULL, NULL);
        }
        actual_room = actual_room->next;
    }
    while (actual_room && well_done_android && flag);
}
Room* relocate_room(Floor* queue, Floor* old_floor, Room *old_room, char* current_floor_number, char* current_room_number) {
    Floor* first_floor = (old_floor) ? old_floor : find_floor(queue, current_floor_number), *target_floor = NULL;
    Room *first_room = (old_room) ? old_room : find_room(first_floor, current_room_number), *target_room = first_room;
    Room_mate* first_man_in_target_room = (first_room) ? first_room->room_mate : NULL, *moving_person = NULL;
    if (!first_man_in_target_room) {
        return NULL;
    }
	find_free_for_name(queue, (old_floor) ? old_floor : NULL, first_room, &target_floor, &target_room);
    while (target_room && first_room->room_mate) {
        first_man_in_target_room = first_room->room_mate;
        if (!strcmp("Lola", first_man_in_target_room->name) || !strcmp("Marilyn Monroe", first_man_in_target_room->name)) {
            printf("Diabolus est in singulis\n");
        }
        delete_room_mate_in_room(first_room, first_room->room_mate, 0);
        settle_person(target_room, first_man_in_target_room);
        update_spaces_after_relocation(first_floor, target_floor);
        find_free_for_name(queue, (old_floor) ? old_floor : NULL, first_room, &target_floor, &target_room);
    }
    return target_room;
}


void relocate_by_name(Floor* queue, char* name) {
    Room *current_room = NULL, *target_room = NULL;
    Floor *current_floor = NULL,*target_floor = NULL;
    Room_mate *person_to_move = find_name_in_queue(queue, &current_floor, &current_room, name);
    if (person_to_move == NULL) {
        printf("Человек с именем %s не найден.\n", name);
        return;
    }
    find_free_for_name(queue, NULL, current_room, &target_floor, &target_room);
    if (target_room == NULL) {
        printf("Свободных мест нет.\n");
        return;
    }
    delete_room_mate_in_room(current_room, person_to_move, 0);
    settle_person(target_room, person_to_move);
	update_spaces_after_relocation(current_floor, target_floor);
    printf("%s был переселен в комнату %d на этаже %d\n", name, target_room->number, target_floor->floor);
}


void settle(Floor* queue, char* current_floor_number, char* current_room_number, char* current_index_person) {
    Room *first_room = find_room(find_floor(queue, current_floor_number), current_room_number), *target_room = NULL;
    Floor *target_floor = NULL;
    Room_mate* first_man_in_target_room = NULL, *moving_person = NULL;
    find_free_space(queue, current_floor_number, current_room_number, &target_floor, &target_room);
    if (target_room) {
        if (current_index_person == NULL) {
            moving_person = input_room_mate_name();
        } else {
            first_man_in_target_room = target_room->room_mate;
            moving_person = find_room_mate_by_index(first_room, *current_index_person);
        }
        if (moving_person) {
            if (current_index_person != NULL) {
                delete_room_mate_in_room(first_room, moving_person, 0);
            }
            settle_person(target_room, moving_person);
            if (current_floor_number == NULL || *current_floor_number != target_floor->floor) {
                target_floor->free_spaces--;
            }
            printf("%s был заселен в комнату %d на этаже %d\n", moving_person->name, target_room->number, target_floor->floor);
        } else {
            printf("Человек не найден.\n");
        }
    } else {
        printf("Свободных мест нет\n");
    }
}
void settle_person(Room* target_room, Room_mate* new_mate) {
    if (!new_mate) {
        new_mate = input_room_mate_name();
    }
    if (!target_room->room_mate) {
        target_room->room_mate = new_mate;
        new_mate->next = new_mate;
        new_mate->prev = new_mate;
    } else {
        new_mate->prev = target_room->room_mate->prev;
        new_mate->next = target_room->room_mate;
        new_mate->prev->next = new_mate;
        target_room->room_mate->prev = new_mate;
    }
}
void delete_numer(Floor* queue) {
    char floor = correct("Введите номер этажа:"), room = correct("Введите номер комнаты:"), numer = correct("Введите индекс человека:");
    eviction_index(queue, floor, room, numer);
}
Room_mate* find_room_mate_by_index(Room *actual_room, char index) {
    index %= PEOPLE_IN_ROOM;
    index = (index > 0) ? index : PEOPLE_IN_ROOM + index;
    printf("New index = %d\n", index);
    Room_mate* first = actual_room->room_mate;
    Room_mate* actual_room_mate = first;
    printf("start_room_mate->name = |%s|\n", first->name);
    char current_index = 1;
    while (actual_room_mate) {
        if (current_index == index) {
            return actual_room_mate;
        }
        current_index++;
		printf("actual_room_mate->name = |%s|\n", actual_room_mate->name);
        printf("index = %d\n", index);
        printf("current_index = %d\n", current_index);
        actual_room_mate = actual_room_mate->next;
        if (actual_room_mate == first) {
            if (current_index == index) {
                return actual_room_mate;
            }
            return NULL;
        }
    }
    return NULL;
}
void eviction_index(Floor* queue, char floor_number, char room_number, char numer) {
    Floor* actual_floor = queue;
    char exit_flag = 0;
    while (actual_floor && !exit_flag) {
        Room* room = actual_floor->rooms;
        while (room && !exit_flag) {
            Room_mate* actual_room_mate = room->room_mate;
            while (actual_room_mate && !exit_flag) {
                if (actual_floor->floor == floor_number && room->number == room_number && find_room_mate_by_index(room, numer)) {
                    delete_room_mate_in_room(room, actual_room_mate, 1);
                    actual_floor->free_spaces++;
                    exit_flag = 1;
                    break;
                }
                actual_room_mate = actual_room_mate->next;
                if (actual_room_mate == room->room_mate) {
                    break;
                }
            }
            room = room->next;
        }
        actual_floor = actual_floor->next;
    }
    if (exit_flag == 1) {
        printf("Все пучком\n");
    }
    else if (exit_flag == 2) {
        printf("Не фартануло\n");
    }
    else {
        printf("Я ошибся, я могу 1 раз ошибиться\n");
    }
}
void eviction_name(Floor* queue, char* delete_name, char flag) {
    Floor *find_floor = NULL;
    Room *find_room = NULL;
    Room_mate *exile = find_name_in_queue(queue, &find_floor, &find_room, delete_name);
    if (exile) {
		printf("Найден |%s| Успешко вернули exile = %s", delete_name,exile->name);
		printf("Найдена комната %d\n", find_room->number);
		delete_room_mate_in_room(find_room, exile, 1);
        find_floor->free_spaces++;
        if (flag) {
            printf("Успешно департировали %s\n", delete_name);
        }
    }
    else {
        printf("Такого человека у нас нету\n");
    }
}
void banish_all_people_in_room(Floor* find_floor, Room *evict_room){
    while (evict_room->room_mate != NULL) {
        delete_room_mate_in_room(evict_room, evict_room->room_mate, 1);
        find_floor->free_spaces++;
       // print_people(evict_room->room_mate);
    }
}
void eviction_room(Floor* queue,char *floor_number,  char *room_number){
    Floor* this_floor = find_floor(queue, floor_number);
    Room* evict_room = find_room(this_floor, room_number);
    banish_all_people_in_room(this_floor, evict_room);
}
void eviction_floor(Floor* queue, char *floor) {
    Floor* evict_floor = find_floor(queue, floor);
    Room* actual_room = evict_floor->rooms;
    while (actual_room) {
        banish_all_people_in_room(evict_floor, actual_room);
        actual_room = actual_room->next;
    }
}

void eviction(Floor* queue) {
    char *delete_name, room_number, floor_number,  answer = correct("Выселить человека:\n1)по ФИО\n2)по номеру этажа, комнаты, человека в комнате\n3)Выселить целую комнату\n4)Выселить целый этаж\n5)Вывод всей общаги\nВаш выбор:");
    switch (answer) {
    case 1:
		delete_name = input_name("Введите ФИО удаляемого:");
        eviction_name(queue, delete_name, 1);
        break;
    case 2:
        delete_numer(queue);
        break;
    case 3:
		floor_number = correct("Введите номер этажа:"), room_number = correct("Введите номер комнаты:");
        eviction_room(queue, &floor_number, &room_number);
        break;
    case 4:
		floor_number = correct("Введите номер этажа:");
        eviction_floor(queue, &floor_number);
        break;
    case 5:
        print_flors(queue);
        break;
    }
}

void change_in_room(Floor* queue) {
    char *delete_name, current_floor, current_room, numer, answer = correct("Переезд человека:\n1)по ФИО\n2)по номеру этажа, комнаты, человека в комнате\n3)Переезд целой комнаты\n4)Переезд целого этажа\n5)Вывод всей общаги\nВаш выбор:");
    switch (answer) {
    case 1:
        delete_name = input_name("Введите ФИО:");
        relocate_by_name(queue, delete_name);
        break;
    case 2:
        current_floor = correct("Введите номер этажа:"), current_room = correct("Введите номер комнаты:"), numer = correct("Введите индекс человека:");
        settle(queue, &current_floor, &current_room, &numer);
        break;
    case 3:
        current_floor = correct("Введите номер этажа:"), current_room = correct("Введите номер комнаты:");
        if (!relocate_room(queue, NULL, NULL, &current_floor, &current_room)) {
            printf("А ты чего хотел? Некуда нам переселять\n");
        }
        break;
    case 4:
        current_floor = correct("Введите номер этажа:");
        relocate_floor(queue, &current_floor);
        break;
    case 5:
        print_flors(queue);
        break;
    }
}
