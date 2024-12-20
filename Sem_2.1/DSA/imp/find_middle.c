#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void findMiddle(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Address of middle node: %p\n", (void *)slow);
}

int main() {
    Node *head = NULL;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Find middle node\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            findMiddle(head);
            break;
        case 2:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
