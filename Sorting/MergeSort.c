#include<stdio.h>

void swap(int *a, int *b) {
  
  int tmp = *a;
  *a = *b;
  *b = tmp;
  
}
void merge(int arr[], int low, int m, int high)
{
    int i, j, k;
    int n1 = m - low + 1;
    int n2 = high - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 

    i = 0; 
    j = 0; 
    k = low; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int low, int high)
{
    if (low < high) {
        int m = low + (high - low) / 2;
        mergeSort(arr, low, m);
        mergeSort(arr, m + 1, high);
        merge(arr, low, m, high);
    }
}
void printArray(int arr[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
}
int main(){
    int i, j,n=10, arr[10] = {5, 10, 15, 12, 11, 9, 7, 13, 6,2};
    printf("Unsorted Array:");
    printArray(arr, n);
    mergeSort(arr, 0, n-1);
    printf("\nSorted Array:");
    printArray(arr, n);
}