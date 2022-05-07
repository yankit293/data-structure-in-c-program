#include<stdio.h>
#include<stdlib.h>

int main(){
    int *m, size, i;

    printf("Enter Size of Array\n");
    scanf("%d", &size);
    m = (int*)malloc(size*sizeof(int));
    for(i=0; i<size; i++){
        printf("Enter value at %d\n", i+1);
        scanf("%d", (m+i));
    }

    printf("Array....\n");
    for(i=0; i<size; i++)
        printf("%d\t", *(m+i));
    
}