#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for a stack node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node for the stack
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a value onto the stack
void push(struct Node** stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *stack;
    *stack = newNode;
}

// Function to pop a value from the stack
int pop(struct Node** stack) {
    if (*stack == NULL) {
        printf("Stack underflow: Attempted to pop an empty stack.\n");
        exit(1);
    }
    struct Node* temp = *stack;
    *stack = temp->next;
    int data = temp->data;
    free(temp);
    return data;
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    struct Node* stack = NULL;
    int i = 0;
    
    while (expression[i] != '\0') {
        if (isdigit(expression[i])) {
            // If the current character is a digit, push it onto the stack
            push(&stack, expression[i] - '0'); // Convert char to int
        } else {
            // If the current character is an operator, pop two operands and perform the operation
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid character in expression: %c\n", expression[i]);
                    exit(1);
            }
        }
        i++;
    }
    
    if (stack == NULL || stack->next != NULL) {
        printf("Invalid postfix expression.\n");
        exit(1);
    }
    
    int result = pop(&stack);
    return result;
}

int main() {
    char expression[100];
    printf("Enter a postfix expression: ");
    gets(expression); // Use gets for simplicity, but it's not recommended in practice
    
    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);
    
    return 0;
}
