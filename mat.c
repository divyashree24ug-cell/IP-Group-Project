#include <stdio.h>
#include <stdlib.h>
#include "header_mat.h"

Graph* createGraph(int vertices)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)calloc(vertices, sizeof(int));
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest)
{
    if (src >= graph->vertices || dest >= graph->vertices) {
        printf("Invalid vertices!\n");
        return;
    }
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;  // Undirected graph
}

void displayAdjMatrix(Graph* graph)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph)
{
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

