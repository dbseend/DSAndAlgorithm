#include "LinkedList.h"

Node* SLL_CreateNode(ElementType NewData){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Data = NewData;
    newNode->NextNode = null;

    return newNode;
}

void  SLL_DestroyNode(Node* Node){
    free(node);
}

void  SLL_AppendNode(Node** Head, Node* NewNode){
    (*Head)->NextNode = NewNode;
}

void  SLL_InsertAfter(Node* Current, Node* NewNode){

}

void  SLL_InsertNewHead(Node** Head, Node* NewHead){

}

void  SLL_RemoveNode(Node** Head, Node* Remove){

}

Node* SLL_GetNodeAt(Node* Head, int Location){
    
}

int   SLL_GetNodeCount(Node* Head){

}
