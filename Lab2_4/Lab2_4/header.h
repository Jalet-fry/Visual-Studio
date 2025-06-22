#ifndef HEADER_H 
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
typedef struct node{
    int data;
    struct node* next;
} Node;
void initStack(Node** top);
int isEmpty(Node* top);
void push(Node** top, int data);
void inputElements(Node** top);
void displayStack(Node* top, char* text);
void sortStackDescending(Node** top);
void task1();
void menu_files();
#endif // HEADER_H
