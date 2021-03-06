#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------------------------------
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
	(*p)->next = NULL;
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
	int data;
	scanf("%d",&phead->num);
	while(1)
	{
		scanf("%d",&data);
		if(data>=0)
		{
			Init_Node(&pnew);
			pnew->num=data;
			
			Tail->next =pnew;
			Tail = pnew;
		}
		else{
			break;
		}
	}
}
//-----------------------------------------------------------------------------------------------
struct Linear_List *CreateList(LinkList L)
{
    LinkList p1;
    LinkList p2;
    int i=0;
    p1=(LinkList)malloc(Len);
    p2=p1;
    if(p1==NULL)
    {
        printf("\nCann't create it, try it again in a moment!\n");
        return NULL;
    }else
    {
        printf ("Please input %d node -- num: ", i + 1);
        scanf ("%d", &(p1->num));
    }
    while(p1->num!=0)
    {
        if(i==0)
        {
            L=p1;
            p2->next=NULL;
        }else
        {
            p2->next=p1;
        }
        p2=p1;
        i++;
        p1=(LinkList)malloc(Len);
         printf ("Please input %d node -- num: ", i + 1);
        scanf ("%d", &(p1->num));
    }
    p2->next=NULL;
    free(p1);
    p1=NULL;
   return L;
}
/*-------------------------------------------------------------------------------------------*/
void Print(LinkList L)
{
  /* if(L==NULL)
        return ;
    else
      printf("%d\n",L->num);
    return Print(L->next);*/
    /*---------------------------------------------------------------*/
  LinkList p;

    p=L;
    if(p!=NULL)
    {
      while(p!=NULL){
            printf ("%p   %d    %p\n", p, p->num, p->next);
            p=p->next;
        };
    }
    else
    {
        printf("\n the Linear_List is empty!!\n");
    }
}
/*-------------------------------------------------------------------------------------------*/
struct Linear_List *SortingList(LinkList L, int length)
{
  int outer=0;
 //int inner=0;
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
          /* for(inner=0;inner<outer;inner++)

            {
                   if(p1->num>=p2->num)
                   {
                       midvalue=p1->num;
                       p1->num=p2->num;
                       p2->num=midvalue;
                   }
                   p1=p2;
                   p2=p2->next;
            }*/
            while(p2!=NULL)
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




/*-------------------------------------------------------------------------------------------*/



struct Linear_List *Del_Node_List(LinkList L,int num)
{
    LinkList p1;
    LinkList p2;
    if(L==NULL)
    {
        printf("\n List is null!\n");
        return L;
    }
    p1=L;
    while(p1->num!=num&&p1->next!=NULL)
    {
        p2=p1;
        p1=p1->next;
    }
    if(p1->num==num)
    {
        if(p1==L)
        {
            L=p1->next;
        }else
        {
            p2->next=p1->next;
        }
        free(p1);
        p1=NULL;
        printf("\n delete %d success!\n",num);
    }else
    {
        printf("\n%d not been found!\n",num);
    }
   return L;
}
/*-------------------------------------------------------------------------------------------*/



struct Linear_List *Add_Node_List(LinkList L,struct Linear_List *Node)
{
    LinkList p1=NULL;
		LinkList p_front=NULL;

    if(L==NULL)
    {
        L=Node;
        Node->next=NULL;
    }
    p1=L;
		

    while(p1->num<Node->num&&p1->next!=NULL)
    {
				p_front=p1;
        p1=p1->next;
    }
    if(p1->next==NULL)
    {
        p1->next=Node;
        Node->next=NULL;
    }
    else if(p1->num>=Node->num)
    {
        //Node->next=p1->next;
        //p1->next=Node;
				p_front->next = Node;
				Node->next = p1;
    }
    else
    {
        printf("\n %d can not insert into the Linear_List!\n");
    }
   return L;
}


/*-------------------------------------------------------------------------------------------*/
/*void Destory_List(*p)
{
#if 0
	pNode pdel,phead =*p;
	if( *p !=NULL)
	{
			while( phead->next != NULL)
			{
					pdel = phead->next;
					phead->next = pdel->next;
					pdel->next =NULL;
					Destory_Memory((void **)&pdel);
			}
			Destory_Memory(p);
	}
#endif
	pNode pdel,ptrav ,phead = *p;
	if(*p!=NULL)
	{
			while(phead->next != NULL)
			{
					ptrav = phead;
					for(pdel = phead;pdel->next!=NULL;pdel=pdel->next)
					{
							ptrav = pdel;
					}
					ptrav->next =NULL;
					Destory_Memory((void **)&pdel);
			}
		Destory_Memory(p);
	}
}

*/
/*-------------------------------------------------------------------------------------------*/



struct Linear_List *Empty_List(LinkList L)
{
	
  return L;
}


int Linear_List_Length(LinkList L)
{
    int length=0;
    LinkList p=NULL;
    p=L;
   while(p!=NULL){
           length++;
            p=p->next;
        };
    return length;
}
