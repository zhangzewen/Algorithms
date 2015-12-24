#ifndef _RBTREE_H_INCLUDED__
#define _RBTREE_H_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>

using namespace std;

template<typename KEY, typename VALUE>
class RBTree
{
public:
  typedef enum COLOR_T {
    RED = 0,
    BLACK = 1
  }COLOR;

  struct Node {
    struct Node *left, *right, *parent;
    KEY key;
    VALUE value;
    int lflag;
    int rflag;
    COLOR color;
    Node() : left(0), right(0), parent(0),
      lflag(0), rflag(0), color(RED) {
    }
    ~Node() {
      left = 0;
      right = 0;
      parent = 0;
    }
  };

  RBTree() : root_(0) {
  }
  ~RBTree();
  bool insert(KEY key, VALUE value);
  Node* search(KEY key);
  Node* Delete(KEY key);
  bool remove(KEY key);
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
  RBTree(const RBTree&);
  RBTree& operator=(const RBTree&);
  Node* root_;
};


template<typename KEY, typename VALUE>
bool RBTree<KEY, VALUE>::leftRotate(typename RBTree::Node* node)
{
  if (root_ == NULL || node == NULL) {
    return false;
  }
  typename RBTree::Node* right_child = node->right;  // y <- right[x]
  node->right = right_child->left;  // right[x] = left[y]
  if (right_child->left) {
    right_child->left->parent = node;  //p[left[y]] = x
  }
  right_child->parent = node->parent;  // p[y] = p[x]

  if (node->parent == NULL) {  // if p[x] == null, that means x is the root_ of RBTree
    root_ = right_child;
  } else {
    if (node->parent->left == node) {  // x == left[p[x]]
      node->parent->left = right_child;  // left[p[x]] = y
    } else {
      node->parent->right = right_child;  // right[p[x]] = y
    }
  }

  right_child->left = node;  // left[y] = x
  node->parent = right_child;  // p[x] = y
  return true;
}

template<typename KEY, typename VALUE>
bool RBTree<KEY, VALUE>::rightRotate(typename RBTree::Node* node)
{
  if (root_ == NULL || node == NULL) {
    return false;
  }
  typename RBTree::Node* left_child = node->left;  // y <- left[x]
  node->left = left_child->right;  // left[x] = right[y]
  if (left_child->right) {
    left_child->right->parent = node;  // p[right[y]] = x
  }
  left_child->parent = node->parent;  // p[y] = p[x]

  if (node->parent == NULL) {  // if p[x] == null,  that means x is the root of RBTree
    root_ = left_child;
  } else {
    if (node->parent->right == node) {  // if x == right[p[x]]
      node->parent->right = left_child;  //right[p[x]] = y
    } else {
      node->parent->left = left_child;  //left[p[x]] = y
    }
  }

  left_child->right = node;  // right[y] = x
  node->parent = left_child;  //p[x] = y

  return true;
}


template<typename KEY, typename VALUE>
bool RBTree<KEY, VALUE>::insert(KEY key, VALUE value)
{
  typename RBTree::Node* parent = NULL;
  typename RBTree::Node* current = root_;
  while (current != NULL) {
    parent = current;
    if (key < current->key) {
      current = current->left;
    } else if (key > current->key) {
      current = current->right;
    } else {
      return false;
    }
  }

  Node* new_node = new Node();
  new_node->key = key;
  new_node->value = value;

  new_node->parent = parent;

  if (NULL == parent) {
    root_ = new_node;
  } else if (new_node->key < parent->key) {
    parent->left = new_node;
  } else if (new_node->key > parent->key) {
    parent->right = new_node;
  }
  return insertFixup(new_node);
}

template<typename KEY, typename VALUE>
bool RBTree<KEY, VALUE>::insertFixup(typename RBTree::Node* node)
{
  while (node->parent && node->parent->color == RBTree::RED) {
    if (node->parent == node->parent->parent->left) {
      typename RBTree::Node* uncle = node->parent->parent->right;
      if (uncle && uncle->color == RBTree::RED) {
        node->parent->color = RBTree::BLACK;
        uncle->color = RBTree::BLACK;
        node->parent->parent->color = RBTree::RED;
        node = node->parent->parent;
      } else {
        if (node == node->parent->right) {
          node = node->parent;
          leftRotate(node);
        }
        node->parent->color = RBTree::BLACK;
        node->parent->parent->color = RBTree::RED;
        rightRotate(node->parent->parent);
      }
    }else {
      typename RBTree::Node* uncle = node->parent->parent->left;
      if (uncle && uncle->color == RBTree::RED) {
        node->parent->color = RBTree::BLACK;
        uncle->color = RBTree::BLACK;
        node->parent->parent->color = RBTree::RED;
        node = node->parent->parent;
      } else {
        if (node == node->parent->left) {
          node = node->parent;
          rightRotate(node);
        }
        node->parent->color = RBTree::BLACK;
        node->parent->parent->color = RED;
        leftRotate(node->parent->parent);
      }
    }
  }
  root_->color = RBTree::BLACK;
}

template<typename KEY, typename VALUE>
typename RBTree<KEY, VALUE>::Node* RBTree<KEY, VALUE>::minimum(typename RBTree::Node* node)
{
  if (NULL == node) {
    return NULL;
  }
  while (NULL != node->left) {
    node = node->left;
  }
  return node;
}

template<typename KEY, typename VALUE>
typename RBTree<KEY, VALUE>::Node* RBTree<KEY, VALUE>::maximum(typename RBTree::Node* node)
{
  if (NULL == node) {
    return NULL;
  }

  while (NULL != node->right) {
    node = node->right;
  }
  return node;
}

