#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode {
  char *data;
  struct tagNode *nextNode;
} Node;

typedef struct tagLinkedQueue {
  Node *front;
  Node *rear;
  int count;
} LinkedQueue;

void LQ_CreateQueue(LinkedQueue **Queue);
void LQ_DestroyQueue(LinkedQueue *Queue);

Node *LQ_CreateNode(char *data);
void LQ_DestroyNode(Node *node);

void LQ_Enqueue(LinkedQueue *queue, Node *newNode);
Node* LQ_Dequeue(LinkedQueue *queue);

int LQ_IsEmpty(LinkedQueue *Queue);

#endif