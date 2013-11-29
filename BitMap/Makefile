main: main.o BitMap.o
	gcc -g3 main.o BitMap.o -o main
BitMap.o: BitMap.c BitMap.h
	gcc -g3 -c BitMap.c -o BitMap.o
main.o: main.c BitMap.h
	gcc -g3 -c main.c -o main.o

clean:
	rm -fr main
	rm -fr *.o
	rm -fr core.*
