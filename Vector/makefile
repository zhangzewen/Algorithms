CFLAGS=-g3 -Wall -Werror
main: main.o vector.o
	gcc ${CFLAGS} -o main main.o vector.o
main.o: main.c vector.h
	gcc ${CFLAGS} -c main.c -o main.o
vector.o: vector.c vector.h
	gcc ${CFLAGS} -c vector.c -o vector.o
clean: 
	@-rm -rf *.o
	@-rm -f main
