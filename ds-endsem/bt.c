#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue structure for level order creation
struct Queue {
    struct Node* arr[MAX];
    int front, rear;
};

// Stack structure for iterative preorder
struct Stack {
    struct Node* arr[MAX];
    int top;
};

// Queue functions
void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmptyQ(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    if (isEmptyQ(q)) return NULL;
    struct Node* temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// Stack functions
void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmptyS(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, struct Node* node) {
    if (s->top == MAX - 1) return;
    s->arr[++s->top] = node;
}

struct Node* pop(struct Stack* s) {
    if (isEmptyS(s)) return NULL;
    return s->arr[s->top--];
}

// Create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Iterative creation of binary tree
struct Node* createTree() {
    struct Queue q;
    initQueue(&q);
    struct Node *root = NULL;
    int val;

    printf("Enter root value (-1 for no node): ");
    scanf("%d", &val);
    if (val == -1) return NULL;

    root = createNode(val);
    enqueue(&q, root);

    while (!isEmptyQ(&q)) {
        struct Node* current = dequeue(&q);
        printf("Enter left child of %d (-1 for no node): ", current->data);
        scanf("%d", &val);
        if (val != -1) {
            current->left = createNode(val);
            enqueue(&q, current->left);
        }

        printf("Enter right child of %d (-1 for no node): ", current->data);
        scanf("%d", &val);
        if (val != -1) {
            current->right = createNode(val);
            enqueue(&q, current->right);
        }
    }
    return root;
}

// Display tree in structured form
void displayTree(struct Node* root, int space) {
    if (root == NULL)
        return;
    space += 5;
    displayTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    displayTree(root->left, space);
}

// Iterative Preorder traversal (Root-Left-Right)
void iterativePreorder(struct Node* root) {
    if (root == NULL) return;
    struct Stack s;
    initStack(&s);
    push(&s, root);

    printf("Preorder: ");
    while (!isEmptyS(&s)) {
        struct Node* current = pop(&s);
        printf("%d ", current->data);

        // Push right first so that left is processed first
        if (current->right) push(&s, current->right);
        if (current->left) push(&s, current->left);
    }
    printf("\n");
}

// Delete node with less than degree 2
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        int degree = 0;
        if (root->left) degree++;
        if (root->right) degree++;

        if (degree < 2) {
            struct Node* child = (root->left) ? root->left : root->right;
            free(root);
            return child;
        } else {
            printf("Node has degree 2. Not deleting.\n");
        }
    }
    return root;
}

// Display all non-leaf nodes
void displayNonLeaf(struct Node* root) {
    if (root == NULL) return;
    if (root->left != NULL || root->right != NULL)
        printf("%d ", root->data);
    displayNonLeaf(root->left);
    displayNonLeaf(root->right);
}

// Main Menu
int main() {
    struct Node* root = NULL;
    int choice, val;

    while (1) {
        printf("\n\n--- BINARY TREE MENU ---\n");
        printf("1. Create Binary Tree (Iterative)\n");
        printf("2. Display Tree Structure\n");
        printf("3. Iterative Preorder Traversal\n");
        printf("4. Delete Node with Degree < 2\n");
        printf("5. Display All Non-Leaf Nodes\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = createTree();
                break;
            case 2:
                if (root)
                    displayTree(root, 0);
                else
                    printf("Tree is empty.\n");
                break;
            case 3:
                iterativePreorder(root);
                break;
            case 4:
                printf("Enter node value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 5:
                printf("Non-leaf nodes: ");
                displayNonLeaf(root);
                printf("\n");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
