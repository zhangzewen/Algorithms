CC = g++
CFLAGS = -g

main: main.o
	$(CC) -c $(CFLAGS) main.o -o main
main.o: main.cpp ChainNode.h
	$(CC) -c $(CFLAGS) main.cpp $(CFLAGS) -o main.o
clean:
	rm -fr *.o
	rm -fr core.*
	rm -fr main
