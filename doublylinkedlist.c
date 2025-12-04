#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node * head = NULL;
struct node * tmp = NULL;
struct node * nw = NULL;
struct node * ptr = NULL;
int size = 0;
int pos, i;

void traverse(){
    if (head == NULL)
    {
       printf("Underflow");
    }
    else {
        tmp = head;
        while (tmp != NULL)
        {
            printf("%d\t", tmp->data);
            tmp = tmp->next;
        }
        
    }
}


void insertion_at_specific_pos(){
    int val;
    nw = (struct node*)(malloc(sizeof(struct node)));
    if (nw == NULL)
    {
        printf("Overflow");
    }
    
    else
    { 
        if (head == NULL)
        {
            printf("Enter Data\t");
            scanf("%d", &val);
            nw->next = NULL;
            nw->prev = NULL;
            nw->data = val;
            head = nw;
            ptr = nw;
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
                nw->prev = NULL;
                head->prev = nw;
                nw->next = head;
                head = nw;
                size++;
            }
            else if (pos > size)
            {
                ptr->next = nw;
                nw->prev = ptr;
                nw->next = NULL; 
                ptr = nw;
                size++;
            }
            else if (pos > 1 && pos <= size)
            {
                tmp = head;
                while (pos > 1)
                {
                    tmp = tmp->next;
                    pos--;
                }
                nw->next = tmp;
                nw->prev = tmp->prev;
                (tmp->prev)->next = nw;
                tmp->prev = nw;
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
            tmp = head;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            free(tmp);
            size--;
        }
        else if (pos == size)
        {
            tmp = ptr;
            ptr = ptr->prev;
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
            
            (tmp->prev)->next = tmp->next;
            (tmp->next)->prev = tmp->prev;
            free(tmp);
            size--;
        }
        else{
            printf("Invalid position\n");
        }
    }
}

int main(void) {
    insertion_at_specific_pos();
    insertion_at_specific_pos();
    delete_at_specific_pos();
    traverse();


    /* int option;
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

    return 0; */
}





