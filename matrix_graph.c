#include <stdio.h>
#include "graph_all.h"

int adj[Max][Max] = {0};
int n;

void addEdge(int u, int v, int directed) {
    adj[u][v] = 1;
    if (!directed)
        adj[v][u] = 1;
}

void displayMatrix() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

