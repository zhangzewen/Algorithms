CFLAGS=-g3 -Wall -Werror
main: main.o Merge_Sort.o
	gcc -o main main.o Merge_Sort.o
Merge_Sort.o: Merge_Sort.h Merge_Sort.c
	gcc -c ${CFLAGS} Merge_Sort.c -o Merge_Sort.o
main.o: main.c Merge_Sort.h 
	gcc -c ${CFLAGS} main.c -o main.o
clean:
	@-rm -f main
	@-rm -f *.o
