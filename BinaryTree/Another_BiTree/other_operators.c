#include "head_bin_tree.h"
/*************************************************************************
 *Function name:recursive_post_tree_depth()
 *Function Description:The function is used to count a binary tree's depth
 *             recursivly
 *Parameter list: the parameter bt which is the binary operation pointer
 *Result:void 
 *************************************************************************/
int recursive_post_tree_depth(bi_tree bt)
{
    int hleft,hright,max;
    if (bt != NULL ) {
        hleft = recursive_post_tree_depth(bt->lchild);
        hright = recursive_post_tree_depth(bt->rchild);
        max = hleft > hright?hleft:hright;
        return (max+1);
    } else {
        return 0;
    }
}
/*************************************************************************
 *Function name:recursive_post_tree_leafnum()
 *Function Description:The function is used to count a binary tree's 
 *                 leafnum recursivly
 *Parameter list: the parameter bt which is the binary operation pointer
 *Result:leaf number
 ************************************************************************/
int recursive_post_tree_leafnum(bi_tree root)
{
    int leaf_num;
    if (root == NULL) {
        leaf_num = 0;
    } else if ((root->lchild == NULL)&&(root->rchild == NULL)) {
        leaf_num = 1;
    } else {/*叶子节点为左右子树数目之和*/
        leaf_num = recursive_post_tree_leafnum(root->lchild) +recursive_post_tree_leafnum(root->rchild);
    }
        return leaf_num;
}

/*************************************************************************
 *Function name:visit()
 *Function Description:The function is used to display node information 
 *Parameter list: the parameter data which is the node variable
 *Result:display the node information 
 *************************************************************************/
void visit(const DATATYPE data)
{
    printf(OUTTYPE,data);
}
