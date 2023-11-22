#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a stack node
struct StackNode {
    char data;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* createStackNode(char data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a character onto the stack
void push(struct StackNode** top, char data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a character from the stack
char pop(struct StackNode** top) {
    if (*top == NULL) {
        return '\0'; // Empty stack
    }
    struct StackNode* temp = *top;
    *top = (*top)->next;
    char data = temp->data;
    free(temp);
    return data;
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    struct StackNode* stack = NULL;

    // Push characters onto the stack
    for (int i = 0; i < len; i++) {
        push(&stack, str[i]);
    }

    // Pop and compare characters
    for (int i = 0; i < len; i++) {
        char ch = pop(&stack);
        if (ch != str[i]) {
            return 0; // Not a palindrome
        }
    }

    return 1; // Palindrome
}

int main() {
    char input[100];
    
    printf("Enter a string: ");
    scanf("%s", input);
    
    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    
    return 0;
}
