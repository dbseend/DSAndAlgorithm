#include "Heap.h"

Heap* HEAP_Create( int InitialSize ){
    Heap* NewHeap = (Heap*)malloc(sizeof(Heap));

    NewHeap->Capacity = InitialSize;
    NewHeap->UsedSize = 0;
    NewHeap->Nodes = (HeapNode*)malloc(sizeof(HeapNode)*NewHeap->Capacity);

    return NewHeap;
}

void HEAP_Destroy( Heap* H ){

}

/*
1. 힙의 최고 깊이 가장 우측에 노드 삽입(배열의 마지막 인덱스) -> 이진트리 유지 위함
2. 삽입한 노드와 부모 노드 비교
2-1. 삽입한 노드 > 부모 노드: 힙의 조건 충족 => 종료
2-2. 삽입한 노드 < 부모 노드: 삽입한 노드와 부모 노드 교환 => 2-1의 종료 조건을 만족할 때 까지 반복
*/
void HEAP_Insert(  Heap* H, ElementType NewData ){
    int CurrIdx = H->UsedSize;

    if(H->Capacity == CurrIdx){
        H->Capacity *= 2;
        H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
    }

    H->Nodes[CurrIdx].Data = NewData;

    int ParentIdx = HEAP_GetParent(CurrIdx);

    while(CurrIdx > 0 && H->Nodes[CurrIdx].Data < H->Nodes[ParentIdx].Data){
        HEAP_SwapNodes(H, CurrIdx, ParentIdx);

        CurrIdx = ParentIdx;
        ParentIdx = HEAP_GetParent(CurrIdx);
    }

    H->UsedSize++;
}

/*
1. 힙의 최고 깊이 가장 우측에 있는 노드를 뿌리 노드로 이동
2. 옮겨온 노드와 양쪽 자식 노드를 비교
2-1. 작은 쪽 자식과 위치 교환
2-2. 옮겨온 노드가 리프 노드가 되거나 양쪽 자식보다 작은 값을 갖는 경우 종료
*/
void HEAP_DeleteMin( Heap* H, HeapNode* Root ){

    HEAP_SwapNodes(H, 0, H->UsedSize-1);
    H->UsedSize--;

    int parentIdx = 0;
    int leftChildIdx = HEAP_GetLeftChild(0);
    int rightChildIdx = leftChildIdx + 1;

    while (leftChildIdx < H->UsedSize) {
        int parentData = H->Nodes[parentIdx].Data;
        int leftChildData = H->Nodes[leftChildIdx].Data;
        int rightChildData = (rightChildIdx < H->UsedSize) ? H->Nodes[rightChildIdx].Data : INT_MAX; // 오른쪽 자식 없으면 최대값으로 설정

        // 힙 속성 만족하면 종료
        if (parentData <= leftChildData && parentData <= rightChildData) {
            break;
        }

        // 더 작은 자식과 교환
        int swapChildIdx = (leftChildData < rightChildData) ? leftChildIdx : rightChildIdx;
        HEAP_SwapNodes(H, parentIdx, swapChildIdx);
        parentIdx = swapChildIdx;
        leftChildIdx = HEAP_GetLeftChild(parentIdx);
        rightChildIdx = leftChildIdx+1;
    }    
}

int HEAP_GetParent( int Index ){
    return (Index-1)/2;
}

int HEAP_GetLeftChild( int Index ){
    return 2*Index + 1;
}

void HEAP_SwapNodes( Heap* H, int Index1, int Index2 ){
    int Temp = H->Nodes[Index1].Data;
    H->Nodes[Index1].Data = H->Nodes[Index2].Data;
    H->Nodes[Index2].Data = Temp;
}

void HEAP_PrintNodes(Heap* H ){
    int i = 0;
    for(i = 0; i< H->UsedSize; i++){
        printf("%d ", H->Nodes[i].Data);
    }
    printf("\n");
}