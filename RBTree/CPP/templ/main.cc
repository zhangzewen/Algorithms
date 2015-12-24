#include <iostream>
#include "RBTree.h"

int main(int argc, char** argv)
{
  RBTree<int*, int> tree;
  int a1 = 1;
  int a2 = 2;
  int a3 = 3;
  int a4 = 4;
  int a5 = 1;
  int a6 = 8;
  int a7 = 6;
  int a8 = 99;
  int a9 = 22;
  int a10 = 11;
  int a11 = 67;
  int a12 = 47;
  int a13 = 58;
  int a14 = 30;

  tree.insert(&a1,2);
  tree.insert(&a2,2);
  tree.insert(&a3,2);
  tree.insert(&a4,2);
  tree.insert(&a5,2);
  tree.insert(&a6,2);
  tree.insert(&a7,2);
  tree.insert(&a8,2);
  tree.insert(&a9,2);
  tree.insert(&a10,2);
  tree.insert(&a11,2);
  tree.insert(&a12,2);
  tree.insert(&a13,2);
  tree.insert(&a14,2);

  tree.Print();
  //std::cout << std::endl;
  //RBTree<int, int>::Node* tmp = tree.Delete(30);
  //delete tmp;
  //tree.Print();
  //RBTree<int, int> other;
  //other = tree;
  return 0;
}
