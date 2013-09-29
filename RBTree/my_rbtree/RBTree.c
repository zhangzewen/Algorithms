#include "RBTree.h"
#include <stdio.h>
#include <stdlib.h>


rbtree_node_t *create_node(char element)
{
	rbtree_node_t *node;
	
	node = (rbtree_node_t *)malloc(sizeof(struct rbtree_node_st));
	
	if(NULL == node) {
		return NULL;
	}
	
	node->parent = NULL;
	node->lchild = NULL;
	node->rchild = NULL;
	node->color = RED;
	node->data = element;

	return node;
}

static int rbtree_find(rbtree_node_t *root, char element, rbtree_node_t **parent)
{
	if(NULL == root) {
		return -1;
	}

	*p = root;

	if (root->data - element > 0 && root->lchild) {
		return rbtree_find(root->lchild, element, parent);
	}
	
	if (root->data - element < 0 && root->rchild) {
		return rbtree_find(root->rchild, element, parent);
	}
	
	if (root->data - element == 0) {
		return 1;
	}
	
	return 0;
}


void rbtree_insert_rebalance(rbtree_node_t *node, rbtree_node_t **root)
{
	
}

void insert_node(rbtree_node_t **root, char element)
{
	rbtree_node_t *parent = NULL;
	rbtree_node_t *node = NULL;

	if ((ret = rbtree_find(*root, element, &parent)) == 1) {
		return ;
	}	

	node = create_node(element);
	
	node->parent = parent;
	
	if (parent) {
		if (parent->date -element > 0) {
			parent->lchild = node;
		} else {
			parent->rchild = node;
		}
	} else {
		*root = node;
	}	
	
	return rbtree_insert_rebalance(node, root);	
}
void delete_node(rbtree_node_t **root, char element)
{
	
}
