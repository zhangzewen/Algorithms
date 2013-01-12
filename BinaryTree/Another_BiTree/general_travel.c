#include "head_bin_tree.h"
#define STACK_LEN 20 

/*************************************************************************
 *Function name:general_pre_order()
 *Function Description:The function is used to first order binary tree 
 *             traversal 
 *Parameter list: the parameter root which is the binary operation pointer
 *Result:display the binary tree node in postorder
 *************************************************************************/
void general_pre_order(bi_tree root)
{
    int top = 0;
    bi_tree p = root;
    bi_tree s[STACK_LEN];
    while ((p != NULL) || (top != 0)) {
        while (p != NULL) {
            top = top + 1;
            if (top > STACK_LEN) {
                printf("Stack over flow!\n");
                return ;
            }
            s[top] = p;
            visit(p->data);
            p = p->lchild;
        }
        if (top > 0) {
            p = s[top];
            top = top - 1;
            if ( p->rchild == NULL) {
                p = NULL;
            }else {
                p = p->rchild;
            }
        }

    }
    
}
/*************************************************************************
 *Function name:general_in_order()
 *Function Description:The function is used to in order binary tree 
 *             traversal 
 *Parameter list: the parameter root which is the binary operation pointer
 *Result:display the binary tree node in postorder
 *************************************************************************/
void general_in_order(bi_tree root) 
{
    int top = 0;
    bi_tree p = root;
    bi_tree s[STACK_LEN];
    do {
        while (p != NULL) {
            if (top > STACK_LEN ) {
                printf("Stack over flow!\n");
                return ;
            }
            top = top + 1;
            s[top] = p;
            p = p -> lchild;
        }

        if (top != 0) {
            p = s[top];
            top = top -1;
            visit(p->data);
            p = p -> rchild;
        }
    } while ((p != NULL) || (top != 0));

}
/*************************************************************************
 *Function name:general_post_order()
 *Function Description:The function is used to postorder binary tree 
 *             traversal 
 *Parameter list: the parameter root which is the binary operation pointer
 *Result:display the binary tree node in postorder
 *************************************************************************/
void general_post_order(bi_tree root)
{
    bi_tree p,q;
    bi_tree s[STACK_LEN];
    int top = 0;
    q = NULL;
    p = root;
    while ( (p != NULL)||(top != 0)) {
        while (p != NULL) {
            top = top + 1;
            if (top >= STACK_LEN) {
                printf("Stack over flow!\n");
                return ;
            }
            s[top] = p;
            p = p -> lchild;
        }
        if (top > 0) {
            p = s[top];
            if ((p -> rchild == NULL) || (p -> rchild == q)) {
                visit(p->data);
                q = p;//save to q in order to use next time

                top = top - 1;
                p = NULL;
            } else {
                p = p -> rchild;
            }
        }
    }
}

