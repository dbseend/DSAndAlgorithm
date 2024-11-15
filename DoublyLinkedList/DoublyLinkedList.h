#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
  ElementType data;
  struct tagNode *prevNode;
  struct tagNode *nextNode;
} Node;

Node *DLL_CreateNode(ElementType NewData);
void DLL_DestroyNode(Node *Node);
void DLL_AppendNode(Node **Head, Node *NewNode);
void DLL_InsertAfter(Node *Current, Node *NewNode);
void DLL_RemoveNode(Node **Head, Node *Remove);
void DLL_RemoveNodeAns(Node **Head, Node *Remove);
Node *DLL_GetNodeAt(Node *Head, int Location);
int DLL_GetNodeCount(Node *Head);
void PrintNode(Node *_Node);
void DLL_PrintReverse(Node *_Node);

#endif