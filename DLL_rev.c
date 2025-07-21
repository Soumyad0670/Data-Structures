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

void ReverseList(){
    struct node *currentnode = head, *prevnode = 0, *nextnode = head;
    while(currentnode != 0){
        currentnode->prev = currentnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        nextnode = nextnode->prev;
        currentnode = nextnode;
    }
    head = prevnode;
}
void displayList() {
    temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    createList();
    printf("Original list:\n");
    displayList();
    printf("Reversing the list...\n");
    ReverseList();
    displayList();
    return 0;
}

