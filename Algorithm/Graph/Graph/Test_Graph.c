#include "Graph.h"

int main( void )
{
    //  그래프 생성     
    Graph* G = createGraph();
    
    //  정점 생성 
    Vertex* V1 = createGraph( '1' );
    Vertex* V2 = createGraph( '2' );
    Vertex* V3 = createGraph( '3' );
    Vertex* V4 = createGraph( '4' );
    Vertex* V5 = createGraph( '5' );

    //  그래프에 정점을 추가 
    addVertex( G, V1 );
    addVertex( G, V2 );
    addVertex( G, V3 );
    addVertex( G, V4 );
    addVertex( G, V5 );

    //  정점과 정점을 간선으로 잇기 
    addEdge( V1, createEdge(V1, V2, 0) );
    addEdge( V1, createEdge(V1, V3, 0) );
    addEdge( V1, createEdge(V1, V4, 0) );
    addEdge( V1, createEdge(V1, V5, 0) );

    addEdge( V2, createEdge(V2, V1, 0) );
    addEdge( V2, createEdge(V2, V3, 0) );
    addEdge( V2, createEdge(V2, V5, 0) );

    addEdge( V3, createEdge(V3, V1, 0) );
    addEdge( V3, createEdge(V3, V2, 0) );

    addEdge( V4, createEdge(V4, V1, 0) );
    addEdge( V4, createEdge(V4, V5, 0) );

    addEdge( V5, createEdge(V5, V1, 0) );
    addEdge( V5, createEdge(V5, V2, 0) );
    addEdge( V5, createEdge(V5, V4, 0) );

    printGraph( G );

    //  그래프 소멸 
    destroyGraph( G );

    return 0;
}
