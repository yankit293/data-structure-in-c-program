#include<stdio.h>
int main(){
    int i, j,swap,n=10, arr[10] = {5, 10, 15, 12, 11, 9, 7, 13, 6,2};
    void printArray(int [], int);
    printf("Unsorted Array:");
    printArray(arr, n);
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j]> arr[j+1]){
                swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap; 
            }
        }
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