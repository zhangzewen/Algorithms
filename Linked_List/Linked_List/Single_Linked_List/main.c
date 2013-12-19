#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"
int main()
{
	LinkList head;
	int length=0;
	head=CreateList(head);
	length=Linear_List_Length(head);
	printf("this linkedlist's length is :%d",length);
	printf("\nPrint the LinkedList:\n");
	Print(head);
	printf("\n Now let's have this linkedlist sorted!:\n ");
	head=SortingList(head,length);
	Print(head);
	return 0;
}
