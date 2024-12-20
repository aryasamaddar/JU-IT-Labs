#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct MultiStack {
    int arr[MAX];
    int top1, top2, top3;
} MultiStack;

void init(MultiStack *stack) {
    stack->top1 = -1;
    stack->top2 = MAX / 3 - 1;
    stack->top3 = 2 * MAX / 3 - 1;
}

void push(MultiStack *stack, int stackNumber, int value) {
    switch (stackNumber) {
    case 1:
        if (stack->top1 < MAX / 3 - 1) {
            stack->arr[++stack->top1] = value;
        } else {
            printf("Stack 1 Overflow\n");
        }
        break;
    case 2:
        if (stack->top2 < 2 * MAX / 3 - 1) {
            stack->arr[++stack->top2] = value;
        } else {
            printf("Stack 2 Overflow\n");
        }
        break;
    case 3:
        if (stack->top3 < MAX - 1) {
            stack->arr[++stack->top3] = value;
        } else {
            printf("Stack 3 Overflow\n");
        }
        break;
    default:
        printf("Invalid Stack Number\n");
        break;
    }
}

int pop(MultiStack *stack, int stackNumber) {
    switch (stackNumber) {
    case 1:
        if (stack->top1 == -1) {
            printf("Stack 1 Underflow\n");
            return -1;
        } else {
            return stack->arr[stack->top1--];
        }
    case 2:
        if (stack->top2 == MAX / 3 - 1) {
            printf("Stack 2 Underflow\n");
            return -1;
        } else {
            return stack->arr[stack->top2--];
        }
    case 3:
        if (stack->top3 == 2 * MAX / 3 - 1) {
            printf("Stack 3 Underflow\n");
            return -1;
        } else {
            return stack->arr[stack->top3--];
        }
    default:
        printf("Invalid Stack Number\n");
        return -1;
    }
}

int main() {
    MultiStack stack;
    init(&stack);
    int choice, stackNumber, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push to stack\n");
        printf("2. Pop from stack\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter stack number (1-3): ");
            scanf("%d", &stackNumber);
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&stack, stackNumber, value);
            break;
        case 2:
            printf("Enter stack number (1-3): ");
            scanf("%d", &stackNumber);
            printf("Popped value: %d\n", pop(&stack, stackNumber));
            break;
        case 3:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
