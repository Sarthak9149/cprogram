#include <stdio.h>

#define SIZE 6

int front = -1;
int rear = -1;

struct PriorityQueue {
    int item;
    int priority;
};

struct PriorityQueue PQ[SIZE];

void enqueue() {
    if (rear == SIZE - 1) {
        printf("Priority Queue is full\n");
        return;
    }

    int value, prio;
    printf("Enter value & priority: ");
    scanf("%d %d", &value, &prio);

    // First element
    if (front == -1) {
        front = rear = 0;
        PQ[rear].item = value;
        PQ[rear].priority = prio;
    } 
    else {
        int i;
        // Shift elements to maintain priority order (higher priority first)
        for (i = rear; i >= front && PQ[i].priority < prio; i--) {
            PQ[i + 1] = PQ[i];
        }
        PQ[i + 1].item = value;
        PQ[i + 1].priority = prio;
        rear++;
    }
}

void display() {
    if (front == -1) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = front; i <= rear; i++) {
        printf("Value: %d, Priority: %d\n", PQ[i].item, PQ[i].priority);
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Enqueue\n2. Display\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}
