#include "Graph.h"

Graph* createGraph(){
    
    Graph* newGraph = (Graph*)malloc(sizeof(Graph));

    newGraph->vertices = NULL;
    newGraph->vertexCount = 0;

    return newGraph;
}

void destroyGraph( Graph* g ){

    // 제거할 Graph와 연결된 Vertex 제거하기
    while(g->vertices != NULL){
        Vertex* vertices = g->vertices->next;
        destroyVertex(g->vertices);
        g->vertices = vertices;
    }

    // Graph 제거
    free(g);
}


Vertex* createVertex( VElemntType data ){

    Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));

    newVertex->data = data;
    newVertex->visited = NotVisited;
    newVertex->index = -1; // 정점 생성 시에는 그래프에 추가 되지 않았기 때문에 -1로 선언

    newVertex->next = NULL;
    newVertex->adjacencyList = NULL;

    return newVertex;
}

void destroyVertex( Vertex* v ){

    // 제거할 Vertex와 연결된 Edge 제거하기
    while(v->adjacencyList != NULL){
        Edge* edge = v->adjacencyList->next;
        printf("DestoryVertex: %d, %d", edge->from->data, edge->target->data);
        destoryEdge(v->adjacencyList);
        v->adjacencyList = edge; 
    }

    // Vertex 제거
    free(v);
}


Edge* createEdge( Vertex* from, Vertex* target, int weight ){

    Edge* newEdge = (Edge*)malloc(sizeof(Edge));

    newEdge->weight = weight;
    newEdge->from = from;
    newEdge->target = target;
    newEdge->next = NULL;

    return newEdge;
}

void destoryEdge( Edge* e ){
    free(e);
}


void addVertex( Graph* g, Vertex* v ){

    Vertex* vertexList = g->vertices;
    if(vertexList == NULL){
        g->vertices = v;
    } else {
        while(vertexList->next != NULL){
            vertexList = vertexList->next;
        }
        vertexList->next = v;     
    }

    v->index = g->vertexCount++;
}

void addEdge( Vertex* v, Edge* e ){

    Edge* edgeList = v->adjacencyList;

    if(edgeList == NULL){
        v->adjacencyList = e;
    } else {
        while(edgeList->next != NULL){
            edgeList = edgeList->next;
        }
        edgeList->next = e;
    }
}

void printGraph( Graph* g ){

    Vertex* vertexList = g->vertices; 
    printf("Vertex Index: %d\n", vertexList->index);

    if(vertexList == NULL) return;

    Edge* edgeList = vertexList->adjacencyList;
    while(vertexList != NULL){

        printf("[%d] ", vertexList->data);
        edgeList = vertexList->adjacencyList;        
        while(edgeList != NULL){
            printf("%d ", edgeList->target->data);
            edgeList = edgeList->next;
        }
        vertexList = vertexList->next;

        printf("\n");
    }

    printf("\n");
}