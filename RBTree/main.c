#include <stdio.h>
#include <stdlib.h>
#include "RBTree.h"

int main(int argc, char *argv[])
{
	
	int count = 100;
	
	key_t key;
	
	rb_node_t *root = NULL;
	rb_node_t *node = NULL;
	
	root = rb_insert(12, 1 ,root);
	root = rb_insert(1, 2,root);
	root = rb_insert(9, 3,root);
	root = rb_insert(2, 4,root);
	root = rb_insert(0, 5,root);
	root = rb_insert(11,6,root);
	root = rb_insert(7, 7,root);
	root = rb_insert(19, 8,root);
	root = rb_insert(4, 9 ,root);
	root = rb_insert(15, 10,root);
	root = rb_insert(18, 11,root);
	root = rb_insert(5, 12,root);
	root = rb_insert(14, 13,root);
	root = rb_insert(13, 14,root);
	root = rb_insert(10, 15,root);
	root = rb_insert(16, 16,root);
	root = rb_insert(6, 17,root);
	root = rb_insert(3, 18,root);
	root = rb_insert(8, 19,root);
	root = rb_insert(17, 20,root);
//------------------------------------------


	root = rb_erase(12, root);
	root = rb_erase(1, root);
	root = rb_erase(9, root);
	root = rb_erase(2, root);
	root = rb_erase(0, root);
	root = rb_erase(11, root);
	root = rb_erase(7, root);
	root = rb_erase(19, root);
	root = rb_erase(4, root);
	root = rb_erase(15, root);
	root = rb_erase(18, root);
	root = rb_erase(5, root);
	root = rb_erase(14, root);
	root = rb_erase(13, root);
	root = rb_erase(10, root);
	root = rb_erase(16, root);
	root = rb_erase(6, root);
	root = rb_erase(3, root);
	root = rb_erase(8, root);
	root = rb_erase(17,root);
	
	return 0;	
}
