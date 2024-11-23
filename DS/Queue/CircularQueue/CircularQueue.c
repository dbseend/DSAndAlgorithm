#include "CircularQueue.h"

void CQ_CreateQueue(CircularQueue **Queue, int capacity) {
  (*Queue) = (CircularQueue *)malloc(sizeof(CircularQueue));

  (*Queue)->nodes = (Node *)malloc(sizeof(Node) * (capacity + 1));
  (*Queue)->capacity = capacity;
  (*Queue)->front = 0;
  (*Queue)->rear = 0;
}

void CQ_DestroyQueue(CircularQueue *Queue) {
  free(Queue);
  free(Queue->nodes);
}

void CQ_Enqueue(CircularQueue *Queue, ElementType data) {
  int position = Queue->rear;

  if (Queue->rear == Queue->capacity) {
    Queue->rear = 0;
  } else {
    position = Queue->rear++;
  }

  Queue->nodes[position].data = data;
}

ElementType CQ_Dequeue(CircularQueue *Queue) {
  int position = Queue->front;

  if (Queue->front == Queue->capacity) {
    Queue->front = 0;
  } else {
    Queue->front++;
  }

  return Queue->nodes[position].data;
}

int CQ_GetSize(CircularQueue *Queue) {
  if (Queue->rear >= Queue->front) {
    return Queue->rear - Queue->front;
  } else {
    return Queue->rear + (Queue->capacity - Queue->front) + 1;
  }
}

int CQ_IsFull(CircularQueue *Queue) {
  return (Queue->front == (Queue->rear + 1) % Queue->capacity);
}

int CQ_IsFull_Ans(CircularQueue *Queue) {
  if (Queue->front < Queue->rear) {
    return (Queue->rear - Queue->front) == Queue->capacity;
  } else {
    return (Queue->rear + 1) == Queue->front;
  }
}

int CQ_IsEmpty(CircularQueue *Queue) { return (Queue->front == Queue->rear); }