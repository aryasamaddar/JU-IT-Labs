#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Stack
{
    int top;
    int capacity;
    int *array;
} Stack;

Stack* createStack(int capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack)
    {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program if memory allocation fails
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    if (!stack->array)
    {
        printf("Memory allocation failed.\n");
        free(stack);
        exit(1); // Exit if memory allocation fails
    }
    return stack;
}

void evaluatePostfix(char *str)
{
    int len = strlen(str);
    if (len == 0)
    {
        printf("Error: Empty expression.\n");
        return;
    }

    Stack *stack = createStack(len);
    
    for (int i = 0; i < len; i++)
    {
        if (isdigit(str[i]))  // Check if the character is an operand
        {
            stack->array[++stack->top] = str[i] - '0';
        }
        else  // Operator
        {
            if (stack->top < 1) // Not enough operands for operation
            {
                printf("Error: Invalid postfix expression.\n");
                free(stack->array);
                free(stack);
                return;
            }
            int b = stack->array[stack->top--];  // Pop operand
            int a = stack->array[stack->top--];  // Pop operand

            switch (str[i])
            {
            case '+':
                stack->array[++stack->top] = a + b;
                break;
            case '-':
                stack->array[++stack->top] = a - b;
                break;
            case '*':
                stack->array[++stack->top] = a * b;
                break;
            case '/':
                if (b == 0)
                {
                    printf("Error: Division by zero.\n");
                    free(stack->array);
                    free(stack);
                    return;
                }
                stack->array[++stack->top] = a / b;
                break;
            default:
                printf("Error: Invalid operator '%c'.\n", str[i]);
                free(stack->array);
                free(stack);
                return;
            }
        }
    }

    if (stack->top != 0)  // There should be only one element in the stack after evaluation
    {
        printf("Error: Invalid postfix expression.\n");
        free(stack->array);
        free(stack);
        return;
    }

    printf("Result: %d\n", stack->array[stack->top]);
    free(stack->array);
    free(stack);
}

int main()
{
    int choice;
    char str[100];
    
    do
    {
        printf("\nMenu:\n");
        printf("1. Evaluate Postfix Expression\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter postfix expression: ");
            scanf("%s", str);
            evaluatePostfix(str);
            break;

        case 2:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 2);

    return 0;
}
