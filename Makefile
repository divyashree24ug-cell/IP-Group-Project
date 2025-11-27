# Makefile

# target program
a.out: main_mat.o mat.o bfs.o dfs.o main_graph.o graph.o
	gcc main_mat.o mat.o bfs.o dfs.o main_graph.o graph.o -o a.out

main_graph.o: main_graph.c header_graph.h
	gcc -c main_graph.c

graph.o: graph.c header_graph.h
	gcc -c graph.c


# compile source files into object files
main_mat.o: main_mat.c header_mat.h
	gcc -c main_mat.c

mat.o: mat.c header_mat.h
	gcc -c mat.c

bfs.o: bfs.c header_mat.h
	gcc -c bfs.c

dfs.o: dfs.c header_mat.h
	gcc -c dfs.c


# clean up build files
clean:
	rm -f *.o a.out

