#include "Graph.h"

Graph* createGraph(){
    
    Graph* newGraph = (Graph*)malloc(sizeof(Graph));

    newGraph->vertices = NULL;
    newGraph->vertexCount = 0;

    return newGraph;
}

void destroyGraph( Graph* g ){

    while(g->vertices != NULL){
        Vertex* vertices = g->vertices->next;
        destroyVertex(g->vertices);
        g->vertices = vertices;
    }

    free(g);
}


Vertex* createVertex( VElemntType data ){

    Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));

    newVertex->data = data;
    newVertex->visited = NotVisited;
    newVertex->index = -1;

    newVertex->next = NULL;
    newVertex->adjacencyList = NULL;

    return newVertex;
}

void destroyVertex( Vertex* v ){

    while(v->adjacencyList != NULL){
        Edge* edge = v->adjacencyList->next;
        destoryEdge(v->adjacencyList);
        v->adjacencyList = edge; 
    }

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
        vertexList = v;
    } else {
        while(vertexList != NULL){
            vertexList = vertexList->next;
        }
        vertexList = v;    
    }

    v->index = ++g->vertexCount;
}

void addEdge( Vertex* v, Edge* e ){

    Edge* edgeList = v->adjacencyList;

    if(edgeList == NULL){
        edgeList = e;
    } else {
        while(edgeList != NULL){
            edgeList = edgeList->next;
        }
        edgeList = e;
    }
}

void printGraph( Graph* g ){
    Vertex* vertexList = g->vertices; 
    Edge* edgeList = vertexList->adjacencyList;

    if(vertexList) return;

    while(vertexList != NULL){
        printf("%c : ", vertexList->data);

        if(edgeList == NULL){
            vertexList = vertexList->next;
            printf("\n");
            continue;
        }

        while(edgeList != NULL){
            printf("%c[%d] ", edgeList->target->data, edgeList->weight);
            edgeList = edgeList->next;
        }

        printf("\n");

        vertexList = vertexList->next;
    }

    printf("\n");
}