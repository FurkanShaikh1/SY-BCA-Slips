#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform an inorder traversal of the tree
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    // Traverse the left subtree
    inorder(root->left);

    // Visit the current node
    printf("%d ", root->data);

    // Traverse the right subtree
    inorder(root->right);
}

// Function to perform a preorder traversal of the tree
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    // Visit the current node
    printf("%d ", root->data);

    // Traverse the left subtree
    preorder(root->left);

    // Traverse the right subtree
    preorder(root->right);
}

// Function to perform a postorder traversal of the tree
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    // Traverse the left subtree
    postorder(root->left);

    // Traverse the right subtree
    postorder(root->right);

    // Visit the current node
    printf("%d ", root->data);
}

int main() {
    // Creating a binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
