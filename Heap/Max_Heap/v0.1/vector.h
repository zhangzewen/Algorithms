#ifndef _HTTP_VECTOR_H_INCLUDED__
#define _HTTP_VECTOR_H_INCLUDED__


#define VECTOR_DEFAULT_TOTAL 6
#define VECTOR_INCREASE_SIZE 4

typedef struct vector_st vector;

struct vector_st{
	unsigned int total;
	unsigned int current;
	void **data;
	int (*push)(vector *, void *data);
	void* (*pop)(vector *);
	void* (*get)(vector *, int index);
	int (*update)(vector *, void *data, int index);
	int (*Isempty)(vector *);
};

vector* vector_create();

int make_heap(vector *v, int (*compare)(void *, void *));

int heap_sort(vector *v, int (*compare)(void *, void *));

void Print(vector *v, void (*func)(void *visit));

void vector_destroy(vector **v, void (*free)(void *));

#endif
