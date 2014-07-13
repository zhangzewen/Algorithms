CC=g++
CFLAGS+=-g3 -Wall -Werror

main: main.o
	$(CC) ${CFLAGS} -o main main.o
main.o: main.cpp Stack.h
	$(CC) ${CFLAGS} -c main.cpp -o main.o
clean:
	@-rm -f *.o
	@-rm -f main
	@-rm -fr core.*
