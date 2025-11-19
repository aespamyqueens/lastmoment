#include <stdio.h>
#include <stdlib.h>

struct Node { int v; struct Node* next; };
struct Node* adj[10];
int visitedB[10];

void addEdge(int u, int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->v = v; n->next = adj[u];
    adj[u] = n;
}

void bfs(int start) {
    int q[20], front = 0, rear = 0;
    visitedB[start] = 1;
    q[rear++] = start;

    while (front < rear) {
        int v = q[front++];
        printf("%d ", v);

        struct Node* t = adj[v];
        while (t) {
            if (!visitedB[t->v]) {
                visitedB[t->v] = 1;
                q[rear++] = t->v;
            }
            t = t->next;
        }
    }
}
