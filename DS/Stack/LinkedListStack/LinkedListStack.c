#include "LinkedListStack.h"

// 스택 생성
void LLS_CreateStack(LinkedListStack **Stack) {
  (*Stack) = (LinkedListStack *)malloc(sizeof(LinkedListStack));
  (*Stack)->List = NULL;
  (*Stack)->Top = NULL;
}

// 스택 소멸
void LLS_DestroyStack(LinkedListStack *Stack) {
  while (!LLS_IsEmpty(Stack)) {
    Node *Popped = LLS_Pop(Stack);
    LLS_DestroyNode(Popped);
  }

  free(Stack);
}

Node *LLS_CreateNode(char *NewData) {
  Node *NewNode = (Node *)malloc(sizeof(Node));
  NewNode->Data = (char *)malloc(strlen(NewData) + 1);

  strcpy(NewNode->Data, NewData);

  NewNode->NextNode = NULL;

  return NewNode;
}

void LLS_DestroyNode(Node *_Node) {
  free(_Node->Data);
  free(_Node);
}

void LLS_Push(LinkedListStack *Stack, Node *NewNode) {
  if (Stack->List == NULL) {
    Stack->List = NewNode;
  } else {
    Stack->Top->NextNode = NewNode;
  }

  Stack->Top = NewNode;
}

Node *LLS_Pop(LinkedListStack *Stack) {
  Node *Top = Stack->Top;
  Node *Current = Stack->List;

  if (Current == Top) {
    Stack->Top = NULL;
    Stack->List = NULL;
  } else {
    while (Current->NextNode != Top && Current != NULL) {
      Current = Current->NextNode;
    }

    Stack->Top = Current;
    Stack->Top->NextNode = NULL;
  }

  return Top;
}

Node *LLS_Top(LinkedListStack *Stack) { return Stack->Top; }

int LLS_GetSize(LinkedListStack *Stack) {
  int Count = 0;

  Node *Current = Stack->List;
  while (Current != NULL) {
    Current = Current->NextNode;
    Count++;
  }

  return Count;
}

int LLS_IsEmpty(LinkedListStack *Stack) { return (Stack->List == NULL); }