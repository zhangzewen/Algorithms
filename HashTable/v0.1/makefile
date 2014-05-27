CFLAGS = -g3 -Werror -Wall
main: main.o hashtable.o hash.o
	gcc ${CFLAGS} main.o hashtable.o hash.o -o main
hashtable.o: hashtable.c hashtable.h list.h hash.h
	gcc ${CFLAGS} -c hashtable.c ${CFLAGS} -o hashtable.o
hash.o: hash.h hash.c
	gcc ${CFLAGS} -c hash.c -o hash.o
main.o: main.c hashtable.h list.h hash.h
	gcc ${CFLAGS} -c main.c ${CFLAGS} -o main.o
clean:
	rm -fr *.o
	rm -fr main
	rm -fr core.*

