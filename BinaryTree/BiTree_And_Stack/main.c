
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
	printf("\n");
	PreOrderTraverse_1( root);
	printf("\nDone!!!!\n");

	printf("InOrderTraveerse..\n");
 	InOrderTraverse(root);
	printf("\n");
 	InOrderTraverse_1(root);
	printf("\nDone!!!!\n");

	printf("PostOrderTravaerse..\n");
	PostOrderTraverse(root);
	printf("\n");
	PostOrderTraverse_1(root);
	printf("\nDone\n");
	BiTree_free(&root);

	return 0;
}
