main: main.o Queue.o
	gcc -o main main.o Queue.o
main.o: main.c Queue.h
	gcc -c main.c -o main.o
Queue.o: Queue.c Queue.h
	gcc -c Queue.c -o Queue.o
clean: 
	@-ctags -R
	@-rm -rf *.o
	@-rm -f main
