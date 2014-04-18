#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

int compare(void *v1, void *v2)
{
	int va_1 = *((int *)v1);
	int va_2 = *((int *)v2);

	return (va_1 - va_2);
	
}


int main(int argc, char **argv)
{
	vector *c = NULL;
	int v1 = 1;
	int v2 = 2;
	int v3 = 3;
	int v4 = 4;
	int v5 = 5;
	int v6 = 6;
	int v7 = 7;
	int v8 = 8;
	int v9 = 9;
	int v10 = 10;
	int v11 = 11;
	int v12 = 12;
	int v13 = 56;
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
	c->push(c, (void *)(&v11));
	c->push(c, (void *)(&v12));
	c->push(c, (void *)(&v13));
	print(c);
	make_heap(c, compare);
	print(c);
	return 0;
}
