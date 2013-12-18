CFLAGS = -g3 -Werror -Wall
main: main.o Stack.o
	gcc ${CFLAGS} -o main main.o Stack.o
main.o: main.c Stack.h
	gcc ${CFLAGS} -Wall -c main.c -o main.o
Stack.o: Stack.c Stack.h
	gcc ${CFLAGS} -Wall -c Stack.c -o Stack.o
clean:
	@-rm -f *.o
	@-rm -f main
