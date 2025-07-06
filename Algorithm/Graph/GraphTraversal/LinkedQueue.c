#include "LinkedQueue.h"

void LQ_CreateQueue(LinkedQueue **Queue) {
  (*Queue) = (LinkedQueue *)malloc(sizeof(LinkedQueue));

  (*Queue)->front = NULL;
  (*Queue)->rear = NULL;
  (*Queue)->count = 0;
}

void LQ_DestroyQueue(LinkedQueue *Queue) {
  while (!LQ_IsEmpty(Queue)) {
    Node *front = LQ_Dequeue(Queue);
    LQ_DestroyNode(front);
  }

  free(Queue);
}

Node *LQ_CreateNode(Vertex* vertex) {
  Node *newNode = (Node *)malloc(sizeof(Node));

  newNode->vertex = (Vertex *)malloc(sizeof(Vertex));
  newNode->vertex = vertex;

  newNode->nextNode = NULL;

  return newNode;
}

void LQ_DestroyNode(Node *node) {
  free(node->vertex);
  free(node);
}

void LQ_Enqueue(LinkedQueue *queue, Node *newNode) {

  if (LQ_IsEmpty(queue)) { // LQ_IsEmpty VS queue->front == NULL
    queue->rear = newNode;
    queue->front = newNode;
    queue->count++;
  } else {
    queue->rear->nextNode = newNode;
    queue->rear = newNode;
    queue->count++;
  }
}

// front 노드 메모리 해제, count 1 감소
// 새로운 front 지정: front의 nextNode로 지정
// rear의 다음 노드가 NULL이라면? 링크드 큐는 비어있지 않은 이상 항상 Full인
// 상태이므로 Empty 체크만 한 후 다음 노드 지정하기
Node *LQ_Dequeue(LinkedQueue *queue) {

  Node *front = queue->front;

  if (queue->front->nextNode == NULL) {
    queue->front = NULL;
    queue->rear = NULL;
  } else {
    queue->front = queue->front->nextNode;
  }

  queue->count--;

  return front;
}

int LQ_IsEmpty(LinkedQueue *Queue) { return Queue->front == NULL; }