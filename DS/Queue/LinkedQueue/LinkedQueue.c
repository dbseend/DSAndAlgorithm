#include "LinkedQueue.h"

void LQ_CreateQueue(LinkedQueue **Queue) {
  (*Queue) = (LinkedQueue *)malloc(sizeof(LinkedQueue));

  (*Queue)->front = NULL;
  (*Queue)->rear = NULL;
  (*Queue)->count = 0;
}

void LQ_DestroyQueue(LinkedQueue *Queue) {
  while (!LQ_IsEmpty(Queue)) {
    Node *Dequeued = LQ_Dequeue(Queue);
    LQ_DestroyNode(Dequeued);
  }

  free(Queue);
}

Node *LQ_CreateNode(char *data) {
  Node *newNode = (Node *)malloc(sizeof(Node));

  newNode->data = (char *)malloc(sizeof(strlen(data)) + 1);
  strcpy(newNode->data, data);

  newNode->nextNode = NULL;

  return newNode;
}

void LQ_DestroyNode(Node *node) {
  free(node->data);
  free(node);
}

void LQ_Enqueue(LinkedQueue *queue, Node *newNode) {

  if (LQ_IsEmpty(queue)) { // LQ_IsEmpty VS queue->front == NULL
    queue->rear = newNode;
    queue->front = newNode;
    queue->count++;
  } else {
    queue->rear = newNode;
    queue->rear->nextNode = queue->front;
    queue->count++;
  }
}

Node *LQ_Dequeue(LinkedQueue *queue) {

  Node *dequeued = queue->front;
  // front 노드 메모리 해제, count 1 감소
  // 새로운 front 지정: front의 nextNode로 지정
  // rear의 다음 노드가 NULL이라면? 링크드 큐는 비어있지 않은 이상 항상 Full인
  // 상태이므로 Empty 체크만 한 후 다음 노드 지정하기
  free(queue->front);
  queue->count--;

  if (!LQ_IsEmpty(queue)) {
    queue->front = queue->front->nextNode;
  }

  return dequeued;
}

int LQ_IsEmpty(LinkedQueue *Queue) { 
    return Queue->count == 0; 
    // return Queue->front == NULL;
}