#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "vector.h"
#include <string.h>

static void vector_free(vector** v);
static int vector_push(vector** v, void* data);
static int vector_empty(vector* v);
static void* vector_get(vector* v, int index);
static void* vector_pop(vector* v);
static int vector_update(vector* v, void* data, int index);

static int vector_len(vector* v);
static int vector_index(vector* v, void* data, size_t n);
static int vector_remove(vector* v, int index);

/**
 * create a vector 
 * @return : return a pointer point to a vector struct
 */
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
	new->remove = vector_remove;
	new->len = vector_len;
	new->index = vector_index;

	return new;
}


static int vecter_expend(vector* v, uint32_t len)
{
	int restLen = 0;
	int newLen = 0;
	void** tmp;
	if (NULL == v) {
		return -1;
	}

	restLen = v->total - v->current;
	if (restLen >= len) {
		return 1;
	}

	newLen = v->total;
	while (newLen < len) {
		newLen << 1;
	}

	tmp = (void**)realloc(v->data, newLen * sizeof(void **));
	if (NULL == tmp) {
		return -1;
	}

	v->data = tmp;
	v->total = newLen;
	return 0;
}

/**
 * Just release the vector container, if it has a element
 * release function, it will realease its elemets too!
 * @param v a pointer points to a pointer to vector
 * @return return nothing, and now vector has been released
 */
static void vector_free(vector** v)
{
	if (NULL == *v) {
		return;
	}

	int i = 0;
	if (*v->element_free) {
		for (i = 0; i < *v->current; i++) {
			*v->element_free(*v->data[i]);
			v->data[i] = NULL;
		}
	}

	free(*v->data);
	free(*v);
	*v = NULL;
	return;
}

/**
 * Push an element to vector
 * @param v a pointer points to vector
 * @param data a pointer points to a type of void ,which will push to the end of vector
 * @return 0: push ok; -1: push error!
 */
static int vector_push(vector* v, void* data)
{
	if (NULL == v) {
		return -1;
	}

	if (vecter_expend(v, 1) != 0) {
		return -1;
	}

	v->data[v->current] = data;
	v->current++;
	return 0;
}

/**
 * Check vector is empty or not
 * @param v a pointer points to vector
 * @return 1: Not empty; 0: Empty!
 */
static int vector_empty(vector* v)
{
	return v->current == 0;
}

/**
 * Get the sum of elements in vector
 * @param v a pointer points to vector
 * @return return the count of elements in v
 */
static int vector_len(vector* v)
{
	return v->current;
}

/**
 * return the index of the element in vector
 * @param v a pointer points to vector
 * @param data a pointer points to the element which will be indexed
 * @param return the index of the element
 */
static int vector_index(vector* v, void* data)
{
	int index = 0;
	if (NULL == v || v->current == 0) {
		return -1;
	}

	for (index = 0; index < v->current; index++) {
		if (v->element_free && v->element_compare(v->data[index], data) == 0) {
			return index;
		}
	}
	return -1;
}

/**
 * remove the data, which its index is index
 * vector_remove NOT REALEASE the data AUTO!
 * you must free the data by yourself!
 *
 * @param v a pointer point to vector
 * @param index the index of the data will be removed
 * @return return the data from the index of vector, error will return NULL
 */
void* vector_remove(vector* v, int index)
{
	if ( NULL == v || v->current == 0 || index > v->current) {
		return NULL;
	}

	void *tmp  = v->data[index];
	if (v->current - 1 == index) {
		v->data[index] = NULL;
	} else {
		for (; index < current - 1; index++){
			v->data[index] = v->data[index + 1];
		}
		v->data[index]= NULL;
	}
	v->current--;
	return tmp;
}

/**
 * get the the data from the gived index ,different from vector_remove
 * @see vector_remove
 * @param v a pointer points to vector
 * @param the gived index the will locate the data and return it
 * @return return the data
 */
static void* vector_get(vector* v, int index)
{
	if (v == NULL || index > v->current) {
		fprintf(stderr, "index is out of range!\n");
		return NULL;
	}

	return v->data[index];
}

/**
 * pop the data from the end of the vector
 * @param v a pointer points to vector
 * @return return the data from the end of the vector
 */
static void* vector_pop(vector* v)
{
	void* value = NULL;
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

/**
 * update the data
 * @param v a pointer points to vector
 * @data the new data will update the v[index]
 * @index the index
 */
static int vector_update(vector* v, void* data, int index)
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

int make_heap(vector* v, int (*compare)(void*, void*))
{
	int heap_size = v->current - 1;
	int i = 0;
	for (i = (v->current / 2) - 1; i >= 0; i--) {
		max_heapify(v, i, heap_size, compare);
		print(v);
	}
	return 0;
}

int heap_sort(vector* v, int (*compare)(void*, void*))
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


