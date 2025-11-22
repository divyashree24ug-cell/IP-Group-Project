// C Program to represent the graph using ajacency matrix
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
typedef struct {
    int vertices;
    int** adjMatrix;
} Graph;

// Function to create a graph
Graph* createGraph(int vertices)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix
        = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i]
            = (int*)calloc(vertices, sizeof(int));
    }

    return graph;
}

// Function to add an edge to the graph (undirected)
void addEdge(Graph* graph, int src, int dest)
{
    if (src >= graph->vertices || dest >= graph->vertices) {
        printf("Invalid vertices!\n");
        return;
    }
    graph->adjMatrix[src][dest] = 1;
    // for a directed graph, set weight
    graph->adjMatrix[dest][src] = 1;
}

// Function to display the adjacency matrix
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

// Function to free the allocated memory for the graph
void freeGraph(Graph* graph)
{
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

int main()
{
    int vertices = 5;

    // Create a graph
    Graph* graph = createGraph(vertices);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Display the adjacency matrix
    displayAdjMatrix(graph);

    // Free the allocated memory
    freeGraph(graph);

    return 0;
} 
// Adjacency Matrix representation in C

