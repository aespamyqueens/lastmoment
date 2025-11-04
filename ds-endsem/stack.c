#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

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

// Function to push an element into the stack
void push(Node** top, int value) {
    Node* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d (Address: %p)\n", value, (void*)newNode);
}

// Function to pop an element from the stack
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    Node* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    printf("Popped %d (Address freed: %p)\n", popped, (void*)temp);
    free(temp);
    return popped;
}

// Function to peek at the top element
void peek(Node* top) {
    if (top == NULL)
        printf("Stack is empty!\n");
    else
        printf("Top element: %d (Address: %p)\n", top->data, (void*)top);
}

// Function to display all elements
void display(Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack (top to bottom):\n");
    Node* temp = top;
    while (temp != NULL) {
        printf("Data: %d (Address: %p)\n", temp->data, (void*)temp);
        temp = temp->next;
    }
}

// Function to delete all even elements
void deleteEven(Node** top) {
    Node* curr = *top;
    Node* prev = NULL;

    while (curr != NULL) {
        if (curr->data % 2 == 0) {
            printf("Deleting even node %d (Address: %p)\n", curr->data, (void*)curr);
            if (prev == NULL) {
                *top = curr->next;
                free(curr);
                curr = *top;
            } else {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

// Function to count number of nodes
int countNodes(Node* top) {
    int count = 0;
    while (top != NULL) {
        count++;
        top = top->next;
    }
    return count;
}

int main() {
    Node* top = NULL;
    int choice, value;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Delete Even Elements\n");
        printf("6. Count Nodes\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                peek(top);
                break;
            case 4:
                display(top);
                break;
            case 5:
                deleteEven(&top);
                break;
            case 6:
                printf("Number of nodes in stack: %d\n", countNodes(top));
                break;
            case 7:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
