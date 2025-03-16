#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ComparePoint(const void*_elem1, const void *_elem2){
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if(*elem1 > *elem2) return 1;
    else if(*elem1 < *elem2) return -1;
    else return 0;
}

int ComparePointDescend(const void*_elem1, const void *_elem2){
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if(*elem1 > *elem2) return -1;
    else if(*elem1 < *elem2) return 1;
    else return 0;
}

int main (){
    int dataSetAscend[] = {6,4,2,3,1,5};
    int dataSetDescend[] = {6,4,2,3,1,5};
    int length = sizeof dataSetAscend / sizeof dataSetAscend[0];
    int i=0;

    qsort((void*)dataSetAscend, length, sizeof(int), ComparePoint);
    qsort((void*)dataSetDescend, length, sizeof(int), ComparePointDescend);

    for(i=0; i<length; i++){
        printf("%d ", dataSetAscend[i]);
    }
    printf("\n");
        for(i=0; i<length; i++){
        printf("%d ", dataSetDescend[i]);
    }
    printf("\n");

    return 0;
}