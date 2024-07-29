#include <stdio.h>

int size = 6;

void merge(int a[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    int b[6];

    while(i <= mid && j <= high) {
        if(a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    if(i > mid) {
        while(j <= high) {
            b[k] = a[j];
            j++;
            k++;
        }
    } else {
        while(i <= mid) {
            b[k] = a[i];
            i++;
            k++;
        }
    }

    for(i = low; i <= high; i++) {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int low, int high) {
    if(low != high) {
        int mid = (low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void printArray(int arr[], int size) {
    
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1,6,5,4,2,3};
    mergeSort(arr,0,size - 1);
    printArray(arr, 6);
    return 0;
}
