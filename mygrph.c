#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

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


void addedge(Graph* g, int src, int dest) //needs learning
{//if statement need here to check
    Node* n = createNode(dest);
    n->next = g->adjLists[src];
    g->adjLists[src] = n;
}

void printGraph(Graph* g)//need to work on this one
{
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        for (Node* current = g->adjLists[i]; current != NULL; current = current->next)
            printf("%d -> ", current->vertex);
        printf("NULL\n");
    }
}

int main()
{
    int V = 3;
    Graph* g = createGraph(V);


	addedge(g,0,1);
    	addedge(g,1,2);
    	addedge(g,0,2);
//	addedge(g,2,3);
//	addedge(g,3,4);
  	  printGraph(g);
    return 0;
}

