#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* moveLastToFirst(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node *secondLast = head;
    while (secondLast->next->next != NULL) {
        secondLast = secondLast->next;
    }

    Node *last = secondLast->next;
    secondLast->next = NULL;
    last->next = head;
    head = last;
    return head;
}

int main() {
    Node *head = NULL;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Move last node to first\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            head = moveLastToFirst(head);
            break;
        case 2:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
