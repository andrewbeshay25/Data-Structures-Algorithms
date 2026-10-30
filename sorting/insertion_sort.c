#include <stdio.h>
#include <stdlib.h>

int SMALLER(int x, int y){
    if (x < y) { return 1; }
    else       { return 0; }
}

void insertion_sort(int *arr, int length, int val){
    int counter = 0;
    int sorted = 0;

    for (int i = 1; i < length; i++){
      
      int j = i;
      int k = i-1;
      while (k >= 0){
        if (SMALLER(arr[j], arr[k])){
            // swap
            int temp = arr[j];
            arr [j] = arr[k];
            arr[k] = temp;
        } else {
            break;
        }
        j--;
        k--;
      }
    }
}

int main(){

}