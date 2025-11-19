#include <stdio.h>

    int n = 4;
    int adj[4][4] = {0};

    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][3] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}



#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node* next;
};

struct Node* adj[10];

void addEdge(int u, int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->v = v;
    n->next = adj[u];
    adj[u] = n;
}

