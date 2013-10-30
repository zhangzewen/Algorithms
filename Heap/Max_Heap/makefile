main: main.o Max_heap.o
	gcc -g main.o Max_heap.o -o main
Max_heap.o: Max_heap.c Max_heap.h 
	gcc -g -c Max_heap.c -g -o Max_heap.o
main.o: main.c Max_heap.h 
	gcc -g -c main.c -g -o main.o
clean:
	rm -fr *.o
	rm -fr main
	rm -fr core.*

