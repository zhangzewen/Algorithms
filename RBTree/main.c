#include <stdio.h>
#include <stdlib.h>
#include "RBTree.h"

int main(int argc, char *argv[])
{
	
	int i;
	int count = 100;
	
	key_t key;
	
	rb_node_t *root = NULL;
	rb_node_t *node = NULL;
	
	srand(time(NULL));
	for(i = 1; i < count; i++) {
		key = rand() % count;
		
		root = rb_insert(key, i ,root);
	}

	
	return 0;	
}
