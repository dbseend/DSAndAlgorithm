#include "DoublyLinkedList.h"

// 노드 생성
Node *DLL_CreateNode(ElementType NewData) {

  Node *newNode = (Node *)malloc(sizeof(Node));

  newNode->data = NewData;
  newNode->prevNode = NULL;
  newNode->nextNode = NULL;

  return newNode;
}

// 노드 소멸
void DLL_DestroyNode(Node *Node) { free(Node); }

// 노드 추가
void DLL_AppendNode(Node **Head, Node *NewNode) {

  if ((*Head) == NULL) {
    *Head = NewNode;
  } else {
    Node *Tail = *Head;

    while (Tail->nextNode != NULL) {
      Tail = Tail->nextNode;
    }

    Tail->nextNode = NewNode;
    NewNode->prevNode = Tail;
  }
}

// 노드 삽입
void DLL_InsertAfter(Node *Current, Node *NewNode) {}

void DLL_RemoveNode(Node **Head, Node *Remove) {
  Node *Current = *Head;
  
  if (*Head == Remove) { // 삭제하려는 노드가 첫번째 노드인 경우 
    if((*Head)->nextNode != NULL){
      (*Head)->nextNode->prevNode = NULL;
    }
  } else {
    if (Remove->nextNode != NULL) { // 삭제하려는 노드 앞,뒤의 노두가 모두 존재하는 경우
      Remove->prevNode->nextNode = Remove->nextNode;
      Remove->nextNode->prevNode = Remove->prevNode;
    } else { // 삭제하려는 노드가 마지막 노드인 경우
      Remove->prevNode->nextNode = NULL;
    }
  }

  Remove->prevNode = NULL;
  Remove->nextNode = NULL;
}

void DLL_RemoveNodeFixed(Node **Head, Node *Remove) {
  Node *Current = *Head;
  Node *Next = NULL;

  if (*Head == Remove) { // 첫번째 노드를 삭제 할 때
    Remove->nextNode = NULL;
    Next->prevNode = NULL;
  }

  while (Current->nextNode != NULL) {

    Next = Current->nextNode;

    if (Next == Remove) {
      Node *NextRemove = Remove->nextNode;

      if (NextRemove == NULL) {
        Remove->prevNode = NULL;
        Current->nextNode = NULL;
      } else {
        Remove->nextNode = NULL;
        Remove->prevNode = NULL;

        Current->nextNode = NextRemove;
        NextRemove->prevNode = Current;
      }

      break;
    }

    Current = Current->nextNode;
  }
}

// 노드 탐색
Node *DLL_GetNodeAt(Node *Head, int Location) {

  Node *Current = Head;

  while (Current != NULL && Location >= 0) {
    Current = Current->nextNode;

    Location--;
  }

  return Current;
}

int DLL_GetNodeCount(Node *Head) {}