CFLAGS+=-g
test: test.o HashTable.o
	gcc test.o HashTable.o -o test
HashTable.o: HashTable.c HashTable.h list.h
	gcc -c HashTable.c -o HashTable.o
test.o: test.c HashTable.h list.h
	gcc -c test.c -o test.o
clean:
	rm -fr *.o
	rm -fr test
