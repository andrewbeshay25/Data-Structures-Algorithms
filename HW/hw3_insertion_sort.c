
#include <stdio.h>
#include <stdlib.h>

long long comparisons = 0;

int SMALLER(int x, int y) {
    comparisons++;
    if (x < y) {
        return 1;
    }
    return 0;
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && SMALLER(key, a[j])) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
        if ((i + 1) % 20 == 0) {
            printf("\n");
        }
    }
    if (n % 20 != 0) {
        printf("\n");
    }
}

void runTest(int n, int type) {
    int a[1000];

    for (int i = 0; i < n; i++) {
        if (type == 0) {
            a[i] = n - i;
        } else {
            a[i] = i + 1;
        }
    }

    if (type == 2) {
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    if (type == 0) {
        printf("Worst case\n");
    } else if (type == 1) {
        printf("Best case\n");
    } else {
        printf("Random case\n");
    }

    printf("Array size: %d\n", n);
    printf("Original input:\n");
    printArray(a, n);

    comparisons = 0;
    insertionSort(a, n);

    printf("Sorted output:\n");
    printArray(a, n);
    printf("Total key comparisons: %lld\n\n", comparisons);
}

int main() {
    srand(42);

    runTest(100, 0);
    runTest(100, 1);
    runTest(100, 2);
    runTest(1000, 0);
    runTest(1000, 1);
    runTest(1000, 2);

    return 0;
}

