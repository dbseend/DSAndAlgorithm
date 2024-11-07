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
void DLL_InsertAfter(Node *Current, Node *NewNode) {
  // Current 노드가 마지막 노드인 경우
  if (Current->nextNode == NULL) {
    Current->nextNode = NewNode;
    NewNode->prevNode = Current;
    NewNode->nextNode = NULL;
  } else {
    // 중간에 삽입하는 경우
    NewNode->prevNode = Current;
    NewNode->nextNode = Current->nextNode;
    Current->nextNode->prevNode = NewNode;
    Current->nextNode = NewNode;
  }
}

void DLL_InsertAfterAns(Node *Current, Node *NewNode) {
  NewNode->nextNode = Current->nextNode;
  NewNode->prevNode = Current;

  if (Current->nextNode != NULL) {
    Current->nextNode->prevNode = NewNode;
    Current->nextNode = NewNode;
  }
}

void DLL_RemoveNode(Node **Head, Node *Remove) {
  Node *Current = *Head;

  if (*Head == Remove) { // 삭제하려는 노드가 첫번째 노드인 경우
    if ((*Head)->nextNode != NULL) {
      (*Head)->nextNode->prevNode = NULL;
    }
  } else {
    if (Remove->nextNode !=
        NULL) { // 삭제하려는 노드 앞,뒤의 노두가 모두 존재하는 경우
      Remove->prevNode->nextNode = Remove->nextNode;
      Remove->nextNode->prevNode = Remove->prevNode;
    } else { // 삭제하려는 노드가 마지막 노드인 경우
      Remove->prevNode->nextNode = NULL;
    }
  }

  Remove->prevNode = NULL;
  Remove->nextNode = NULL;
}

void DLL_RemoveNodeAns(Node **Head, Node *Remove) {
  if (*Head == Remove) {
    *Head = Remove->nextNode;
    if ((*Head) != NULL) {
      (*Head)->prevNode = NULL;
    }

    Remove->prevNode = NULL;
    Remove->nextNode = NULL;
  } else {
    Node *Temp = Remove;

    if (Remove->prevNode != NULL) {
      Remove->nextNode->prevNode = Temp->nextNode;
    }
    if (Remove->nextNode != NULL) {
      Remove->nextNode->prevNode = Temp->prevNode;
    }

    Remove->prevNode = NULL;
    Remove->nextNode = NULL;
  }
}

// 노드 탐색
Node *DLL_GetNodeAt(Node *Head, int Location) {

  Node *Current = Head;

  while (Current != NULL && (--Location) >= 0) {
    Current = Current->nextNode;
  }

  return Current;
}

int DLL_GetNodeCount(Node *Head) {
  int count = 0;
  Node *Current = Head;

  while (Current != NULL) {
    Current = Current->nextNode;
    count++;
  }

  return count;
}

void PrintNode(Node *_Node) {
  if (_Node->prevNode == NULL) {
    printf("Prev: NULL");
  } else {
    printf("Prev: %d", _Node->prevNode->data);

    printf("Current: %d", _Node->data);
  }

  if (_Node->nextNode == NULL) {
    printf("Next: NULL\n");
  } else {
    printf("Next: %d\n", _Node->nextNode->data);
  }
}

void DLL_PrintReverse(Node *_Node) {
  int Count = DLL_GetNodeCount(_Node);

  for (int i = Count; i > 0; i--) {
    Node *node = DLL_GetNodeAt(_Node, i - 1);
    printf("[%d] : %d\n", i - 1, node->data);
  }
}