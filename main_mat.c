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

    return 0;
}

