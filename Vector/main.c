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
	int a12 = 12;
	int a13 = 13;
	v->visit = visit;
	v->element_compare = compare;

	v->push(v, (void*)&a);
	v->dump(v);
	printf("\n");
	v->push(v, (void*)&a1);
	v->dump(v);
	printf("\n");
	v->push(v, (void*)&a2);
	v->dump(v);
	printf("\n");
	v->push(v, (void*)&a3);
	v->dump(v);
	printf("\n");
	v->push(v, (void*)&a4);
	v->dump(v);
	printf("\n");
	v->push(v, (void*)&a5);
	v->dump(v);
	printf("\n");
	v->push(v, (void*)&a6);
	v->dump(v);
	printf("\n");
	v->push(v, (void*)&a7);
	v->dump(v);
	printf("\n");
	v->push(v, (void*)&a8);
	v->dump(v);
	printf("\n");
	v->push(v, (void*)&a9);
	v->dump(v);
	printf("\n");
	v->push(v, (void*)&a10);
	v->dump(v);
	printf("\n=====================\n");

	v->insert(v, 6, (void*)&a12);
	v->dump(v);
	printf("\n");
	printf("\n=====================\n");
	v->insertn(v, 6, 4, (void*)&a13);
	v->dump(v);
	printf("\n");
	printf("\n=====================\n");
	int index = v->index(v, (void*)&a4);
	printf("index : %d\n", index);
	vector_free(&v);

	/*
	 *v->pop(v);
	 *v->dump(v);
	 *printf("\n");
	 *v->pop(v);
	 *v->dump(v);
	 *printf("\n");
	 *v->pop(v);
	 *v->dump(v);
	 *printf("\n");
	 *v->pop(v);
	 *v->dump(v);
	 *printf("\n");
	 */

	vector_free(&v);

	return 0;
}
