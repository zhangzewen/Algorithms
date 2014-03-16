CFLAGS=-g3 -Wall -Werror
main: main.o Queue.o
	gcc ${CFLAGS} -o main main.o Queue.o
main.o: main.c Queue.h
	gcc ${CFLAGS} -c main.c -o main.o
Queue.o: Queue.c Queue.h
	gcc ${CFLAGS} -c Queue.c -o Queue.o
clean: 
	@-rm -rf *.o
	@-rm -f main
