#include "DoublyLinkedList.h"

int main() {
  int i = 0;
  int Count = 0;
  Node *List = NULL;
  Node *NewNode = NULL;
  Node *Current = NULL;

  // 노드 5개 추가
  for (i = 0; i < 5; i++) {
    NewNode = DLL_CreateNode(i);
    DLL_AppendNode(&List, NewNode);
  }

  // 리스트 출력
  Count = DLL_GetNodeCount(List);
  printf("Count : %d\n", Count);
  for (i = 0; i < Count; i++) {
    Current = DLL_GetNodeAt(List, i);
    printf("List[%d]: %d\n", i, Current->data);
  }

  // 모든 노드를 메모리에서 제거
  printf("\nDestorying List..\n");

  Count = DLL_GetNodeCount(List);
  for (i = 0; i < Count; i++) {
    Current = DLL_GetNodeAt(List, 0);

    if (Current != NULL) {
      // DLL_RemoveNodeAns(&List, Current);
      DLL_RemoveNode(&List, Current);
      DLL_DestroyNode(Current);
    }
  }

  Count = DLL_GetNodeCount(List);
  printf("Count: %d\n", Count);
  PrintNode(List);

  return 0;
}