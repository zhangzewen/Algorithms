#include<stdio.h>
#include"Banlanced_Binary_Tree.h"
#include<stdlib.h>


#define ELEMENT_IN_AVL
#define ELEMENT_NOT_IN_AVL
#define ELEMENT_CAN_NOT_MALLOC


static enum Route_stat{
	ROUTE_RIGHT_RIGHT = 0,
	ROUTE_LIFT_LIFT,
	ROUTE_RIGHT_LIFT,
	ROUTE_LIFT_RIGHT,
	ROUTE_DONE
	FIND_LEAST_ROUTE,
	BANLANCED_TREE_BUILD_DONE
};

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
	SqStack S=NULL;
	S=InitStack(S);
	BiTree p=NULL;
	BiTree tmp = NULL;
	p = T;
  Push(S, p);
	while(!StackEmpty(S))
	{

		while(p){
			if(p->lflag != 1 )
			{
				if(GetTop(S) != p) {
					Push(S, p);	
				}
				p->lflag = 1;
				if(p->lchild){
                    Push(S, p->lchild);
                    p = p->lchild;
				}
			}else if(p->rflag != 1 )
			{
				if(GetTop(S) != p) {
					Push(S, p);	
				}
				p->rflag = 1;
                if(p->rchild){
                    Push(S, p->rchild);
                    p = p->rchild;
                }

			}
			if(p->lflag == 1 && p->rflag == 1){
                break;
			}
		}
		p = Pop(S);
		printf("%4c", p->data);
		if(StackEmpty(S)) {
			return;
		}
		tmp = GetTop(S);
		if(tmp->lflag == 1 && tmp->rflag == 1) {
			p = tmp;
		}else if(tmp->lflag != 1){
			tmp->lflag = 1;
			p = tmp->lchild;
		}else if(tmp->rflag != 1){
			tmp->rflag = 1;
			p = tmp->rchild;
		}
	}
}



BiTree Create_BiTNode()
{
	BiTree node;
	
	node = (BiTree)malloc(sizeof(struct BiTNode));
	
	if(NULL == node) {
		return NULL;
	}

	node->lchild = NULL;
	node->rchild = NULL;
	
	node->lflag = 0;
	node->rflag = 0;
	
	node->rHigh = 0;
	node->lHigh = 0;
	
	node->data = '0';
	
	return node;
	
}

int Banlanced_Binary_Tree_find(BiTree T, char element, BiTree p) // find element in AVL, and return it
{

	if(NULL == T){
		return -1; 
	}

	p = T;

	if(T->data - element > 0) {
		return Banlanced_Binary_Tree_find(T->lchild, element);
	}
	
	if(T->data - element < 0) {
		return Banlanced_Binary_Tree_find(T->rchild, element);
	}

	if(T->data - element == 0) {
		return 0;
	}
	
	return -1;
}

int Banlanced_Binary_Tree_insert(BiTree *T, char element) // add a element to a AVL, and make the new tree to AVL
{
	int ret = 0;
	BiTree p = NULL;

	BiTree node = NULL;
	BiTree bf = NULL;
	BiTree ptr_root = NULL;

	if(NULL == *T) {
		*T = Create_Node();
		if(*T == NULL) {
			return ELEMENT_CAN_NOT_MALLOC;
		}
	}	

	ptr_root = *T;

	if((ret = Banlanced_Binary_Tree_find(*T, element, p)) != 0)	 { // check the element is in or not in the AVL
		return ELEMENT_IN_AVL;
	}
	
	node = Create_BiTNode();
	
	if(NULL == node) {
		return ELEMENT_CAN_NOT_MALLOC;
	}

	node->data = element;
	
	if(p->data - element > 0) {
		int ret = 0;
		p->rchild = node;
		node->parent = p;
		while(p) {
			p->lHigh += 1;
			ret = p->lHigh - p->rHigh;
			if(ret > 1 ||  ret < -1) {
				bf = p; //找出要平衡的节点
				break;
			}
			p = p->parent;	
		}
		
		Balanced_node(bf, 1);
	
		return 0;	
	}

	if(p->data - element < 0) {
		int ret = 0;
		p->lchild = node;
		node->parent = p;
		while(p){
			p->rHigh += 1;
			ret = p->lHigh - p->rHigh;
			if(ret > 1 || ret < -1) {
				bf = p;
				break;
			}
			p = p->parent;
		}

		Balanced_node(bf, -1);
	}

	return 0;
}

