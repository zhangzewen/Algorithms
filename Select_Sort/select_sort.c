#include "select_sort.h"
void select_sort(int *a, int n)
{
	int i = 0;
	int j = 0;
	int min = 0;
	int t = 0;

	for(i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (a[min] > a[j])
				min = j;
		}
		
		if(min != i) {
			t = a[min];
			a[min] = a[i];
			a[i] = t;
		}
	}
}


int main(int argc, char **argv)
{
	int a[] = {9,8,7,6,5,4,3,2,1,0};
	select_sort(a, 10);
	return 0;
}
