#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 123456
#define k 100

void HeapAdjust(int array[], int i, int length)
{
	int child;
	int temp;
	for (temp = array[i]; (2*i + 1) < length ; i = child)
	{
		child = 2*i + 1;
		if(child < length - 1 && array[child + 1] < array[child])
			child++;
		if(temp > array[child])
			array[i] = array[child];
		else
			break;
		array[child] = temp;
	}
}

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int GetMin(int *array, int len, int k)
{
	int min = array[0];
	swap(&array[0], &array[len - 1]);
	
	int child;
	int temp;
	int i = 0;
	int j = k - 1;
	for(temp = array[0]; j > 0 && (2*i + 1) <len; --j, i = child)
	{
		child = 2*i + 1;
		if (child < len -1 && array[child + 1] < array[child])
			child++;
		if(temp > array[child])
			array[i] = array[child];
		else
			break;
		array[child] = temp;
	}
	return min;
}

void Kmin(int array, int len, int k)
{
	int i;
	int j;
	for (i = len/2 - 1; i >= 0; --i)
		HeapAdjust(array, i ,len);
	j = len;	

	for(i = k; i > 0; --i, --j)
	{
		int min = GitMin(array, j,i);
		printf("%d",min);
	}
}

