# Makefile

a.out: mat_main.o mat.o
	gcc mat_main.o mat.o

mat_main.o: mat_main.c header_mat.h
	gcc -c mat_main.c

mat.o: mat.c header_mat.h
	gcc -c mat.c

clean:
	rm -f *.o a.out

