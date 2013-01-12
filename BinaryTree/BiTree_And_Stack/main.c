
#include"BiTree.h"
#include<stdlib.h>
#include<stdio.h>

int main()
{
	BiTree root=NULL;
	printf("Create BiTree..\n");
	CreateBiTree(&root);
	printf("\nDone!!!!\n");

	printf("PreOrderTraverse..\n");
	PreOrderTraverse( root);
	printf("\nDone!!!!\n");

	printf("InOrderTraveerse..\n");
 	InOrderTraveerse(root);
	printf("\nDone!!!!\n");

	printf("后序遍历.....\n");
  PostOrderTravaerse(root);
	printf("\n遍历完成\n");

	return 0;	
}
