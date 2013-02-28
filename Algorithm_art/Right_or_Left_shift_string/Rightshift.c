#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RightShift_1(int *arr, int N, int K)
{
	int t = 0;
	int i = 0;
	while(K--)
	{
		t = arr[N - 1];
		for(i = N - 1; i > 0; i--)
			arr[i] = arr[i - 1];
		arr[0] = t;
	}
}

//-----------------------------------------------
void RightShift_2(int *arr, int N, int K)
{
	int t = 0;
	int i = 0;
	K %= N;
	while(K--)
	{
		t = arr[N - 1];
		for(i = N - 1; i > 0; i--)
			arr[i] = arr[i - 1];
		arr[0] = t;
	}
}
//-----------------------------------------------------

void Reverse(int *arr, int b, int e)
{
	int temp = 0;
	for(; b < e; b++, e--)
	{
		temp = arr[e];
		arr[e] = arr[b];
		arr[b] = temp;
	}
}

void RightShift_3(int *arr, int N, int K)
{
	K %= N;
	Reverse(arr, 0 , N - K -1);
	Reverse(arr, N - K, N - 1);
	Reverse(arr, 0, N - 1);
}
//-----------------------------------------------------------
void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
void Reverse(char *start, char *end)
{
	if (*start != '\0' && *end != '\0')
	{
		while (start < end)
		{
			swap(start, end);
			start++;
			end--;
		}
	}
}
char *LeftRotateString(char *src, unsigned int n)
{
	if (src != NULL)
	{
		int len = strlen(src);
		if ( n < len && n >0)
		{
			char *pFirstStart = src;
			char *pFirstEnd = src + n - 1;
			char *pSecondStart = src + n;
			char *pSecondEnd = src + len - 1; 
			Reverse(pFirstStart, pFirstEnd);
			Reverse(pSecondStart, pSecondEnd);
			Reverse(pFirstStart, pSecondEnd);
		}
	}

	return src;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
//-----------------------------------------------------------
//-----------------------------------------------------------
int main (int argc, char *argv[])
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int i = 0;
	RightShift_3(a,10,5);
	for (i = 0; i< 10; i++)
	{
		printf("%2d",a[i]);
	}
	
	return 0;
}
