#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char elementType;

typedef struct tagSBTNode {
  struct tagSBTNode *left;
  struct tagSBTNode *right;

  elementType data;
} SBTNode;

SBTNode* SBT_CreateNode(elementType newData);
void SBT_DestroyNode(SBTNode* node);
void SBT_DestroyTree(SBTNode* root);

void SBT_PreorderPrintTree(SBTNode* Node);
void SBT_InorderPrintTree(SBTNode* Node);
void SBT_PostorderPrintTree(SBTNode* Node);

#endif
