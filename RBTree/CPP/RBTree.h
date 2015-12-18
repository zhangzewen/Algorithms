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
    rbtree_node() : left(0), right(0), parent(0),
      color(RED) {
    }
    ~rbtree_node() {
      left = 0;
      right = 0;
      parent = 0;
    }
  }Node;

  RBTree() : root_(0) {
  }
  ~RBTree();
  bool insert(int key, int value);
  Node* search(int key);
  Node* Delete(int key);
  bool remove(int key);
  bool leftRotate(Node* node);
  bool rightRotate(Node* node);
  bool insertFixup(Node* node);
  void deleteFixup(Node* node);
  Node* minimum(Node* node);
  Node* maximum(Node* node);
  Node* successor(Node* node);
  Node* perdecessor(Node* node);
  void Print();
private:
  Node* root_;
};


#endif
