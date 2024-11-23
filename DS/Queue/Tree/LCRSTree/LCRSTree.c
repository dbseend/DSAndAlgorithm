#include "LCRSTree.h"

LCRSNode *LCRS_CreateNode(elementType newData){
    LCRSNode* newNode = (LCRSNode*)malloc(sizeof(LCRSNode));

    newNode->data = newData;
    newNode->leftChild = NULL;
    newNode->rightSibling = NULL;

    return newNode;
}

void LCRS_DestroyNode(LCRSNode *node){
    free(node);
}

void LCRS_DestroyTree(LCRSNode *root){
    
}

void LCRS_AddchildNode(LCRSNode *parentNode, LCRSNode *childNode){

}

void LCRS_PrintTree(LCRSNode *node, int depth){

}