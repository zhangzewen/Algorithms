#include <stdio.h>
#include "Banlanced_Binary_Tree.h"
int main(int argc, char *argv[])
{
	BiTree T = NULL;
	Banlanced_Binary_Tree_insert(&T, 'h');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'e');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'r');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'c');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'g');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'j');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'k');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 't');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'q');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'v');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 's');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
}
