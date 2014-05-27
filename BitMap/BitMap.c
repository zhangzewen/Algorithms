#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "BitMap.h"

bitmap_t *bitmap_create(int n)
{
	bitmap_t *bitmap;

	bitmap = (bitmap_t *)malloc(sizeof(struct bitmap_st));

	if (NULL == bitmap) {
		 return NULL;
	}
	
	bitmap->n = n;
	bitmap->b = (uint32_t *)malloc(sizeof(bitmap->b[0])*(n+31)/32);
	if (NULL == bitmap->b) {
		free(bitmap);
		return NULL;
	}

	memset(bitmap->b, 0, sizeof(bitmap->b[0])*(n+31)/32);

	return bitmap;
}


void bitmap_free(bitmap_t *bitmap)
{
	if (NULL == bitmap)
		return;

	free(bitmap->b);
	free(bitmap);
}

int bitmap_set(bitmap_t *bitmap, unsigned i)
{
	if (i >= bitmap->n) {
		fprintf(stderr, "Setting invalid bitmap entry %d (of %d)\n",
		      i, bitmap->n);
		return -1;
	}
	bitmap->b[i/32] |= (1<<(i%32));
	return 0;
}

int bitmap_clear(bitmap_t *bitmap, unsigned i)
{
	if (i >= bitmap->n) {
		fprintf(stderr,"clearing invalid bitmap entry %d (of %d)\n",
		      i, bitmap->n);
		return -1;
	}
	bitmap->b[i/32] &= ~(1<<(i%32));
	return 0;
}

/****************************************************************************
 * query a bit in a bitmap
 * ****************************************************************************/
int bitmap_query(bitmap_t *bitmap, unsigned i)
{
	if (i >= bitmap->n) return -1;
	if (bitmap->b[i/32] & (1<<(i%32))) {
		return 0;
	}
	return -1;
}

/****************************************************************************
 * find a zero bit in a bitmap starting at the specified offset, with
 * wraparound
 * ****************************************************************************/
int bitmap_find(bitmap_t *bitmap, unsigned ofs)
{
	int i, j;

	if (ofs > bitmap->n) ofs = 0;

	i = ofs;
	while (i < bitmap->n) {
		if (~(bitmap->b[i/32])) {
			j = i;
			do {
				if (!bitmap_query(bitmap, j)) return j;
				j++;
			} while (j & 31 && j < bitmap->n);
		}
		i += 32;
		i &= ~31;
	}

	i = 0;
	while (i < ofs) {
		if (~(bitmap->b[i/32])) {
			j = i;
			do {
				if (!bitmap_query(bitmap, j)) return j;
				j++;
			} while (j & 31 && j < bitmap->n);
		}
		i += 32;
		i &= ~31;
	}

	return -1;
}

