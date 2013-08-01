#include <stdio.h>
#include <stdlib>

typedef struct {
	int size;
	int start;
	int end;
	ElemType *elems;
}CircularBuffer;

void cbInit(CircularBuffer *cb, int size)
{
	cb->size = size;
	cb->start = 0;
	cb->end = 0;
	cb->elems = (ElemType *)calloc(cb->size, sizeof(ElemType));
}

void cbPrint(CircularBuffer *cb)
{
	printf("size = 0x%x, start = %d, end = %d\n", cb->size, cb->start, cb->end);
}

int cbIsFull(CircularBuffer *cb)
{
	return cb->end == (cb->start ^ cb->size);
}


int cbIsEmpty(CircularBuffer *cb)
{
	return cb->end == cb->start;
}

int cbIncr(CircularBuffer *cb, int p)
{
	return (p + 1)&(2 * cb->size - 1);
}

void cbWrite(CircularBUffer *cb, ElemType *elem)
{
	cb->elems[cb->end & (cb->size -1)] = *elem;
	if (cbIsFull(cb))
		cb->start = cbIncr(cb, cb->start);
	cb->end = cbIncr(cb, cb->end);
}

void cbRead(CircularBuffer *cb, ElemType *elem)
{
	*elem = cb->elems[cb->start & (cb->size - 1)];
	cb->start = cbIncr(cb, cb->start);
}
