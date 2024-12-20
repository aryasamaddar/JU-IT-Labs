#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *arr;
    int top;
    int size;
} Stack;

typedef struct Queue {
    Stack *s1;
    Stack *s2;
    int currentSize;
} Queue;

Stack *createStack(int size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->size * sizeof(int));
    return stack;
}

int isFull(Stack *stack) {
    return stack->top == stack->size - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int data) {
    if (!isFull(stack)) {
        stack->arr[++stack->top] = data;
    }
}

int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return -1; // Return -1 if the stack is empty
}

Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->s1 = createStack(size);
    queue->s2 = createStack(size);
    queue->currentSize = 0; // Initialize current size to 0
    return queue;
}

int isQueueFull(Queue *queue) {
    return queue->currentSize == queue->s1->size;
}

void enqueue(Queue *queue, int data) {
    if (isQueueFull(queue)) {
        printf("Overflow! Queue is full.\n");
    } else {
        push(queue->s1, data);
        queue->currentSize++; // Increment the current size
    }
}

int dequeue(Queue *queue) {
    if (isEmpty(queue->s1) && isEmpty(queue->s2)) {
        printf("Underflow! Queue is empty.\n");
        return -1; // Indicate underflow
    }

    if (isEmpty(queue->s2)) {
        while (!isEmpty(queue->s1)) {
            push(queue->s2, pop(queue->s1));
        }
    }
    queue->currentSize--; // Decrement current size
    return pop(queue->s2);
}

void inputQueue(Queue *queue, int n) {
    if (queue->currentSize + n > queue->s1->size) {
        printf("Cannot enqueue %d elements. It will exceed the queue size of %d.\n", n, queue->s1->size);
        return; // Exit the function if the user tries to enqueue more than the available space
    }

    int data;
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        enqueue(queue, data);
    }
}

void displayQueue(Queue *queue) {
    if (isEmpty(queue->s1) && isEmpty(queue->s2)) {
        printf("Queue is empty\n");
        return;
    }
    
    if (isEmpty(queue->s2)) {
        while (!isEmpty(queue->s1)) {
            push(queue->s2, pop(queue->s1));
        }
    }
    
    printf("Queue contents: ");
    for (int i = queue->s2->top; i >= 0; i--) {
        printf("%d ", queue->s2->arr[i]);
    }
    printf("\n");
}

int main() {
    int size, n, choice;
    Queue *queue;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    queue = createQueue(size);

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements to enqueue: ");
                scanf("%d", &n);
                inputQueue(queue, n);
                break;

            case 2:
                {
                    int dequeued = dequeue(queue);
                    if (dequeued != -1) {
                        printf("Dequeued: %d\n", dequeued);
                    }
                }
                break;

            case 3:
                displayQueue(queue);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
