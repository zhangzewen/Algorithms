#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void visit(void *value)
{
	printf("%4d", *(int *)value);
}
int main()
{
	stack S=NULL;
	void *e;
	int v_1 = 1;
	int v_2 = 2;
	int v_3 = 3;
	int v_4 = 4;
	int v_5 = 5;
	int v_6 = 6;
	S=InitStack();
	S=Push(S, (void *)&v_1);
	S=Push(S, (void *)&v_2);
	S=Push(S, (void *)&v_3);
	S=Push(S, (void *)&v_4);
	S=Push(S, (void *)&v_5);
	S=Push(S, (void *)&v_6);
	Print(S, visit);
	e=GetTop(S);
	printf("\nthe top num of the stack is %d\n",*(int *)e);
	e = Pop(S);
	printf("\nthe Pop num is %d\n", *(int *)e);
	e=GetTop(S);
	printf("\nthe top num of the stack is %d\n",*(int *)e);

	Stack_destroy(&S, NULL);
	return 0;
}
