#include <stdio.h>
#include "header_mat.h"

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    addEdge(0, 1, 0);
    addEdge(0, 4, 0);
    addEdge(1, 2, 0);
    addEdge(1, 3, 0);
    addEdge(1, 4, 0);
    addEdge(2, 3, 0);
    addEdge(3, 4, 0);



    displayMatrix();

    printf("\nRunning BFS from node 0:\n");
    BFS(0);    
    printf("\n");
    printf("\nRunning DFS from node 0:\n");
    DFS(0);

    return 0;
}

