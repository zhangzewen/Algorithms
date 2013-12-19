CFLAGS=-g3 -Wall -Werror
main: main.o Max_heap.o
	gcc ${CFLAGS} main.o Max_heap.o -o main
Max_heap.o: Max_heap.c Max_heap.h 
	gcc ${CFLAGS} -c Max_heap.c ${CFLAGS} -o Max_heap.o
main.o: main.c Max_heap.h 
	gcc ${CFLAGS} -c main.c ${CFLAGS} -o main.o
clean:
	rm -fr *.o
	rm -fr main
	rm -fr core.*

