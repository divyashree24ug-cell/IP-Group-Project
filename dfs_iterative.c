#include <stdio.h>
#include "graph_all.h"

void DFS_iterative(Graph* g, int start) {
    int visited[g->numVertices];
    for (int i = 0; i < g->numVertices; i++)
        visited[i] = 0;

    int stack[100];
    int top = -1;

    stack[++top] = start;

    while (top != -1) {
        int v = stack[top--];

        if (!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;

            for (Node* temp = g->adjLists[v]; temp != NULL; temp = temp->next) {
                if (!visited[temp->vertex]) {
                    stack[++top] = temp->vertex;
                }
            }
        }
    }

    printf("\n");
}

