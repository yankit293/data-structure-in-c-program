#include<stdio.h>

int main(){
    int i, j, size, row=4, col = 5, sparseM[4][5] = {
        {0, 0, 0, 1, 0},
        {1, 0, 0, 0, 2},
        {0, 4, 0, 3, 0},
        {0, 0, 5, 0, 0},
    };

    for(i =0; i<4; i++)
        for(j = 0; j<5; j++)
            if(sparseM[i][j]!=0)
                size++;

    int compactM[size+1][3];
    compactM[0][0] = row;
    compactM[0][1] = col;
    compactM[0][2] = size;
    int k = 1;
    for(i=0; i<4; i++)
        for(j=0; j<5; j++)
            if(sparseM[i][j]!=0){
                compactM[k][0] = i;
                compactM[k][1] = j;
                compactM[k][2] = sparseM[i][j];
                k++;
            }
    printf("Printing Compact array of sparse matrix\n");
    printf("Row\tColumn\tvalue\n");
    for(i=0; i<=size; i++){
        for(j=0; j<3; j++){
            printf("%d\t", compactM[i][j]);
        }
        printf("\n");
    }

    
    return 0;
}