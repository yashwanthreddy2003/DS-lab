#include <stdio.h>
#include <stdlib.h>

// Define the structure for the binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node
struct Node* makeTree() {
    struct Node* newNode; // Pointer to the newly created node
    int info; // Variable to hold user input

    // Prompt user to enter data for the new node or -1 to make it a null node
    printf("Enter the info or -1 for null\n");
    scanf("%d", &info);

    // If user enters -1, return null to make the current node a null node
    if (info == -1) {
        return NULL;
    }

    // Allocate memory for the new node
    newNode = (struct Node*)malloc(sizeof(struct Node));

    // Set the data value for the new node
    newNode->data = info;

    // Prompt user to enter data for the left child of the new node
    printf("Enter the left child of %d\n", info);
    newNode->left = makeTree(); // Recursively call makeTree to create the left subtree

    // Prompt user to enter data for the right child of the new node
    printf("Enter the right child of %d\n", info);
    newNode->right = makeTree(); // Recursively call makeTree to create the right subtree

    // Return the pointer to the newly created node
    return newNode;
}

// Function to perform pre-order traversal of the binary tree
void preOrder(struct Node* node) {
    if (node != NULL) {
        // Visit the root node
        printf("%d->", node->data);
        // Traverse the left subtree
        preOrder(node->left);
        // Traverse the right subtree
        preOrder(node->right);
    }
}

// Function to perform post-order traversal of the binary tree
void postOrder(struct Node* node) {
    if (node != NULL) {
        // Traverse the left subtree
        postOrder(node->left);
        // Traverse the right subtree
        postOrder(node->right);
        // Visit the root node
        printf("%d->", node->data);
    }   
}

// Function to perform in-order traversal of the binary tree
void inOrder(struct Node* node) {
    if (node != NULL) {
        // Traverse the left subtree
        inOrder(node->left);
        // Visit the root node
        printf("%d->", node->data);
        // Traverse the right subtree
        inOrder(node->right);
    }
}

int main() {
    struct Node* root; // Pointer to the root node of the binary tree
    root = makeTree(); // Create the binary tree
    printf("Preorder: ");
    preOrder(root); // Traverse the binary tree in pre-order
    printf("\nPostorder: ");
    postOrder(root); // Traverse the binary tree in post-order
    printf("\nInorder: ");
    inOrder(root); // Traverse the binary tree in in-order
    return 0;
}