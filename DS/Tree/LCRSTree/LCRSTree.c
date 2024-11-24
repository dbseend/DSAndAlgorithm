#include "LCRSTree.h"

LCRSNode *LCRS_CreateNode(elementType newData) {
  LCRSNode *newNode = (LCRSNode *)malloc(sizeof(LCRSNode));

  newNode->data = newData;
  newNode->leftChild = NULL;
  newNode->rightSibling = NULL;

  return newNode;
}

void LCRS_DestroyNode(LCRSNode *node) { free(node); }

void LCRS_DestroyTree(LCRSNode *root) {
  if (root->rightSibling != NULL) {
    LCRS_DestroyTree(root->rightSibling);
  }
  if (root->leftChild != NULL) {
    LCRS_DestroyTree(root->leftChild);
  }

  root->leftChild = NULL;
  root->rightSibling = NULL;

  LCRS_DestroyNode(root);
}

// parentNode의 leftChild가 NULL이라면 자식이 없음 -> leftChild에 바로 삽입
// parentNode의 leftChild가 NULL이 아니라면 -> 오른쪽으로 타고 가면서 끝에 삽입
// 반복
void LCRS_AddChildNode(LCRSNode *parentNode, LCRSNode *childNode) {
  if (parentNode->leftChild == NULL) {
    parentNode->leftChild = childNode;
  } else {
    LCRSNode *tempNode = parentNode->leftChild;

    while (tempNode->rightSibling != NULL) {
      tempNode = tempNode->rightSibling;
    }

    tempNode->rightSibling = childNode;
  }
}

void LCRS_PrintTree(LCRSNode *node, int depth) {
  int i = 0;
  for (i = 0; i < depth - 1; i++) {
    printf("   ");
  }

  if (depth > 0) {
    printf("+--");
  }

  printf("%c\n", node->data);

  if (node->leftChild != NULL) {
    LCRS_PrintTree(node->leftChild, depth + 1);
  }
  if (node->rightSibling != NULL) {
    LCRS_PrintTree(node->rightSibling, depth);
  }
}

void LCRS_PrintNodesAtLevel(LCRSNode *root, int targetLevel) {}