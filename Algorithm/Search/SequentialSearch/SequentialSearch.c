#include "LinkedList.h"

Node* SLL_SequentialSearch(Node* Head, int Target)
{
    Node* Match = NULL;
    Node* Current = Head;

    while(Current != NULL && Current->Data != Target){
        Current = Current->NextNode;
    }

    if(Current != NULL){
        Match = Current;
    }

    return Match;
}

Node* SLL_MoveToFront(Node** Head, int Target)
{
    Node* Origin = *Head;
    Node* Match = NULL;
    Node* Current = *Head;
    Node* Prev = NULL;

    while(Current != NULL ){
        if(Current->Data== Target){

            if(Prev != NULL){
                Match = Current;
                Node* Next= Current->NextNode;

                *Head = Current;
                (*Head)->NextNode = Origin;
                Prev->NextNode = Next;

            }
            break;
        } else{
            Prev = Current;
            Current = Current->NextNode;
        }
    }

    return Match;
}

Node* SLL_Transpose(Node** Head, int Target)
{
    Node* Match = NULL;
    Node* Current = *Head;
    Node* Prev = NULL;

    if(Current->Data == Target) return *Head;

    while(Current->NextNode != NULL){
        if(Current->NextNode->Data == Target){
            Match = Current->NextNode;

            Current->NextNode = Match->NextNode;
            Match->NextNode = Current;
            
            if(Prev == NULL){
                *Head = Match;
            } else{
                Prev->NextNode = Match;
            }

            break;
        } else{
            Prev = Current;
            Current = Current->NextNode;
        }
    }

    return Match;
}

Node* SLL_FrequencyCount(Node** Head, int target){
    return NULL;
}


int main( void )
{
    int   i       = 0;
    int   Count   = 10;
    Node* List    = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;
    Node* Match   = NULL;

    int   InitValue[10] = {1, 2, 6, 10, 4, 9, 5, 3, 8, 7};

    //  리스트 초기화
    for ( i = 0; i<Count; i++ )
    {
        NewNode = SLL_CreateNode(InitValue[i]);
        SLL_AppendNode(&List, NewNode);
    }

    // 순차 탐색
    printf("Simple Sequential Search...\n");
    
    Match =  SLL_SequentialSearch(List, 9);
    if (Match != NULL)
        printf("Found : %d\n", Match->Data);
    else
        printf("Not Found : %d\n", Match->Data);

    // 전진 이동법
    printf("Move To Front...\n");

    Match =  SLL_MoveToFront(&List, 4);
    if (Match != NULL)
        printf("Found : %d\n", Match->Data);
    else
        printf("Not Found : %d\n", Match->Data);
    SLL_PrintAllNode(List);

    // 전위법
    printf("Transpose...\n");

    Match =  SLL_Transpose(&List, 7);
    if (Match != NULL)
        printf("Found : %d\n", Match->Data);
    else
        printf("Not Found : %d\n", Match->Data);
    SLL_PrintAllNode(List);

    //  모든 노드를 메모리에서 제거     
    printf("Destroying List...\n");

    for ( i = 0; i<Count; i++ )
    {
        Current = SLL_GetNodeAt(List, 0);

        if ( Current != NULL ) 
        {
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
    }

    return 0;
}
