#include "Chaining.h"

HashTable* CHT_CreateHashTable( int TableSize )
{
    HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
    HT->TableSize = TableSize;
    HT->Table = (List*)malloc(sizeof(Node)*TableSize);

    memset(HT->Table, 0, sizeof(List) * TableSize);

    return HT;
}

Node* CHT_CreateNode( KeyType Key, ValueType Value )
{
    Node* NewNode = (Node*) malloc( sizeof(Node) );

    NewNode->Key = (char*)malloc( sizeof(char) * ( strlen(Key) + 1 ));
    strcpy( NewNode->Key,   Key );

    NewNode->Value = (char*)malloc( sizeof(char) * ( strlen(Value) + 1 ));
    strcpy( NewNode->Value, Value );
    NewNode->Next = NULL;

    return NewNode;
}

void CHT_DestroyNode( Node* TheNode )
{
    free(TheNode->Key);
    free(TheNode->Value);
    free(TheNode);
}

void CHT_Set( HashTable* HT, KeyType Key, ValueType Value )
{
    Node* newNode = CHT_CreateNode(Key, Value);
    int address = CHT_Hash(Key, strlen(Key), HT->TableSize);

    if(HT->Table[address] == NULL){
        HT->Table[address] = newNode;        
    } else {
        List l = HT->Table[address];
        newNode->Next = l;
        HT->Table[address] = newNode;

        printf("Collision occured: Key(%s), Address(%d)\n", Key, address);
    }
}

ValueType CHT_Get( HashTable* HT, KeyType Key )
{
    // 1. 주소 해싱
    int address = CHT_Hash(Key, strlen(Key), HT->TableSize);

    // 2. 해싱 한 주소에 해당하는 링크드 리스트 불러오기
    List theList = HT->Table[address];
    List target = NULL;

    if(theList == NULL){
        return NULL;
    }

    // 3. 반복문 돌면서 원하는 값 탐색
    while(1){

        if(strcmp(theList->Key, Key) == 0){
            target = theList;
            break;
        }

        if(theList->Next == NULL){
            break;
        } else{
            theList = theList->Next;
        }
    }

    return target->Value;
}

void CHT_DestroyList( List L )
{
    if(L == NULL) return;

    if(L->Next != NULL) CHT_DestroyList(L->Next);

    CHT_DestroyNode(L);
}

void CHT_DestroyHashTable( HashTable* HT)
{
    int i=0;
    for(i=0; i<HT->TableSize; i++){
        List L = HT->Table[i];
        CHT_DestroyList(L);
    }

    free(HT->Table);
    free(HT);
}

int CHT_Hash( KeyType Key, int KeyLength, int TableSize )
{
    int i = 0;
	int hashValue = 0;
	
	for(i=0; i<KeyLength; i++)
		hashValue = (hashValue << 3) + Key[i];
	
	return hashValue % TableSize;
}
                              
