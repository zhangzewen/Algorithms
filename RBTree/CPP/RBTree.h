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
    rbtree_node() : left(NULL), right(NULL), parent(NULL),
      color(RED) {
    }
  }Node;

  RBTree() : root(0) {
  }
  bool Insert(int key, int value);
  bool Search(int key);
  bool Remove(int key);
  bool LeftRotate(Node** root, Node* NodeShouldRotated);
  bool RightRotate(Node** root, Node* NodeShouldRotated);
  bool InsertFixUp(Node** root, Node* NodeshouldFixup);
  bool DeleteFixUp(Node** root, Node* node_should_fixup);
  Node* minimum(Node* node);
  Node* maximum(Node* node);
  Node* successor(Node* node);
  Node* perdecessor(Node* node);
private:
  Node* root;
};


#endif
