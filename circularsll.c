#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * head = NULL;
struct node * tmp = NULL;
struct node * nw = NULL;
struct node * ptr = NULL;
int size = 0;
int pos, i;

void traverse() {
    if (head == NULL) {
        printf("Underflow");
        return;
    }

    tmp = head;

    do {
        printf("%d\t", tmp->data);
        tmp = tmp->next;
    } while (tmp != head);
}



void insertion_at_specific_pos(){
    int val;
    nw = (struct node*)(malloc(sizeof(struct node)));
    if (nw == NULL)
    {
        printf("Overflow");
    }

    else
    {   nw->next = NULL;
        if (head == NULL)
        {
            printf("Enter Data\t");
            scanf("%d", &val);
            nw->data = val;
            head = nw;
            ptr = nw;
            head->next = head;
            size++;
        }
        else {
            printf("Enter postion\t");
            scanf("%d", &pos);
            printf("Enter data\t"); 
            scanf("%d", &val);
            nw->data = val;
            if (pos == 1)
            {
                nw->next = head;
                head = nw;
                ptr->next = head;
                size++;
            }
            // Corrected
            else if (pos > size)
            {
                ptr->next = nw;
                ptr = nw;
                ptr->next = head;
                size++;
            }
            else if (pos > 1 && pos <= size)
            {
                tmp = head;
                while (pos > 2)
                {
                    tmp = tmp->next;
                    pos--;
                }
                nw->next = tmp->next;
                tmp->next = nw;

                size++;
            }
            else{
                printf("Invalid position\n");
            }
        }
    }
}

void delete_at_specific_pos(){
    if (head == NULL){
        printf("Overflow");
    }
    else {
        if (size == 1)
        {
            free(head);
            head = NULL;
            ptr = NULL;
            size--;
        }
        
        printf("Enter position to delete\t");
        scanf("%d", &pos);
        if (pos == 1){
           if (head->next == head) {
                free(head);
                head = NULL;
                ptr = NULL;
            } 
            else {
                tmp = head;
                head = head->next;
                ptr->next = head;
                free(tmp);
            }
            size--;
           }
        else if (pos == size)
        {
            tmp = ptr;
            ptr->next = NULL;
            free(tmp);
            size--;
        }
        else if (pos > 1 && pos < size)
        {
            tmp = head;
            while (pos > 1)
            {
                tmp = tmp->next;
                pos--;
            }

            free(tmp);
            size--;
        }
        else{
            printf("Invalid position\n");
        }
    }
}


int main(void) {
    int option;
    do {
        printf("\n***** MAIN MENU *****");
        printf("\n1: Insert element at specific position");
        printf("\n2: Display the list");
        printf("\n3: Delete node at specific position");
        printf("\n4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1: insertion_at_specific_pos();
                    break;
            case 2: traverse();
                    break;
            case 3: delete_at_specific_pos();
                    break;
            case 4: printf("Exiting...\n");
                    break;
            default: printf("Invalid choice!\n");
        }
    } while(option != 4);

    return 0;
}

