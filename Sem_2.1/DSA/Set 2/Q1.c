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

void insertNode(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) { 
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    if (position == 0) { 
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    for (int i = 0; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void reversePrintUtil(struct Node* head) {
    if (head == NULL) return;
    reversePrintUtil(head->next);
    printf("%d -> ", head->data);
}

void reversePrint(struct Node* head) {
    reversePrintUtil(head);
    printf("NULL\n");
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void createLinkedList(struct Node** head, int size) {
    printf("Enter %d values to create the linked list:\n", size);
    for (int i = 0; i < size; i++) {
        int value;
        scanf("%d", &value);
        insertNode(head, value, i);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, size, data, position;
    char ch;
    do {
        printf("\nMenu:\n");
        printf("0. Create Linked List\n");
        printf("a. Insert Node at a specified position\n");
        printf("b. Delete Node from a specified position\n");
        printf("c. Count the number of nodes\n");
        printf("d. Reverse Print the linked list\n");
        printf("e. Reverse the linked list\n");
        printf("f. Exit\n");
        printf("Enter your choice (0/a/b/c/d/e/f): ");
        

  
        scanf(" %c", &ch);

        switch (ch) {
            case '0':
                printf("Enter the size of the linked list: ");
                scanf("%d", &size);
                createLinkedList(&head, size);
                printf("Linked List created: ");
                printList(head);
                break;

            case 'a':
                printf("Enter the value and position to insert: ");
                scanf("%d %d", &data, &position);
                insertNode(&head, data, position);
                printf("After insertion: ");
                printList(head);
                break;

            case 'b':
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteNode(&head, position);
                printf("After deletion: ");
                printList(head);
                break;

            case 'c':
                printf("Number of nodes: %d\n", countNodes(head));
                break;

            case 'd':
                printf("Reverse Print: ");
                reversePrint(head);
                break;

            case 'e':
                reverseList(&head);
                printf("Linked List reversed: ");
                printList(head);
                break;

            case 'f':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (ch != 'f');

    return 0;
}
