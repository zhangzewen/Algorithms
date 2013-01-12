#ifndef __bin_tree__
#define __bin_tree__

#include <stdio.h>
#include <stdlib.h>

#define DATATYPE char //Definition of node type information

#define OUTTYPE "%c " //Definition of node output format


typedef struct node
{
    DATATYPE data;
    struct node *lchild;
    struct node *rchild;
}bi_tnode,*bi_tree;

extern void create_bi_tree(bi_tree *bt); 

extern void pre_order(bi_tree root); //First order travel a binary tree recusivly

extern void in_order(bi_tree root); //In order travel a binary tree recusivly

extern void post_order(bi_tree root);//Postorder travel a binary tree recusivly


extern void general_pre_order(bi_tree root); //first order travel a binary tree generally

extern void general_in_order(bi_tree root); //In order travel a binary tree generally

extern void general_post_order(bi_tree root); //Postorder travel a binary tree generally


extern int recursive_post_tree_depth(bi_tree bt);//count a binary tree's depth
extern int recursive_post_tree_leafnum(bi_tree bt);//count a binary tree's leafnum 
void visit(DATATYPE data); //Display the node information


#endif
