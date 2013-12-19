CFLAGS=-g3 -Wall -Werror
main: main.o Dlinkedlist.o
	gcc ${CFLAGS} -o main main.o Dlinkedlist.o
main.o: main.c Dlinkedlist.h
	gcc ${CFLAGS} -c main.c -o main.o
linkedlist.o: Dlinkedlist.c Dlinkedlist.h
	gcc ${CFLAGS} -c Dlinkedlist.c -o Dlinkedlist.o
clean:
	rm -fr main
	rm -fr *.o
	rm -fr core.*
