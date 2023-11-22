#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

char stack[MAX_STACK_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(char item) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("Stack overflow!\n");
    } else {
        stack[++top] = item;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return 0;
    } else {
        return stack[top--];
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to return the precedence of an operator
int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    }
    return 0;
}

// Function to convert infix to prefix
void infixToPrefix(char infix[], char prefix[]) {
    int i, j = 0;
    for (i = strlen(infix) - 1; i >= 0; i--) {
        char ch = infix[i];
        if (ch == ')') {
            push(ch);
        } else if (ch == '(') {
            while (top != -1 && stack[top] != ')') {
                prefix[j++] = pop();
            }
            if (top != -1) {
                pop(); // Pop the closing parenthesis
            }
        } else if (isOperator(ch)) {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                prefix[j++] = pop();
            }
            push(ch);
        } else {
            prefix[j++] = ch;
        }
    }
    while (top != -1) {
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
    // Reverse the result to get the correct prefix expression
    strrev(prefix);
}

int main() {
    char infix[100], prefix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
