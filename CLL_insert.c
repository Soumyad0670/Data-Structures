#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
} *tail = NULL;
int isEmpty() {
    return tail == NULL;
}
void createList() {
    int choice = 1;
    while(choice) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(tail == NULL) {
            tail = newnode;
            tail->next = tail;
        } else {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
        printf("Do you want to continue (0 or 1): ");
        scanf("%d", &choice);
    }
}
void insertatbeg() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data to insert at beginning: ");
    scanf("%d", &newnode->data);
    if(tail == NULL) {
        tail = newnode;
        tail->next = newnode;
    } else {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}
void insertatend() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data to insert at end: ");
    scanf("%d", &newnode->data);
    if(tail == NULL) {
        tail = newnode;
        tail->next = newnode;
    } else {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}
void insertatpos(int pos) {
    if (pos < 1) {
        printf("Invalid position. Position should be >= 1.\n");
        return;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data to insert at position %d: ", pos);
    scanf("%d", &newnode->data);
    if (tail == NULL) {
        if (pos != 1) {
            printf("List is empty. Can only insert at position 1.\n");
            free(newnode);
            return;
        }
        tail = newnode;
        tail->next = tail;
        return;
    }
    struct node *current = tail->next;
    int count = 1;
    if (pos == 1) {
        newnode->next = tail->next;
        tail->next = newnode;
        return;
    }
    while (count < pos - 1 && current != tail) {
        current = current->next;
        count++;
    }
    if (count == pos - 1) {
        newnode->next = current->next;
        current->next = newnode;
        if (current == tail) {
            tail = newnode;
        }
    } else {
        printf("Position out of bounds.\n");
        free(newnode);
    }
}
void displayList() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = tail->next; 
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("(%d back to head)\n", tail->next->data);
}
int main() {
    int choice, pos;
    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Create list\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                insertatbeg();
                break;
            case 3:
                insertatend();
                break;
            case 4:
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                insertatpos(pos);
                break;
            case 5:
                displayList();
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please select from 1 to 6.\n");
        }
    }
    return 0;
}
