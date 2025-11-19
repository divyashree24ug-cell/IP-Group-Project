#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[10];
int n;

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v, int directed) {
    struct Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    if (!directed) {
        newNode = createNode(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }
}

void displayList() {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++) {
        struct Node* temp = adjList[i];
        printf("Node %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // add edges
    addEdge(0, 1, 0);
    addEdge(1, 2, 0);
    addEdge(2, 3, 0);

    displayList();

    return 0;
}

