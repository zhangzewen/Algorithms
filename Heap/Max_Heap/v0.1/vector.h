#ifndef _HTTP_VECTOR_H_INCLUDED__
#define _HTTP_VECTOR_H_INCLUDED__


#define VECTOR_DEFAULT_TOTAL 6
#define VECTOR_INCREASE_SIZE 4

typedef struct vector_st vector;

struct vector_st{
	unsigned int total;
	unsigned int current;
	void **data;
	//int (*insert)(vector *,void *data, int index);
	int (*push)(vector *, void *data);
	void* (*pop)(vector *);
	void* (*get)(vector *, int index);
	int (*update)(vector *, void *data, int index);
	int (*Isempty)(vector *);
	void (*free)(vector *);
};

vector* vector_create();
/*
 *flag = 0 min_heap 
 *flag = 1 max_heap
 */
int make_heap(vector *v, int (*compare)(void *, void *));

void print(vector *v);

#endif
