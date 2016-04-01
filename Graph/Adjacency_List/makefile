CFLAGS=-g3 -Wall -Werror
main: main.o AdjList.o
	gcc ${CFLAGS} main.o AdjList.o -o main
AdjList.o: AdjList.c AdjList.h 
	gcc ${CFLAGS} -c AdjList.c ${CFLAGS} -o AdjList.o
main.o: main.c AdjList.h 
	gcc ${CFLAGS} -c main.c ${CFLAGS} -o main.o
clean:
	rm -fr *.o
	rm -fr main
	rm -fr core.*

