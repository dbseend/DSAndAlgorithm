#include "GraphTraversal.h"

/*
*DFS(깊이 우선 탐색)*
1. 시작 정점을 밟은 후 이 정점을 '방문했음'으로 표시
2. 그리고 이 정점과 이웃 정점(인접 정점) 중에 아직 방문하지 않은 곳을 선택하여 
이를 시작 정점으로 삼고 다시 DFS 시작. => 1단계 재수행
3. 더 이상 방문하지 않은 이웃 정점이 없으면 이전 정점으로 돌아가 2단계 수행
4. 이전 정점으로 돌아가도 더 이상 방문할 이웃 정점이 없다면 그래프의 모든 정점을 방문했다는 뜻이므로
탐색을 종료
*/
void DFS( Vertex* v ) {

    Edge* e = NULL;

    printf("%d ", v->data);

    v->visited = Visited;

    e = v->adjacencyList;

    while(e != NULL){
        if(e->target != NULL && e->target->visited == NotVisited){
            DFS(e->target);
        }

        e = e->next;
    }
}

/*
BFS(너비 우선 탐색)
1. 시작 정점을 '방문했음'으로 표시하고 큐에 삽입
2-1. 큐로부터 정점을 제거.
2-2. 제거한 정점의 인접 정점 중에서 아직 방문하지 않은 곳을 '방문했음'으로 표시하고 큐에 삽입
3. 큐가 비면 탐색이 종료. -> 큐가 빌 때까지 단게 2의 과정 반복
*/
void BFS( Vertex* v, LinkedQueue* queue ){

    Edge* e = NULL;
    v->visited = Visited;
    printf("%d ", v->data);
    LQ_Enqueue(queue, LQ_CreateNode(v));

    while(!LQ_IsEmpty(queue)){
        Node* popped = LQ_Dequeue(queue);
        v = popped->vertex;
        e = v->adjacencyList;

        while(e != NULL){
            v = e->target;

            if(v != NULL && v->visited == NotVisited){
                printf("%d ", v->data);
                v->visited = Visited;
                LQ_Enqueue(queue, LQ_CreateNode(v));
            }

            e = e->next;
        }
    }
}