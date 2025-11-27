# ===============================
# Program 1: Adjacency Matrix (BFS)
# ===============================

matrix: main_matrix.o matrix_graph.o bfs.o
	gcc main_matrix.o matrix_graph.o bfs.o -o matrix

main_matrix.o: main_matrix.c graph_all.h
	gcc -c main_matrix.c

matrix_graph.o: matrix_graph.c graph_all.h
	gcc -c matrix_graph.c

bfs.o: bfs.c graph_all.h
	gcc -c bfs.c


# ===============================
# Program 2: Adjacency List (DFS)
# ===============================

list: main_list.o list_graph.o dfs_iterative.o
	gcc main_list.o list_graph.o dfs_iterative.o -o list

main_list.o: main_list.c graph_all.h
	gcc -c main_list.c

list_graph.o: list_graph.c graph_all.h
	gcc -c list_graph.c

dfs_iterative.o: dfs_iterative.c graph_all.h
	gcc -c dfs_iterative.c


# ===============================
# Clean command
# ===============================

clean:
	rm -f *.o matrix list

