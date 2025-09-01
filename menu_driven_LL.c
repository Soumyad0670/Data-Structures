#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void createLinkedList(int n) {
    struct Node *temp, *newNode;
    int value;
    head = NULL;
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

void traverseList() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtPosition(int value, int pos) {
    if (pos <= 1) {
        insertAtBeginning(value);
        return;
    }
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (pos <= 1) {
        deleteAtBeginning();
        return;
    }
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }
    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void deleteByKey(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->data == key) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;
    if (temp->next == NULL) {
        printf("Key not found.\n");
        return;
    }
    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

int countNodes() {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int searchElement(int key) {
    struct Node *temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

int isEmpty() {
    return head == NULL;
}

int main() {
    int choice, value, pos, key, n;
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    createLinkedList(n);
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Traverse\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Insert at position\n");
        printf("5. Delete at beginning\n");
        printf("6. Delete at end\n");
        printf("7. Delete at position\n");
        printf("8. Delete by key\n");
        printf("9. Count nodes\n");
        printf("10. Search element\n");
        printf("11. Check if empty\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverseList();
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 4:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertAtPosition(value, pos);
                break;
            case 5:
                deleteAtBeginning();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 8:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteByKey(key);
                break;
            case 9:
                printf("Total nodes: %d\n", countNodes());
                break;
            case 10:
                printf("Enter element to search: ");
                scanf("%d", &key);
                pos = searchElement(key);
                if (pos == -1)
                    printf("Element not found.\n");
                else
                    printf("Element found at position %d\n", pos);
                break;
            case 11:
                if (isEmpty())
                    printf("List is empty.\n");
                else
                    printf("List is not empty.\n");
                break;
            case 12:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
