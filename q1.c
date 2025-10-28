#include <stdio.h>

int main() {
    int n, e, i, u, v, directed;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int adj[n][n];

    // initialize all to 0
    for(i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter 1 for directed, 0 for undirected: ");
    scanf("%d", &directed);

    printf("Enter edges (u v):\n");
    for(i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        if(!directed)
            adj[v][u] = 1;
    }

    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    return 0;
}
