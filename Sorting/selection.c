#include<stdio.h>
int main(){
    int i, j, position, swap,n=10, arr[10] = {5, 10, 15, 12, 11, 9, 7, 13, 6,2};
    void printArray(int [], int);
    printf("Unsorted Array:");
    printArray(arr, n);
    for(i=0; i<n-1; i++){
        position = i;
        for(j=i+1; j<n; j++){
            if(arr[position]>arr[j]){
                position = j;
            }
        }
        if(position!=i){
            swap = arr[i];
            arr[i] = arr[position];
            arr[position] = swap;
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