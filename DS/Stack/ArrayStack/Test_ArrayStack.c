#include "ArrayStack.h"

int main(void) {
  int i = 0;
  ArrayStack *Stack = NULL;

  AS_CreateStack(&Stack, 10);

  AS_Push(Stack, 1);
  AS_Push(Stack, 11111);
  AS_Push(Stack, 37);
  AS_Push(Stack, 1123);
  AS_Push(Stack, 342);
  AS_Push(Stack, 122);
  AS_Push(Stack, 542);
  AS_Push(Stack, 642);
  AS_Push(Stack, 152);
  AS_Push(Stack, 1342);

  printf("Capacity: %d, Size: %d, Top: %d\n\n", Stack->Capacity,
         AS_GetSize(Stack), AS_Top(Stack));

  for (i = 0; i < 4; i++) {
    if (AS_IsEmpty(Stack))
      break;

    printf("Popped: %d, ", AS_Pop_Improved(Stack));

    if (!AS_IsEmpty(Stack))
      printf("Current Top: %d\n", AS_Top(Stack));
    else
      printf("Stack Is Empty.\n");
  }

  printf("Capacity: %d, Size: %d, Top: %d\n\n", Stack->Capacity,
         AS_GetSize(Stack), AS_Top(Stack));

  if (AS_IsFull(Stack)) {
    printf("Is Full\n");
  } else {
    printf("Is Not Full\n");
  }

  AS_DestroyStack(Stack);

  return 0;
}
