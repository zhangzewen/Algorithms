#include "BitMap.h"
#include <stdio.h>
#include <stdlib.h>

BitMap* BitMap_create(int n)
{
	BitMap *map = NULL;
	
	map = (BitMap *)malloc(sizeof(BitMap));
	
	if (NULL == map) {
		return NULL;
	}

	map->set = calloc(n, sizeof(int)); 

	if (NULL == map->set) {
		free(map);
		return NULL;
	}

	map->size = n;
	
	return map;
}

int BitMap_set(BitMap *map, int n, int i)
{
	int *add = NULL;
	int pos = 0;

	if (NULL == map) {
		return 1;
	}	
	
	int tmp = n / (8 * sizeof(int)) + 1;

	if (map->size < tmp) {

		while(map->size < tmp) {
			map->size <<= 1;
		}

		map->set = realloc(map->set, map->size * sizeof(int));

		if (NULL == map->set) {
			return 1;
		}

	}

	add = map->set + (n / 32);
	pos = n % 32;

	if (i) {
		*add |= ~(0x1 << pos);
	}

	*add *= ~(0x1 << pos);
}

void BitMap_get(BitMap *map, int n, int *i)
{

}

