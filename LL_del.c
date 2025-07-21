#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
int length = 0;
void createNode() {
    char choice;
    do {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        if (!newnode) {
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
        } else {
            struct node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
        length++;
        printf("Node inserted.\n");
        printf("Do you want to insert another node? (y/n): ");
        scanf(" %c", &choice);  
    } while (choice == 'y' || choice == 'Y');
}
int isEmpty() {
    return head == NULL;
}
void DeletefromBeg() {
    if (isEmpty()) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("Deleted from beginning.\n");
}
void DeletefromEnd() {
    if (isEmpty()) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Deleted the only node in the list.\n");
        return;
    }
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("Deleted from end.\n");
}
void DeletefromPos(int pos) {
    if (isEmpty()) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (pos < 1 || pos > length) {
        printf("Invalid Position. Current list length: %d\n", length);
        return;
    }
    if (pos == 1) {
        DeletefromBeg();
        return;
    }
    struct node *temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;
    struct node *nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
    printf("Deleted from position %d.\n", pos);
}
void displayList() {
    if (isEmpty()) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    printf("Current List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int choice, pos;
    while (1) {
    printf("\n----- MENU -----\n");
    printf("1. Insert Node\n");
    printf("2. Delete from Beginning\n");
    printf("3. Delete from End\n");
    printf("4. Delete from Position\n");
    printf("5. Display List\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d%*c", &choice); 
    switch (choice) {
        case 1:
            createNode();
            break;
        case 2:
            DeletefromBeg();
            break;
        case 3:
            DeletefromEnd();
            break;
        case 4:
            printf("Enter position to delete: ");
            scanf("%d%*c", &pos);
            DeletefromPos(pos);
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