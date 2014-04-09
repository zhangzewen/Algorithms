CFLAGS=-g3 -Wall -Werror
main: main.o BiTree.o
	gcc ${CFLAGS} main.o BiTree.o -o main
main.o: main.c BiTree.h
	gcc ${CFLAGS} -Wall -c main.c -o main.o
BiTree.o: BiTree.h BiTree.c
	gcc ${CFLAGS} -Wall -c BiTree.c -o BiTree.o
clean:
	rm -f *.o
	rm -f main
	rm -fr core.*
