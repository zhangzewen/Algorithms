CC=g++
CFLAGS+=-g

main: main.o Stack.o
	$(CC) -g -o main main.o Stack.o
main.o: main.cpp Stack.h
	$(CC) -g -Wall -c main.cpp -o main.o
Stack.o: Stack.cpp Stack.h
	$(CC) -g -Wall -c Stack.cpp -o Stack.o
clean:
	@-rm -f *.o
	@-rm -f main
