#include <stdio.h>

#define STACK_SIZE 9
int stack[STACK_SIZE];
int top = -1;

void push() {
    int item;
    if (top == STACK_SIZE - 1) {
        printf("Stack is full. Cannot push more data.\n");
    } else {
        printf("\nEnter data to push: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
        printf("Successfully pushed %d.\n", item);
    }
}

void pop() {
    if (top == -1) {
        printf("\nStack is empty. Cannot pop.\n");
    } else {
        printf("\nPopping value = %d\n", stack[top]);
        top--;
    }
}

void traverse() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("\nStack elements (from top to bottom):\n");
        // Corrected loop condition
        for (int i = top; i >= 0; i--) {
            printf("%d", stack[i]);
        }
    }
}

void peek() {
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("\nTop value is %d\n", stack[top]);
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
        printf("-----------------------------\n");
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