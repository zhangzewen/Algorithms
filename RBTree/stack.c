#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

stack InitStack()
{
	stack S;
	S=(stack)malloc(sizeof(struct Stack));

	if (NULL == S) {
		return NULL;
	}

	S->base =(void **)malloc(STACK_INIT_SIZE * sizeof(void **));

	if (NULL == S->base) {
		return NULL;
	}

	S->top=S->base;
	S->stacksize = STACK_INIT_SIZE;
	return S;
}

int StackEmpty(stack S)
{
	return (S->base == S->top);
}

void* GetTop(stack S)
{
	void **p;
	void *e;
	if(NULL == S || StackEmpty(S)) {
		return NULL;
	} 

	p = S->top;
	p=p-1;
	e=*p;
	return e;

}

stack Push(stack S, void *e)
{
	if((S->top) - (S->base) >= (S->stacksize)) {
		S->base =(void**)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(void**));

		S->stacksize+=STACKINCREMENT;
	}
	*(S->top)=e;
	S->top++;
	return S;
}


void* Pop(stack S)
{
	void *e;
	if(NULL == S || S->top ==S->base) {
		return NULL;
	}
	S->top = S->top-1;
	e=*S->top;
	return e;
}


void Print(stack S, void (*visit)(void *))
{ 
  void **p; 
  p=S->top-1;
  while(p != S->base)
  {
		visit(*p);
    p=p-1;
  }
  visit(*S->base);
}

void Stack_destroy(stack *S, void (*free_func)(void *))
{
	void **p;
	
	if (!StackEmpty(*S)) {
		p = (*S)->top - 1;
		while(p != (*S)->base){
			if(free_func) {
				free(*p);
			}
			p = p - 1;
		}

		if(free_func) {
			free(*(*S)->base);
		}
	}

	free((*S)->base);
	free(*S);
	*S = NULL;
}

