main: main.o Dlinkedlist.o
	gcc -o main main.o Dlinkedlist.o
main.o: main.c Dlinkedlist.h
	gcc -c main.c -o main.o
linkedlist.o: Dlinkedlist.c Dlinkedlist.h
	gcc -c Dlinkedlist.c -o Dlinkedlist.o
