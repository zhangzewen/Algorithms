main: main.o QuickSort.o
	gcc -g -Wall -o main main.o QuickSort.o
main.o: main.c QuickSort.h
	gcc -g -Wall -c main.c -o main.o
QuickSort.o: QuickSort.c QuickSort.h
	gcc -g -Wall -c QuickSort.c -o QuickSort.o
