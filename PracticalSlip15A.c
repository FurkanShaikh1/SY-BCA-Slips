#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    char data;
    struct Stack* next;
};

struct Stack* createStack() {
    return NULL;
}

int isEmpty(struct Stack* top) {
    return (top == NULL);
}

void push(struct Stack** top, char data) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

char pop(struct Stack** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    char data = (*top)->data;
    struct Stack* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}

void infixToPostfix(char* infix) {
    struct Stack* stack = createStack();
    char postfix[100]; // Adjust the size as needed
    int postfixIndex = 0;

    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[postfixIndex++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (!isEmpty(stack) && stack->data != '(') {
                postfix[postfixIndex++] = pop(&stack);
            }
            if (!isEmpty(stack) && stack->data != '(') {
                printf("Invalid expression\n");
                exit(1);
            } else {
                pop(&stack); // Pop the '('
            }
        } else {
            while (!isEmpty(stack) && precedence(ch) <= precedence(stack->data)) {
                postfix[postfixIndex++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!isEmpty(stack)) {
        postfix[postfixIndex++] = pop(&stack);
    }

    postfix[postfixIndex] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[100]; // Adjust the size as needed
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
