#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

enum VisitMode { Visited = 1, NotVisited = 0 };

typedef int VElemntType;

typedef struct tagVertex {
    VElemntType data;
    int visited; 
    int index;

    struct tagVertex* next;
    struct tagEdge* adjacencyList;
} Vertex;

typedef struct tagEdge {
    int weight;
    struct tagEdge* next;
    Vertex* from;
    Vertex* target;
} Edge;

typedef struct tagGraph {
    Vertex* vertices;
    int vertexCount;
} Graph;

Graph* createGraph();
void destroyGraph( Graph* g );

Vertex* createVertex( VElemntType data );
void destroyVertex( Vertex* v );

Edge* createEdge( Vertex* from, Vertex* target, int weight );
void destoryEdge( Edge* e );

void addVertex( Graph* g, Vertex* v );
void addEdge( Vertex* v, Edge* e );
void printGraph( Graph* g );

#endif
