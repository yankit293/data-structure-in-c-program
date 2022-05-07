#include<stdio.h>
int main()
{
    int row, space, i, j;
    printf("Enter number of rows\n");
    scanf("%d", &row);
    for(i=0; i<=row; i++){
        for(space = row-i-1; space>=0; space--){
            printf(" ");
        }
        for(j=0; j<=i; j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
