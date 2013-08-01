#include <stdio.h>
#include <string.h>

typedef struct {
	int size;
	int start;
	int end;
	int s_msb;
	int e_msb；
	ElemType *elems
}CircularBuffer;

void cbInit(CircularBuffer *cb, int size)
{
	cb->size = size;
	cb->start = 0;
	cb->end = 0;
	cb->s_msb = 0;
	cb->e_msb = 0;
	cb->elems = (ElemType *)calloc(cb->size, sizeof(ElemType));
}

int cbIsFull(CircularBuffer *cb)
{
	return cb->end == cb->start && cb->e_msb != cb->s_msb;
}

int cbIsEmpty(CircularBuffer *cb)
{
	return cb->end == cb->start && cb->e_msb  == cb->s_msb;
}

void cbIncr(CircularBuffer *cb, int *p, int *msb)
{
	*p = *p + 1;
	
	if (*p == cb->size) {
		*msb ^= 1;
		*p = 0;
	}
	
}


void cbWrite(CircularBuffer *cb, ElemType *elem)
{
	cb->elems[cb->end] = *elem;
	if (cbIsFull(cb))
		cbIncr(cb, &cb->start, &cb->s_msb);
	cbIncr(cb, &cb->start, &cb->s_msb);
}

void cbRead(CircularBuffer *cb, ElemTypd *elem)
{
	*elem = cb->elems[cb->start];
	cbIncr(cb, &cb->start, &cb->s_msb);
}
