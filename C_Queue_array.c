#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int cqueue[MAX];
int front = -1, rear = -1, size;

int isFull() {
    return (front == 0 && rear == size - 1) || (rear + 1) % size == front;
}

int isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Circular Queue is full!\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % size;
    cqueue[rear] = value;
}

void dequeue() {
    if (isEmpty()) {
        printf("Circular Queue is empty!\n");
        return;
    }
    printf("Dequeued: %d\n", cqueue[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % size;
}

void peek() {
    if (isEmpty()) printf("Circular Queue is empty!\n");
    else printf("Front element: %d\n", cqueue[front]);
}

void display() {
    if (isEmpty()) {
        printf("Circular Queue is empty!\n");
        return;
    }
    printf("Circular Queue: ");
    int i = front;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    int choice, value;
    printf("Enter size of Circular Queue: ");
    scanf("%d", &size);

    while (1) {
        printf("\n1: Enqueue\n2: Dequeue\n3: Peek\n4: Display\n5: Empty\n6: Full\n7: Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &value); enqueue(value); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf(isEmpty() ? "Queue is empty\n" : "Queue is not empty\n"); break;
            case 6: printf(isFull() ? "Queue is full\n" : "Queue is not full\n"); break;
            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
