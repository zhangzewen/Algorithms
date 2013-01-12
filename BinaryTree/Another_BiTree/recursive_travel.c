#include "head_bin_tree.h"
/*************************************************************************
 *Function name:create_bi_tree()
 *Function Description:The function is used to create a binary tree
 *             recursivly
 *Parameter list: the parameter bt which is the binary operation pointer
 *Result:void 
 *************************************************************************/
void create_bi_tree(bi_tree *bt)
{
    char ch;
    ch = getchar();
    if ( ch == '#') { 
        *bt == NULL;
    } else {
        *bt = (bi_tnode *)malloc(sizeof(bi_tnode));
        (*bt) -> data = ch;
        create_bi_tree(&((*bt) -> lchild));
        create_bi_tree(&((*bt) -> rchild));
    }
}

/*************************************************************************
 *Function name:pre_order()
 *Function Description:The function is used to first order binary tree 
 *             traversal secursivly
 *Parameter list: the parameter root which is the binary operation pointer
 *Result:display the binary tree node in pre order
 *************************************************************************/
void pre_order(bi_tree root)
{
    if (root != NULL) {
        visit(root->data);
        pre_order(root->lchild);
        pre_order(root->rchild);
    }
}

/*************************************************************************
 *Function name:in_order()
 *Function Description:The function is used to in order binary tree 
 *             traversal rescursivly
 *Parameter list: the parameter root which is the binary operation pointer
 *Result:display the binary tree node in middle order
 *************************************************************************/
void in_order(bi_tree root)
{
    if (root != NULL) {
        in_order(root->lchild);
        visit(root->data);
        in_order(root->rchild);
    }
}

/*************************************************************************
 *Function name:post_order()
 *Function Description:The function is used to postorder binary tree 
 *             traversal recursivly
 *Parameter list: the parameter root which is the binary operation pointer
 *Result:display the binary tree node in postorder
 *************************************************************************/
void post_order(bi_tree root)
{
    if (root != NULL) {
        post_order(root->lchild);
        post_order(root->rchild);
        visit(root->data);
    }
}
