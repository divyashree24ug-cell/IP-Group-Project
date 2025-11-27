
#include <stdio.h>
#include <stdlib.h>
#define V 6

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

Graph* createGraph() {
    Graph* g = malloc(sizeof(Graph));
    g->numVertices = V;
    g->adjLists = malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++) 
	    g->adjLists[i] = NULL;
    return g;
}


void addedge(Graph* g, int src, int dest) //needs learning
{
	if(src < V && dest<V){ 
    Node* n = createNode(dest);
    n->next = g->adjLists[src];
    g->adjLists[src] = n;
	}
	else 
		printf("Out of bounds");
}
void DFS(Graph* g, int start)
{
    int visited[V] = {0};
    int stack[100];            
    int top = -1;

    
    top = top + 1;
    stack[top] = start;

    while (top != -1) 
    {
        int v = stack[top];  
	top=top-1;
	
        if (visited[v]==0) 
	{
            printf("%d ", v);
            visited[v] = 1;

	  for (Node* temp = g->adjLists[v]; temp != NULL; temp = temp->next) 
	  {
                if (visited[temp->vertex]==0)
		{	
			top=top +1;
                    	stack[top] = temp->vertex;
		}
          }
        }
    }
}



void printGraph(Graph* g)
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
   
    Graph* g = createGraph(V);

    
	addedge(g, 0, 1);
	addedge(g, 0, 4);
	addedge(g, 1, 2);
	addedge(g, 2, 3);
	addedge(g, 3, 4);
	addedge(g, 3, 5);


  	  printGraph(g);

	int visited[V];
	for (int i = 0; i < V; i++) visited[i] = 0;

	printf("DFS traversal: ");
	DFS(g, 0);
	printf("\n");

    return 0;
}


