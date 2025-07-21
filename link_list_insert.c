#include<stdio.h>
#include<stdlib.h>

struct node { // Define the structure for a node in the linked list
    int data;
    struct node *next; // Pointer to the next node in the linked list
};

struct node* createList() { // Function to create a linked list
    struct node *head = NULL; // Pointer to the head of the linked list
    struct node *temp = NULL; // Temporary pointer to traverse the list
    int choice = 1;
    
    while(choice) { // Loop to add nodes to the linked list
        struct node *newnode = (struct node*)malloc(sizeof(struct node)); // Allocate memory for a new node
        printf("Enter data: ");
        scanf("%d", &newnode->data); // Read data from user and store it in the new node
        newnode->next = NULL; // Initialize the next pointer of the new node to NULL
        
        if(head == NULL) {
            head = temp = newnode; // If the list is empty, set head and temp to the new node
        } else {
            temp->next = newnode; // Link the new node to the last node
            temp = newnode; // Move temp to the new node
        }
        
        printf("Want to add more nodes? (1/0): ");
        scanf("%d", &choice); // Ask user if they want to continue adding nodes
    }
    return head; // Return the head of the linked list to insertAtPosition function
}

// Function to insert at ith position
struct node* insertAtPosition(struct node* head, int position) { // Function to insert a new node at a specified position in the linked list
    struct node* newnode = (struct node*)malloc(sizeof(struct node)); // Allocate memory for the new node
    printf("\nEnter the data you want to insert at position %d: ", position);
    scanf("%d", &newnode->data);
    newnode->next = NULL; // Initialize the next pointer of the new node to NULL

    if (position < 1) { // Check if the position is valid (1-based indexing)
        printf("Invalid position!\n");
        return head; // If the position is invalid, return the current head without inserting
    }

    if (position == 1) { // If the position is 1, insert at the beginning
        newnode->next = head; // Point the new node's next to the current head
        return newnode; // Return the new node as the new head of the linked list
    }
    
    struct node* current = head; // Pointer to traverse the linked list
    int count = 1;
    while (count < position - 1 && current != NULL) { // Traverse the list to find the position before the desired position
        current = current->next; // Move to the next node
        count++; // Increment the count
    }
    
    if (current == NULL) { // If current is NULL, it means the position exceeds the length of the list
        printf("Position exceeds list length!\n");
        free(newnode); // Free the allocated memory for the new node
        return head;  // Return the current head without inserting
    }
    
    newnode->next = current->next; // Point the new node's next to the current node's next
    current->next = newnode; // Link the current node to the new node
    return head;
}

int main() {
    printf("Create your linked list:\n");
    struct node* head = createList();
    
    // Get position from user
    int position;
    printf("\nEnter the position where you want to insert (1-based indexing): ");
    scanf("%d", &position);
    
    // Insert at specified position
    head = insertAtPosition(head, position); // Call the function to insert a new node at the specified position
    
    // Display the linked list
    printf("\nLinked list after insertion: ");
    struct node* current = head; // Pointer to traverse the linked list
    while(current != NULL) { // Traverse the linked list
        printf("%d ", current->data); // Print the data of the current node
        current = current->next; // Move to the next node
    }
    
    getchar(); // To consume the newline character left by scanf
    getchar(); // Wait for user input before exiting
    return 0;
}