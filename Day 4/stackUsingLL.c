#include<stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(){
    int value;
    printf("Enter value to push: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Value pushed\n");
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    free(temp);
    printf("Value popped\n");
}
void display(){
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        struct Node* temp = top;
        printf("Stack elements are:\n");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
int main(){
    int choice;
    do{
        printf("1. Push \n2. pop \n3. Display\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
                
        }
    } while(choice != 4);

    return 0;
}