//Write a program in C to create a single linked list of more than one node and search a
//particular key element.

#include<stdio.h>
#include<stdlib.h>
 struct node{
        int data;
        struct node *next;
    };
    typedef struct node * nodeptr;
    nodeptr headNode, currentNode, tmpNode;
    nodeptr getNode();
    void printList(nodeptr);
int main(){
    
    int length, i, ch, elm, count = 0, flag =0;
    printf("\nEnter the length of list:");
    scanf("%d", &length);

    for(i=0; i<length; i++){
        currentNode = getNode();
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
    printList(tmpNode);
    tmpNode = headNode;
    printf("Enter element which you want to Search?\n");
    scanf("%d", &elm);
    while (tmpNode != NULL)
    {
        if (tmpNode->data == elm)
        {
            flag = 1;
            break;
        }
        count++;
        tmpNode = tmpNode->next;
    }
    if (flag == 1)
        printf("Element fount at %d\n", count + 1);
    else
        printf("Element not found\n");

    free(headNode);
    return 0;
}
nodeptr getNode(){
    nodeptr tmp;
    tmp = (nodeptr)malloc(sizeof(nodeptr));
    printf("\nEnter element:");
    scanf("%d", &tmp->data);
    return tmp;
}
void printList(nodeptr tmp){
    printf("\nPrinting List:\n");
    while(tmp!=NULL){
        printf("->[%d]", tmp->data);
        tmp = tmp->next;
    }
}