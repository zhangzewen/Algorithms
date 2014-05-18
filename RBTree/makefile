CFLAGS=-g3 -Wall -Werror
main: main.o RBTree.o stack.o
	gcc -o main main.o RBTree.o stack.o
RBTree.o: RBTree.h RBTree.c stack.h
	gcc -c ${CFLAGS} RBTree.c -o RBTree.o
stack.o: stack.h stack.c
	gcc -c ${CFLAGS} stack.c -o stack.o
main.o: main.c RBTree.h 
	gcc -c ${CFLAGS} main.c -o main.o
clean:
	rm -f main
	rm -f *.o
	rm -fr core.*
