#include <stdio.h>
#include <stdlib.h>
#include "BitMap.h"

int main(int argc, char *argv[])
{
	bitmap_t *new = NULL;
	int i = 0;
	new = bitmap_create(10000);
	for (i = 0; i < 1000; i++) {
		bitmap_set(new, i);	
	}
	return 0;		
}
