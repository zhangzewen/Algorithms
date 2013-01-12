main: main.o Stack.o
	gcc -g -o main main.o Stack.o
main.o: main.c Stack.h
	gcc -g -Wall -c main.c -o main.o
Stack.o: Stack.c Stack.h
	gcc -g -Wall -c Stack.c -o Stack.o
clean:
	@-rm -f *.o
	@-rm -f main
