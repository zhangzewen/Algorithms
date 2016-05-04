CFLAGS=-g3 -Wall -Werror
CC=g++
main: main.o AdjList.o
	${CC} ${CFLAGS} main.o AdjList.o -o main
AdjList.o: AdjList.cc AdjList.h 
	${CC} ${CFLAGS} -c AdjList.cc ${CFLAGS} -o AdjList.o
main.o: main.c AdjList.h 
	${CC} ${CFLAGS} -c main.c ${CFLAGS} -o main.o
clean:
	rm -fr *.o
	rm -fr main
	rm -fr core.*

