#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"
int main()
{
	LinkList head;
	LinkList add;
	int length=0;
	int del_num=0;
	Init_Node(&head);
	Create_List_Tail(head);
	length=Linear_List_Length(head);
	printf("this linkedlist's length is :%d",length);
	printf("\nPrint the LinkedList:\n");
	Print(head);
	printf("\n Now let's have this linkedlist sorted!:\n ");
	head=SortingList(head,length);
	Print(head);
	printf("Now delete the num :\n");
	scanf("%d",&del_num);
  head=Del_Node_List(head,del_num);
	Print(head);
	printf("\nNow add the num :\n");
	Init_Node(&add);
	scanf("%d",&add->num);
	putchar('\n');
	head = Add_Node_List(head,add);
	Print(head);
	printf("sizeof(struct Linear_List) is :%d\n",sizeof(struct Linear_List));
	Destory_List(&head);
	return 0;
}
