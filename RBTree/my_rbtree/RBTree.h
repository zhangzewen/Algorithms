#ifndef _RBTREE_H_INCLUDED__
#define _RBTREE_H_INCLUDED__



typedef enum color_st{
	RAD = 0,
	BLACK = 1
}color_t;


typedef rbtree_node_st{
	rbtree_node_st *lchild;
	rbtree_node_st *rchild;
	rbtree_node_st *parent;
	color_t color;
	char data;
}rbtree_node_t;


rbtree_node_t *create_node();

void insert_node(rbtree_node_t **root, char element);
void delete_node(rbtree_node_t **root, char element);




#endif
