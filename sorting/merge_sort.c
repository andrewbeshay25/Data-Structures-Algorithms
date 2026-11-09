#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;

    int size = high - low + 1;
    int *temp = malloc(size * sizeof(int));

    if (temp == NULL)
        exit(EXIT_FAILURE);

    // 1. Compare arr[i] and arr[j].
    // Store the smaller element in temp[k].
    // Advance the appropriate pointers.

    for (; k < size; k++){
        if (i > mid || j > high) break;

        if (arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
        } else{
            temp[k] = arr[j];
            j++;
        }
    }

    // 2. Copy any remaining elements
    // from the left half.
    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }

    // 3. Copy any remaining elements
    // from the right half.
    while(j <= high){
        temp[k] = arr[j];
        j++;
        k++;
    }
    // 4. Copy temp back into arr
    // starting at index low.
    k=0;
    for (int i = low; i <= high; i++){
        arr[i] = temp[k];
        k++;
    }

    free(temp);
}



void mergeSort(int arr[], int low, int high) {

    // Base case: stop if there is zero or one element.
    if (low >= high) return;

    // Calculate the middle index.
    int mid = low + (high - low) / 2;

    // Recursively sort the left half.
    mergeSort(arr, low, mid);

    // Recursively sort the right half.
    mergeSort(arr, mid+1, high);

    // Merge the two sorted halves.
    merge(arr, low, mid, high);
}



int main(){
    int arr[] = {5, 2, 8, 1, 3};
    mergeSort(arr, 0, 4);

    for (int i = 0; i < 5; i++){
        printf("%d \n", arr[i]);
    }
}