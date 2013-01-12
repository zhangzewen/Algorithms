#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"

int main()
{
	SqStack S=NULL;
	int e;
	S=(SqStack)malloc(sizeof(struct Stack));

	S=InitStack(S);
	S=Push(S,1);
	S=Push(S,2);
	S=Push(S,3);
	S=Push(S,4);
	Print(S);
	e=GetTop(S);
	printf("\nthe top num of the stack is %d\n",e);
	S=Pop(S);
	S=Pop(S);
	Print(S);
	return 0;
}
