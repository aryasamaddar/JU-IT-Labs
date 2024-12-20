#include <stdio.h>
#include <stdlib.h>

typedef struct CNode {
    int data;
    struct CNode *next, *prev;
} CNode;

CNode* addNodeAtEnd(CNode *head, int data) {
    CNode *newNode = (CNode *)malloc(sizeof(CNode));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode->prev = newNode;
        return newNode;
    }

    CNode *temp = head->prev;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
    head->prev = newNode;

    return head;
}

int main() {
    CNode *head = NULL;
    int data, choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add node to circular doubly linked list\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            head = addNodeAtEnd(head, data);
            break;
        case 2:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
