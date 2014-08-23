CFLAGS=-g3 -Wall -Werror
main: main.o BiTree.o
	g++ ${CFLAGS} main.o BiTree.o -o main
main.o: main.cpp BiTree.hpp
	g++ ${CFLAGS} -Wall -c main.cpp -o main.o
BiTree.o: BiTree.hpp BiTree.cpp Stack.hpp
	g++ ${CFLAGS} -Wall -c BiTree.cpp -o BiTree.o
clean:
	rm -f *.o
	rm -f main
	rm -fr core.*
