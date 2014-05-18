#define TRUE 1
#define ERROR 0
#define OK	1
#define FALUSE 0
#define OVERFLOW	-1

typedef int Status;
typedef char TElemType;
typedef struct BiTNode
{
	TElemType  data;
	int lflag;
	int rflag;
	struct BiTNode *lchild,*rchild;
}*BiTree;


Status CreateBiTree(BiTree *T);
//Status CreateBiTree(BiTree &T);

void PreOrderTraverse(BiTree T);
void PreOrderTraverse_1(BiTree T);

void InOrderTraverse(BiTree T);
void InOrderTraverse_1(BiTree T);

void PostOrderTraverse(BiTree T);
void PostOrderTraverse_1(BiTree T);
void BiTree_free(BiTree *T);
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
