#ifndef GRAPH_ALL_H
#define GRAPH_ALL_H

#define Max 10

/********** MATRIX GRAPH **********/
extern int adj[Max][Max];
extern int n;

void addEdge(int u, int v, int directed);
void displayMatrix();
void BFS(int start);
void DFS(int start);

/********** LIST GRAPH **********/
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

Graph* createGraph(int V);
Node* createNode(int v);
void addEdgeList(Graph* g, int src, int dest);
void printGraph(Graph* g);

void DFS_iterative(Graph* g, int start);

#endif

