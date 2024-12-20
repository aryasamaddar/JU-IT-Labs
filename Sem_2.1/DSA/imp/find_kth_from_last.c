#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void findKthFromLast(Node *head, int k) {
    Node *temp = head;
    int length = 0;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    if (k > length) {
        printf("Invalid position\n");
        return;
    }

    temp = head;
    for (int i = 1; i < length - k + 1; i++) {
        temp = temp->next;
    }

    printf("Address of %dth node from the last: %p\n", k, (void *)temp);
}

int main() {
    Node *head = NULL;
    int choice, k;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Find kth node from the last\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter k: ");
            scanf("%d", &k);
            findKthFromLast(head, k);
            break;
        case 2:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
