#include "LinkedList.h"

Node* SLL_CreateNode(ElementType NewData){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Data = NewData;
    newNode->NextNode = NULL;

    return newNode;
}

void  SLL_DestroyNode(Node* Node){
    free(Node);
}

void  SLL_AppendNode(Node** Head, Node* NewNode){

    if(*Head == NULL){
        *Head = NewNode;
    } else{
        Node* Current = (*Head);
        while(Current->NextNode != NULL){
            Current = Current->NextNode; 
        }

        Current->NextNode = NewNode;
    }

}

void  SLL_InsertAfter(Node* Current, Node* NewNode){
    if(Current->NextNode == NULL){
        Current->NextNode = NewNode;
    } else{
        NewNode->NextNode = Current->NextNode;
        Current->NextNode = NewNode;
    }
}

void  SLL_InsertNewHead(Node** Head, Node* NewHead){
    if((*Head) == NULL){
        *Head = NewHead;
    } else {
        NewHead->NextNode = *Head;
        *Head = NewHead;
    }
}

void  SLL_RemoveNode(Node** Head, Node* Remove){
    if((*Head) == Remove){
        *Head = Remove->NextNode;
    } else {
        Node* Current = (*Head);
        while(Current != NULL && Current->NextNode != Remove){
            Current = Current->NextNode;
        }

        if(Current != NULL){
            Current->NextNode = Remove->NextNode;
        }
    }
}

Node* SLL_GetNodeAt(Node* Head, int Location){
    Node* Current = Head;

    while(Current != NULL && Location > 0){
        Current = Current->NextNode;
        Location--;
    }

    return Current;
}

int SLL_GetNodeCount(Node* Head){
    int count = 0;
    Node* Current = Head;

    while(Current != NULL){
        Current = Current->NextNode;
        count++;
    }

    return count;
}

void SLL_PrintAllNode(Node* Head){
    Node* Current = Head;

    printf("\n");
    while(Current != NULL){
        printf("%d ", Current->Data);
        Current = Current->NextNode;
    }
    printf("\n");
}

