#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void Create_Memory(void **p,int size)
{
	*p = malloc(size);
}

void Destory_Memory(void **p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}

void Init_Node(LinkList *p)
{
	Create_Memory((void **)p,sizeof(struct Linear_List));
	(*p)->num = 0;
	(*p)->next = *p;
}

void Create_List_Head(LinkList phead)
{
	LinkList pnew;
	int data;
	scanf("%d",&phead->num);
	while(1)
	{	
		scanf("%d",&data);
		if(data>=0)
		{
			Init_Node(&pnew);	
			pnew->num=data;
			pnew->next = phead->next;
			phead->next = pnew;
		}
		else
		{
			break;
		}
	}
	
}

void Create_List_Tail(LinkList phead)
{
	LinkList Tail=phead;
	LinkList pnew;
	int data=0;
	scanf("%d",&data);
	if(data >= 0)
	{
		phead->num =data;
	}
	else
	{
		return ;
	}
	while(1)
	{
		scanf("%d",&data);
		if(data>=0)
		{
			Init_Node(&pnew);
			pnew->num=data;
			
			Tail->next =pnew;
			Tail = pnew;
			pnew->next=phead;
		}
		else{
			break;
		}
	}
}
void Print(LinkList L)
{
  LinkList p;

    p=L;
    if(p!=NULL)
    {
      while(p->next!=L){
            printf ("%p   %d    %p\n", p, p->num, p->next);
            p=p->next;
        };

            printf ("%p   %d    %p\n", p, p->num, p->next);
    }
    else
    {
        printf("\n the Linear_List is empty!!\n");
    }

}
struct Linear_List *SortingList(LinkList L, int length)
{
	int outer=0;
	int midvalue=0;
	LinkList p1=NULL;
	LinkList p2=NULL;
	if(L==NULL)
	{
		printf(" It's a  empty Linear List!Can not be sorted!");
		return NULL ;
	}

	else
	{
		for(outer=length-1;outer>=1;outer--)
		{
			p1=L;
			p2=L->next;
			while(p2!=L)
			{
				if(p1->num>=p2->num)
				{
					midvalue=p1->num;
					p1->num=p2->num;
					p2->num=midvalue;
				}
				p1=p2;
				p2=p2->next;
			};
		}
	}
	return L;
}

struct Linear_List *Del_Node_List(LinkList L,int num)
{
    LinkList p1;
    LinkList p2;
		LinkList Tail;
    if(L->next==L)
    {
        printf("\n List is null!\n");
        return L;
    }
    p1=L;
		Tail=L;
		while(Tail->next!=L)
		{
			Tail = Tail->next;
		}
    while(p1->num!=num&&p1->next!=L)
    {
        p2=p1;
        p1=p1->next;
    }
    if(p1->num==num)
    {
        if(p1==L)
        {
            L=L->next;
						Tail->next = L;
        }else
        {
            p2->next=p1->next;
        }
        Destory_Memory((void **)&p1);
        printf("\n delete %d success!\n",num);
    }else
    {
        printf("\n%d not been found!\n",num);
    }
   return L;
}

struct Linear_List *Add_Node_List(LinkList L,struct Linear_List *Node)
{
		LinkList p_front;
		LinkList p_current;
		LinkList p_tail;
		if(NULL == L)
		{
			L=Node;
			L->next = L;
		}

		p_tail = L;
		p_current = L;
		
		while(p_tail->next!=L)
		{
			p_tail = p_tail->next;
		}
		
		while( p_current->next != L&& p_current->num < Node->num)
		{
				p_front = p_current;
				p_current=p_current->next;
		}
		if(p_current->num >= Node->num)
		{
			if(p_current == L)
			{
				Node->next =L;
				p_tail->next =Node;
				L = Node;
			}
			else
			{
				p_front->next =Node;
				Node->next = p_current;
			}
		}
		else if(p_current->next == L)
		{
				Node->next =L;
				p_current->next = Node;
		}
		else 
		{
				printf("\nCan not add the Node :%d!\n",Node->num);
				return L;
		}
		return L;
}


Destory_List(LinkList *p)
{
	LinkList pdel,phead =*p;
	if( *p !=NULL)
	{
			while( phead->next != phead)
			{
					pdel = phead->next;
					phead->next = pdel->next;
					pdel->next =NULL;
					Destory_Memory((void **)&pdel);
			}
			Destory_Memory((void **)p);
	}
/*
	LinkList pdel,p_front ,phead = *p;
	if(*p != NULL)
	{
			while(phead->next != phead)
			{
					printf("Destory_List[%d]++++++++++++++++++++++++++++++++++++++++++++++\n",__LINE__);
					for(pdel = phead;pdel->next!=phead;pdel=pdel->next)
					{
						p_front = pdel;
						printf("Destory_List[%d]\n",__LINE__);
					}
					p_front->next = phead;;
					Destory_Memory((void **)&pdel);
					printf("Destory_List[%d]++++++++++++++++++++++++++++++++++++++++++++++\n",__LINE__);
			}
		printf("Destory_List[%d]\n",__LINE__);
		Destory_Memory((void **)p);
		printf("Destory_List[%d]\n",__LINE__);
	}*/
}

/*-------------------------------------------------------------------------------------------*/

int Linear_List_Length(LinkList L)
{
    int length=0;
    LinkList p=NULL;
    p=L;
   while(p->next!=L){
           length++;
            p=p->next;
        };
    return length+1;
}
