#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* findIntersection(Node *head1, Node *head2) {
    int len1 = 0, len2 = 0;
    Node *temp1 = head1, *temp2 = head2;

    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    int diff = len1 - len2;
    temp1 = head1;
    temp2 = head2;

    if (diff > 0) {
        for (int i = 0; i < diff; i++) {
            temp1 = temp1->next;
        }
    } else {
        for (int i = 0; i < -diff; i++) {
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 == temp2) {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return NULL;  // No intersection
}

int main() {
    Node *head1 = NULL, *head2 = NULL;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Find intersection\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            Node *intersection = findIntersection(head1, head2);
            if (intersection != NULL) {
                printf("Intersection at: %p\n", (void *)intersection);
            } else {
                printf("No intersection\n");
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
