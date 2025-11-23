# Makefile

# target program
a.out: main_mat.o mat.o bfs.o dfs.o
	gcc main_mat.o mat.o bfs.o dfs.o -o a.out

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

