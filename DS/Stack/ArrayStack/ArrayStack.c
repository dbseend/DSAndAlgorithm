#include "ArrayStack.h"

// 스택 및 노드 생성
void AS_CreateStack(ArrayStack** Stack, int Capacity){
	(*Stack) = (ArrayStack*)malloc(sizeof(Stack));
	
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}

// 스택 및 노드 소멸
void AS_DestroyStack(ArrayStack* Stack){
	free(Stack->Nodes);
	free(Stack);
}

// 노드 삽입
void AS_Push(ArrayStack* Stack, ElementType Data){
	Stack->Top++;
	Stack->Nodes[Stack->Top].Data = Data;
}

// 노드 제거
ElementType AS_Pop(ArrayStack* Stack){
	
	int Position = Stack->Top--;
	
	return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack){	
	return Stack->Nodes[Stack->Top].Data;
}

int AS_GetSize(ArrayStack *Stack){
	return Stack->Top+1;
}

int AS_IsEmpty(ArrayStack *Stack){
	return (Stack->Top == -1);
}

int AS_IsFull(ArrayStack* Stack){
	return (Stack->Top+1 == Stack->Capacity);
}

