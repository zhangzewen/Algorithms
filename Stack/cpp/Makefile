CC=g++
CFLAGS+=-g3 -Wall -Werror

main: main.o Stack.o
	$(CC) ${CFLAGS} -o main main.o Stack.o
main.o: main.cpp Stack.h
	$(CC) ${CFLAGS} -c main.cpp -o main.o
Stack.o: Stack.cpp Stack.h
	$(CC) ${CFLAGS} -c Stack.cpp -o Stack.o 
clean:
	@-rm -f *.o
	@-rm -f main
