#include<stdio.h>

int main(){
    int row, col, size, i, j;

    int compact[6][3] = {{4,5,5}, {0, 3, 1}, {1, 2, 3}, {2, 0, 2}, {3, 3, 3}, {4, 3, 4}};
    
    row = compact[0][0];
    col = compact[0][1];
    size = compact[0][2];
    int sparseM[row][col];
    for(i=0; i<row; i++)
        for(j=0; j<col; j++)
            sparseM[i][j] = 0;
    
    int x, y, z, k;
    for(k=1; k<size; k++){
        x = compact[k][0];
        y = compact[k][1];
        z = compact[k][2];
        sparseM[x][y] = z;
    }

    printf("Printing Sparse matrix..\n");
    for(i=0; i<row; i++){
        for(j=0; j<col; j++)
            printf("%d\t", sparseM[i][j]);
        printf("\n");
    }
    return 0;
}