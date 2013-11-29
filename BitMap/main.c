#include <stdio.h>
#include <stdlib.h>
#include "BitMap.h"

int main(int argc, char *argv[])
{
	BitMap *map = NULL;
	
	map = BitMap_create(4);

	BitMap_set(map, 32, 1);

		
}
