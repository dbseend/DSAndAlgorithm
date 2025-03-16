#include <stdio.h>

void Swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int dataSet[], int left, int right){
    int first = left;
    int pivot = dataSet[first];

    while(left <= right){
        while(pivot >= dataSet[left] && left < right) left++;
        while(pivot <= dataSet[right] && left <= right) right--;

        if(left < right) Swap(&dataSet[left], &dataSet[right]);
        else break;
    }

    Swap(&dataSet[first], &dataSet[right]);

    return right;
}

void QuickSort(int dataSet[], int left, int right){
    if(left < right){
        int pivot = Partition(dataSet, left, right);

        QuickSort(dataSet, left, pivot-1);
        QuickSort(dataSet, pivot+1, right);
    }
}

int main (){
    int dataSet[] = {6,4,2,3,1,5};
    int length = sizeof dataSet / sizeof dataSet[0];
    int i=0;

    QuickSort(dataSet,0,length-1);

    for(i=0; i<length; i++){
        printf("%d ", dataSet[i]);
    }

    printf("\n");

    return 0;
}