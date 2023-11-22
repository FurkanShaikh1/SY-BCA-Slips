#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree
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

// Function to count the number of nodes in the binary search tree
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count the degree of the tree
int countDegree(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDegree = countDegree(root->left);
    int rightDegree = countDegree(root->right);
    int degree = (leftDegree > rightDegree) ? leftDegree : rightDegree;
    if (root->left && root->right) {
        degree++;
    }
    return degree;
}

// Function to count the number of leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to display the counts
void displayCounts(struct Node* root) {
    if (root == NULL) {
        printf("Number of nodes: 0\n");
        printf("Degree of tree: 0\n");
        printf("Leaf nodes: 0\n");
        return;
    }

    int nodes = countNodes(root);
    int degree = countDegree(root);
    int leafNodes = countLeafNodes(root);

    printf("Number of nodes: %d\n", nodes);
    printf("Degree of tree: %d\n", degree);
    printf("Leaf nodes: %d\n", leafNodes);
}

int main() {
    struct Node* root = NULL;
    int n, data;
    
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    
    printf("Enter the integers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }
    
    displayCounts(root);
    
    return 0;
}
