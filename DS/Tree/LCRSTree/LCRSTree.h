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

void LCRS_AddChildNode(LCRSNode *parentNode, LCRSNode *childNode);
void LCRS_PrintTree(LCRSNode *node, int depth);
void LCRS_PrintNodesAtLevel(LCRSNode* node, int level);

#endif