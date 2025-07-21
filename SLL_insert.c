#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next; 
};
struct node* createList() {
    int l = 0;
    struct node *head = NULL;
    struct node *temp = NULL;
    int choice = 1;
    while(choice) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        l ++;
        printf("Want to add more nodes? (1/0): ");
        scanf("%d", &choice);
    }
    return head;
}
struct node* insertAtPosition(struct node* head, int position) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    struct node* temp = head;
    if (position == 1) {
        head = newnode;
        newnode->next = temp;
    }
    int i = 1;
    while (i < position - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newnode);
        return head;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}
int main() {
    printf("Create your linked list:\n");
    struct node* head = createList();
    int position;
    printf("\nEnter the position where you want to insert (1-based indexing): ");
    scanf("%d", &position);
    head = insertAtPosition(head, position); 
    printf("\nLinked list after insertion: ");
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return 0;
}