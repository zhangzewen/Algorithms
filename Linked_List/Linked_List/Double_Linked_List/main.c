#include<stdio.h>
#include<stdlib.h>
#include "Dlinkedlist.h"
int main()
{
	DLinkList head;
	int length =0;
	head=CreateDList(head);
	Print(head);
	length=DLinear_List_Length(head);
	printf("this linkedlist's length is :%d",length);
	printf("\nPrint the LinkedList:\n");
	Print(head);
	printf("\n Now let's have this linkedlist sorted!:\n ");
	head=SortingDList(head,length);
	Print(head);
	return 0;
}
