#include<stdio.h>
#include"Banlanced_Binary_Tree.h"
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
				//printf("self: %p, data:%4c, parent:%p, lchild: %p, rchild: %p, High:%d\n", p, p->data, p->parent, p->lchild, p->rchild, p->High);
				printf("%c:%d  ", p->data, p->High);
				
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
		//printf("self: %p, data:%4c, parent:%p, lchild: %p, rchild: %p, High:%d\n", p, p->data, p->parent, p->lchild, p->rchild, p->High);
		printf("%c:%d  ", p->data, p->High);
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
	
	node->High = 0;
	
	node->data = '0';
	
	return node;
	
}

void Route_right(BiTree *p);
void Route_left(BiTree *p);
void Balanced_right(BiTree *p);
void Balanced_left(BiTree *p);
void Balanced_node(BiTree *p, int op);

int Banlanced_Binary_Tree_find(BiTree T, char element, BiTree *p) // find element in AVL, and return it
{

	if(NULL == T){
		return -1; 
	}

	*p = T;

	if(T->data - element > 0  &&  T->lchild) {
		return Banlanced_Binary_Tree_find(T->lchild, element, p);
	}
	
	if(T->data - element < 0 &&  T->rchild) {
		return Banlanced_Binary_Tree_find(T->rchild, element, p);
	}

	if(T->data - element == 0) {
		return 1;
	}
	
	return 0;	
}

int reset_High(BiTree *p, BiTree *ptr)
{
	int ret = 0;
	BiTree current;
	BiTree tmp;
	current = *p;
	if(current->High == 0)	{
		return 0;
	}
	
	tmp = current;
		
	current = current->parent;
	
	while(current) {

		if(current->lchild == tmp) {
			current->High += 1;
		}
		
		if(current->rchild == tmp) {
			current->High -= 1;
		}

		if((current->High > 1 || current->High < -1) && !ret) {
			*ptr = current;
			ret++;
		}
		
		tmp = current;
		current = current->parent;	
		
	}
	
	return 0;	
}
void reset_root_high(BiTree *p)
{
	BiTree current;
	BiTree tmp;
	current = *p;
	
	tmp = current;
		
	current = current->parent;
	while(current) {

		if(current->lchild == tmp) {
			current->High -= 1;
		}
		
		if(current->rchild == tmp) {
			current->High += 1;
		}

		
		tmp = current;
		current = current->parent;	
		
	}
}



int Banlanced_Binary_Tree_insert(BiTree *T, char element) // add a element to a AVL, and make the new tree to AVL
{
	int ret = 0;
	BiTree p = NULL;

	BiTree node = NULL;
	BiTree bf = NULL;
	BiTree ptr_root = NULL;

	if(NULL == *T) {
		*T = Create_BiTNode();
		if(*T == NULL) {
			return -1;
		}
		
		(*T)->data = element;
	}	

	ptr_root = *T;

	if((ret = Banlanced_Binary_Tree_find(*T, element, &p)) != 0)	 { // check the element is in or not in the AVL
		return -1;
	}
	
	node = Create_BiTNode();
	
	if(NULL == node) {
		return -1;
	}

	node->data = element;
	
	if(p->data - element > 0) {
		p->lchild = node;
		node->parent = p;
		p->High += 1;
		reset_High(&p, &bf);
		if(bf != NULL) {	
			Balanced_node(&bf, 1);
			reset_root_high(&bf);
			if(bf->parent == NULL) {
				*T = bf;
			}
		}
	
	}else if (p->data - element < 0) {
		p->rchild = node;
		node->parent = p;
		p->High -= 1;
		reset_High(&p, &bf);
		if(bf != NULL) {
			Balanced_node(&bf, -1);
			reset_root_high(&bf);
			if(bf->parent == NULL) {
				*T = bf;
			}
		}
	}
	return 0;
}
#if 0
/*
	@op 这个标记是为了说明当删除一个节点的时候bf因子到底要不要去调整
*/
int reset_High_after_delete(BiTree *p, BiTree *ptr, int op)
{
	int ret = 0;
	BiTree current;
	BiTree tmp;
	current = *p;

	tmp = current;	
	current = current->parent;

	while(current && op) {

		if(current->lchild == tmp) {
			current->High -= 1;
		}
		
		if(current->rchild == tmp) {
			current->High += 1;
		}

		if((current->High > 1 || current->High < -1) && !ret) {
			*ptr = current;
			ret++;
		}
		
		tmp = current;
		current = current->parent;	
		
	}
	
	return 0;	
}

