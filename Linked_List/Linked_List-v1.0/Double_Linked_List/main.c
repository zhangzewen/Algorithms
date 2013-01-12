#include<stdio.h>
#include<stdlib.h>
#include "Dlinkedlist.h"
int main()
{
	DLinkList head;
	DLinkList add_node;
	int length =0;
	int num = 0;
	add_node = (struct DLinear_List *)malloc(sizeof(Len));
	if(add_node == NULL)
	{
		printf("add_node malloc error!\n");
	}
	head=CreateDList(head);
	length=DLinear_List_Length(head);
	printf("this linkedlist's length is :%d",length);
	printf("\nPrint the LinkedList:\n");
	Print(head);
  printf("\n Now let's have this linkedlist sorted!:\n ");
	head=SortingDList(head,length);
	Print(head);
	//printf("please input the num you want to delete:");
	//scanf("%d",&num);
	//head = Del_Node_DList(head,num);
	//Print(head);
	printf("please input the num you want to add:");
	scanf("%d",&num);
	add_node->num = num;
	head = Add_Node_DList(head,add_node);
	Print(head);
	Destory_DList(&head);
	printf("&head is %p",head);
	return 0;
}
