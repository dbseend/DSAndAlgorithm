#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

typedef struct tagNode {
  Vertex* vertex;
  struct tagNode *nextNode;
} Node;

typedef struct tagLinkedQueue {
  Node *front;
  Node *rear;
  int count;
} LinkedQueue;

void LQ_CreateQueue(LinkedQueue **Queue);
void LQ_DestroyQueue(LinkedQueue *Queue);

Node *LQ_CreateNode(Vertex* vertex);
void LQ_DestroyNode(Node *node);

void LQ_Enqueue(LinkedQueue *queue, Node *newNode);
Node* LQ_Dequeue(LinkedQueue *queue);

int LQ_IsEmpty(LinkedQueue *Queue);

#endif