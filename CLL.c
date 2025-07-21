#include<stdio.h>
#include<stdlib.h>

int main() {
    struct node {
        int data;
        struct node *next;
    };
    struct node *head, *newnode, *temp; 
    head = NULL;
    int choice = 1;
    
    while(choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data); 
        newnode->next = NULL; 
        
        if(head == NULL) {
            head = temp = newnode;
        }
        else {
            temp->next = newnode;
            temp = newnode; 
        }
        temp->next = head;
        printf("Do you want to continue(0 or 1): ");
        scanf("%d", &choice);
    }
    
    temp = head; 
    while(temp->next != head) {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("%d", head->data);
    return 0;
}