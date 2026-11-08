#include <stdio.h>


void bubbleSort(int arr[], int n) {
    int sorted = 0;
    while (!sorted){
        sorted = 1;

        for (int i = 0; i < n-1; i++){
            if (arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                
                sorted = 0;
            }
        }
    }
}

int main(){
    int arr[] = {5, 2, 8, 1, 3};
    bubbleSort(arr, 5);

    for (int i = 0; i < 5; i++){
        printf("%d \n", arr[i]);
    }
}