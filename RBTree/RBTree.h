#ifndef _RBTREE_H_INCLUDED__
#define _RBTREE_H_INCLUDED__

#define TRUE 1
#define ERROR 0
#define OK	1
#define FALUSE 0
#define OVERFLOW	-1

typedef int Status;

typedef struct BiTNode
{
	char  data;
	int lflag;
	int rflag;
	int High;
	struct BiTNode *lchild,*rchild, *parent;
}*BiTree;


Status CreateBiTree(BiTree *T);
//Status CreateBiTree(BiTree &T);

void PreOrderTraverse(BiTree T);

void InOrderTraveerse(BiTree T);

void PostOrderTravaerse(BiTree T);
//---------------------------------------------------------------

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct Stack{
	BiTree *top;
	BiTree *base;
	int stacksize;
}*SqStack;

SqStack InitStack(SqStack S);


int StackEmpty(SqStack S);

//void StackLength(SqStack S);

BiTree  GetTop(SqStack S);

SqStack Push(SqStack S,BiTree T);

BiTree Pop(SqStack S);

void Print(SqStack S);


#endif
