main: main.o BiTree.o
	gcc -g main.o BiTree.o -o main
main.o: main.c BiTree.h
	gcc -g -Wall -c main.c -o main.o
BiTree.o: BiTree.h BiTree.c
	gcc -g -Wall -c BiTree.c -o BiTree.o
clean:
	rm -f *.o
	rm -f main
	rm -fr core.*
