# Makefile

# Program 1: adjacency matrix
matrix: main_matrix.o matrix_graph.o bfs.o dfs.o
	gcc main_matrix.o matrix_graph.o bfs.o dfs.o -o matrix

# Program 2: adjacency list
list: main_list.o list_graph.o
	gcc main_list.o list_graph.o -o list

main_matrix.o: main_matrix.c graph_all.h
	gcc -c main_matrix.c

matrix_graph.o: matrix_graph.c graph_all.h
	gcc -c matrix_graph.c

bfs.o: bfs.c graph_all.h
	gcc -c bfs.c

dfs.o: dfs.c graph_all.h
	gcc -c dfs.c

main_list.o: main_list.c graph_all.h
	gcc -c main_list.c

list_graph.o: list_graph.c graph_all.h
	gcc -c list_graph.c

clean:
	rm -f *.o matrix list

