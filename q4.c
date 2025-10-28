#include <stdio.h>

#define MAX 20

void DFS(int adj[MAX][MAX], int n, int start, int visited[MAX]) {
    printf("%d ", start);
    visited[start] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[start][i] && !visited[i])
            DFS(adj, n, i, visited);
    }
}

int main() {
    int n, e, u, v;
    int adj[MAX][MAX] = {0}, visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1; // undirected
    }

    int start;
    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(adj, n, start, visited);
    printf("\n");
    return 0;
}
