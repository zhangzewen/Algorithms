#include "RBTree.h"
#include <stdio.h>
#include <stdlib.h>

bool RBTree::leftRotate(RBTree::Node** root, RBTree::Node* nodeShouldRotated)
{
  if (*root == NULL || nodeShouldRotated == NULL) {
    return false;
  }
  RBTree::Node* rightChild = nodeShouldRotated->right;  // y <- right[x]
  nodeShouldRotated->right = rightChild->left;  // right[x] = left[y]
  rightChild->left->parent = nodeShouldRotated;  //p[left[y]] = x
  rightChild->parent = nodeShouldRotated->parent;  // p[y] = p[x]

  if (nodeShouldRotated->parent == NULL) {  // if p[x] == null, that means x is the root of RBTree
    *root = rightChild;
  } else {
    if (nodeShouldRotated->parent->left = nodeShouldRotated) {  // x == left[p[x]]
      nodeShouldRotated->parent->left = nodeShouldRotated;  // left[p[x]] = y
    } else {
      nodeShouldRotated->parent->right = rightChild;  // right[p[x]] = y
    }
  }

  rightChild->left = nodeShouldRotated;  // left[y] = x
  nodeShouldRotated->parent = rightChild;  // p[x] = y

  return true;
}

bool RBTree::rightRotate(RBTree::Node** root, RBTree::Node* node)
{
  if (*root == NULL || node == NULL) {
    return false;
  }
  RBTree::Node* left_child = node->left;  // y <- left[x]
  node->left = left_child->right;  // left[x] = right[y]
  left_child->right->parent = node;  // p[right[y]] = x
  left_child->parent = node->parent;  // p[y] = p[x]

  if (node->parent == NULL) {  // if p[x] == null,  that means x is the root of RBTree
    *root = left_child;
  } else {
    if (node->parent->right = node) {  // if x == right[p[x]]
      node->parent->right = left_child;  //right[p[x]] = y
    } else {
      node->parent->right = left_child;  //left[p[x]] = y
    }
  }

  left_child->right = node;  // right[y] = x
  node->parent = leftChild;  //p[x] = y

  return true;
}


void RBTree::insert(int key, int value)
{
  RBTree::Node* parent = NULL;
  RBTree::Node* current = *root;
  while (current != NULL) {
    parent = current;
    if (key < current->key) {
      current = current->left;
    } else if (key > current->key) {
      current = current->right;
    } else {
      return ;
    }
  }

  new_node = new Node();
  new_node->key = key;
  new_node->value = value;

  new_node->parent = parent;

  if (NULL == parent) {
    *root = new_node;
  } else if (new_node->key < parent->key) {
    parent->left = new_node;
  } else if (new_node->key > parent->key) {
    parent->right = new_node;
  }
  return insertFixup(root, new_node);
}

bool RBTree::insertFixup(RBTree::Node** root, RBTree::Node* node)
{
  while (node->parent && node->parent->color == RBTree::RED) {
    if (node->parent == node->parent->parent->left) {
      RBTree::Node* uncle = node->parent->parent->right;
      if (uncle->color == RBTree::RED) {
        node->parent->color = RBTree::BLACK;
        uncle->color = RBTree::BLACK;
        node->parent->parent->color = RBTree::RED;
        node = nodeShouldFixup->parent->parent;
      } else {
        if (node = node->parent->right) {
          node = node->parent;
          leftRotate(root, node);
        }
        node->parent->color = RBTree::BLACK;
        node->parent->parent->color = RBTree::RED;
        rightRotate(root, node->parent->parent);
      }
    }else {
      RBTree::Node* uncle = node->parent->parent->left;
      if (uncle->color == RBTree::RED) {
        node->parent->color = RBTree::BLACK;
        uncle->color = RBTree::BLACK;
        node->parent->parent->color = RBTree::RED;
        node = node->parent->parent;
      } else {
        if (node = node->parent->left) {
          node = node->parent;
          rightRotate(root, node);
        }
        nodeShouldFixup->parent->color = RBTree::BLACK;
        nodeShouldFixup->parent->parent->color = RED;
        leftRotate(root, nodeShouldFixup->parent->parent);
      }
    }
  }
  (*root)->color = RBTree::BLACK;
  return true;
}

RBTree::Node* RBTree::Minimum(RBTree::Node* node)
{
  if (NULL == node) {
    return NULL;
  }
  while (NULL != node->left) {
    node = node->left;
  }
  return node;
}

RBTree::Node* RBTree::Maximum(RBTree::Node* node)
{
  if (NULL == node) {
    return NULL;
  }

  while (NULL != node->right) {
    node = node->right;
  }
  return node;
}
RBTree::Node* RBTree::Successor(RBTree::Node* node)
{
  if (NULL == node) {
    return NULL;
  }
  if (NULL != node->right) {
    return minimum(node->right);
  }

  RBTree::Node* parent = node->parent;
  while (NULL != parent && node == parent->right) {
    node = parent;
    parent = parent->parent;
  }
  return parent;
}

RBTree::Node* RBTree::Perdecessor(RBTree::Node* node)
{
  if (NULL == node) {
    return NULL;
  }

  if (NULL != node->left) {
    return maximum(node->left);
  }
  RBTree::Node* parent  = node->parent;
  if (NULL != parent && node == parent->left) {
    node = parent;
    parent = parent->parent;
  }
  return parent;
}


bool RBTree::Node* RBTree::delete(RBTree::Node** root, RBTree::Node *nodeShouldDelete)
{
  Node* tmp;
  if (nodeShouldDelete->left == NULL || nodeShouldDelete->right) {
    tmp = nodeShouldDelete;
  } else {
    y = successor(nodeShouldDelete);
  }

  if tmp
}


RBTree::Node* RBTree::Node* search(RBTree::Node** root, int key)
{
  if (NULL == *root) {
    return NULL;
  }

  Node* current = *root;
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

RBTree::Node* RBTree::Delete(RBTree::Node** root, int key)
{
  Node* node = search(root, key);
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

  child->parent = current->parent;

  if (NULL == current->parent) {
    *root = child;
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
    deleteFixup(root, child);
  }
  return current;
}


void RBTree::deleteFixup(RBTree::Node** root, RBTree::Node* node)
{

  while (node != *root && node->color == RBTree::BLACK) {
    if (node == node->parent->left) {
      brother = node->parent->right;
      if (brother->color == RBTree::RED) {
        node->parent->color = RBTree::RED;
        leftRotate(root, node->parent);
        brother = node->parent->right;
      }

    }
  }
  node->color = RBTree::BLACK;
}
