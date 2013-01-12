/* quick sort algorithms */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Partition_for_int(int *a ,int low,int high)
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
char *Partition_for_char(char *src, char *low, char *high)
{
	char pivotkey = *low;
	while(low < high) {
		while((low < high) && ((*high - pivotkey) > 0 || (*high - pivotkey) == 0)) 
		{
			high--;
		}
		*low = *high;
		while(low < high && (*high - pivotkey < 0))
		{
			low++;
		}
		*high = *low;
	}
	*low = pivotkey;
	return low;
}
void quick_sort_for_int(int *in, int low, int high)
{
	int pivotkey =Partition_for_int(in,low,high);
	if(pivotkey-1>low)
	{
		quick_sort_for_int(in,low,pivotkey-1);
	}
	if(pivotkey+1<high)
	{
		quick_sort_for_int(in,pivotkey+1,high);
	}
}
void do_quick_sort_for_char(char *in, char *low, char *high)
{
	char *pivotkey  = Partition_for_char(in, low, high);
	if(pivotkey - 1 > low) {
		do_quick_sort_for_char(in, low, pivotkey - 1);
	}
	if(pivotkey + 1 < high) {
		do_quick_sort_for_char(in, pivotkey + 1, high);
	}
}

void quick_sort_for_char(char *in)
{
	char *low = NULL;
	char *high = NULL;
	if(NULL == in) {
		fprintf(stderr,"the string which be sorted empty!\n");
		exit(1);
	}
	low = in;
	high = in + strlen(in) - 1;
	do_quick_sort_for_char(in, low, high);
}
