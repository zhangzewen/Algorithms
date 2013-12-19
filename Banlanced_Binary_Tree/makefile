CFLAGS=-g3 -Wall -Werror
main: main.o Banlanced_Binary_Tree.o
	gcc -o main main.o Banlanced_Binary_Tree.o
Banlanced_Binary_Tree.o: Banlanced_Binary_Tree.h Banlanced_Binary_Tree.c
	gcc -c ${CFLAGS} Banlanced_Binary_Tree.c -o Banlanced_Binary_Tree.o
main.o: main.c Banlanced_Binary_Tree.h 
	gcc -c ${CFLAGS} main.c -o main.o
clean:
	rm -f main
	rm -f *.o
	rm -fr core.*
