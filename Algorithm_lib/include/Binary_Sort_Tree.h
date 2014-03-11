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
	struct BiTNode *lchild,*rchild;
}*BiTree;


void CreateBiTree(BiTree *T);

void PreOrderTraverse(BiTree T);

void InOrderTraveerse(BiTree T);

void PostOrderTravaerse(BiTree T);

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct Stack{
	BiTree *top;
	BiTree *base;
	int stacksize;
}*SqStack;

SqStack InitStack(SqStack S);

int StackEmpty(SqStack S);

BiTree  GetTop(SqStack S);

SqStack Push(SqStack S,BiTree T);

BiTree Pop(SqStack S);

void Print(SqStack S);
//------------------------------------------------



Status Binary_Sort_Tree(BiTree T,char e,BiTree f,BiTree *p);
Status Insert_Binary_Sort_Tree(BiTree *T,char e);
Status Delete_Binary_Sort_Tree(BiTree *T,char e);
Status Delete(BiTree *p);
