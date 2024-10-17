#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10

int arr[MAXSIZE];
int top = -1;

void push(){
    if(top > MAXSIZE){
        printf("overflow\n");
    } else {
        int n;
        printf("enter the num: ");
        scanf("%d", &n);
        top++;
        arr[top] = n;
    }
}
void pop() {
    if (top < 0) {
        printf("underflow\n");
    } else {
        printf("Popped element: %d\n", arr[top]);
        top--;
    }
}
void display(){
    if (top < 0) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d ", arr[i]);
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
    getch();

    return 0;
}

