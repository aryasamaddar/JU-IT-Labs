#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int detectCycle(Node *head) {
    if (head == NULL) return 0;

    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;  // Cycle detected
        }
    }
    return 0;  // No cycle
}

int main() {
    Node *head = NULL;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Detect cycle\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (detectCycle(head)) {
                printf("Cycle detected\n");
            } else {
                printf("No cycle\n");
            }
            break;
        case 2:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
