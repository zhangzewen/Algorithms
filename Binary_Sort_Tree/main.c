
#include"Binary_Sort_Tree.h"
#include<stdlib.h>
#include<stdio.h>

int main()
{
	BiTree T=NULL;
	Insert_Binary_Sort_Tree(&T,'G');
    Insert_Binary_Sort_Tree(&T,'D');
	Insert_Binary_Sort_Tree(&T,'C');
    Insert_Binary_Sort_Tree(&T,'A');
	Insert_Binary_Sort_Tree(&T,'B');
	Insert_Binary_Sort_Tree(&T,'E');
	Insert_Binary_Sort_Tree(&T,'H');
	Insert_Binary_Sort_Tree(&T,'F');
	Insert_Binary_Sort_Tree(&T,'K');
	Insert_Binary_Sort_Tree(&T,'I');
	Insert_Binary_Sort_Tree(&T,'J');
	Insert_Binary_Sort_Tree(&T,'S');
	Insert_Binary_Sort_Tree(&T,'Z');
	Insert_Binary_Sort_Tree(&T,'M');
	Insert_Binary_Sort_Tree(&T,'R');
	Insert_Binary_Sort_Tree(&T,'Y');
	Insert_Binary_Sort_Tree(&T,'Z');
 
  PreOrderTraverse( T);
	printf("\n");
	InOrderTraveerse(T);
	printf("\n");
  PostOrderTravaerse(T);
	printf("\n");
	printf("\nAfter delete a letter:D\n");
	Delete_Binary_Sort_Tree(&T,'D');
  PreOrderTraverse( T);
	printf("\n");
	InOrderTraveerse(T);
	printf("\n");
  PostOrderTravaerse(T);
	printf("\n");
	printf("\nAfter delete a letter:J\n");
	Delete_Binary_Sort_Tree(&T,'J');
	printf("\n");
  PreOrderTraverse( T);
	printf("\n");
	InOrderTraveerse(T);
	printf("\n");
  PostOrderTravaerse(T);
}
