#include <stdio.h>
#include "graph_all.h"

void DFS_iterative(Graph* g, int start) {
    int visited[g->numVertices];
    for (int i = 0; i < g->numVertices; i++)
        visited[i] = 0;

    int stack[g->numVertices];
    int top = -1;

    stack[++top] = start;

    while (top != -1) {
        int node = stack[top--];

        if (!visited[node]) {
            printf("%d ", node);
            visited[node] = 1;
        }

        // Add neighbors in reverse order to visit in correct order
        Node* temp = g->adjLists[node];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                stack[++top] = temp->vertex;
            }
            temp = temp->next;
        }
    }

    printf("\n");
}

