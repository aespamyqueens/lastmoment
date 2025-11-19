#include <stdio.h>
#include <stdlib.h>

struct Node { int v; struct Node* next; };
struct Node* adj[10];
int visited[10];

void add(int u, int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->v = v; n->next = adj[u];
    adj[u] = n;
}

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* t = adj[v];
    while (t) {
        if (!visited[t->v])
            dfs(t->v);
        t = t->next;
    }
}
