#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *ptr = NULL;
struct node *nw = NULL;
struct node *tmp = NULL;
struct node *next_pointer = NULL;
int size = 0;

// Display the linked list
void traverseSLL() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    tmp = start;
    printf("Linked List: ");
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}


int insert_at_specific_pos(){
    int pos,i=1;
    nw = (struct node*)malloc(sizeof(struct node));
    if (nw == NULL)
    {
        printf("\nOverflow");
        return 1;
    }
    else {
        int val;
        printf("enter data\t");
        scanf("%d", &val);
        nw->next = NULL;
        nw->data = val;
        if (start == NULL)
        {
            start = nw;
            ptr = nw;
            size++;
            return 0;
        }
        else {
            printf("Enter position\t");
            scanf("%d", &pos);
            if (pos == 1)
            {
                nw->next = start;
                start = nw;
                size++;
                return 0;
            }
            else if (pos > size)
            {
                ptr->next = nw;
                ptr = nw;
                size++;
                return 0;
            }
            else if (pos > 1 && pos <=size)
            {
                tmp = start;
                while (i < pos -1)
                {
                    tmp = tmp->next;
                    i++;
                }
                nw->next = tmp->next;
                tmp->next = nw;
                size++;
                return 0;
            }
            else {
                printf("Invalid position");
                free(nw);
                return 1;
            }
        } 
    }
}



void delete_at_specific_pos(){
    int pos,i=1;
    if (start == NULL)
    {
        printf("Underflow");
    }
    else {
        printf("Enter position to delete\t");
        scanf("%d", &pos);
        if (pos == 1)
        {
           tmp = start;
           start = start->next;
           printf("Deleted element is %d\n", tmp->data);
           free(tmp);
           size--;
        }
        else if (pos ==size){
            tmp = start;
            while (i < size -1)
            {
                tmp = tmp->next;
                i++;
            }
            printf("Deleted element is %d\n", ptr->data);
            tmp->next = NULL;
            free(ptr);
            ptr = tmp;
            size--;
        }
        else if (pos > 1 && pos < size)
        {
            tmp = start;
            while (i < pos -1)
            {
                tmp = tmp->next;
                i++;
            }
            printf("Deleted element is %d\n", tmp->next->data);
            next_pointer = tmp->next;
            tmp->next = next_pointer->next;
            free(next_pointer);
            size--;

        }
        else {
            printf("Invalid position");
            
        }
    }
}

int main(void){
    insert_at_specific_pos();
    insert_at_specific_pos();
    delete_at_specific_pos();
    traverseSLL();
}




// Function declarations
/* int insert_at_specific_pos();
void traverseSLL();
void delete_at_specific_pos(); */
/* 
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
            case 1: insert_at_specific_pos();
                    break;
            case 2: traverseSLL();
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
 */