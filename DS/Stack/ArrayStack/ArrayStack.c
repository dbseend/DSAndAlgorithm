#include "ArrayStack.h"

// 스택 및 노드 생성
void AS_CreateStack(ArrayStack **Stack, int Capacity) {
  (*Stack) = (ArrayStack *)malloc(sizeof(Stack));

  (*Stack)->Nodes = (Node *)malloc(sizeof(Node) * Capacity);
  (*Stack)->Capacity = Capacity;
  (*Stack)->Top = -1;
}

// 스택 및 노드 소멸
void AS_DestroyStack(ArrayStack *Stack) {
  free(Stack->Nodes);
  free(Stack);
}

// 노드 삽입
void AS_Push(ArrayStack *Stack, ElementType Data) {
  Stack->Top++;
  Stack->Nodes[Stack->Top].Data = Data;
}

// 노드 삽입 개선 - 용량 모두 소진 시 현재 용량의 30%만큼 늘리기
void AS_Push_Improved(ArrayStack *Stack, ElementType Data) {

  if (AS_IsFull(Stack)) {
    Stack->Capacity = Stack->Capacity * 1.3;
    Stack->Nodes =
        (Node *)realloc(Stack->Nodes, sizeof(Node) * (Stack->Capacity));
  }
  Stack->Top++;
  Stack->Nodes[Stack->Top].Data = Data;
}

// 노드 제거
ElementType AS_Pop(ArrayStack *Stack) {

  int Position = Stack->Top--;

  return Stack->Nodes[Position].Data;
}

// 노드 제거 - 용량이 70% 미만으로 내려갈 시 현재 용량의 30%만큼 줄이기
ElementType AS_Pop_Improved(ArrayStack *Stack) {

  int Position = Stack->Top--;

  if((float)(Stack->Top+1)/Stack->Capacity < 0.7){
	Stack->Capacity = Stack->Capacity * 0.7;
	Stack->Nodes = (Node*)realloc(Stack->Nodes, sizeof(Node*) * (Stack->Capacity));
  }

  return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack *Stack) { return Stack->Nodes[Stack->Top].Data; }

int AS_GetSize(ArrayStack *Stack) { return Stack->Top + 1; }

int AS_IsEmpty(ArrayStack *Stack) { return (Stack->Top == -1); }

int AS_IsFull(ArrayStack *Stack) { return (Stack->Top + 1 == Stack->Capacity); }
