#ifndef _RBTREE_H_INCLUDED__
#define _RBTREE_H_INCLUDED__

class RBTree
{
public:
  typedef enum COLOR_T {
    RED = 0,
    BLACK = 1
  }COLOR;

  typedef struct rbtree_node {
    struct rbtree_node *left, *right, *parent;
    int key;
    int value;
    COLOR color;
  }Node;

  RBTree() : root(0) {
  }
  bool insert(int key, int value);
  bool insert(Node** root, Node* nodeShouldInsert);
  bool search(int key);
  bool remove(int key);
  bool leftRotate(Node** root, Node* NodeShouldRotated);
  bool rightRotate(Node** root, Node* NodeShouldRotated);
  bool insertFixup(Node** root, Node* NodeshouldFixup);
  Node* minimum(Node* node);
  Node* maximum(Node* node);
  Node* successor(Node* node);
  Node* perdecessor(Node* node);
private:
  Node* root;
};


#endif
