#include <stdio.h>
#include <stdlib.h>

// Define structure for a queue node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure for Queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Enqueue function
void enqueue(Queue* q, int value) {
    Node* newNode = createNode(value);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued %d (Address: %p)\n", value, (void*)newNode);
}

// Dequeue function
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow! (Queue is empty)\n");
        return -1;
    }

    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    // If front becomes NULL, rear should also be NULL
    if (q->front == NULL)
        q->rear = NULL;

    printf("Dequeued %d (Address freed: %p)\n", value, (void*)temp);
    free(temp);
    return value;
}

// Peek function
void peek(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d (Address: %p)\n", q->front->data, (void*)q->front);
    }
}

// Display function
void display(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    Node* temp = q->front;
    printf("Queue (front → rear):\n");
    while (temp != NULL) {
        printf("Data: %d (Address: %p)\n", temp->data, (void*)temp);
        temp = temp->next;
    }
}

// Delete all elements divisible by 3
void deleteDivBy3(Queue* q) {
    Node* curr = q->front;
    Node* prev = NULL;

    while (curr != NULL) {
        if (curr->data % 3 == 0) {
            printf("Deleting node %d (Address: %p)\n", curr->data, (void*)curr);
            if (prev == NULL) {
                q->front = curr->next;
                free(curr);
                curr = q->front;
            } else {
                prev->next = curr->next;
                if (curr == q->rear)
                    q->rear = prev;
                free(curr);
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    // Update rear if all nodes are deleted
    if (q->front == NULL)
        q->rear = NULL;
}

// Count number of elements
int countNodes(Queue* q) {
    int count = 0;
    Node* temp = q->front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Queue q;
    initQueue(&q);
    int choice, value;

    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Delete elements divisible by 3\n");
        printf("6. Count elements\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                peek(&q);
                break;

            case 4:
                display(&q);
                break;

            case 5:
                deleteDivBy3(&q);
                break;

            case 6:
                printf("Number of elements in queue: %d\n", countNodes(&q));
                break;

            case 7:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
