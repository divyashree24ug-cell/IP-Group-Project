#ifndef HEADER_H
#define HEADER_H

#define Max 10

extern int adj[Max][Max];
extern int n;

void addEdge(int u, int v, int directed);
void displayMatrix();
void DFS(int start);
void BFS(int start);


#endif