int Banlanced_Binary_Tree_delete(BiTree *T, char element) // delete a element from a AVL, and make the new tree to AVL
{
	int ret = 0;
	BiTree p = NULL;
	BiTree bf = NULL;
	BiTree tmp = NULL;

	if((ret = Banlanced_Binary_Tree_find(*T, element, &p)) != 1)	 { // check the element is in or not in the AVL
		return -1;
	}


	if(p->lchild != NULL && p->rchild == NULL) { //左子树不为空，右子树为空
		tmp = p->lchild;	
		if(p->parent->lchild == p) {
			p->parent->lchild = p->lchild;
		}
		if(p->parent->rchild == p) {
			p->parent->rchild = p->lchild;	
		}

		p->lchild->parent = p->parent;
		
		free(p);
		p = tmp;
		reset_High_after_delete(&p, &bf);
		
		if(bf != NULL) {
			Balanced_node(&bf, 0);
			reset_root_high(&bf);
			if(bf->parent == NULL) {
				*T = bf;
			}
		}
	}else if(p->rchild != NULL && p->lchild == NULL) {//左子树为空，右子树不为空
		tmp = p->rchild;
		if(p->parent->lchild == p) {
			p->parent->lchild = p->rchild;
		}
		if(p->parent->rchild == p) {
			p->parent->rchild = p->rchild;	
		}

		p->rchild->parent = p->parent;
		
		free(p);
		p = tmp;
		reset_High_after_delete(&p, &bf);
		
		if(bf != NULL) {
			Balanced_node(&bf, 0);
			reset_root_high(&bf);
			if(bf->parent == NULL) {
				*T = bf;
			}
		}
	}else if(p->rchild != NULL && p->lchild != NULL) {//左右子树都不为空
		BiTree ptr = NULL;
		tmp = p;
		tmp = tmp->lchild;	
		while(tmp->rchild) {
			tmp = tmp->rchild;
		}
		
		ptr = tmp->parent;
		
		if(tmp == ptr->lchild) {
			ptr->High -= 1;
			ptr->lchild = NULL;
		}
		
		if(tmp == ptr->rchild) {
			ptr->High += 1;
			ptr->rchild = NULL;
		}
		
		reset_High_after_delete(&ptr, &bf);
		
		p->data = tmp->data;
		if(bf != NULL) {
			Balanced_node(&bf, 0);
			reset_root_high(&bf);
			if(bf->parent == NULL) {
				*T = bf;
			}
		}
		tmp->parent->rchild = NULL;
		free(tmp);
		tmp = NULL;
	}else {//左右子树都为空
		BiTree ptr = NULL;
		
		if(p->parent->High == 0) {

			if(p == p->parent->lchild) {
				p->parent->High -= 1;
				p->parent->lchild = NULL;
			}
			
			if(p == p->parent->rchild) {
				p->parent->High += 1;
				p->parent->rchild = NULL;
			}
			
			free(p);
			p = NULL;
			return 0;
		}
		
		ptr = p->parent;	
		
		if(p == ptr->lchild) {
			if(ptr->High == -1) {
				ptr->High -= 1;	
			}else if(ptr->High == 1) {
				ptr->High -= 1;	
			}
			
		}

		if(p == ptr->rchild) {
			if(ptr->High == -1) {
				ptr->High += 1;
				
			}else if(ptr->High == 1) {
				ptr->High += 1;
			}
			
		}
		reset_High_after_delete(&p, &bf);

		free(p);	


		if(bf != NULL) {
			Balanced_node(&bf, 0);
			reset_root_high(&bf);
			if(bf->parent == NULL) {
				*T = bf;
			}
		}
	}
	
	return 0;
}
#endif


void Route_right(BiTree *p)
{
	BiTree left_child = NULL;
	BiTree tmp = NULL;

	left_child = (*p)->lchild;
	
	if(left_child->rchild != NULL) {
		tmp = left_child->rchild;
	}

	left_child->parent = (*p)->parent;
	if((*p)->parent != NULL) {
		if((*p)->parent->lchild == *p) {
			(*p)->parent->lchild = left_child;
		}
		
		if((*p)->parent->rchild == *p) {
			(*p)->parent->rchild = left_child;
		}
	}

	(*p)->parent = left_child;
	left_child->rchild = *p;
	
	(*p)->lchild = tmp;
	
	(*p) = left_child;
	
	(*p)->High = 0;
	(*p)->rchild->High = 0;
	
}

void Route_left(BiTree *p)
{
	BiTree right_child = NULL;
	BiTree tmp = NULL;
	
	right_child = (*p)->rchild;
	
	if(right_child->lchild != NULL) {
		tmp = right_child->lchild;
	}

	right_child->parent = (*p)->parent;
	if((*p)->parent != NULL) {
		if((*p)->parent->lchild == *p) {
			(*p)->parent->lchild = right_child;
		}
		
		if((*p)->parent->rchild == *p) {
			(*p)->parent->rchild = right_child;
		}
	}
	
	(*p)->parent = right_child;
	
	right_child->lchild = (*p);

	(*p)->rchild = tmp;
	
	(*p) = right_child;
	
	(*p)->High = 0;
	(*p)->lchild->High = 0;
}

void Balanced_right(BiTree *p)
{
	BiTree left_child = NULL;
	BiTree left_right_child = NULL;
	
	left_child = (*p)->lchild;
	
	left_right_child = left_child->rchild;

	(*p)->lchild = left_right_child;
	left_right_child->parent = (*p);
	left_right_child->lchild = left_child;
	left_child->parent = left_right_child;
	left_child->rchild = NULL;

	left_child->High = 0;
	left_right_child->High = 1;
	
	Route_right(p);
}

void Balanced_left(BiTree *p)
{
	BiTree right_child = NULL;
	BiTree right_left_child = NULL;
	right_child = (*p)->rchild;
	right_left_child = right_child->lchild;

	(*p)->rchild = right_left_child;
	right_left_child->parent = (*p);
	right_left_child->rchild = right_child;
	right_child->parent =right_left_child;
	right_child->lchild = NULL;

	right_child->High = 0;
	right_left_child->High = -1;

	Route_left(p);
}

void Balanced_node(BiTree *p, int op) 
{
	switch((*p)->High) {
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
				case 0:
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
				case 0:
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


int Banlanced_Binary_Tree_delete(BiTree *T, char element)
{
	return 0;
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
