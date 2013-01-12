#include "head_bin_tree.h"

int main(int argc ,char *argv[])
{
    bi_tree bt;
    
    printf("Create binary tree:\n");
    printf("Please input a string of characters end with '#':");
    create_bi_tree(&bt);
    
    printf("Pre order(recursivly):\n");
    pre_order(bt);
    printf("\n");
    
    printf("In order(recursivly):\n");
    in_order(bt);
    printf("\n");
    
    printf("Post order(recursivly):\n");
    post_order(bt);
    printf("\n");

    printf("pre order(generally):\n");
    general_pre_order(bt);
    printf("\n");
    
    printf("in order(generally):\n");
    general_in_order(bt);
    printf("\n");
    
    printf("post order(generally):\n");
    general_post_order(bt);
    printf("\n");

    printf("Binary 's depth is :%d\n",recursive_post_tree_depth(bt));
    printf("Binary 's leafnum is :%d\n",recursive_post_tree_leafnum(bt));
    return 0;
}

