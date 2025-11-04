#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Inorder traversal (sorted)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to find the second smallest node
void findSecondSmallest(struct Node* root, int *count, int *secondSmallest) {
    if (root == NULL || *count >= 2) return;
    findSecondSmallest(root->left, count, secondSmallest);
    (*count)++;
    if (*count == 2)
        *secondSmallest = root->data;
    findSecondSmallest(root->right, count, secondSmallest);
}

// Delete node with non-empty left subtree and empty right subtree
struct Node* deleteSpecific(struct Node* root) {
    if (root == NULL)
        return NULL;

    root->left = deleteSpecific(root->left);
    root->right = deleteSpecific(root->right);

    if (root->left != NULL && root->right == NULL) {
        struct Node* temp = root->left;
        free(root);
        return temp;
    }
    return root;
}

// Count number of nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    struct Node* root = NULL;
    int choice, val, n, i;
    
    while (1) {
        printf("\n\n--- BST MENU ---\n");
        printf("1. Create & Display BST\n");
        printf("2. Find Second Smallest Element\n");
        printf("3. Delete Nodes (Left Subtree Non-Empty, Right Empty)\n");
        printf("4. Difference in Node Count (Left vs Right Subtree)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = NULL;
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                printf("Enter %d values:\n", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &val);
                    root = insert(root, val);
                }
                printf("Inorder traversal (sorted BST): ");
                inorder(root);
                printf("\n");
                break;

            case 2:
                if (root == NULL) {
                    printf("BST is empty.\n");
                    break;
                }
                {
                    int count = 0, secondSmallest = -1;
                    findSecondSmallest(root, &count, &secondSmallest);
                    if (count >= 2)
                        printf("Second smallest number: %d\n", secondSmallest);
                    else
                        printf("Not enough nodes in BST.\n");
                }
                break;

            case 3:
                root = deleteSpecific(root);
                printf("After deletion, BST inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                if (root == NULL) {
                    printf("BST is empty.\n");
                    break;
                }
                {
                    int leftCount = countNodes(root->left);
                    int rightCount = countNodes(root->right);
                    printf("Left subtree nodes: %d\n", leftCount);
                    printf("Right subtree nodes: %d\n", rightCount);
                    printf("Difference = %d\n", abs(leftCount - rightCount));
                }
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
