#include "TopologicalSort.h"

/*
*Topological Sort(위상정렬)*
진입 간선(Incomming Edge), 진출 간선(Outgoing Edge)
1. 리스트를 하나 준비
2. 그래프에서 진입 간선이 없는 정점을 리스트에 추가하고 해당 정점 자신과 진출 간선을 제거
- 정점의 진입 간선이 없다는 것을 어떻게 알지?
-- 특정 정점에 대해 Edge의 target이 아무것도 없는 경우
-- 특정 정점을 기준으로 나머지 모든 정점을 순회 하면서 target이 정점을 향하는지 여부 판단
3. 모든 정점에 대해 2단계를 반복하고 그래프 내에 정점이 남아 있지 않다면 정렬 종료
=> 리스트에는 위상 정렬된 그래프가 저장
*/
void TopologicalSort( Vertex* v, Node** list ){

    while(v != NULL && v->visited == NotVisited){
        TS_DFS(v, list);

        v = v->next;
    }
}

/*
DFS를 이용한 위상 정렬
1. 리스트 준비
2. 그래프에서 진입 간선이 없는 정점에 대해 깊이 우선 탐색 시행, 
탐색 중 더 이상 옮겨갈 수 있는 인접 정점이 없는 정점을 만나면 이 정점을 리스트의 새로운 '헤드'로 입력
3. 2단계를 반복하다가 더 이상 방문할 정점이 없으면 DFS 종료
=> 리스트에는 위상 정렬된 그래프가 저장
*/
void TS_DFS( Vertex* v, Node** list){
    
    Node* newHead = NULL;
    Edge* e = NULL;

    v->visited = Visited;
    e = v->adjacencyList;

    while(e != NULL){
        if(e->target != NULL && e->target->visited == NotVisited){
            TS_DFS(e->target, list);
        }

        e = e->next;
    }

    printf("%c\n", v->data);

    newHead = SLL_CreateNode(v);
    SLL_InsertNewHead(list, newHead);
}
