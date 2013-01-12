#include<stdio.h>
#include"Binary_Sort_Tree.h"
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


void CreateBiTree(BiTree *T)
{
	char ch;
	ch=getchar();

		if(ch=='#') (*T)=NULL;
		else
		{ 
			if(!((*T)=(BiTree)malloc(sizeof(struct BiTNode))))   exit(FALUSE);
			(*T)->data=ch;
			CreateBiTree(&(*T)->lchild);
			CreateBiTree(&(*T)->rchild);

		}
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
	
	if(T)
	{ 
		PostOrderTravaerse(T->lchild); 
		PostOrderTravaerse(T->rchild); 
		printf("%4c",T->data); 
	} 
	
}



Status Binary_Sort_Tree(BiTree T,char e,BiTree f,BiTree *p)
{
	if(!T) {(*p)=f;return FALUSE;}
	else if(e-T->data ==0){(*p)=T;return TRUE;}
	else if(e-T->data<0){return Binary_Sort_Tree(T->lchild,e,T,p);}
	else return Binary_Sort_Tree(T->rchild,e,T,p);
}


Status Insert_Binary_Sort_Tree(BiTree *T,char e)
{
	BiTree p;
	BiTree s;
	if(!Binary_Sort_Tree((*T),e,NULL,&p))
	{
		s=(BiTree)malloc(sizeof(struct BiTNode));
		s->data =e;
		s->lchild=s->rchild=NULL;
		if(!p)	(*T)=s;
		else if(e - p->data<0) p->lchild=s;
		else p->rchild=s;
		return TRUE;
	}
	return FALUSE;
}



Status Delete_Binary_Sort_Tree(BiTree *T,char e)
{
	if(!T) return FALUSE;
	else
	{
		if(e == (*T)->data) return Delete(T);
		else if(e - (*T)->data <0) return Delete_Binary_Sort_Tree(&((*T)->lchild),e);
		else return Delete_Binary_Sort_Tree(&((*T)->rchild),e);
	}
}



Status Delete(BiTree *p)
{
	BiTree q;
	BiTree s;
	if(!(*p)->rchild)
	{
		q=(*p); (*p)=(*p)->lchild; free(q);
	}
	else if(!(*p)->lchild)
	{
		q=(*p);
		(*p)=(*p)->rchild; free(q);
	}
	else
	{
		q=(*p); s=(*p)->lchild;
		while(s->rchild){q=s;s=s->rchild;}
		(*p)->data =s->data;
		if(q!=(*p))q->rchild=s->lchild;
		else q->lchild=s->lchild;
		//delete s;
		free(s);
	}
	return TRUE;
}


