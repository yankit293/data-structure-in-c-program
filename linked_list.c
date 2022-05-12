#include<stdio.h>
#include<stdlib.h>

int main(){
    struct node {
        int data;
        struct node *next;
    };
    struct node *headNode, *currentNode, *tmpNode;
    int length, i;
    printf("Enter the length of list:");
    scanf("%d", &length);

    for(i=0; i<length; i++){
        currentNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the element at %d:",i+1);
        scanf("%d", &currentNode->data);
        if(i==0){
            headNode = tmpNode = currentNode;
        }
        else{
            tmpNode->next = currentNode;
            tmpNode = currentNode;
        }
    }
    tmpNode->next = NULL;
    tmpNode = headNode;
    printf("\nPrinting List:\n");
    while(tmpNode!=NULL){
        printf("->[%d]", tmpNode->data);
        tmpNode = tmpNode->next;
    }
    free(headNode);
    return 0;
}