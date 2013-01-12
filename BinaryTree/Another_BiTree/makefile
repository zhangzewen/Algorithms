bin_tree: bin_tree.o recursive_travel.o general_travel.o other_operators.o
	gcc bin_tree.o recursive_travel.o general_travel.o other_operators.o -o bin_tree
bin_tree.o: bin_tree.c head_bin_tree.h
	gcc -c bin_tree.c -o bin_tree.o
recursive_travel.o: recursive_travel.c head_bin_tree.h
	gcc -c recursive_travel.c -o recursive_travel.o
general_travel.o: general_travel.c head_bin_tree.h
	gcc -c general_travel.c -o general_travel.o
other_operators.o: other_operators.c head_bin_tree.h
	gcc -c other_operators.c -o other_operators.o
.PHONY:clean 
#.PHONY is a var means no matter object file exist or not ,it will run
clean:
	rm -f *.o
	rm -f main
