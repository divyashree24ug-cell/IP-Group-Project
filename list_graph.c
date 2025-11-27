#include <stdio.h>
#include <stdlib.h>
#include "graph_all.h"

Node* createNode(int v) {
    Node* n = malloc(sizeof(Node));
    n->vertex = v;
    n->next = NULL;
    return n;
}

Graph* createGraph(int V) {
    Graph* g = malloc(sizeof(Graph));
    g->numVertices = V;
    g->adjLists = malloc(V * sizeof(Node*));

    for (int i = 0; i < V; i++)
        g->adjLists[i] = NULL;

    return g;
}

void addEdgeList(Graph* g, int src, int dest) {
    Node* n = createNode(dest);
    n->next = g->adjLists[src];
    g->adjLists[src] = n;
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        Node* temp = g->adjLists[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

