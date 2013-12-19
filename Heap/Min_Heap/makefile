CFLAGS=-g3 -Wall -Werror
main: main.o Min_Heap.o
	gcc ${CFLAGS} main.o Min_Heap.o -o main
Min_Heap.o: Min_Heap.c Min_Heap.h 
	gcc ${CFLAGS} -c Min_Heap.c ${CFLAGS} -o Min_Heap.o
main.o: main.c Min_Heap.h 
	gcc ${CFLAGS} -c main.c ${CFLAGS} -o main.o
clean:
	rm -fr *.o
	rm -fr main
	rm -fr core.*

