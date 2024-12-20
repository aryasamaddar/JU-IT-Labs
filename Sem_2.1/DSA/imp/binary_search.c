#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int binarySearch(Node *head, int key) {
    Node *slow = head;
    int length = 0;

    while (slow != NULL) {
        length++;
        slow = slow->next;
    }

    int start = 0, end = length - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        slow = head;
        for (int i = 0; i < mid; i++) {
            slow = slow->next;
        }

        if (slow->data == key) {
            return 1;  // Found the key
        }
        if (slow->data < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return 0;  // Key not found
}

int main() {
    Node *head = NULL;
    int key, choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Binary search\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key: ");
            scanf("%d", &key);
            if (binarySearch(head, key)) {
                printf("Found\n");
            } else {
                printf("Not found\n");
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
