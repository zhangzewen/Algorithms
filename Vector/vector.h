#ifndef _HTTP_VECTOR_H_INCLUDED__
#define _HTTP_VECTOR_H_INCLUDED__


#define VECTOR_DEFAULT_TOTAL 6
#define VECTOR_INCREASE_SIZE 4

typedef struct vector_st vector;

struct vector_st{
	unsigned int total;
	unsigned int current;
	void **data;
	int (*push)(vector*, void *data); //done
	void* (*pop)(vector*);//done
	void* (*get)(vector*, int index);//done
	int (*update)(vector*, void *data, int index);//done
	int (*Isempty)(vector*);//done
	int (*size)(vector*); //done
	int (*index)(vector*, void*);// done
	void* (*remove)(vector*, int index);
	int (*insert)(vector*, int index, void *data); //done
//	int (*pinsert)(vector*, void *ptr, void *data);
	int (*insertn)(vector*, int index, int count, void *data);//done
//	int (*pinsertn)(vector*, void *ptr, void *data, int n);
//	int (*insert_range)(vector*, int index, void *start, void *end);
//	int (*pinsert_range)(vector*, void *ptr, void *start, void *end);
	void (*element_free)(void *data);
	int (*element_compare)(void* dest, void* src);
	void (*visit)(void* data);
	void (*dump)(vector*);
};

vector* vector_create();
void vector_free(vector** v);
int make_heap(vector *v, int (*compare)(void *, void *));
int heap_sort(vector *v, int (*compare)(void *, void *));
#endif
