#include "ExpressionTree.h"

ETNode *ET_CreateNode(elementType newData) {
  ETNode *newNode = (ETNode *)malloc(sizeof(ETNode));
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->data = newData;

  return newNode;
}

void ET_DestroyNode(ETNode *node) { free(node); }

void ET_DestroyTree(ETNode *root) {
  if (root == NULL) {
    return;
  }

  ET_DestroyTree(root->left);
  ET_DestroyTree(root->right);
  ET_DestroyNode(root);
}

void ET_PreorderPrintTree(ETNode *node) {
  if (node == NULL) {
    return;
  }

  printf("%c ", node->data);
  ET_PreorderPrintTree(node->left);
  ET_PreorderPrintTree(node->right);
}

void ET_InorderPrintTree(ETNode *node) {
  if (node == NULL) {
    return;
  }

  printf("(");
  ET_InorderPrintTree(node->left);
  printf("%c ", node->data);
  ET_InorderPrintTree(node->right);
  printf(")");
}

void ET_PostorderPrintTree(ETNode *node) {
  if (node == NULL) {
    return;
  }

  ET_PostorderPrintTree(node->left);
  ET_PostorderPrintTree(node->right);
  printf("%c ", node->data);
}

void ET_BuildExpressionTree(char *postfixExpression, ETNode **node) {

  int len = strlen(postfixExpression);
  char token = postfixExpression[len - 1];
  postfixExpression[len - 1] = '\0';

  // 연산자인 경우
  switch (token) {
  case '+':
  case '-':
  case '*':
  case '/':
    (*node) = ET_CreateNode(token);
    ET_BuildExpressionTree(postfixExpression, &(*node)->right);
    ET_BuildExpressionTree(postfixExpression, &(*node)->left);
    break;

  // 피연산자인 경우
  default:
    (*node) = ET_CreateNode(token);
    break;
  }
}

double ET_Evaluate(ETNode *node) {
  char temp[2];

  double left = 0;
  double right = 0;
  double result = 0;

  if (node == NULL) {
    return 0;
  }

  switch (node->data) {
  case '+':
  case '-':
  case '*':
  case '/':
    left = ET_Evaluate(node->left);
    right = ET_Evaluate(node->right);

    if (node->data == '+')
      result = left + right;
    else if (node->data == '-')
      result = left - right;
    else if (node->data == '*')
      result = left * right;
    else if (node->data == '/')
      result = left / right;

    break;

  default:
    memset(temp, 0, sizeof(temp));
    temp[0] = node->data;
    result = atof(temp);
    
    break;
  }

  return result;
}