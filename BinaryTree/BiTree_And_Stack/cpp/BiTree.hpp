#ifndef _BINARYTREE_HPP_INCLUDED_
#define _BINARYTREE_HPP_INCLUDED_

class BiTree {
	public:
		typedef struct BiTNode{
			int data;
			struct BiTNode *lchild;
			struct BiTNode *rchild;
		} _BiTree;

		BiTree();
		~BiTree();
		_BiTree* insert(int data);
		_BiTree* remove(int data);
		void Print();
	private:
		_BiTree *root;
		void free_Bitree(_BiTree **root);
};

#if 0
Status CreateBiTree(BiTree *T);
//Status CreateBiTree(BiTree &T);
void PreOrderTraverse(BiTree T);
void PreOrderTraverse_1(BiTree T);
void InOrderTraverse(BiTree T);
void InOrderTraverse_1(BiTree T);
void PostOrderTraverse(BiTree T);
void PostOrderTraverse_1(BiTree T);
void BiTree_free(BiTree *T);
//---------------------------------------------------------------

#endif
#endif
