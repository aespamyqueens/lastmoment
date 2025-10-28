#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

void addEdge(Node* adj[], int u, int v, int directed) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    if (!directed) {
        Node* newNode2 = malloc(sizeof(Node));
        newNode2->vertex = u;
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }
}

void printGraph(Node* adj[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);
        Node* temp = adj[i];
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n, e, u, v, directed;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter 1 for directed, 0 for undirected: ");
    scanf("%d", &directed);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v, directed);
    }

    printf("\nAdjacency List:\n");
    printGraph(adj, n);
    return 0;
}
