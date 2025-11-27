#include <stdio.h>
#include "graph_all.h"

void BFS(int start) {
    int visit[Max] = {0};
    int queue[Max], delete = 0, insert = 0;

    visit[start] = 1;
    queue[insert++] = start;

    printf("\nBFS Traversal: ");

    while (delete < insert) {
        int node = queue[delete++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visit[i]) {
                visit[i] = 1;
                queue[insert++] = i;
            }
        }
    }
}

