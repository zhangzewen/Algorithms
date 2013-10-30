
#include <stdio.h>
#include <stdlib.h>
#include "Min_Heap.h"
#if 0
/*
 *一般都用数组来表示堆，i节点的父节点下标就为(i - 1) / 2，它的左右子节点的下标
 *分别是 2 * i + 1 和 2 * i + 2
 *每次插入都是将新数据放在数组最后。可以发现从这个新数据的父节点到根节点必然为一个有序的数列
 *现在的任务是将这个新数据插入到这个有序数据中
 *类似于直接插入排序中将一个数据并入到有序的区间去
 */

//新加入i节点，其父节点为(i - 1) / 2
void MinHeapFixup(int *a, int i)
{
	int j;
	int temp;
	
	temp = a[i];
	
	j = (i - 1) / 2; //父节点
	
	while (j >= 0 && i != 0) {
		if (a[j] <= temp) {
			break;
		}
	
		a[i] = a[j]; //把较大的子节点往下移动，替换它的子节点
		
		i = j;
		
		j = (i - 1) / 2;
	}
	
	a[i] = temp;
}


void MinHeapAddNumber(int *a, int n, int num)
{
	a[n] = num;
	
	MinHeapFixup(a, n);
}


/*
 *按定义，堆中每次都只能删除第0个数据，为了便于重建堆，实际的操作是将最后
 *一个数据的值赋给根节点，然后再从跟节点开始进行一次从上向下的调整。
 *调整时先在左右儿子节点中找最小的，如果父节点比这个最小的子节点还小说明不需要调整了
 *反之将父节点和它交换后在考虑后面的节点。
 */







void MinHeapFixdown(int *a, int i, int n)
{
	int j;
	int temp;
	
	temp = a[i];
	
	j = 2 * i + 1;
	
	while (j < n) {
		if (j + 1 < n && a[j + 1] < a[j]) { //在左右孩子中找最小的
			j++;
		}

		if (a[j] >= temp) {
			break;
		}

		a[i] = a[j];//把较小的子节点往上移动，代替它的父节点

		i = j;
		
		j = 2 * i + 1;
	}

	a[i] = temp;
}



void MinHeapDeleteNumber(int *a, int n)
{
	int tmp;
	a[0] = tmp;
	a[0] = a[n - 1];
	
	a[n - 1] = tmp;

	MinHeapFixdown(a, 0, n - 1);
}


void MakeMinHeap(int *a, int n)
{
	int i = 0;

	for (i = n / 2 - 1; i >= 0; i--) {
		MinHeapFixdown(a, i, n);
	}
}


void MinheapsortTodescendarry(int *a, int n)
{
	for (i = n - 1; i >= 1; i--) {
		Swap(a[i], a[0]);
		MinHeapFixdown(a, 0, 1);
	}
}
#endif





struct heap* create()
{
	struct heap* heap;
	
	heap = calloc(1, sizeof(struct heap));
	
	if (NULL == heap) {
		fprintf(stderr, "[%s:%s:%d] calloc heap error!\n", __FILE__, __func__, __LINE__);
		return NULL;
	}

	heap->current = 0;
	heap->max = HEAPMAX;

	heap->data = calloc(HEAPMAX, sizeof(int));

	if (NULL == heap->data) {
		fprintf(stderr, "[%s:%s:%d] calloc data error!\n", __FILE__, __func__, __LINE__);
		free(heap);
		return NULL;
	}
	return heap;	
}


int MinHeapInsert(struct heap* heap, int num)
{
	if (heap->current == heap->max) {
		fprintf(stderr, "[%s:%s:%d] heap is full!\n", __FILE__, __func__, __LINE__);
		return -1;
	}	

	int i = heap->current;

	while(i !=0 && num < heap->data[(i - 1)/2]) {
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

	int minvalue = heap->data[0];

	int lastvalue = heap->data[heap->current - 1];

	int child = 1;
	int i = 0;
	
	heap->current--;
	
	while (child <= heap->current) {
		if (child < heap->current &&
			heap->data[child] > heap->data[child + 1]) {
			child ++;
		}

		if (lastvalue < heap->data[child]) break;
	
		heap->data[i] = heap->data[child];

		i = child;
		
		child = child * 2 + 1;
	}

	heap->data[i] = lastvalue;

	return 0;
}
