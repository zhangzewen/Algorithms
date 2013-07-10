#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int value;
}ElemType;

typedef struct {
	int size;
	int start;
	int end;
	ElemType *elems;
}CircularBuffer;	


void cbInit(CircularBuffer *cb, int size)
{
	cb->size = size + 1;
	cb->start = 0;
	cb->end = 0;
	cb->elems = (ElemType *)calloc(cb->size, sizeof(ElemType));
}


void cbFree(CircularBuffer *cb)
{
	free(cb->elems);
}


int cbIsFull(CircularBuffer *cb)
{
	return (cb->end + 1) % cb->size == cb->start;
}

int cbIsEmpty(CircularBuffer *cb)
{
	return cb->end == cb->start;
}


void cbWrite(CircularBuffer *cb, ElemType *elem)
{
	cb->elems[cb->end] = *elem;
	cb->end = (cb->end + 1) % cb->size;
	if(cb->end == cb->start) {
		cb->start = (cb->start + 1) % cb->size;
	}
}


void cbRead(CircularBuffer *cb, ElemType *elem) {
	*elem = cb->elems[cb->start];
	cb->start = (cb->start + 1) % cb->size;
}


int main(int argc, char **argv)
{
	CircularBuffer cb;
	ElemType elem = {0};
	
	int testBufferSize = 10;
	
	cbInit(&cb, testBufferSize);

	for(elem.value = 0; elem.value < 3 * testBufferSize; ++ elem.value) {
		cbWrite(&cb, &elem);
	}

	while(!cbIsEmpty(&cb)) {
		cbRead(&cb, &elem);
		printf("%d\n", elem.value);
	}	


	cbFree(&cb);
	return 0;
}
