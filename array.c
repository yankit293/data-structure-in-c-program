#include<stdio.h>
void print_array(int [], int);
int main(){
    int y=1, choice, size;
    int arr[5] = {0,1,2,3,4};
    size = sizeof(arr)/sizeof(arr[0]);
    void insert(int [], int);
    void delete(int [], int);
    void replace();
    void search();
    do{
        printf("1. Insert an element in Array at any position\n");
        printf("2. Delete an element from Array at any position\n");
        printf("3. Replace an element in array at any position\n");
        printf("4. Search an element in array at any position\n");
        printf("5. Exit\n");
        printf("Choose an option from above\n");
        scanf("%d", &choice);
        if(choice == 1)
            insert(arr, size);
        else if(choice == 2)
            delete(arr, size);
        else if(choice == 3)
            replace();
        else if(choice == 4)
            search();
        else if(choice == 5)
            y = 0;
        else
            printf("Wrong Choice\n");
        
    }while(y == 1);

    return 0;
}
void print_array(int arr[], int size){
    int i;
    for(i=0; i<size; i++){
        printf("%d\n", arr[i]);
    }
}
void insert(int arr[], int size){
    
    int pos, i, num;
    printf("Printing Array........\n");
    print_array(arr, size);
    printf("Total element in array is %d\n", size);
    position:
    printf("Enter position where you want to insert element\n");
    scanf("%d", &pos);
    printf("Enter element to insert at %dth postion in array\n", pos);
    scanf("%d", &num);
    
    if( pos > size+1 || pos < 0){
        printf("Wrong postion\n");
        goto position;
    }
    size++;
    for(i=size-1; i>pos-1; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos-1] = num;
    printf("Printing New Array........\n");
    print_array(arr, size);
}
int binary_search(int arr[], int low, int high, int elm){
    int mid;
    if(low<high){
        mid = (low+high)/2;
    if(arr[mid] == elm)
        return mid;
    else if(arr[mid]>elm)
        return binary_search(arr, mid-1, high, elm);
    else if(arr[mid]<elm)
        return binary_search(arr, low, mid-1, elm);
    }
    else
        return -1;
    


}
void delete(int arr[], int size){
    

}
void replace(){

}
void search(){

}