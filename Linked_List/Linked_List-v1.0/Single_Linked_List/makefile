main: main.o linkedlist.o
	gcc -o main main.o linkedlist.o
main.o: main.c linkedlist.h
	gcc -c main.c -o main.o
linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c -o linkedlist.o
clean: 
	@-rm -rf *.o
	@-rm -f main
