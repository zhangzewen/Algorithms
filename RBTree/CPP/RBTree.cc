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


bool RBTree::insert(int key, int value)
{

}

bool RBTree::insert(RBTree::Node** root, RBTree::Node* nodeShouldInsert)
{
  RBTree::Node* parent = NULL;
  RBTree::Node* current = *root;
  while (current != NULL) {
    parent = current;
    if (nodeShouldInsert->key < current->key) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  nodeShouldInsert->parent = parent;
  if (NULL == parent) {
    *root = nodeShouldInsert;
  } else if (nodeShouldInsert->key < parent->key) {
    parent->left = nodeShouldInsert;
  } else if (nodeShouldInsert->key > parent->key) {
    parent->right = nodeShouldInsert;
  }
  return insertFixup(root, nodeShouldInsert);
}

bool RBTree::insertFixup(RBTree::Node** root, RBTree::Node* nodeShouldFixup)
{
  while (nodeShouldFixup->color == RBTree::RED) {
    if (nodeShouldFixup->parent == nodeShouldFixup->parent->parent->left) {
      RBTree::Node* uncle = nodeShouldFixup->parent->parent->right;
      if (uncle->color == RBTree::RED) {
        nodeShouldFixup->parent->color = RBTree::BLACK;
        uncle->color = RBTree::BLACK;
        nodeShouldFixup->parent->parent->color = RBTree::RED;
        nodeShouldFixup = nodeShouldFixup->parent->parent;
      } else {
        if (nodeShouldFixup = nodeShouldFixup->parent->right) {
          nodeShouldFixup = nodeShouldFixup->parent;
          leftRotate(root, nodeShouldFixup);
        }
        nodeShouldFixup->parent->color = RBTree::BLACK;
        nodeShouldFixup->parent->parent->color = RBTree::RED;
        rightRotate(root, nodeShouldFixup->parent->parent);
      }
    }else {
      RBTree::Node* uncle = nodeShouldFixup->parent->parent->left;
      if (uncle->color == RBTree::RED) {
        nodeShouldFixup->parent->color = RBTree::BLACK;
        uncle->color = RBTree::BLACK;
        nodeShouldFixup->parent->parent->color = RBTree::RED;
        nodeShouldFixup = nodeShouldFixup->parent->parent;
      } else {
        if (nodeShouldFixup = nodeShouldFixup->parent->left) {
          nodeShouldFixup = nodeShouldFixup->parent;
          rightRotate(root, nodeShouldFixup);
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

RBTree::Node* RBTree::minimum(RBTree::Node* node)
{
  if (NULL == node) {
    return NULL;
  }
  while (NULL != node->left) {
    node = node->left;
  }
  return node;
}

RBTree::Node* RBTree::maximum(RBTree::Node* node)
{
  if (NULL == node) {
    return NULL;
  }

  while (NULL != node->right) {
    node = node->right;
  }
  return node;
}
RBTree::Node* RBTree::successor(RBTree::Node* node)
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

RBTree::Node* RBTree::perdecessor(RBTree::Node* node)
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

