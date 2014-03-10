#include<stdio.h>
#include<stdlib.h>
#include"QuickSort.h"
int Partition(int a [] ,int low,int high)
{
	int pivotkey =a[low];
	while(low<high)	
	{
		while (low<high && a[high]>=pivotkey) --high;
		a[low]=a[high];
		while (low<high && a[low]<=pivotkey) ++low;
		a[high] =a[low];
	}
	a[low]=pivotkey;
	return low;
}
void QuickSort(int a[],int low,int high)
{
	int pivotkey =Partition(a,low,high);
	if(pivotkey-1>low)
	{
		QuickSort(a,low,pivotkey-1);
	}
	if(pivotkey+1<high)
	{
		QuickSort(a,pivotkey+1,high);
	}
}
