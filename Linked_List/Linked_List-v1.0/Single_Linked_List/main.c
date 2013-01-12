#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"
int main()
{
	LinkList head;
	LinkList add;
	int length=0;
	Init_Node(&head);
	//head=CreateList(head);
	//Create_List_Head(head);
	Create_List_Tail(head);
	length=Linear_List_Length(head);
	printf("this linkedlist's length is :%d",length);
	printf("\nPrint the LinkedList:\n");
	Print(head);
	printf("\n Now let's have this linkedlist sorted!:\n ");
	head=SortingList(head,length);
	Print(head);
	printf("Now delete the num :10\n");
	head=Del_Node_List(head,10);
	Print(head);
	printf("\nNow add the num :10\n");
	Init_Node(&add);
	add->num=10;
	head = Add_Node_List(head,add);
	Print(head);
	printf("sizeof(struct Linear_List) is :%d\n",sizeof(struct Linear_List));
	return 0;
}
