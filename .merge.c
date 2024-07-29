#include <stdio.h>
#include <time.h>

void printArray(int a[], int size) {
    for(int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertionSort(int a[], int size) {
    for(int i = 1; i < size; i++) {
        int temp = a[i];
        int j = i - 1;
        while(j>=0 && a[j]>temp) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
    printArray(a, size);
}

int main() {
    int start, stop;
    int arr[] = {5, 4, 10, 1, 6, 2};
    start = clock();
    insertionSort(arr, 6);
    stop = clock();
    printf("Time taken to complete insertion sort is %lf seconds.",(double)((stop-start)/CLOCKS_PER_SEC));

    return 0;
}
