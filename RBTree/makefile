main: main.o RBTree.o
	gcc -o main main.o RBTree.o
RBTree.o: RBTree.h RBTree.c
	gcc -c -g3 RBTree.c -o RBTree.o
main.o: main.c RBTree.h 
	gcc -c -g3 main.c -o main.o
clean:
	rm -f main
	rm -f *.o
	rm -fr core.*
