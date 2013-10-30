main: main.o Min_Heap.o
	gcc -g main.o Min_Heap.o -o main
Min_Heap.o: Min_Heap.c Min_Heap.h 
	gcc -g -c Min_Heap.c -g -o Min_Heap.o
main.o: main.c Min_Heap.h 
	gcc -g -c main.c -g -o main.o
clean:
	rm -fr *.o
	rm -fr main
	rm -fr core.*

