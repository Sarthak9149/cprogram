#include <stdio.h>
#include <stdlib.h> // Included for completeness, though not strictly needed here

#define SIZE 6

// Global pointers for the queue boundaries
int front = -1;
int rear = -1;

// Struct for a single item in the queue
// Priority Convention: Higher number = Higher Priority
struct PriorityQueue {
    int item;
    int priority;
};

// Global array to hold the queue elements
struct PriorityQueue PQ[SIZE];

// Function to insert an element into the queue while maintaining sorted order
// Complexity: O(N)
void enqueue() {
    if (rear == SIZE - 1) {
        printf("Priority Queue is full\n");
        return;
    }

    int value, prio;
    printf("Enter value & priority: ");
    // Note: In real-world code, error checking for scanf results is recommended.
    if (scanf("%d %d", &value, &prio) != 2) {
        printf("Invalid input.\n");
        // Clear input buffer to prevent infinite loop
        while (getchar() != '\n');
        return;
    }

    // First element
    if (front == -1) {
        front = rear = 0;
        PQ[rear].item = value;
        PQ[rear].priority = prio;
    } 
    else {
        int i;
        // Find insertion point by shifting elements to the right.
        // Shift if the existing element's priority is LESS than the new item's priority.
        for (i = rear; i >= front && PQ[i].priority < prio; i--) {
            PQ[i + 1] = PQ[i];
        }
        
        // Insert the new item at the correct position (i + 1)
        PQ[i + 1].item = value;
        PQ[i + 1].priority = prio;
        rear++;
    }
    printf("Enqueued Value: %d with Priority: %d\n", value, prio);
}

// Function to remove the element with the highest priority (at front)
// Complexity: O(1)
void dequeue() {
    if (front == -1) {
        printf("Priority Queue is empty, nothing to dequeue\n");
        return;
    }

    // The highest priority item is always at the front index (PQ[front])
    printf("Dequeued highest priority item. Value: %d, Priority: %d\n", PQ[front].item, PQ[front].priority);
    
    // Check if this was the last element
    if (front == rear) {
        // Last element removed, reset the queue
        front = -1;
        rear = -1;
    } else {
        // Move front to the next element
        front++;
    }
}

// Function to view the element with the highest priority (at front) without removing it
// Complexity: O(1)
void peek() {
    if (front == -1) {
        printf("Priority Queue is empty, cannot peek\n");
        return;
    }
    printf("PEEK: Highest priority item is Value: %d, Priority: %d\n", PQ[front].item, PQ[front].priority);
}

// Function to display all elements in the queue (Traversing)
void display() {
    if (front == -1) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("\n--- Current Priority Queue Content ---\n");
    printf("Index | Value | Priority\n");
    printf("---------------------------\n");
    for (int i = front; i <= rear; i++) {
        printf("%5d | %5d | %8d\n", i, PQ[i].item, PQ[i].priority);
    }
    printf("---------------------------\n");
}

int main() {
    int choice;

    do {
        printf("\n==================================\n");
        printf("Priority Queue Operations:\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Display (Traverse)\n");
        printf("3. Dequeue (Delete Max)\n");
        printf("4. Peek (View Max)\n");
        printf("5. Exit\n");
        printf("==================================\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number.\n");
            // Clear input buffer to prevent infinite loop
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                display();
                break;
            case 3:
                dequeue();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
