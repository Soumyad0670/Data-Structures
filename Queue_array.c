#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1, size;

int isFull() {
    return rear == size - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front++]);
}

void peek() {
    if (isEmpty()) printf("Queue is empty!\n");
    else printf("Front element: %d\n", queue[front]);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, value;
    printf("Enter size of queue: ");
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
