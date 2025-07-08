#include "Graph.h"
#include "TopologicalSort.h"

int main( void )
{
    Node* SortedList  = NULL;
    Node* CurrentNode = NULL;

    //  그래프 생성     
    Graph* graph = createGraph();
    
    //  정점 생성 
    
    Vertex* A = createVertex( 'A' );
    Vertex* B = createVertex( 'B' );
    Vertex* C = createVertex( 'C' );
    Vertex* D = createVertex( 'D' );
    Vertex* E = createVertex( 'E' );
    Vertex* F = createVertex( 'F' );
    Vertex* G = createVertex( 'G' );
    Vertex* H = createVertex( 'H' );
    
    //  그래프에 정점을 추가 
    addVertex( graph, A );
    addVertex( graph, B );
    addVertex( graph, C );
    addVertex( graph, D );
    addVertex( graph, E );
    addVertex( graph, F );
    addVertex( graph, G );
    addVertex( graph, H );

    //  정점과 정점을 간선으로 잇기 
    addEdge( A, createEdge( A, C, 0 ) );
    addEdge( A, createEdge( A, D, 0 ) );

    addEdge( B, createEdge( B, C, 0 ) );
    addEdge( B, createEdge( B, E, 0 ) );

    addEdge( C, createEdge( C, F, 0 ) );
    
    addEdge( D, createEdge( D, F, 0 ) );
    addEdge( D, createEdge( D, G, 0 ) );

    addEdge( E, createEdge( E, G, 0 ) );

    addEdge( F, createEdge( F, H, 0 ) );
    
    addEdge( G, createEdge( G, H, 0 ) );

    //  위상 정렬 
    TopologicalSort( graph->vertices, &SortedList );

 
    printf("Topological Sort Result : ");

    CurrentNode = SortedList;

    while ( CurrentNode != NULL )
    {
        printf("%C ", CurrentNode->Data );
        CurrentNode = CurrentNode->NextNode;
    }
    printf("\n");
    

    //  그래프 소멸 
    destroyGraph( graph );

    return 0;
}
