#include <stdio.h>

void selectionSort(int arr[], int n) {

    // Outer loop: select each position
    for (int i = 0; i < n; i++){
        int min = arr[i];
        int min_index = i;

        // Inner loop: find the smallest element
        for (int j = i; j < n; j++){
            if (arr[j] < min){
                min = arr[j];
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[min_index] = temp;
    }
}

int main(){
    int arr[] = {5, 2, 8, 1, 3};
    selectionSort(arr, 5);

    for (int i = 0; i < 5; i++){
        printf("%d \n", arr[i]);
    }
}