#ifndef __SINOGRID_BITMAP_H_INCLUDED_
#define __SINOGRID_BITMAP_H_INCLUDED_

#define BitMapStep 4096
typedef struct BitMap_s BitMap;

struct BitMap_s{
	int *set;
	long int size;
};

BitMap *BitMap_create(int n);

int BitMap_set(BitMap *map, int n, int i);

void BitMap_get(BitMap *map, int n, int *i);



#endif
