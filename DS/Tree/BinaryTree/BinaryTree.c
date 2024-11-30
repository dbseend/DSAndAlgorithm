#include "BinaryTree.h"

SBTNode *SBT_CreateNode(elementType newData) {

  SBTNode *newNode = (SBTNode *)malloc(sizeof(SBTNode));
  newNode->data = newData;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

void SBT_DestroyNode(SBTNode *node) { free(node); }

void SBT_DestroyTree(SBTNode *root) {
  if (root == NULL) {
    return;
  }

  SBT_DestroyTree(root->left);
  SBT_DestroyTree(root->right);

  SBT_DestroyNode(root);
}

void SBT_PreorderPrintTree(SBTNode *node) {
  if (node == NULL) {
    return;
  }

  printf("%c", node->data);

  SBT_PreorderPrintTree(node->left);
  SBT_PreorderPrintTree(node->right);
}

void SBT_InorderPrintTree(SBTNode *node) {
  if (node == NULL) {
    return;
  }

  SBT_InorderPrintTree(node->left);

  printf("%c", node->data);

  SBT_InorderPrintTree(node->right);
}

void SBT_PostorderPrintTree(SBTNode *node) {
  if (node == NULL) {
    return;
  }

  SBT_PostorderPrintTree(node->left);

  SBT_PostorderPrintTree(node->right);

  printf("%c", node->data);
}