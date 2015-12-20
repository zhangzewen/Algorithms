#include <iostream>
#include "RBTree.h"

int main(int argc, char** argv)
{
  RBTree<int, int> tree;
  tree.insert(1, 2);
  tree.insert(2, 2);
  tree.insert(3, 2);
  tree.insert(4, 2);
  tree.insert(5, 2);
  tree.insert(6, 2);
  tree.insert(7, 2);
  tree.insert(8, 2);
  tree.insert(9, 2);
  tree.insert(10, 2);
  tree.insert(11, 2);
  tree.insert(12, 2);
  tree.insert(13, 2);
  tree.insert(14, 2);
  tree.Print();
  return 0;
}
