#include <stdio.h>
#define SIZE 10

int stack[SIZE], top = -1;

void push(int x) {
    if (top == SIZE - 1) return;
    stack[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *top = NULL;

void push(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
}

int pop() {
    if (!top) return -1;
    struct Node* temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    return x;
}
