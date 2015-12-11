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

bool RBTree::rightRotate(RBTree::Node** root, RBTree::Node* nodeShouldRotated)
{
  if (*root == NULL || nodeShouldRotated == NULL) {
    return false;
  }
  RBTree::Node* leftChild = nodeShouldRotated->left;  // y <- left[x]
  nodeShouldRotated->left = leftChild->right;  // left[x] = right[y]
  leftChild->right->parent = nodeShouldRotated;  // p[right[y]] = x
  leftChild->parent = nodeShouldRotated->parent;  // p[y] = p[x]

  if (nodeShouldRotated->parent == NULL) {  // if p[x] == null,  that means x is the root of RBTree
    *root = leftChild;
  } else {
    if (nodeShouldRotated->parent->right = nodeShouldRotated) {  // if x == right[p[x]]
      nodeShouldRotated->parent->right = leftChild;  //right[p[x]] = y
    } else {
      nodeShouldRotated->parent->right = leftChild;  //left[p[x]] = y
    }
  }

  leftChild->right = nodeShouldRotated;  // right[y] = x
  nodeShouldRotated->parent = leftChild;  //p[x] = y

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
    return NULL;
  }
  while(NULL != parent && node == parent->right) {
    node = parent;
    parent = parent->parent;
  }
  return node;
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


RBTree::Node* RBTree::Node* RBTree::Delete(RBTree::Node** root, int key)
{
  Node* current = *root;
  Node* node;
  Node* child;
  while (current != NULL) {
    if (key > current->key) {
      current = current->right;
    } else if (key < current->key) {
      current = current->left;
    } else {
      break;
    }
  }

  if (current == *root || current == NULL) {
    return current;
  }

  if (current->left == NULL || current->right == NULL) {
    node = current;
  } else {
    node = Successor(current);
  }

  if (node->left) {
    child = node->right;
  } else {
    child = node->left;
  }


}
