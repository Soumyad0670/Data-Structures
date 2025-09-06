#include<stdio.h>
#include<stdlib.h>

int main() {
    struct node {
        int data;
        struct node *next;
    };
    struct node *head, *newnode, *temp; // Pointer to the head, newnode and temp of the linked list
    head = NULL;
    int choice = 1;
    
    while(choice) {
        newnode = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the new node
        printf("Enter data: ");
        scanf("%d", &newnode->data); // Read the data into the new node
        newnode->next = NULL; // Initialize the next pointer to NULL
        
        if(head == NULL) {
            head = temp = newnode;
        }
        else {
            temp->next = newnode; // Link the new node to the last node
            temp = newnode; // Move temp to the new node
        }
        printf("Do you want to continue(0 or 1): ");
        scanf("%d", &choice);
    }
    
    temp = head; // Set temp to head to traverse the list
    while(temp != NULL) {
        printf("%d\n", temp->data); // Print the data of the current node
        temp = temp->next; // Move to the next node
    } 
    printf("%d", &head); // Print the address of the head node
    return 0;
}