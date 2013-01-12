#ifndef STACK_H
#define STACK_H	
#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct Stack{
	int *top;
	int *base;
	int stacksize;
}*SqStack;

struct Stack *InitStack(SqStack S);

struct Stack *ClearStack(SqStack S);

struct Stack *StackEmpty(SqStack S);

void StackLength(SqStack S);

int  GetTop(SqStack S);

struct Stack *Push(SqStack S,int e);

struct Stack *Pop(SqStack S);

void Print(SqStack S);
#endif
