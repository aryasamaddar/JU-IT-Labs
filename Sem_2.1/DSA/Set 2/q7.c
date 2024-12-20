#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define maximum size of the queue for array implementation

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Structure for Array-based Queue
typedef struct {
    int front, rear;
    int *arr;
} QueueArray;

// Create both Queue (Linked List and Array)
void createBoth(Node **head, QueueArray *queue) {
    *head = NULL;
    queue->arr = (int *)malloc(MAX * sizeof(int));
    queue->front = queue->rear = -1;
}

// Linked List Operations
Node *enqueueList(Node *head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

Node *dequeueList(Node *head) {
    if (head == NULL) {
        printf("Underflow: Queue is empty.\n");
        return head;
    }
    Node *temp = head;
    head = head->next;
    printf("Dequeued: %d\n", temp->data);  // Print the dequeued element
    free(temp);
    return head;
}

void displayList(Node *head) {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int countList(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Array-based Queue Operations
void enqueueArray(QueueArray *queue, int data) {
    if (queue->rear == MAX - 1) {
        printf("Overflow: Queue is full.\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->arr[++queue->rear] = data;
    }
}

void dequeueArray(QueueArray *queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Underflow: Queue is empty.\n");
    } else {
        printf("Dequeued: %d\n", queue->arr[queue->front]);
        queue->front++;
    }
}

void displayArray(QueueArray *queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue is empty.\n");
    } else {
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->arr[i]);
        }
        printf("\n");
    }
}

int countArray(QueueArray *queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        return 0;
    }
    return queue->rear - queue->front + 1;
}

// Main Menu
int main() {
    int choice, data;
    Node *head = NULL;
    QueueArray queue;
    createBoth(&head, &queue);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue in Linked List\n");
        printf("2. Dequeue from Linked List\n");
        printf("3. Display Linked List Queue\n");
        printf("4. Enqueue in Array\n");
        printf("5. Dequeue from Array\n");
        printf("6. Display Array Queue\n");
        printf("7. Count Elements in Linked List Queue\n");
        printf("8. Count Elements in Array Queue\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                head = enqueueList(head, data);
                break;
            case 2:
                head = dequeueList(head);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueueArray(&queue, data);
                break;
            case 5:
                dequeueArray(&queue);
                break;
            case 6:
                displayArray(&queue);
                break;
            case 7:
                printf("Number of elements in Linked List Queue: %d\n", countList(head));
                break;
            case 8:
                printf("Number of elements in Array Queue: %d\n", countArray(&queue));
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
