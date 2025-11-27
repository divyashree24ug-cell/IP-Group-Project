#include <stdio.h>
#include "graph_all.h"

int main() {
    Graph* g = createGraph(3);

    addEdgeList(g, 0, 1);   // FIXED
    addEdgeList(g, 1, 2);   // FIXED
    addEdgeList(g, 0, 2);   // FIXED

    printGraph(g);

    printf("DFS (iterative) starting from 0:\n");
    DFS_iterative(g, 0);

    return 0;
}

