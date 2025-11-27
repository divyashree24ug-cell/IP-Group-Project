#include <stdio.h>
#include "header_mat.h"

int visitedDFS[Max];

void DFS_util(int node) {
    visitedDFS[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visitedDFS[i]) {
            DFS_util(i);
        }
    }
}

void DFS(int start) {
    for (int i = 0; i < n; i++)
        visitedDFS[i] = 0;

    printf("\nDFS Traversal: ");
    DFS_util(start);
}

