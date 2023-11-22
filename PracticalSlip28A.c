#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

// Function to search for a node in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    
    if (key < root->data) {
        return search(root->left, key);
    }
    
    return search(root->right, key);
}

// Function to display the BST using post-order traversal
void displayPostOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    
    displayPostOrder(root->left);
    displayPostOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = NULL;
    
    // Create a Binary Search Tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    // Search for a node
    int key = 40;
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("%d found in the BST.\n", key);
    } else {
        printf("%d not found in the BST.\n", key);
    }
    
    // Display the BST using post-order traversal
    printf("Post-order Traversal: ");
    displayPostOrder(root);
    
    return 0;
}
