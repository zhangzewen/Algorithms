CFLAGS=-g3 -Wall -Werror
main: main.o deque.o
	gcc ${CFLAGS} -o main main.o deque.o
main.o: main.c deque.h
	gcc ${CFLAGS} -c main.c -o main.o
deque.o: deque.c deque.h
	gcc ${CFLAGS} -c deque.c -o deque.o
clean: 
	@-rm -rf *.o
	@-rm -f main
	@-rm -fr core.*
	@-rm -fr core
