#include <stdio.h>
#include "graph_all.h"

void BFS(int start) {
    int visit[Max] = {0};
    int queue[Max], front = 0, rear = 0;

    visit[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visit[i]) {
                visit[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

