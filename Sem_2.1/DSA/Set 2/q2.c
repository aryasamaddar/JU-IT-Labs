#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createCircularLinkedList(int n) {
    Node* head = NULL;
    Node* temp = NULL;
    Node* current = NULL;

    for (int i = 1; i <= n; i++) {
        temp = createNode(i);
        if (head == NULL) {
            head = temp;
            current = head;
        } else {
            current->next = temp;
            current = current->next;
        }
        current->next = head;  
    }
    return head;
}

int josephus(int n, int k) {
    Node* head = createCircularLinkedList(n);
    Node* prev = NULL;
    Node* current = head;

    while (current->next != current) {
        for (int i = 1; i < k; i++) {
            prev = current;
            current = current->next;
        }

        printf("Person at position %d is eliminated.\n", current->data);
        prev->next = current->next;
        free(current);
        current = prev->next;
    }

    int result = current->data;
    free(current);  
    return result;
}

void printCircularLinkedList(Node* head) {
    if (!head) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    int choice, n, k;
    Node* head = NULL;

    do {
        printf("\nMenu:\n");
        printf("0. Create Circular Linked List\n");
        printf("1. Display Circular Linked List\n");
        printf("2. Solve Josephus Problem\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Enter the number of people to create the list: ");
                scanf("%d", &n);
                head = createCircularLinkedList(n);
                printf("Circular Linked List created.\n");
                break;

            case 1:
                printf("Circular Linked List: ");
                printCircularLinkedList(head);
                break;

            case 2:
                if (head == NULL) {
                    printf("Create the circular linked list first!\n");
                    break;
                }
                printf("Enter the step count (k): ");
                scanf("%d", &k);
                printf("Solving Josephus Problem...\n");
                int survivor = josephus(n, k);
                printf("The last remaining person is at position %d\n", survivor);
                head = NULL;  // List is destroyed after solving
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
