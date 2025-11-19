#include <stdio.h>
#define SIZE 10

int q[SIZE], front = 0, rear = 0;

void enqueue(int x) {
    if (rear == SIZE) return;
    q[rear++] = x;
}

int dequeue() {
    if (front == rear) return -1;
    return q[front++];
}


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x; n->next = NULL;

    if (!front)
        front = rear = n;
    else {
        rear->next = n;
        rear = n;
    }
}

int dequeue() {
    if (!front) return -1;
    struct Node* temp = front;
    int x = temp->data;
    front = front->next;
    free(temp);
    return x;
}
