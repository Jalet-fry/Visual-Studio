#ifndef QUEUE_H 
#define QUEUE_H
#include "header.h"
typedef struct room_mate{
    char* name;
    struct room_mate* next;
    struct room_mate* prev;
} Room_mate;
typedef struct room{
    char number;
    Room_mate* room_mate;
    struct Room* next;
} Room;
typedef struct floor{
    char floor;
    char total_spaces;
    char free_spaces;
    Room* rooms;
    struct floor *next;
    struct floor *prev;
} Floor;
void update_spaces_after_relocation(Floor* first_floor, Floor* target_floor);
Room_mate* input_room_mate_name();
Floor* find_not_full_floor(Floor* floors);
Room* find_free_room(Floor* free_floor);
Floor* find_floor(Floor* queue, char* floor_number);
Room* find_room(Floor* queue, char* room_number);
int count_people(Room_mate* room_mate);
int populate_student(Floor* floors, char* name_student);
Floor* fill();

void print_people(Room_mate *room_mate);
void print_flors(Floor *flors);
void printCharsFromFile(const char *filename);

void saver(Floor *floors, char *path_to_bin_file);
Floor* read_from_binary_file(char* path_to_bin_file);

Room *find_names_room_in_queue(Floor* queue, char* delete_name);
Room_mate* find_name_in_queue(Floor* queue, Floor** find_floor, Room** find_room, char* delete_name);
Room_mate* find_name_in_room(Room *our_room, char* delete_name);


void change_floor_number(Floor *queue);
void delete_floor_main(Floor** queue);
void delete_all_room_in_floor(Floor *delete_floor);
void delete_floor_in_queue(Floor *delete_floor, char user_choice);

void add_floor_main(Floor** queue);
void init_new_floor(Floor* new_floor, char new_floor_number, char count_room);
void create_rooms_for_floor(Floor* floor, char count_room);
void insert_floor(Floor** queue, Floor* new_floor, Floor* before, Floor* after);
void update_floor_numbers(Floor* start);
void add_floor(Floor** queue, Floor *last_floor, Floor *min_floor, char new_floor_number, char count_room);
void change_queue(Floor** flors, char* exit_flag);
void menu_queue(Floor** queue, char* exit_flag);
void control_people(Floor* queue, char* exit_flag);


Room_mate* find_person_in_room(Room* our_room);
void find_free_space(Floor* queue, char* current_floor_number, char* current_room_number, Floor** target_floor, Room** target_room);


void find_free_for_name(Floor* queue, Floor* exclude_floor, Room* exclude_room, Floor** target_floor, Room** target_room);

void relocate_floor(Floor* queue, char* current_floor_number);
Room* relocate_room(Floor* queue, Floor* old_floor, Room *old_room, char* current_floor_number, char* current_room_number);
void relocate_by_name(Floor* queue, char* name);
void settle(Floor* queue, char* current_floor_number, char* current_room_number, char* current_index_person);
void settle_person(Room* target_room, Room_mate* new_mate);
void settle_2(Floor* queue);


void delete_room_mate_in_room(Room* room, Room_mate* delete_person, char delete_mate);
void delete_numer(Floor* queue);
Room_mate* find_room_mate_by_index(Room *actual_room, char index);

void eviction_index(Floor* queue, char floor_number, char room_number, char numer);
void eviction_name(Floor* queue, char* delete_name, char flag);


void banish_all_people_in_room(Room *evict_room);
void eviction_room(Floor* queue,char *floor_number,  char *room_number);
void eviction_floor(Floor* queue, char *floor) ;
void eviction(Floor* queue);

void change_in_room(Floor* queue);
#endif 
