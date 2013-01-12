#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#define Len sizeof(struct DLinear_List)
typedef struct DLinear_List
{
	int num;
	struct DLinear_List *next,*before;
}*DLinkList;

struct DLinear_List *CreateDList(DLinkList L);

void Print(DLinkList L);

struct DLinear_List *SortingDList(DLinkList L ,int length);

struct DLinear_List *Del_Node_DList(DLinkList L ,int num);

struct DLinear_List *Add_Node_DList(DLinkList L ,struct DLinear_List *Node);

struct DLinear_List *Del_DList(DLinkList L);

struct DLinear_List *Empty_DList(DLinkList L);

int DLinear_List_Length(DLinkList L);

void Create_Memory(void **p,int size);

void Destory_Memory(void **p);

void Destory_DList(DLinkList *L);

#endif
