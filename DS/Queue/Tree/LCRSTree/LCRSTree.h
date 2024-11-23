#ifndef LCRS_TREE_H
#define LCRS_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char elementType;

typedef struct tagLCRSNode {
  struct tagLCRSNode *leftChild;
  struct tagLCRSNode *rightSibling;

  elementType data;
} LCRSNode;

LCRSNode *LCRS_CreateNode(elementType newData);
void LCRS_DestroyNode(LCRSNode *node);
void LCRS_DestroyTree(LCRSNode *root);

void LCRS_AddchildNode(LCRSNode *parentNode, LCRSNode *childNode);
void LCRS_PrintTree(LCRSNode *node, int depth);

#endif