#include <stdio.h>

#define MAX 20

void BFS(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0}, queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, e, u, v;
    int adj[MAX][MAX] = {0};

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

    BFS(adj, n, start);
    return 0;
}
