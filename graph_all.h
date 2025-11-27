#ifndef GRAPH_ALL_H
#define GRAPH_ALL_H


#define Max 10   // for adjacency matrix


// ADJACENCY MATRIX DECLARATIONS

extern int adj[Max][Max];
extern int n;

void addEdge(int u, int v, int directed);
void displayMatrix();
void DFS(int start);   // recursive DFS using matrix
void BFS(int start);   // BFS using matrix

// ADJACENCY LIST DECLARATIONS

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// graph creation
Graph* createGraph(int V);
Node* createNode(int v);
void addEdgeList(Graph* g, int src, int dest);  // renamed from addedge
void printGraph(Graph* g);

// DFS iterative (using stack, adjacency list)
void DFS_iterative(Graph* g, int start);


#endif

