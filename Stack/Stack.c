#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"

struct Stack *InitStack(SqStack S)
{
	S->base =(int *)malloc(STACK_INIT_SIZE*sizeof(int));
	if(!S->base) exit(1);
	S->top=S->base;
	S->stacksize =STACK_INIT_SIZE;	
	return S;
}


struct Stack *ClearStack(SqStack S)
{
	return S;
}

struct Stack *StackEmpty(SqStack S)
{
	return S;
}

void StackLength(SqStack S)
{	
	
}

int GetTop(SqStack S)
{	
	int e;
	int *p;
	p=S->top;
	if(S->top == S->base) return 0 ;
	p=p-1;
	e=*p;
	return e;
	
}

struct Stack *Push(SqStack S,int e)
{	
	if((S->top)-(S->base)>=(S->stacksize)){
		S->base =(int *)realloc(S->base,(S->stacksize + STACKINCREMENT)*sizeof(int));
		
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;	
	}
	*(S->top)=e;
	S->top++;
	return S;
}


struct Stack *Pop(SqStack S)
{
	int e=0;;
	if(S->top ==S->base) return S;
	S->top=S->top-1;
	e=*(S->top);
	printf("\nStack has pop the num: %d\n",e);
	return S;
}


void Print(SqStack S)
{	
	int *p;
	p=S->top-1;
	while(p!=S->base)
	{
        printf("%4d",*p);
		p=p-1;
	}
	printf("%4d",*S->base);
}
