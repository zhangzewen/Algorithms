#include "Dlinkedlist.h"
#include<stdio.h>
#include<stdlib.h>
struct DLinear_List *CreateDList(DLinkList L)
{
	DLinkList p1;
	DLinkList p2;
	int i=0;
	p1=(DLinkList)malloc(Len);
	p2=p1;
	if(NULL==p1)
	{
		printf("\nCann't creat it ,try again in a moment!\n");
		exit(1);
	}else
	{
		printf("Please input %d node--num: ",i+1);
		scanf("%d",&(p1->num));
	}
	while(p1->num!=0&&p1->num>0)
	{
		if(0==i)
		{
			L=p1;
			L->before=L;
			L->next=L;
		}else
		{
			p2->next=p1;
			p1->before=p2;
		}
		p2=p1;
		++i;
		p1=(DLinkList)malloc(Len);
		printf("Please input %d node--num: ",i+1);
		scanf("%d",&(p1->num));
	};
	p2->next=L;
	L->before=p2;
	free(p1);
	p1=NULL;
	return L;
}

void Print(DLinkList L)
{
	DLinkList p;
	if(NULL== L)
	{
		printf("\nIt is an empty Dlinkedlist!\n");
		exit(0);
	}
	else
	{
		p=L;
		//do{
		//	printf("%o		%o		%d		%o\n",p->before,p,p->num,p->next);
		//	p=p->next;
		//}while(p->next!=L);
		while(p)
		{
			printf("%p		%p		%d		%p\n",p->before,p,p->num,p->next);
			p=p->next;
			if(p->next==L)
			{
			 printf("%p		%p		%d		%p\n",p->before,p,p->num,p->next);
			 break;
		 	}
		}
	}
}

struct DLinear_List *SortingDList(DLinkList L ,int length)
{
		int outer=0;
  	int midvalue=0;
    DLinkList p1=NULL;
    DLinkList p2=NULL;
    if(L==NULL)
    {
            printf(" It's a  empty Linear List!Can not be sorted!");
            return NULL ;
    }

    else
    {

        for(outer=length;outer>0;outer--)
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


int DLinear_List_Length(DLinkList L)
{
	int length=0;
	DLinkList p;
	if(NULL==L)
	{
		printf("\nIt's an empty DLinkList!\n");
		return 0;
	}
	p =L;
	while(p->next!= L)
	{
		length++;
		p=p->next;
	}
	return length+1;
}


struct DLinear_List *Del_Node_DList(DLinkList L ,int num)
{
	DLinkList p;
	if(NULL == L)
	{
		printf("\n This is a empty Dlinkedlist!\n");
		exit(1);
	}else{
		p = L;
		while(p->next!=L&&p->num!=num)
		{
			p=p->next;
		}
		if(p->num==num)
		{
			if(p == L)
			{
				p->before->next = p->next;
				p->next->before = p->before;
				L = p->next;
				free(p);
			}else
			{
				p->before->next = p->next;
				p->next->before = p->before;
				free(p);
			}
		}
		else if(p->next == L)
		{
				printf("the node of \"%d\" is not exstis!",num);
			
		}
		else{
				printf("the node of \"%d\" is not exstis!",num);
		}
	}
	return L;
}

struct DLinear_List *Add_Node_DList(DLinkList L ,struct DLinear_List *Node)
{
	DLinkList p;
	if(NULL == L)
	{
			L=Node;
			L->next=L;
			L->before =L;
	}
	p = L->next;
	while(p != L && p->num <= Node->num)
	{
			printf("Add_Node_DList[%d]\n",__LINE__);
		  p=p->next;
			printf("Add_Node_DList[%d]\n",__LINE__);
	}
	if(p == L)
	{
		Node->next = L;
		Node->before = L->before;
		L->before->next = Node;
		L->before = Node;
	}
	else if(p->num > Node->num)
	{
		printf("Add_Node_DList[%d]\n",__LINE__);
		Node->next = p;
		Node->before = p->before;
		p->before->next = Node;
		p->before = Node;	
		printf("Add_Node_DList[%d]\n",__LINE__);
	}
	else
	{
		printf("\nCan not add the %d to the DList!\n",Node->num);
	}	
	return L;
}


void Create_Memory(void **p,int size)
{
	*p = malloc(size);
}

void Destory_Memory(void **p)
{
		if(*p !=NULL)
		{
				free(*p);
				*p = NULL;
		}
}

void Destory_DList(DLinkList *L)
{
		DLinkList p_head,p_current,p_front;
		if(*L == NULL)
		{
				printf("this is an empty list!\n");
				return ;
		}
		p_head = *L;
		while(p_head->next != p_head)
		{
				for(p_current = p_head; p_current->next != p_head; p_current = p_current->next)
				{
					printf("Destory_DList[%d]\n",__LINE__);
				}
				p_current->before->next = p_head;
				p_head->before = p_current->before;
				p_current->next = p_current;
				p_current->before = p_current;
				Destory_Memory((void **)&p_current);
		}
		Destory_Memory((void **)L);
}

