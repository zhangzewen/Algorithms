#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define Len sizeof(struct Linear_List)
typedef struct Linear_List
{
    int num;
    struct Linear_List *next;
}*LinkList;

struct Linear_List *CreateList(LinkList L);


void Print(LinkList L);

struct Linear_List *SortingList(LinkList L ,int length);

struct Linear_List *Del_Node_List(LinkList L ,int num);

struct Linear_List *Add_Node_List(LinkList L,struct Linear_List *Node);

struct Linear_List *Del_List(LinkList L);

struct Linear_List *Empty_List(LinkList L);

int Linear_List_Length(LinkList L);


#endif // LINEAR_LIST_H_INCLUDED

