# include <stdio.h>
# define MAX_SIZE 8
int sorted[MAX_SIZE]; // 추가적인 공간이 필요

void merge(int list[], int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int k = left; // 임시 배열 복사용

    while(i<=mid && j<=right){
        if(list[i] <= list[j]){
            sorted[k++] = list[i++];
        } else{
            sorted[k++] = list[j++];
        }
    }

    if (i<=mid){
        for(int l = i; l<=mid; l++){
            sorted[k++] = list[l];
        }
    } else{
        for(int l = j; l <= right; l++){
            sorted[k++] = list[l];
        }
    }

    for(int l = left; l<=right; l ++){
        list[l] = sorted[l];
    }
}

// 합병 정렬
void merge_sort(int list[], int left, int right){
  int mid;

  if(left<right){
    mid = (left+right)/2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
    merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
    merge_sort(list, mid+1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
    merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
  }
}

int main(){
  int i;
  int n = MAX_SIZE;
  int list[MAX_SIZE] = {21, 10, 12, 20, 25, 13, 15, 22};

  merge_sort(list, 0, n-1);

  // 정렬 결과 출력
  for(i=0; i<n; i++){
    printf("%d ", list[i]);
  }

  printf("\n");

  return 0;
}
