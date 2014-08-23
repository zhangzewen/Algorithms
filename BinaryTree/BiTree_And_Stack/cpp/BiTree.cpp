#include "BiTree.hpp"
#include "Stack.h"

BiTree::BiTree()
{
	root = new _BiTree();
}

BiTree::~BiTree()
{
	if (NULL == root) {
		// todo nothing!
	}
	free_Bitree(&root);
}

_BiTree* BiTree::insert(int data)
{

}

_BiTree* BiTree::remove(int data)
{

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
