#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int compare(void* dest, void* src)
{
	int a = *((int*)dest);
	int b = *((int*)src);
	return a - b;
}

void visit(void* data)
{
	int value = *((int*)data);
	printf("%4d", value);
}


int main(int argc, char *argv[])
{
	vector *v = NULL;
	v = vector_create();
	int a = 1;
	int a1 = 2;
	int a2 = 3;
	int a3 = 4;
	int a4 = 5;
	int a5 = 6;
	int a6 = 7;
	int a7 = 8;
	int a8 = 9;
	int a9 = 10;
	int a10 = 11;

	v->push(v, (void*)&a);
	v->push(v, (void*)&a1);
	v->push(v, (void*)&a2);
	v->push(v, (void*)&a3);
	v->push(v, (void*)&a4);
	v->push(v, (void*)&a5);
	v->push(v, (void*)&a6);
	v->push(v, (void*)&a7);
	v->push(v, (void*)&a8);
	v->push(v, (void*)&a9);
	v->push(v, (void*)&a10);
	v->visit = visit;
	v->dump(v);
	return 0;
}
