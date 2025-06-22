#include <stdio.h>
#include <stdlib.h>

int correct(char* text) {
    char input[100];
    int valid = 0;
    int num;        
    char* endptr; 
    valid = 0;
    while (!valid) {
        printf("%s\n", text);
        fgets(input, sizeof(input) / sizeof(char), stdin);
        if (input[0] != '\n') {
            num = (int)strtol(input, &endptr, 10);
            if (*endptr != '\n' && *endptr != '\0') {
                printf("Это не число.Попробуйте еще раз.\n");
            }
            else {
                valid = 1;
                printf("Вы ввели число: %d\n", num);
            }
        }
    }
    return num;
}

void russian(unsigned char first[1], int moving, FILE *file, FILE *thing){
    unsigned short russian_upper[] = {
        0xD090, 0xD091, 0xD092, 0xD093, 
        0xD094, 0xD095, 0xD081, 0xD096,                                  
        0xD097, 0xD098, 0xD099, 0xD09a,                                 
        0xD09b, 0xD09c, 0xD09d, 0xD09e,
        0xD09f, 0xD0a0, 0xD0a1, 0xD0a2,
        0xD0a3, 0xD0a4, 0xD0a5, 0xD0a6,
        0xD0a7, 0xD0a8, 0xD0a9, 0xD0aa,
        0xD0ab, 0xD0ac, 0xD0ad, 0xD0ae,
        0xD0af
    };
    unsigned short russian_lower[] = {
        0xD0b0, 0xD0b1, 0xD0b2, 0xD0b3, 
        0xD0b4, 0xD0b5, 0xD191, 0xD0b6, 
        0xD0b7, 0xD0b8, 0xD0b9, 0xD0ba, 
        0xD0bb, 0xD0bc, 0xD0bd, 0xD0be, 
        0xD0bf,
        0xD180, 0xD181, 0xD182, 0xD183,
        0xD184, 0xD185, 0xD186, 0xD187, 
        0xD188, 0xD189, 0xD18a, 0xD18b,
        0xD18c, 0xD18d, 0xD18e, 0xD18f
    };
    unsigned char size_russian = sizeof(russian_upper)/sizeof(russian_upper[0]), second[1];
    fread(second, 1, 1, file);
    int bytes = (first[0] << 8) | second[0];
    int is_upper = (bytes >= 0xD090 && bytes <= 0xD0AF) || (bytes == 0xD081);
    int index = -1;
    for(int i = 0; i < size_russian; ++i){
        if(russian_upper[i] == bytes){
            index = i;
            break;
        }
        if(russian_lower[i] == bytes){
            index = i;
            break;
        }
    }
    if(index != -1){
        index = (index + moving) % size_russian;
        if(index < 0){
            index += size_russian; 
        }
        bytes = (is_upper ? russian_upper[index] : russian_lower[index]);
    }
    int buffer = bytes >> 8 | bytes << 8 ;
    fwrite(&buffer, 2, 1, thing);
}
void english(unsigned char *first, int moving, FILE *thing) {
    int is_upper = (*first >= 'A' && *first <= 'Z');
    int index = (*first - (is_upper ? 'A' : 'a') + moving) % 26;
    if (index < 0) index += 26;
    *first = (is_upper ? 'A' : 'a') + index;
    fwrite(first, 1, 1, thing);
}
void choise(unsigned char first[1], int moving, FILE *file, FILE *thing){
    if((first[0] >= 0x41 && first[0] <= 0x5A) || (first[0] >= 0x61 && first[0] <= 0x7A)){
        english(first, moving, thing);
    }
    else if(first[0] == 0xD0 || first[0] == 0xD1){
        russian(first, moving, file, thing);
    }
    else{
        fwrite(first, 1, 1, thing);
    }
}
int main(int argc, char **argv) {
    int moving = correct("Введите число сдвига:");
    FILE *file = fopen((argc > 1) ? argv[1] : "god_was_never_on_your_side.txt", "rb");
    FILE *thing = fopen((argc > 2) ? argv[2] : "result.txt", "wb");
    if (file == NULL) {
        perror("Error opening file: ");
        return EXIT_FAILURE;
    }
    unsigned char first[1];
    while(fread(first, 1, sizeof(first), file)){
        choise(first, moving, file, thing);
    }
    fclose(file);
    fclose(thing);
    return 0;
}
