
main: main.o
	g++ -g  main.o -o main

main.o: main.cc RBTree.h
	g++ -g -O0 -c main.cc -o main.o


clean:
	rm -fr *.o
	rm -fr main
	rm -fr core.*
	rm -fr *.core
