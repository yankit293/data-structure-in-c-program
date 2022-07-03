#include<stdio.h>
int main(){
    int i, j,key,n=10, arr[10] = {5, 10, 15, 12, 11, 9, 7, 13, 6,2};
    void printArray(int [], int);
    printf("Unsorted Array:");
    printArray(arr, n);
    for(i=1; i<n; i++){
        key = arr[i];
        j = i-1;
        while(j >=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j =j-1;
        }
        arr[j+1] = key;
    }
    printf("\nSorted Array:");
    printArray(arr, n);
}
void printArray(int arr[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
}