int Banlanced_Binary_Tree_delete(BiTree *T, char element) // delete a element from a AVL, and make the new tree to AVL
{
	return 0;
}


BiTree Banlanced_Binary_Tree_build_from_BST(BiTree T) // transform BST to AVL
{
	return 0;
}


void Route_right(BiTNode *p)
{
	BiTNode left_child = NULL;
	BiTNode tmp = NULL;

	left_child = *P->lchild;
	
	if(left_child->rchild != NULL) {
		tmp = left_child->rchild;
	}

	left_child->parent = *p->parent;
	*p->parent = left_child;
	left_child->rchild = *p;
	
	*p->lchild = tmp;
	
	*p = left_child;
	
}

void Route_left(BiTNode *p)
{
	BiTNode right_child = NULL;
	BiTNode tmp = NULL;
	
	right_child = *p->rchild;
	
	if(right_child->lchild != NULL) {
		tmp = right_child->left;
	}

	right_child->parent = *p->parent;
	
	*p->parent = right_child;
	
	right_child->lchild = *p;

	*p->rchild = tmp;
	
	*p = right_child;
}

void Balanced_right(BiTNode *p)
{
	BiTNode left_child = NULL;
	BiTNode left_right_child = NULL;
	
	left_child = *p->lchild;
	
	left_right_child = left_child->rchild;

	*p->lchild = left_right_child;
	left_right_child->parent = *p;
	left_right_child->lchild = left_child;
	left_child->parent = left_right_child;
	left_child->rchild = NULL;
	
	Route_right(p);
}

void Balanced_left(BiTnode *p)
{
	BiTNode  right_child = NULL;
	BiTNode right_left_child = NULL;
	right_child = *p->rchild;
	right_left_child = right_child->lchild;

	*p->rchild = right_left_child;
	right_left_child->parent = *p;
	right_left_child->rchild = right_child;
	right_child->parent =right_left_child;
	right_child->lchild = NULL;

	Route_left(p);
}

void Balanced_node(BiTnode *p, int op) 
{
	switch(*p->High) {
		case -1:
		case 0:
		case 1:
			break;
		case -2:
			switch(op){
				case 1:
					Balanced_left(p);	
					break;
				case -1:
					Route_left(p);
					break;
				default:
					break;
			}	
			break;
		case 2:
			switch(op){
				case -1:
					Balanced_right(p);	
					break;
				case 1:
					Route_right(p);
					break;
				default:
					break;
			}	
			break;
		default:
			break;
	}
}


/*

=================================================================
add

<1> 左左
								x															a
							 /														 / \
<a>						a     ---------->             y   x
						 /
						y




<b>           x                                a
             /\                               / \
            a  b                             c   x
           /\      --------------->         /   / \
          c  d                             y   d   b
         /
        y



<2>右右

             x                                 a 
              \                               / \
<a>            a --------------->            x   y           
                \
                 y  








<b>              x                                              b
                / \                                            / \
               a   b               -------------->            x   d
									/ \                                        / \   \
                 c   d                                      a   c   y 
                      \                                          
                       y 
<3>左右


                   x            x                   y      
                  /            /                   / \
<a>              a      --->  y           --->    a   x
                  \          /
                   y        a


                 x                  x                  d
                / \                / \                / \
<b>            a   b              d   b              a   x
              / \       ---->    / \      ---->     /   / \  
             c   d              a   y              c   y   b
                  \            /
                   y          c

<4>右左

             x                   x                               y
              \                   \                             / \
<a>            a   ---- >          y    ------------->         x   a
              /                     \
             y                       a 



                x                      x                       c
               / \                    / \                     / \
              b   a        ---->     b   c   ----->          x   a
                 / \                    / \                 /   / \
<b>             c   d                  y   a               b   y   d
                 \                          \
                  y                          d   


==========================================================================
del



















*/
