#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next; 
    struct node *prev;
};
struct node *head, *newnode, *temp;
void createList(){
    head = 0;
    int choice = 1;
    while(choice){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data:\n");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        newnode->next = 0;
        if(head == 0){
            head=temp=newnode;
        }
        else{
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("Do you want to continue (0 or 1):\n");
        scanf("%d", &choice);
    }
}
void deletefrompos(int pos){
    if (head == NULL || pos < 1) {
        printf("Invalid position or empty list\n");
        return;
    }
    temp = head;
    if (pos == 1) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }
    int i = 1;
    while (i < pos) {
        temp = temp->next;
        i ++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    
}
int isEmpty() {
    return head == NULL;
}
void displayList() {
    if (isEmpty()) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    printf("Current List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int choice, pos;
    while (1) {
    printf("\n----- MENU -----\n");
    printf("1. Insert Node\n");
    printf("2. Delete from Position\n");
    printf("3. Display List\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d%*c", &choice); 
    switch (choice) {
        case 1:
            createList();
            break;
        case 2:
            printf("Enter position to delete: ");
            scanf("%d%*c", &pos);
            deletefrompos(pos);
            break;
        case 3:
            displayList();
            break;
        case 4:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice. Please select from 1 to 6.\n");
    }
}
    return 0;
}
