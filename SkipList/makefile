CFLAGS=-g3 -Wall -Werror
main: main.o SkipList.o 
	gcc -o main main.o SkipList.o
SkipList.o: SkipList.h SkipList.c
	gcc -c ${CFLAGS} SkipList.c -o SkipList.o
main.o: main.c SkipList.h 
	gcc -c ${CFLAGS} main.c -o main.o
clean:
	rm -f main
	rm -f *.o
	rm -fr core.*
