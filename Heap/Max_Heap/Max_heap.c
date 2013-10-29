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
		head = (struct node *)relloc(head, (256 + max) *sizeof(struct node));

		if (NULL == head) {
			return -1;
		}

	
	}

	while(i < max) {
		ret = heap->compare(head[i]->data, data);
		
		if (ret > 0) {
			i = i*2 + 1;
		}	else if (ret < 0) {
			i = i*2 + 2;
		} else {
			return -1;
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


int MaxHeapInsert(int *a, int length, int num)
{
	int i = 0;	

	while (i < length) {
		if (a[i] > num) {
			i = 2 * i + 1;
		}	else if (a[i] < num) {
			i = 2 * i + 2;
		} else  {
			return 0;
		}

		if (a[i] == 0) {
			a[i] = num;
			break;
		}
	}
}



int MaxHeapDelete(int *a, int num)
{
	
}
