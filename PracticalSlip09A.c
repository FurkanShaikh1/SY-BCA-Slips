#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for the stack
struct Stack {
    int top;
    int* array;
};

// Function to create a stack
struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->array = (int*)malloc(size * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

// Function to evaluate the postfix expression
int evaluatePostfix(char* expression, int* values) {
    struct Stack* stack = createStack(100); // You can adjust the size as needed

    for (int i = 0; expression[i]; i++) {
        if (isdigit(expression[i])) {
            push(stack, values[expression[i] - 'a']);
        } else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);

            switch (expression[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(stack);
}

int main() {
    char expression[100];
    int values[26];

    printf("Enter the postfix expression: ");
    scanf("%s", expression);

    for (int i = 0; i < 26; i++) {
        printf("Enter value for %c: ", 'a' + i);
        scanf("%d", &values[i]);
    }

    int result = evaluatePostfix(expression, values);
    printf("Answer: %d\n", result);

    return 0;
}
