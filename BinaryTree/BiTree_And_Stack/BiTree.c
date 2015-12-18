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
	BiTree p = NULL;
	p = T;
	if (p != NULL) {
		printf("%4c",p->data);
		PreOrderTraverse(p->lchild);
		PreOrderTraverse(p->rchild);
	}

}


#if 1
void PreOrderTraverse_1(BiTree T)
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
	free(S->base);
	free(S);
}
#endif

void InOrderTraverse(BiTree T)
{

	BiTree p = NULL;
	p = T;
	if (p != NULL) {
		InOrderTraverse(p->lchild);
		printf("%4c",p->data);
		InOrderTraverse(p->rchild);
	}
}

#if 1
void InOrderTraverse_1(BiTree T)
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
	free(S->base);
	free(S);
}
#endif
//

#if 1
void PostOrderTraverse_1(BiTree T)
{
	SqStack S=NULL;
	S=InitStack(S);
	BiTree p=NULL;
	p = T;
  Push(S, p);
	while(!StackEmpty(S))
	{

		while(p){
			if(p->lflag != 1 )
			{
				p->lflag = 1;
#if 0
				if(GetTop(S) != p) {
					Push(S, p);
				}
#endif
				if(p->lchild){
					Push(S, p->lchild);
					p = p->lchild;
				}
			}else if(p->rflag != 1)
			{
				p->rflag = 1;
#if 0
				if(GetTop(S) != p) {
					Push(S, p);
				}
#endif
				if(p->rchild){
					Push(S, p->rchild);
					p = p->rchild;
				}

			}else if(p->lflag == 1 && p->rflag == 1){
				break;
			}
		}
		p = Pop(S);
		printf("%4c", p->data);
		p->lflag = 0;
		p->rflag = 0;
		if(StackEmpty(S)) {
			break;
		}
		p = GetTop(S);
	}

	free(S->base);
	free(S);
}
#endif

void PostOrderTraverse(BiTree T)
{
	BiTree p = NULL;
	p = T;
	if (p != NULL) {
		PostOrderTraverse(p->lchild);
		PostOrderTraverse(p->rchild);
		printf("%4c",p->data);
	}

}



void BiTree_free(BiTree *T)
{

	SqStack S=NULL;
	S=InitStack(S);
	BiTree p=NULL;
	p = *T;
  Push(S, p);
	while(!StackEmpty(S))
	{

		while(p){
			if(p->lflag != 1 )
			{
				p->lflag = 1;
				if(p->lchild){
					Push(S, p->lchild);
					p = p->lchild;
				}
			}else if(p->rflag != 1)
			{
				p->rflag = 1;
				if(p->rchild){
					Push(S, p->rchild);
					p = p->rchild;
				}

			}else if(p->lflag == 1 && p->rflag == 1){
				break;
			}
		}
		p = Pop(S);
		//printf("%4c", p->data);
		free(p);
		p = NULL;
		if(StackEmpty(S)) {
			break;
		}
		p = GetTop(S);
	}

	*T = NULL;
	free(S->base);
	free(S);
}
