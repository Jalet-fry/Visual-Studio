#include "header.h"
#include "functions.h"
void initStack(Node** top) {
    *top = NULL;
}
int isEmpty(Node* top) {
    return top == NULL;
}
void push(Node** top, int new_data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = new_data;
    newNode->next = *top;
    *top = newNode;
    //printf("Элемент %d добавлен в стек.\nТеперь top->data = %d\n", new_data, (*top)->data);
}

void inputElements(Node** top) {
    int element;
    //printf("Enter elements for the stack, end input with a non-integer value:\n");
    while (scanf("%d", &element) == 1) {
        push(top, element);
    }
    while (getchar() != '\n');  
}

void displayStack(Node* top, char* text) {
    printf("%s");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

void sortStackDescending(Node** top) {
    Node *tempStack = NULL, *temp;  
    int tempData;

    // Пока исходный стек не пуст
    while (!isEmpty(*top)) {
        // Взять элемент из вершины исходного стека
        tempData = (*top)->data;
        temp = *top;
        *top = (*top)->next;
        //printf("Взят элемент %d из исходного стека.\n", tempData);
        //displayStack(*top,"Top:");

        // Пока временный стек не пуст и верхний элемент временного стека больше чем tempData
        while (!isEmpty(tempStack) && tempStack->data > tempData) {
            // Переместить элемент из временного стека обратно в исходный стек
            push(top, tempStack->data);
            temp = tempStack;
            tempStack = tempStack->next;
            //printf("Элемент %d перемещен из временного стека в исходный.\n", temp->data);
			//displayStack(tempStack,"TEMPSTACK = ");
			//displayStack(*top,"Top = ");
            free(temp);
        }

        // Поместить захваченный элемент во временный стек
        push(&tempStack, tempData);
        //printf("Элемент %d помещен во временный стек.\n", tempData);
		//displayStack(tempStack,"TEMPSTACK = ");
    }

    while (!isEmpty(tempStack)) {
        push(top, tempStack->data);
        temp = tempStack;
        tempStack = tempStack->next;
        //printf("Элемент %d перемещен из временного стека в исходный.\n", temp->data);
        //displayStack(*top,"Top:");
		//displayStack(tempStack,"TEMPSTACK = ");
        free(temp);
    }
}
void task1() {
    Node* stack = NULL;
    initStack(&stack);
    int method = correct("Choose the input method for stack elements: 1 - console input, 2 - default values: ");
    if (method == 1) {
        inputElements(&stack);
    }
    else {
        //int static_arr[] = { 1, 34, 566, -77, 90, 0, 15, -22, -192, 566, -44, 13, 6 };
        int static_arr[] = { 1, 34, 566, -77, 90};
        //int static_arr[] = { 4, 3, 2, 1};
        int size = sizeof(static_arr) / sizeof(static_arr[0]);
        for (int i = 0; i < size; i++) {
            push(&stack, static_arr[i]);
        }
    }
    displayStack(stack, "Old_stack:");
    sortStackDescending(&stack);
    displayStack(stack, "New_stack:");
}

