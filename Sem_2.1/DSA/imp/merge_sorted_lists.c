#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* mergeSortedLists(Node *head1, Node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    if (head1->data < head2->data) {
        head1->next = mergeSortedLists(head1->next, head2);
        return head1;
    } else {
        head2->next = mergeSortedLists(head1, head2->next);
        return head2;
    }
}

int main() {
    Node *head1 = NULL, *head2 = NULL;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Merge sorted lists\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            head1 = mergeSortedLists(head1, head2);
            break;
        case 2:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
