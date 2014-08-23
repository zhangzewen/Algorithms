#include <iostream>

using namespace std;

class A{
public:
	typedef struct BiTree {
		int data;
		struct BiTree *lchild;
		struct BITree *rchild;
	}bitree;

private:
	bitree root;
};

int main()
{
	A::bitree Node;
	A a;
	return 0;
}
