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

static void rb_rotate_left(rbtree_node_t *node, rbtree_node_t **root)
{
	rb_node_t *right_child = node->right;
	
	if ((node->right = right_child->left)) {
		right_child->left->parent = node;
	}

	right_child->left = node;
	
	if ((right_child->parent = node->parent)) {
		if (node == node->parent->right) {
			node->parent->right = right_child;
		}	else {
			node->parent->left = right_child;
		}
	} else {
		*root = right_child;
	}
	
	node->parent = right_child;
}

static void rb_rotate_right(rbtree_node_t *node, rbtree_node_t **root)
{
	rb_node_t *left_child = node->left;

	if ((node->left = left_child->right)) {
		left_child->right->parent = node;
	}

	left_child->right = node;
	
	if ((left_child->parent = node->parent)) {
		if (node == node->parent->right) {
			node->parent->right = left_child;
		} else {
			node->parent->left = left_child;
		}
	} else {
		*root = left;
	}

	node->parent = left_child;
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
	rbtree_node_t *parent = NULL;
	rbtree_node_t *gparent = NULL;
	rbtree_node_t *uncle = NULL;	
	rbtree_node_t *tmp = NULL;

	while((parent = node->parent) && parent->color == READ) { // 当父亲节点存在的时候且父亲节点是红色的，需要调整，当父亲几点是黑色（这时插入不破坏红黑树的性质）或者为NULL的时候（插入的几点就是父节点）
		gparent = parent->parent;
	
		if (parent == gparent->left) { // 父亲节点是祖父的的左孩子
			uncle = gparent->right;
			if (uncle && uncle->color == RED) { //情况1：叔叔是红色的，此时只要把叔叔和父亲染黑，祖父染红就OK，不需要考虑当前节点是父亲节点的左右孩子情况
				uncle->color = BLACK; // 叔叔节点染黑
				parent->color = BLACK;//父亲节点染黑
				gparent->color = RED; // 祖父节点染红<可以更具红黑树的性质看出，此时的祖父几点在没有染红之前一定是黑色的>
				
				node = gparent; //此时，把当前几点指向祖父几点，然后对祖父几点进行调整
			} else { //情况2：:叔叔节点是黑色的（红黑树中NULL节点也是黑色的）
				if (parent->right == node) { // 当前节点是父亲节点的右孩子
					rb_rotate_left(parent, root); //进行左旋转，把子变父，父变子 //旋转之后就相当于父节点是红色的，其左孩子还是红色的
					tmp = parent;
					parent = node;
					node = tmp;	
				}	
				//情况3：叔叔是黑色的，当前节点是父节点的左孩子
				//	
				parent->color = BLACK;
				gparent->clor = RED;
				rb_rotate_right(gparent, root);
			}
		} else { //父亲节点是祖父的右孩子
			uncle = gparent->left;
			if (uncle && uncle->color == RED) { // 情况1：叔叔是红色的
				uncle->color = BLACK;
				parent->color = BLACK;
				gparent->color = RED;
				node = gparent;
			} else { //情况2：叔叔是黑色的
				if (parent->left == node) { // 当前节点为父节点的左孩子
					rb_rotate_right(parent, root);
					tmp = parent;
					parent = node;
					node = tmp;
				}

				//情况3：当前节点是父节点的右孩子
				parent->color = BLACK;
				gparent->color = RED;
				rb_rotate_left(gparent, root);
			}
		}
	}
	
	*root->color = BLACK;
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
