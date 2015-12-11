
main: RBTree.o main.o
	g++ -g RBTree.o main.o -o main

RBTree.o: RBTree.cc RBTree.h
	g++ -g -O0 -c RBTree.cc -o RBTree.o
main.o: main.cc RBTree.h
	g++ -g -O0 -c main.cc -o main.o


clean:
	rm -fr *.o
	rm -fr main
