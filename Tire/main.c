#include <stdio.h>
#include <stdlib.h>
#include "Tire.h"

int main(int argc, char** argv)
{
    struct node* root;
    root = create_node();
    addText(root, "zhangjie");
    addText(root, "jie");
    addText(root, "yifan");
    addText(root, "wangwei");
    return 0;
}
