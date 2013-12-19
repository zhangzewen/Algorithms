#include <stdio.h>
#include "Merge_Sort.h"

void Merge(int a[],int b[],int low,int mid,int high)
{
	int k = low;
	int begin_1 = low;
	int end_1 = mid;
	int begin_2 = mid+1;
	int end_2 = high;
	int q = 0;

	while(begin_1 <= end_1 && begin_2 <= end_2)
	{
		if(a[begin_1] <= a[begin_2])
		{
			b[k++] = a[begin_1++];
		}
		else
		{
			b[k++] = a[begin_2++];
		}
	}
	if(begin_1 <= end_1)
	{
		for(q = begin_1;q <= end_1;q++)
				b[k++] = a[q];
	}
	if(begin_1 <= end_1)
	{
		for(q = begin_2;q<= end_2;q++)
				b[k++] = a[q];
	}
}


void Merge_Pass(int a[],int b[],int seg,int size)
{
	int seg_start_ind = 0;
	int j = 0;
	while(seg_start_ind < size - 2*seg)
	{
			Merge(a,b,seg_start_ind,seg_start_ind+seg-1,seg_start_ind+seg*2 -1);
			seg_start_ind +=2*seg;
	}
	if(seg_start_ind + seg <size)
		Merge(a,b,seg_start_ind,seg_start_ind+seg -1,size-1);
	else
	{
		for(j = seg_start_ind;j<size;j++)
			b[j] = a[j];
	}
}

void Merge_Sort(int a[],int size)
{
		int *temp = a;
		int seg = 1;
		while(seg<size)
		{
			Merge_Pass(a,temp,seg,size);
			seg += seg;
			Merge_Pass(temp,a,seg,size);
			seg += seg;
		}
}
