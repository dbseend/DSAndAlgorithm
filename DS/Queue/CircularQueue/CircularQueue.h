#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
  ElementType data;
} Node;

typedef struct tagCircularQueue {
  int capacity;
  int front;
  int rear;

  Node *nodes;
} CircularQueue;

void CQ_CreateQueue(CircularQueue **Queue, int capacity);
void CQ_DestroyQueue(CircularQueue *Queue);
void CQ_Enqueue(CircularQueue *Queue, ElementType data);
ElementType CQ_Dequeue(CircularQueue *Queue);
int CQ_GetSize(CircularQueue *Queue);
int CQ_IsFull(CircularQueue *Queue);
int CQ_IsFull_Ans(CircularQueue *Queue);
int CQ_IsEmpty(CircularQueue *Queue);

#endif
