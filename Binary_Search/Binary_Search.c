#include<stdio.h>
#include<stdlib.h>
#icnlude"Binary_Search.h"

int Search_Bin(SSTable ST,KeyType key)
{
	low=1;
	high=ST.length
	while(low<high)
	{
		mid=(low+high)/2;
		if(key == ST.[elem].key)	return mid;
		else if(key<ST.[elem].key)	high =mid-1;	
		else low =mid+1;
	}
	return 0;
}
