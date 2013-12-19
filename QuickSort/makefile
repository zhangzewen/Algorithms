CFLAGS=-g3 -Wall -Werror
main: main.o QuickSort.o
	gcc ${CFLAGS} -Wall -o main main.o QuickSort.o
main.o: main.c QuickSort.h
	gcc ${CFLAGS} -Wall -c main.c -o main.o
QuickSort.o: QuickSort.c QuickSort.h
	gcc ${CFLAGS} -Wall -c QuickSort.c -o QuickSort.o
clean:
	rm -fr main
	rm -fr core.*
	rm -fr *.o
