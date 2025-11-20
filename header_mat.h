#ifndef GRAPH_H
#define GRAPH_H

typedef struct {
    int vertices;
    int** adjMatrix;
} Graph;

Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void displayAdjMatrix(Graph* graph);
void freeGraph(Graph* graph);

#endif

