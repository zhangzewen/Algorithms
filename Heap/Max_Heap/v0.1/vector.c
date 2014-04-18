#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "vector.h"
#include <string.h>

static void vector_free(vector *v);
static int vector_push(vector *v, void *data);
static int vector_empty(vector *v);
static void* vector_get(vector *v, int index);
static void* vector_pop(vector *v);
static int vector_update(vector *v, void *data, int index);

vector* vector_create()
{
	vector *new = NULL;
	new = calloc(1, sizeof(struct vector_st));
	
	if (NULL == new) {
			return NULL;
	}

	new->total = VECTOR_DEFAULT_TOTAL;
	new->current = 0;
	new->data = (void **)calloc(VECTOR_DEFAULT_TOTAL, sizeof(void **));
	
	if (NULL == new->data) {
		free(new);
		return NULL;
	}

	new->push = vector_push;
	new->pop = vector_pop;
	new->get = vector_get;
	new->update = vector_update;
	new->Isempty = vector_empty;
	new->free = vector_free;

	return new;
}

static void vector_free(vector *v)
{
	int i = 0;
	for (i = 0; i < v->current; i++) {
		free(v->data[i]);
		v->data[i] = NULL;
	}	
	free(v->data);
}

static int vector_push(vector *v, void *data)
{
	if (v->current == v->total) {
		void **tmp = NULL;
		tmp = (void **)realloc(v->data, (VECTOR_INCREASE_SIZE + v->total) * sizeof(void **));
		if (NULL == tmp) {
			return -1;
		} 

		v->data = tmp;
		v->total += VECTOR_INCREASE_SIZE;
	}

	v->data[v->current] = data;
	v->current++;
	return -1;
}

static int vector_empty(vector *v)
{
	return v->current;
}


static void *vector_get(vector *v, int index)
{
	if (v == NULL || index > v->current) {
		return NULL;
	}	
	
	return v->data[index];
}

#if 0
int insert(vector *v, void *data, int index)
{
	if (NULL == v || NULL == v->data) {
		return -1;
	}

	if (v->current + 1 > v->total) {
		void **tmp = NULL;
		tmp = (void **)(v->data, VECTOR_INCREASE_SIZE + v->total);
		if (NULL == tmp) {
			return -1;
		} 

		v->data = tmp;
		v->total += VECTOR_INCREASE_SIZE;
	}

	if ( index > v->current) {
		
	}	
}
#endif


static void* vector_pop(vector *v)
{
	void *value = NULL;
	int i = 0;
	if (NULL == v || NULL == v->data || v->current == 0) {
		return NULL;
	}

	value = v->data[0];
	for(i = 0; i< v->current - 1; i++) {
		v->data[i] = v->data[i + 1];
	}
	v->data[v->current - 1] = NULL;
	v->current--;
	return value;
}

static int vector_update(vector *v, void *data, int index)
{
	if (NULL == v || NULL == v->data || v->current == 0) {
		return -1;
	}

	if (index > v->current) {
		return -1;
	}
	v->data[index] = data;
	return 0;
	
}


static void max_heapify(vector *v, int i, int heap_size, int (*compare)(void *, void *))
{
	int lchild = 0;
	int rchild = 0;
	int largest = 0;

	lchild = 2 * i + 1;
	rchild = 2 * i + 2;	

	if (lchild <= heap_size && compare(v->data[lchild], v->data[i]) > 0) {
		largest = lchild;	
	} else {
		largest = i;
	}

	if (rchild <= heap_size && compare(v->data[rchild], v->data[largest]) > 0) {
		largest = rchild;
	}

	if (largest != i) {
		void *tmp = NULL;
		tmp = v->data[i];
		v->data[i] = v->data[largest];
		v->data[largest] = tmp;
		max_heapify(v, largest, heap_size, compare);
	}
} 





int make_heap(vector *v, int (*compare)(void *, void *))
{
	int heap_size = v->current - 1;	
	int i = 0;
	for (i = (v->current / 2) - 1; i >= 0; i--) {
		max_heapify(v, i, heap_size, compare);
		print(v);
	}
	return 0;
}


int heap_sort(vector *v, int (*compare)(void *, void *))
{
	int i = 0;
	int heap_size = v->current - 1;
	
	for (i = v->current - 1; i >= 1; i--) {
		void *tmp = NULL;

		tmp = v->data[0];
		v->data[0] = v->data[i];
		v->data[i] = tmp;

		heap_size--;

		max_heapify(v, 0, heap_size, compare);
		print(v);
	}
	return 0;
}


#if 1
void print(vector *v)
{
	int i = 0;	

	for(i = 0; i < v->current; i++){
		printf("%d ",*((int *)(v->data[i])));
	}

	printf("\n");
}
#endif
