CFLAGS=-g3 -Wall -Werror
main: main.o linkedlist.o
	gcc ${CFLAGS} -o main main.o linkedlist.o
main.o: main.c linkedlist.h
	gcc ${CFLAGS} -c main.c -o main.o
linkedlist.o: linkedlist.c linkedlist.h
	gcc ${CFLAGS} -c linkedlist.c -o linkedlist.o

clean:
	rm -fr main
	rm -fr *.o
	rm -fr core.*
