#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto the stack.\n", data);
}

void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        return;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    printf("Popped %d from the stack.\n", temp->data);
    free(temp);
}

void peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top of the stack: %d\n", top->data);
}

int countNodes(struct Node* top) {
    int count = 0;
    while (top != NULL) {
        count++;
        top = top->next;
    }
    return count;
}

void printStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* top = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Push onto the stack\n");
        printf("2. Pop from the stack\n");
        printf("3. Peek the top of the stack\n");
        printf("4. Count the number of elements in the stack\n");
        printf("5. Print the stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to push: ");
                scanf("%d", &data);
                push(&top, data);
                break;

            case 2:
                pop(&top);
                break;

            case 3:
                peek(top);
                break;

            case 4:
                printf("Number of elements in the stack: %d\n", countNodes(top));
                break;

            case 5:
                printStack(top);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
