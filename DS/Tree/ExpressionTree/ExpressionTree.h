#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char elementType;

typedef struct tagETNode {
  struct tagETNode *left;
  struct tagETNode *right;

  elementType data;
} ETNode;

ETNode *ET_CreateNode(elementType newData);
void ET_DestroyNode(ETNode *node);
void ET_DestroyTree(ETNode *root);

void ET_PreorderPrintTree(ETNode *node);
void ET_InorderPrintTree(ETNode *node);
void ET_PostorderPrintTree(ETNode *node);
void ET_BuildExpressionTree(char *postfixExpression, ETNode **node);
double ET_Evaluate(ETNode *node);

#endif