#include <stdio.h>
#include <string.h>

// memmove 함수 사용 O
// void InsertionSort(int dataSet[], int length){
//     int i, j, key;

//     for(i=1; i<length; i++){
//         if(dataSet[i] >= dataSet[i-1]) continue;
        
//         key = dataSet[i];

//         for(j=0; j<i; j++){
//             if(key < dataSet[j]){
//                 memmove(&dataSet[j+1], &dataSet[j], sizeof(dataSet[0])*(i-j));
//                 dataSet[j] = key;
//                 break;
//             }
//         }
//     }
// }

// memmove 함수 사용 X
void InsertionSort(int dataSet[], int length) {
    int i, j, key;

    for (i = 1; i < length; i++) {
        key = dataSet[i];
        j = i - 1;

        while (j >= 0 && dataSet[j] > key) {
            dataSet[j + 1] = dataSet[j];
            j = j - 1;
        }
        dataSet[j + 1] = key;
    }
}

int main (){
    // int dataSet[] = {1,2,3,4,5,6};
    int dataSet[] = {6,4,2,3,1,5};
    int length = sizeof dataSet / sizeof dataSet[0];

    InsertionSort(dataSet, length);

    for(int i=0; i< length; i++){
        printf("%d ", dataSet[i]);
    }

    printf("\n");

    return 0;
}