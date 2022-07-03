#include<stdio.h>

void swap(int *a, int *b) {
  
  int tmp = *a;
  
  *a = *b;
  
  *b = tmp;
  
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int j,i = (low - 1);
 
    for (j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high){
     if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(arr, 0, n-1);
    printf("\nSorted Array:");
    printArray(arr, n);
}
