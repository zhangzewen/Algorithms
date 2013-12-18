CFLAGS = -g3 -Werror -Wall
test: test.o HashTable.o
	gcc ${CFLAGS} test.o HashTable.o -o test
HashTable.o: HashTable.c HashTable.h list.h
	gcc ${CFLAGS} -c HashTable.c ${CFLAGS} -o HashTable.o
test.o: test.c HashTable.h list.h
	gcc ${CFLAGS} -c test.c ${CFLAGS} -o test.o
clean:
	rm -fr *.o
	rm -fr test
