#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void convertToCircular(struct Node *head) {
    if(head == NULL) {
        return;
    }
    struct Node* temp = head;
    while(temp->next == NULL) {
        temp = temp->next;
    }
    temp->next = head;
}
void display(struct Node* head, int count) {
    struct Node* temp = head;
    int i = 0;

    while (temp != NULL && i < count) {
        printf("%d ", temp->data);
        temp = temp->next;
        i++;
    }
    printf("...\n");
}
int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    printf("Before conversion (singly linked list):\n");
    display(head, 4);
    convertToCircular(head);
    printf("After conversion (circular linked list):\n");
    display(head, 10); 
    return 0;
}