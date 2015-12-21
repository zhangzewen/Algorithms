#include <iostream>
#include "RBTree.h"

int main(int argc, char** argv)
{
  RBTree tree;
  tree.insert(1,2);
  tree.insert(2,2);
  tree.insert(3,2);
  tree.insert(4,2);
  tree.insert(10,2);
  tree.insert(8,2);
  tree.insert(6,2);
  tree.insert(99,2);
  tree.insert(22,2);
  tree.insert(11,2);
  tree.insert(67,2);
  tree.insert(47,2);
  tree.insert(58,2);
  tree.insert(30,2);
  tree.Print();
  std::cout << std::endl;
  RBTree::Node* tmp = tree.Delete(30);
  delete tmp;

  tree.Print();
  return 0;
}
