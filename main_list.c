#include <stdio.h>
#include "graph_all.h"

int main() {
    int V = 6;
    Graph* g = createGraph(V);

    addEdgeList(g, 0, 1);
    addEdgeList(g, 0, 4);
    addEdgeList(g, 1, 2);
    addEdgeList(g, 2, 3);
    addEdgeList(g, 3, 4);
    addEdgeList(g, 3, 5);

    printf("Adjacency List:\n");
    printGraph(g);

    printf("\nDFS (Iterative) starting from 0:\n");
    DFS_iterative(g, 0);

    return 0;
}

