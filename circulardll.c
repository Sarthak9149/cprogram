#include <stdio.h>
#include <stdlib.h>

// Define the node structure (Assuming this is defined globally or in a header)
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

// Global Pointers and variables (Assuming these are defined globally)
struct node *head = NULL;
struct node *ptr = NULL; // ptr is typically used to point to the last node
int size = 0;
int pos;
struct node *tmp;
struct node *nw;

// --- CORRECTED TRAVERSE FUNCTION ---
void traverse(){
    if (head == NULL) {
        printf("Underflow: List is empty\n");
        return;
    }
    
    tmp = head;
    printf("List elements: ");
    
    do {
        printf("%d\t", tmp->data);
        tmp = tmp->next;
    } while (tmp != head); // Traverse until we loop back to head
    
    printf("\n");
}

// --- CORRECTED INSERTION FUNCTION ---
void insertion_at_specific_pos(){
    int val;
    nw = (struct node*)(malloc(sizeof(struct node)));
    if (nw == NULL)
    {
        printf("Overflow: Memory allocation failed.\n");
        exit(0); 
    }

    else{
        printf("Enter Data\t");
        scanf("%d", &val);
        nw->data = val;
        if (head == NULL) // Case 1: Empty List
        {
            nw->next = nw;
            nw->prev = nw;
            head = nw;
            ptr = nw; // ptr (last node) is also nw
            size++;
            printf("Node inserted at beginning.\n");
        }
        else // Case 2: Non-empty list
        { 
            printf("Enter position to insert\n");
            scanf("%d", &pos);

            // Case 2a: Insertion at the beginning (pos == 1)
            if (pos == 1)
            {
                nw->next = head;
                nw->prev = ptr;      // New node's prev points to the last node
                head->prev = nw;     // Old head's prev points to the new node
                ptr->next = nw;      // Last node's next points to the new node
                head = nw;           // Update head
                size++;
                printf("Node inserted at position 1.\n");
            }
            // Case 2b: Insertion at the end (pos > size) or last element (pos == size + 1)
            else if (pos > size) 
            {
                // We traverse to the end, which is ptr
                nw->next = head;     // New node's next points to head
                nw->prev = ptr;      // New node's prev points to current last node
                ptr->next = nw;      // Current last node's next points to new node
                head->prev = nw;     // Head's prev points to new node
                ptr = nw;            // Update the last node pointer
                size++;
                printf("Node inserted at the end.\n");
            }
            // Case 2c: Insertion in the middle (1 < pos <= size)
            else if (pos > 1 && pos <= size)
            {
                tmp = head;
                for (int i = 1; i < pos - 1; i++) // Stop at the node *before* the insertion point
                {
                    tmp = tmp->next;
                }
                
                // New node links
                nw->next = tmp->next;
                nw->prev = tmp;
                
                // Neighbor links
                (tmp->next)->prev = nw;
                tmp->next = nw;
                
                size++;
                printf("Node inserted at position %d.\n", pos);
            }
            else{
                printf("Invalid position\n");
                free(nw); // Free the allocated node if insertion fails
            }
        }
    }
}

// --- CORRECTED DELETION FUNCTION ---
void delete_at_specific_pos(){
    if (head == NULL){
        printf("Underflow: List is empty\n");
        return;
    }
    else{    
        printf("Enter position to delete (1 to %d)\t", size);
        scanf("%d", &pos);
    // Check for single node case before checking pos > size
        if (size == 1 && pos == 1) 
        {
            free(head);
            head = NULL;
            ptr = NULL;
            size = 0; // Set size to 0
            printf("The only node has been deleted.\n");
            return;
        }
        
        if (pos < 1 || pos > size)
        {
            printf("Invalid position\n");
            return;
        }

        // Case 1: Delete head (pos == 1)
        if (pos == 1){
            tmp = head;
            head = head->next;      // Move head to the next node
            ptr->next = head;       // Last node's next points to new head
            head->prev = ptr;       // New head's prev points to last node
            free(tmp);
            size--;
            printf("Node at position 1 deleted.\n");
        }
        // Case 2: Delete last node (pos == size)
        else if (pos == size)
        {
            tmp = ptr;
            ptr = ptr->prev;        // ptr moves to the second-to-last node
            ptr->next = head;       // New last node's next points to head
            head->prev = ptr;       // Head's prev points to new last node
            free(tmp);
            size--;
            printf("Node at position %d deleted.\n", pos);
        }
        // Case 3: Delete middle node (1 < pos < size)
        else 
        {
            tmp = head;
            for (int i = 1; i < pos; i++)
            {
                tmp = tmp->next;
            }
            
            (tmp->prev)->next = tmp->next;
            (tmp->next)->prev = tmp->prev;
            free(tmp);
            size--;
            printf("Node at position %d deleted.\n", pos);
        }
    }
}

int main(void) {
    // ... main function remains the same ...
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