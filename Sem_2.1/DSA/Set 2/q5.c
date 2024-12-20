#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Stack {
    int top;
    int capacity;
    char *array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

int isOperand(char ch) {
    return isalnum(ch);
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return -1;
}

int isValid(char* exp) {
    for (int i = 0; i < strlen(exp); i++) {
        if (!isalnum(exp[i]) && strchr("+-*/^() ", exp[i]) == NULL) {
            return 0;  // Invalid character found
        }
    }
    return 1;
}

int hasMismatchedParentheses(char* exp) {
    struct Stack* stack = createStack(strlen(exp));
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(') {
            push(stack, exp[i]);
        } else if (exp[i] == ')') {
            if (isEmpty(stack)) {
                return 1;  // Mismatched closing parenthesis
            }
            pop(stack);
        }
    }
    return !isEmpty(stack);  // If stack is not empty, it means there's an unmatched opening parenthesis
}

void infixToPostfix(char* exp, char* postfix) {
    struct Stack* stack = createStack(strlen(exp));
    int k = 0;

    if (strlen(exp) == 0) {
        printf("Error: Empty expression!\n");
        return;
    }

    if (!isValid(exp)) {
        printf("Error: Invalid character in expression!\n");
        return;
    }

    if (hasMismatchedParentheses(exp)) {
        printf("Error: Mismatched parentheses!\n");
        return;
    }

    for (int i = 0; i < strlen(exp); i++) {
        if (isOperand(exp[i])) {
            postfix[k++] = exp[i];
        } else if (exp[i] == '(') {
            push(stack, exp[i]);
        } else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[k++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) == '(') {
                pop(stack);  // Pop '('
            }
        } else {  // Operator case
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack))) {
                if (exp[i] == '^' && peek(stack) == '^') break;  // Handle right-associativity of '^'
                postfix[k++] = pop(stack);
            }
            push(stack, exp[i]);
        }
    }

    while (!isEmpty(stack)) {
        postfix[k++] = pop(stack);
    }
    postfix[k] = '\0';
}

int main() {
    char exp[MAX];
    char postfix[MAX];
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Enter infix expression\n");
        printf("2. Convert infix to postfix\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter infix expression: ");
                scanf("%s", exp);
                break;

            case 2:
                infixToPostfix(exp, postfix);
                if (strlen(postfix) > 0) {
                    printf("Postfix expression: %s\n", postfix);
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
