#ifndef HEADER_GRAPH_H
#define HEADER_GRAPH_H

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

Node* createNode(int v);
Graph* createGraph(int V);
void addEdge(Graph* g, int src, int dest);
void printGraph(Graph* g);

#endif

