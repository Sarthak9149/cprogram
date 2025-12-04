#include <stdio.h>

#define size 9
int stack[size];
int top = -1;

void push(){
    int item;
    if (top == size - 1)
    {
        printf("stack is full");
    }
    else {
        printf("\n enter");
        scanf("%d", &item);
        top++;
        stack[top] = item;
    }
}

void pop(){
    if (top == -1)
    {
        printf("\n Stack is empty");
    }
    else {
        printf(" \n Top value = %d", stack[top]);
        top--;
    }
}

void traverse(){
    if (top == -1){
        printf("stack is empty");
    }
    else {
        for (int i = top; i >= 0; i--)
        {
           printf("\n %d", stack[i]);
        }
        
    }
}

void peek(){
    if (top == -1){
        printf("the stack is empty");
    }
    else {
        printf("\n top value is %d\n", stack[top]);
    }
}

int main(void) {
    int n;
    while (1) {
        printf("\n--- Stack Operations Menu ---\n");
        printf("0. Exit\n");
        printf("1. Push data\n");
        printf("2. Pop data\n");
        printf("3. Traverse (see all data)\n");
        printf("4. Peek (see the current value)\n");

        printf("Enter your choice: ");

        scanf("%d", &n);
        
        if (n == 0) {
            printf("Exiting program.\n");
            break;
        } else if (n == 1) {
            push();
        } else if (n == 2) {
            pop();
        } else if (n == 3) {
            traverse();
        } else if (n == 4) {
            peek();
        } else {
            printf("Invalid choice. Please enter a number from 0 to 4.\n");
        }
    }
    return 0;
}