#include "header.h" 

char *my_strchr(const char *str, int c){
    while (*str != '\0'){ 
        if (*str == c){ 
            return (char*)str; 
        }
        str++; 
    }
    return NULL; 
}

char *my_strtok(char *str, const char *delim) {
    static char *next; 
    char *p; 
    if (str != NULL) { 
        next = str; 
    }
    if (next == NULL) { 
        return NULL; 
    }
    p = next; 
    while (*next != 0) { 
        if (my_strchr(delim, *next) != NULL) { 
            *next = 0; 
            next++; 
            if (*p != 0) { 
                return p; 
            } else { 
                p = next; 
            }
        } else { 
            next++; 
        }
    }
    if (*p != 0) { 
        next = NULL; 
        return p; 
    } else { 
        return NULL; 
    }
}

char *my_strcat(char *dest, const char *src) {
    char *p = dest; 
    while (*dest != '\0'){ 
        dest++;
    }
    while (*src != '\0') { 
        *dest = *src; 
        dest++; 
        src++; 
    }
    *dest = '\0'; 
    return p; 
}

int my_strlen(const char *str){
    int len = 0; 
    while (str[len] != '\0'){ 
        len++; 
    }
    return len; 
}

void my_strncpy(char* dest, const char* src, int max_len) {
    int len = 0; 
    while (*src != '\0' && len < max_len - 1) { 
        *dest = *src; 
        dest++; 
        src++; 
        len++; 
    }
    *dest = 0; 
}

void my_strcpy(char *dest, const char *src){
    while (*src != 0){ 
        *dest = *src; 
        dest++; 
        src++; 
    }
    *dest = '\0'; 
}
