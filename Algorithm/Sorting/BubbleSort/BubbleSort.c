#include <stdio.h>
#include <stdbool.h>

void BubbleSort(int dataSet[], int length){
    bool isSorted = true;

    for(int i=0; i<length-1; i++){
        for(int j=0; j<length-(i+1); j++){
            if(dataSet[j] > dataSet[j+1]){
                isSorted = false;
                
                int temp = dataSet[j];
                dataSet[j] = dataSet[j+1];
                dataSet[j+1] = temp; 
            }
        }

        if(isSorted) break; // n번째 비교 후 정렬이 완료된 경우, 더이상 진행하지 않고 함수 종료
    }

    printf("Count: %d\n", count);
}

int main (){
    // int dataSet[] = {1,2,3,4,5,6};
    int dataSet[] = {6,4,2,3,1,5};
    int length = sizeof dataSet / sizeof dataSet[0];

    BubbleSort(dataSet, length);

    for(int i=0; i< length; i++){
        printf("%d ", dataSet[i]);
    }

    printf("\n");

    return 0;
}