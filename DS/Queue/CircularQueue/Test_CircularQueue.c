#include "CircularQueue.h"

int main(void) {
  int i;
  CircularQueue *Queue;

  CQ_CreateQueue(&Queue, 10);

  CQ_Enqueue(Queue, 1);
  CQ_Enqueue(Queue, 2);
  CQ_Enqueue(Queue, 3);
  CQ_Enqueue(Queue, 4);

  for (i = 0; i < 3; i++) {
    printf("Dequeue: %d, ", CQ_Dequeue(Queue));
    printf("Front:%d, Rear:%d\n", Queue->front, Queue->rear);
  }

  i = 100;
  int isFull = CQ_IsFull_Ans(Queue);
  printf("Is Full? : %d\n", isFull);
  while (CQ_IsFull(Queue) == 0) {
    CQ_Enqueue(Queue, i++);
  }

  printf("Capacity: %d, Size: %d\n\n", Queue->capacity, CQ_GetSize(Queue));

  while (CQ_IsEmpty(Queue) == 0) {
    printf("Dequeue: %d, ", CQ_Dequeue(Queue));
    printf("Front:%d, Rear:%d\n", Queue->front, Queue->rear);
  }

  CQ_DestroyQueue(Queue);

  return 0;
}
