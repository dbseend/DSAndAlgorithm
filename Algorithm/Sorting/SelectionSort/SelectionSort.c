# include <stdio.h>
# define MAX_SIZE 5

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


// int list[]: 정렬할 배열
// int n: 배열의 길이
void selection_sort(int list[], int n){
    int i, j;
    int current = 0, min = 0;

    for(i = 0; i < n; i++){
        for(j = current; j < n; j++){
            if(list[j] < list[min]){
                min = j;
            }
        }
        
        if(current != min){
            swap(&list[current], &list[min]);
        }
        current++;
    }
}

int main(){
  int i;
  int n = MAX_SIZE;
  int list[MAX_SIZE] = {9, 6, 7, 3, 5};

  // 선택 정렬 수행
  selection_sort(list, n);

  // 정렬 결과 출력
  for(i=0; i<n; i++){
    printf("%d ", list[i]);
  }

  printf("\n");

  return 0;
}
