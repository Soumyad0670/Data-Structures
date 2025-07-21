#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_at_end(int value) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    new_node->data = value;
    new_node->next = NULL;
    
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

struct node* delete_from_position(int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    if (position < 1) {
        printf("Invalid position!\n");
        return head;
    }
    
    struct node *temp = head;
    
    if (position == 1) {
        head = head->next;
        free(temp);
        return head;
    }
    
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("Position exceeds list length!\n");
        return head;
    }
    
    struct node *to_delete = temp->next;
    temp->next = temp->next->next;
    free(to_delete);
    return head;
}

void display_list() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void free_list() {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, value, position;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid number of elements!\n");
        return 1;
    }
    
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert_at_end(value);
    }
    
    printf("Initial ");
    display_list();
    
    printf("Enter the position to delete (1 to %d): ", n);
    scanf("%d", &position);
    
    delete_from_position(position);
    printf("After deleting position %d: ", position);
    display_list();
    
    free_list();
    return 0;
}
