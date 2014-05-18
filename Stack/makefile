CFLAGS = -g3 -Werror -Wall
main: main.o stack.o
	gcc ${CFLAGS} -o main main.o stack.o
main.o: main.c stack.h
	gcc ${CFLAGS} -c main.c -o main.o
stack.o: stack.c stack.h
	gcc ${CFLAGS} -c stack.c -o stack.o
clean:
	@-rm -f *.o
	@-rm -f main
	@-rm -fr core.*