template<typename KEY, typename VALUE>
typename RBTree<KEY, VALUE>::Node* RBTree<KEY, VALUE>::successor(typename RBTree::Node* node)
{
  if (NULL == node) {
    return NULL;
  }
  if (NULL != node->right) {
    return minimum(node->right);
  }

  RBTree<KEY, VALUE>::Node* parent = node->parent;
  while (NULL != parent && node == parent->right) {
    node = parent;
    parent = parent->parent;
  }
  return parent;
}

template<typename KEY, typename VALUE>
typename RBTree<KEY, VALUE>::Node* RBTree<KEY, VALUE>::perdecessor(typename RBTree::Node* node)
{
  if (NULL == node) {
    return NULL;
  }

  if (NULL != node->left) {
    return maximum(node->left);
  }
  typename RBTree::Node* parent  = node->parent;
  if (NULL != parent && node == parent->left) {
    node = parent;
    parent = parent->parent;
  }
  return parent;
}


template<typename KEY, typename VALUE>
typename RBTree<KEY, VALUE>::Node* RBTree<KEY, VALUE>::search(KEY key)
{
  if (NULL == root_) {
    return NULL;
  }

  Node* current = root_;
  while(current) {
    if (current->key > key) {
      current = current->left;
    } else if (current->key < key) {
      current = current->right;
    } else {
      return current;
    }
  }
  return NULL;
}

template<typename KEY, typename VALUE>
typename RBTree<KEY, VALUE>::Node* RBTree<KEY, VALUE>::Delete(KEY key)
{
  Node* node = search(key);
  Node* current = NULL;
  Node* child = NULL;

  if (NULL == node) {
    return NULL;
  }

  if (NULL == node->left || NULL == node->right) {
    current = node;
  } else {
    current = successor(node);
  }

  if (NULL != current->left) {
    child = current->left;
  } else {
    child = current->right;
  }

  if (child) {
    child->parent = current->parent;
  }

  if (NULL == current->parent) {
    root_ = child;
  } else if (current == current->parent->left) {
    current->parent->left = child;
  } else if (current == current->parent->right) {
    current->parent->right = child;
  }

  if (node != current) {
    node->key = current->key;
    node->value = current->value;
  }

  if (current->color == RBTree::BLACK) {
    deleteFixup(child);
  }
  return current;
}


template<typename KEY, typename VALUE>
void RBTree<KEY, VALUE>::deleteFixup(typename RBTree::Node* node)
{
  Node* brother = NULL;
  while (node != root_ && node->color == RBTree::BLACK) {
    if (node == node->parent->left) {
      brother = node->parent->right;
      if (brother->color == RBTree::RED) {
        brother->color = RBTree::BLACK;
        node->parent->color = RBTree::RED;
        leftRotate(node->parent);
        brother = node->parent->right;
      }
      if (brother->left->color == RBTree::BLACK && brother->right->color == RBTree::BLACK) {
        brother->color = RBTree::RED;
        node = node->parent;
      } else {
        if (brother->right->color == RBTree::BLACK) {
          brother->left->color = RBTree::BLACK;
          brother->color = RBTree::RED;
          rightRotate(brother);
          brother = node->right;
        }
        brother->color = brother->parent->color;
        node->parent->color = RBTree::BLACK;
        brother->right->color = RBTree::BLACK;
        leftRotate(node->parent);
        node = root_;
      }
    } else {
      brother = node->parent->left;
      if (brother->color == RBTree::RED) {
        brother->color = RBTree::BLACK;
        node->parent->color = RBTree::RED;
        rightRotate(node->parent);
        brother = node->parent->left;
      }
      if (brother->left->color == RBTree::BLACK && brother->right->color == RBTree::BLACK) {
        brother->color = RBTree::RED;
        node = node->parent;
      } else {
        if (brother->left->color == RBTree::BLACK) {
          brother->right->color = RBTree::BLACK;
          brother->color = RBTree::RED;
          leftRotate(brother);
          brother = node->left;
        }
        brother->color = brother->parent->color;
        node->parent->color = RBTree::BLACK;
        brother->left->color = RBTree::BLACK;
        rightRotate(node->parent);
        node = root_;
      }
    }
  }
  node->color = RBTree::BLACK;
}


template<typename KEY, typename VALUE>
void RBTree<KEY, VALUE>::Print()
{
  std::stack<Node* > tree_stack;
  Node* current = root_;
  while(current || !tree_stack.empty()) {
    if (current) {
      tree_stack.push(current);
      current = current->left;
    } else {
      Node* p = tree_stack.top();
      tree_stack.pop();
      std::cout << p->key << " ";
      current = p->right;
    }
  }
}


template<typename KEY, typename VALUE>
RBTree<KEY, VALUE>::~RBTree()
{
    std::stack<Node*> tree_stack;
    Node* current = root_;
    tree_stack.push(current);

    while(!tree_stack.empty())
    {

        while(current){
            if(current->lflag != 1 )
            {
                current->lflag = 1;
                if(current->left){
                    tree_stack.push(current->left);
                    current = current->left;
                }
            }else if(current->rflag != 1)
            {
                current->rflag = 1;
                if(current->right){
                    tree_stack.push(current->right);
                    current = current->right;
                }

            }else if(current->lflag == 1 && current->rflag == 1){
                break;
            }
        }
        current = tree_stack.top();
        tree_stack.pop();
        delete current;
        current = NULL;
        if(tree_stack.empty()) {
            break;
        }
        current = tree_stack.top();
    }

    root_ = NULL;
}

#endif
