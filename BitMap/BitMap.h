#ifndef _ALGORITHMS_BITMAP_H_INCLUDED_
#define _ALGORITHMS_BITMAP_H_INCLUDED_

#include <stdint.h>

typedef struct bitmap_st bitmap_t;
struct bitmap_st {
	uint32_t *b;
	int n;
};

bitmap_t *bitmap_create(int n);

void bitmap_free(bitmap_t *bitmap);

int bitmap_set(bitmap_t *bitmap, unsigned i);

int bitmap_clear(bitmap_t *bitmap, unsigned i);

int bitmap_query(bitmap_t *bitmap, unsigned i);

int bitmap_find(bitmap_t *bitmap, unsigned ofs);

#endif
