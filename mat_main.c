#include "header_mat.h"

int main()
{
    int vertices = 5;

    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    displayAdjMatrix(graph);

    freeGraph(graph);

    return 0;
}

