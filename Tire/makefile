CFLAGS=-g -Wall -Werror
main: main.o Tire.o
	gcc ${CFLAGS} main.o Tire.o -o main
main.o: main.c Tire.h
	gcc ${CFLAGS} -Wall -c main.c -o main.o
Tire.o: Tire.h Tire.c
	gcc ${CFLAGS} -Wall -c Tire.c -o Tire.o
clean:
	rm -f *.o
	rm -f main
	rm -fr core.*
