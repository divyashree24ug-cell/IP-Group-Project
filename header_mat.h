#ifndef HEADER_H
#define HEADER_H

#define Max 10

extern int adj[Max][Max];
extern int n;

void addEdge(int u, int v, int directed);
void displayMatrix();
void DFS(int start);
void BFS(int start);


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
void addedge(Graph* g, int src, int dest);
void printGraph(Graph* g);


#endif

