#include <stdio.h>
#include <conio.h>
#define MAX 10
int queue[MAX];
int front= -1, rear =-1;

void insert() {
    int num;
    printf("\n Enter the number to be inserted in the queue : ");
    scanf("%d", &num);
    if(front==0 && rear==MAX-1)
        printf("\n OVERFLOW");
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=num;
    }
    else if(rear==MAX-1 && front!=0)
    {
    rear=0;
    queue[rear]=num;
    }
    else
    {
    rear++;
    queue[rear]=num;
    }
}



int peek(){
    if (front == -1){
    printf("Underflow");
    return -1;
        }
    else {
        printf("%d", queue[front]);
        return 0;
    }
}

void delete(){
    int val;
    if (front == -1 && rear == -1)
    {
        printf("Underflow");
    }
    val = queue[front];
    if(front == rear){
        front = rear = -1;
    }
    else {
        if (front == MAX-1){
            front = 0;
        }
        else {
            front++;
        }
    }
    printf("Deleted value is %d", val);
}


void display() {
    int i;
    printf("\n");
    if (front ==-1 && rear == -1)
        printf ("\n QUEUE IS EMPTY");
    else {
        if(front<rear)
        {
            for(i=front;i<=rear;i++)
                printf("\t %d", queue[i]);
        }
        else {
            for(i=front;i<MAX;i++)
                printf("\t %d", queue[i]);
            for(i=0;i<=rear;i++)
                printf("\t %d", queue[i]);
        }
    }
 }


int main() {
    int n;
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Peek\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Enter a valid input\n");
        }
    } while (n != 0);

    return 0;
}