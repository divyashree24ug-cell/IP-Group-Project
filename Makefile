# Makefile

# target program
# default rule
a.out: main_mat.o mat.o
	gcc main_mat.o mat.o

# compile source files into object files
main.o: main_mat.c header_mat.h
	gcc -c main_mat.c

mat.o: mat.c header_mat.h
	gcc -c mat.c

# clean up build files
clean:
	rm -f *.o a.out

