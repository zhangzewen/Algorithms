test: test.o HashTable.o
	gcc -g test.o HashTable.o -o test
HashTable.o: HashTable.c HashTable.h list.h
	gcc -g -c HashTable.c -g -o HashTable.o
test.o: test.c HashTable.h list.h
	gcc -g -c test.c -g -o test.o
clean:
	rm -fr *.o
	rm -fr test
