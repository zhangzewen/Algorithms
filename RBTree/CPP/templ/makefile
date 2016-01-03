
CFLAGS=-g -O0 -std=c++11
main: main.o
	g++ ${CFLAGS}  main.o -o main

main.o: main.cc RBTree.h
	g++ ${CFLAGS} -c main.cc -o main.o


clean:
	rm -fr *.o
	rm -fr main
	rm -fr core.*
	rm -fr *.core
