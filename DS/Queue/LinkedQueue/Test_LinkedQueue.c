#include "LinkedQueue.h"
#include <stdio.h>

int main(void) {
  Node *front;
  LinkedQueue *Queue;

  LQ_CreateQueue(&Queue);

  LQ_Enqueue(Queue, LQ_CreateNode("abc"));
  LQ_Enqueue(Queue, LQ_CreateNode("def"));
  LQ_Enqueue(Queue, LQ_CreateNode("efg"));
  LQ_Enqueue(Queue, LQ_CreateNode("hij"));

  printf("Queue Size : %d\n", Queue->count);

  while (!LQ_IsEmpty(Queue)) {

    front = LQ_Dequeue(Queue);

    printf("Dequeue: %s \n", front->data);

    LQ_DestroyNode(front);
  }

  LQ_DestroyQueue(Queue);

  return 0;
}
