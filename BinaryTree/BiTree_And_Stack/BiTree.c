#include<stdio.h>
#include"BiTree.h"
#include<stdlib.h>

SqStack InitStack(SqStack S)
{
	S=(SqStack)malloc(sizeof(struct Stack));
	S->base =(struct BiTNode **)malloc(STACK_INIT_SIZE*sizeof(struct BiTNode**));
	if(!S->base) exit(1);
	S->top=S->base;
	S->stacksize =STACK_INIT_SIZE;	
	return S;
}

BiTree GetTop(SqStack S)
{	
	BiTree e;
	BiTree *p;
	p=S->top;
	if(S->top == S->base) return 0 ;
	p=p-1;
	e=*p;
	return e;
	
}

SqStack Push(SqStack S,BiTree e)
{	
	if((S->top)-(S->base)>=(S->stacksize)){
		S->base =(BiTree*)realloc(S->base,(S->stacksize + STACKINCREMENT)*sizeof(struct BiTNode**));
		
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;	
	}
	*(S->top)=e;
	S->top++;
	return S;
}


BiTree Pop(SqStack S)
{
	BiTree e;
	if(S->top ==S->base) return NULL;
	S->top=S->top-1;
	e=*S->top;
	return e;
}
int StackEmpty(SqStack S)
{
	if(S==NULL||(S->base == S->top))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



Status CreateBiTree(BiTree *T)
{
	char ch;
	ch=getchar();

	if(ch=='#') (*T)=NULL;
	else
	{ 
		if(!((*T)=(BiTree)malloc(sizeof(struct BiTNode))))   exit(FALUSE);
		(*T)->data=ch;
		(*T)->lflag = 0;
		(*T)->rflag = 0;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);

	}
	return OK;	
}

void PreOrderTraverse(BiTree T)
{
	SqStack S=NULL;
	S=InitStack(S);
	BiTree p=NULL;
	p=T;
	while(p||!StackEmpty(S))
	{
		if(p)
		{
			printf("%4c",p->data);
			S=Push(S,p);
			p=p->lchild;
		}
		else
		{
			p=Pop(S);
			p=p->rchild;
		}
	}
}
void InOrderTraveerse(BiTree T)
{
		SqStack S=NULL;
		S=InitStack(S);
		BiTree p=NULL;
		p=T;
		while(p||!StackEmpty(S))
		{
			if(p){S=Push(S,p); p=p->lchild;}
			else
			{
				p=Pop(S);
				printf("%4c",p->data);
				p=p->rchild;
			}
		}
}
//
void PostOrderTravaerse(BiTree T)
{
/*
	SqStack S=NULL;
	S=InitStack(S);
	BiTree p=NULL;
	char flag;
	BiTree q = NULL;
	p = T;
	while(p || !StackEmpty(S))
	{
		if(p != q)
		{
				while(p)
				{
					Push(S,p);
					if(p->lchild)
						p = p->lchild;
					else
						p = p->rchild;
				}
		}
		if(!StackEmpty(S)) break;
		q=GetTop(S);
		if(q->rchild == p)
		{
			p = Pop(S);
			printf("%4c",p->data);
			p = q;
			flag = p->data;
		}
		else
		{
			p = q->rchild;
			if(flag == p->data)
			{
				p = Pop(S);
				printf("%4c",p->data);
				p = q;
				flag = p->data;
			}
		}
	}
*/



	SqStack S=NULL;
	S=InitStack(S);
	BiTree p=NULL;
	p = T;
	while(p||!StackEmpty(S))
	{
		while(p &&(p->lflag != 1 || p->rflag != 1))
		{
			if(p->lchild && p->lflag != 1)
			{
				p->lflag = 1;
				Push(S,p);
				p = p->lchild;
			}
			else if(p->rchild && p->rflag != 1)
			{
				p->rflag = 1;
				Push(S,p);
				p = p->rchild;
			}
			else
			{
				/*Do Nothing*/
			}
		}
		p = Pop(S);		
		printf("%4c",p->data);
		p = GetTop(S);

	}
}




