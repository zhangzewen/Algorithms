#include "Max_heap.h"
#include <stdio.h>
#include <stdlib.h>
#if 0
struct Max_heap* creat_heap(int max)
{
	struct Max_heap *heap;
	
	heap = (struct Max_heap *)malloc(sizeof(struct Max_heap));	

	if (NULL == heap) {
		fprintf(stderr, "[%s:%s:%d]create Max_heap error!", __FILE__, __func__, __LINE__);
		return NULL;
	}

	heap->max = max;
	
	heap->node = (struct node *)calloc(max, sizeof(struct node));
	
	if (NULL == heap->node) {
		free(heap);
		return NULL;
	}

	return heap;
	
}

int InsertFixup()
{

}

int find(struct Max_heap *heap, void *data)
{
	struct node *head = heap->node;
	int i = 0;

	while (1) {
		ret = heap->compare(head[i]->data, data);
		if (ret > 0) {
			
		} else if (ret < 0) {
			
		} else {
		
		}
	}
}


int Insert(struct Max_heap *heap, void *data)
{

	struct node *head  = heap->node;
	int i = 0;
	int ret = 0;
	
	if (head[0]->data == NULL) {
			head[0]->data = data;
			return 0;
	}

	if (current >= max) {
		head = (struct node *)relloc(head, (HEAPINCREASE + heap->max) *sizeof(struct node));

		if (NULL == head) {
			return -1;
		}
		
		heap->max += 256;
	}

	while(i < max) {
		ret = heap->compare(head[i]->data, data);
		
		if (ret > 0) {
			i = i*2 + 1;
		}	else if (ret < 0) {
			i = i*2 + 2;
		} else {
			return 1;
		}

		if (head[i]->data == NULL &&  ret > 0) {
			head[i]->data = data;
			return 0;
		} else if(head[i]->data == NULL && ret < 0) {
			
		}
	}

		
}

int delete(struct Max_heap *heap, void *data)
{
	
}

int pop(struct Max_heap *heap, void *data)
{

}
#endif

struct heap* create()
{
	struct heap *heap = NULL;
	heap = calloc(1, sizeof(struct heap));

	if (NULL == heap) {
		fprintf(stderr, "[%s:%s:%d] calloc heap error!\n", __FILE__, __func__, __LINE__);
		return NULL;
	}

	heap->data = calloc(HEAPMAX, sizeof(int));
	
	if (NULL == heap->data) {
		fprintf(stderr, "[%s:%s:%d] calloc data error!\n", __FILE__, __func__, __LINE__);
		free(heap);
		return NULL;
	}

	heap->max = HEAPMAX;
	heap->current = 0;

	return heap;
}

int MaxHeapInsert(struct heap *heap, int num)
{
	if (heap->current == heap->max) {
		fprintf(stderr, "[%s:%s:%d] heap is full!", __FILE__, __func__, __LINE__);
		return -1;
	}		

	int i = heap->current;

	while(i != 0 && num > heap->data[(i -1) / 2]) {
		heap->data[i] = heap->data[(i - 1) / 2];
		i = (i - 1) / 2;
	}

	heap->data[i] = num;
	heap->current++;
	return 0;
}

int pop(struct heap *heap)
{
	if (heap->current == 0) {
		return 0;
	}	

	int maxvalue = heap->data[0];

	int lastvalue = heap->data[heap->current - 1];

	int child = 1;//堆最大节点的左子节点
	int i = 0; //堆的最大节点

	heap->current--;
	while (child <= heap->current) {
		if (child < heap->current &&
			heap->data[child] < heap->data[child + 1]) {
			child++;
		}

		if (lastvalue >= heap->data[child]) break;

		heap->data[i] = heap->data[child];
	
		i = child;
		
		child  = child * 2 + 1;
	}

	heap->data[i] = lastvalue;

	return 0;
}
