#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[low];

    int i = low + 1;
    int j = high;

    while (i <= j) {
        if (arr[i] >= pivot && arr[j] <= pivot){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
        } else if (arr[i] >= pivot){
            j--;
        } else {
            i++;
        } 
    }

    int temp = pivot;
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low >= high)
        return;

    int p = partition(arr, low, high);

    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
}

int main(){
    int arr[] = {5, 2, 8, 1, 3, 6, 7, 9, 12, 11, 55, 53, 23, 42, 15};
    quickSort(arr, 0, 14);

    for (int i = 0; i < 14; i++){
        printf("%d \n", arr[i]);
    }
}