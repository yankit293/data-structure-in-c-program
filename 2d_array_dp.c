#include<stdio.h>
#include<stdlib.h>

int main(){
    int  row, col, i, j, sum=0;

    printf("Enter the size of Row and column\n");
    scanf("%d%d", &row, &col);
    int *m[row];
    for(i=0; i<row; i++)
        m[i] = (int*)malloc(col*sizeof(int));

    for(i =0; i<row; i++){
        for(j=0; j<col; j++){
            printf("Enter value at %d , %d\n", i+1, j+1);
            scanf("%d", (*m+i)+j);
        }
    }

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            if(i==j)
                sum = sum + *((*m+i)+j);
        }
    }
    printf("Sum:%d", sum);
        
    return 0;
}