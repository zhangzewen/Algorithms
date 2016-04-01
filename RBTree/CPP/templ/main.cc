#include <iostream>
#include "RBTree.h"

struct comp
{
  bool operator()(int* a, int *b) {
    return *a <= *b ? true : false;
  }
};


void visit(int* key, int value)
{
  std::cout << "key: " << *key << ", value: " << value << std::endl;
}

int main(int argc, char** argv)
{
  RBTree<int*, int, comp> tree;
  int a1 = 1;
  int a2 = 4;
  int a3 = 3;
  int a4 = 2;
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
  int a15 = 22;
  int a16 = 5;

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
  tree.insert(&a15,2);
  tree.insert(&a16,2);

  tree.Print(visit);
  std::cout << std::endl;
  tree.Delete(&a14);
  tree.Print(visit);
  std::cout << "================================" << std::endl;
  tree.Delete(&a14);
  tree.Print(visit);
  return 0;
}
