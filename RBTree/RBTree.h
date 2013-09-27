#ifndef _RBTREE_H_INCLUDED__
#define _RBTREE_H_INCLUDED__
#if 0
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
	int color;
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


typedef int key_t;
typedef int data_t;

typedef enum color_t{
	RED = 0,
	BLACK = 1
}color_t;

typedef struct rb_node_t{
	struct rb_node_t *left, *right, *parent;
	key_t key;
	data_t data;
	color_t color;
}rb_node_t;

rb_node_t *rb_insert(key_t key, data_t data, rb_node_t *root);
rb_node_t *rb_search(key_t key, rb_node_t *root);
rb_node_t *rb_erase(key_t key, rb_node_t *root);





#endif
