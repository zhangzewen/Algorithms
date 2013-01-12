main: main.o Binary_Sort_Tree.o
	gcc -o main main.o Binary_Sort_Tree.o
Binary_Sort_Tree.o: Binary_Sort_Tree.h Binary_Sort_Tree.c
	gcc -c -g Binary_Sort_Tree.c -o Binary_Sort_Tree.o
main.o: main.c Binary_Sort_Tree.h 
	gcc -c -g main.c -o main.o
clean:
	@-rm -f main
	@-rm -f *.o
