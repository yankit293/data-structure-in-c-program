#include<stdio.h>

void printArray(int arr[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("|%d", arr[i]);
    }
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void maxHeapify(int arr[], int n, int i){
    int l, r, largest;
    l = left(i);
    r = right(i);
    if(l < n  & arr[l] >arr[i])
        largest = l;
    else
        largest = i;
    if(r < n && arr[r] > arr[largest])
        largest = r;
    
    if(largest != i){
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n){
    int i;
    for(i=n/2-1; i>=0; i--)
        maxHeapify(arr, n, i);
}

int left(int i){
    return (2*i+1);
}

int right(int i){
    return (2*i+2);
}

void heapSort(int arr[], int n){
    int i;
    buildMaxHeap(arr, n);
    for(i=n-1; i>=0; i--){
        swap(&arr[0] , &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main(){
    int i, j, n=10, arr[10] = {5, 10, 15, 12, 11, 9, 7, 13, 6,2};
    printf("Unsorted Array:");
    printArray(arr, n);
    heapSort(arr, n);
    printf("\nSorted Array:");
    printArray(arr, n);
}

