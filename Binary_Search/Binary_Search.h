#include<stdio.h>
#include<stdlib.h>

typedef struct {
	ElemType *elem;
	int length;
}BBTable;

int Search_Bin(SSTable ST,KeyType key);
