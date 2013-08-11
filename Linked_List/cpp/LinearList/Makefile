CC=g++
CFLAGS+=-g

main: main.o LinearList.o
	$(CC) -g -o main main.o LinearList.o
main.o: main.cpp LinearList.h
	$(CC) -g -Wall -c main.cpp -o main.o
LinearList.o: LinearList.cpp LinearList.h
	$(CC) -g -Wall -c LinearList.cpp -o LinearList.o
clean:
	@-rm -f *.o
	@-rm -f main
