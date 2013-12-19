#include<stdio.h>
#include<stdlib.h>
#include"QuickSort.h"

int main()
{
	int a[]={3,6,5,8,5,4,9,7,2,8,3,5,6,8,1,0};
	int i=0;
	int j=0;
	for(i=0;i<16;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\nAfter the QuickSort!\n");
	QuickSort(a,0,15);
	for(j=0;j<16;j++)
	{
		printf("%d ",a[j]);
	}
	printf("\nDone\n");
	return 0;
}
