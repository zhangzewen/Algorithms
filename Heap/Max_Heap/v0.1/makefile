CFLAGS=-g3 -Wall -Werror
main: main.o vector.o
	gcc ${CFLAGS} main.o vector.o -o main
main.o: main.c vector.h 
	gcc ${CFLAGS} -c main.c ${CFLAGS} -o main.o
vector.o: vector.h vector.c
	gcc $(CFLAGS) -c vector.c ${CFLAGS} -o vector.o
clean:
	rm -fr *.o
	rm -fr main
	rm -fr core.*

