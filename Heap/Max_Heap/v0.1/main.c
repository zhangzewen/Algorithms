#include <stdio.h>
#include <stdlib.h>

#include "vector.h"


void visit(void *value)
{
	printf("%4d", *((int*)value));
}

int compare(void *v1, void *v2)
{
	
	int va_1 = (v1 == NULL) ? 0 : *((int *)v1);
	int va_2 = (v2 == NULL) ? 0 :*((int *)v2);

	return (va_1 - va_2);
	
}


int main(int argc, char **argv)
{
	vector *c = NULL;
	int v1 = 4;
	int v2 = 1;
	int v3 = 3;
	int v4 = 2;
	int v5 = 16;
	int v6 = 9;
	int v7 = 10;
	int v8 = 14;
	int v9 = 8;
	int v10 = 7;
	c = vector_create();	

	c->push(c, (void *)(&v1 ));
	c->push(c, (void *)(&v2 ));
	c->push(c, (void *)(&v3 ));
	c->push(c, (void *)(&v4 ));
	c->push(c, (void *)(&v5 ));
	c->push(c, (void *)(&v6 ));
	c->push(c, (void *)(&v7 ));
	c->push(c, (void *)(&v8 ));
	c->push(c, (void *)(&v9 ));
	c->push(c, (void *)(&v10));
	Print(c, visit);
	make_heap(c, compare);
	Print(c, visit);
	printf("\n===============================\n");
	heap_sort(c, compare);
	Print(c, visit);
	vector_destroy(&c, NULL);
	return 0;
}
