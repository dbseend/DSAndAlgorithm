#include "LinkedList.h"

int main() {

  int i = 0;
  int Count = 0;
  Node *List = NULL;
  Node *Current = NULL;
  Node *NewNode = NULL;

  for (i = 0; i < 5; i++) {
    NewNode = SLL_CreateNode(i);
    SLL_AppendNode(&List, NewNode);
  }

  Current = SLL_GetNodeAt(List, 0);
  NewNode = SLL_CreateNode(1201);
  SLL_InsertBefore(&List, Current, NewNode);

  // NewNode = SLL_CreateNode(-1);
  // SLL_InsertNewHead(&List, NewNode);

  // NewNode = SLL_CreateNode(-2);
  // SLL_InsertNewHead(&List, NewNode);

  Count = SLL_GetNodeCount(List);
  for (i = 0; i < Count; i++) {
    Current = SLL_GetNodeAt(List, i);
    printf("List[%d] : %d\n", i, Current->Data);
  }

  printf("\nInserting 3000 After [2]...\n\n");

  Current = SLL_GetNodeAt(List, 2);
  NewNode = SLL_CreateNode(3000);

  SLL_InsertAfter(Current, NewNode);

  Count = SLL_GetNodeCount(List);
  for (i = 0; i < Count; i++) {
    Current = SLL_GetNodeAt(List, i);
    printf("List[%d] : %d\n", i, Current->Data);
  }

  printf("\nDestorying List...\n");
  SLL_DestroyAllNodes(&List);

  Count = SLL_GetNodeCount(List);
  printf("Count: %d\n", Count);
    for (i = 0; i < Count; i++) {
    Current = SLL_GetNodeAt(List, i);
    printf("List[%d] : %d\n", i, Current->Data);
  }

  //   for (i = 0; i < Count; i++) {
  //     Current = SLL_GetNodeAt(List, 0);

  //     if (Current != NULL) {
  //       SLL_RemoveNode(&List, Current);
  //       SLL_DestroyNode(Current);
  //     }
  //   }

  return 0;
}