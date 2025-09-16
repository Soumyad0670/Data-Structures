#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) root = root->left;
    return root;
}
struct Node* findMax(struct Node* root) {
    while (root && root->right != NULL) root = root->right;
    return root;
}
void deleteTree(struct Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n--------------------------------------\n");
        printf("Binary Search Tree Menu\n");
        printf("--------------------------------------\n");
        printf("0. Quit\n");
        printf("1. Create (Insert)\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Search\n");
        printf("6. Find Smallest Element\n");
        printf("7. Find Largest Element\n");
        printf("8. Deletion of Tree\n");
        printf("--------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                printf("Exiting...\n");
                exit(0);
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("%d found in BST.\n", value);
                else
                    printf("%d not found in BST.\n", value);
                break;
            case 6:
                if (root) printf("Smallest: %d\n", findMin(root)->data);
                else printf("Tree is empty.\n");
                break;
            case 7:
                if (root) printf("Largest: %d\n", findMax(root)->data);
                else printf("Tree is empty.\n");
                break;
            case 8:
                deleteTree(root);
                root = NULL;
                printf("Tree deleted.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
