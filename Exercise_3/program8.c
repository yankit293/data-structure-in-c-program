//Write a program in C to create two single linked lists of more than one node and concatenate the list. 

#include<stdio.h>
#include<stdlib.h>
 struct node{
        int data;
        struct node *next;
    };
    typedef struct node * nodeptr;
    nodeptr headNode, currentNode, tmpNode;
    nodeptr headNode2, currentNode2, tmpNode2;
    nodeptr getNode();
    void printList(nodeptr);
int main(){
    
    int length, len, i;
    printf("\nEnter the length of 1st list:");
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
    printf("\nEnter the length of 2st list:");
    scanf("%d", &len);
    for(i=0; i<len; i++){
        currentNode2 = getNode();
        if(i==0){
            headNode2 = tmpNode2 = currentNode2;
        }
        else{
            tmpNode2->next = currentNode2;
            tmpNode2 = currentNode2;
        }
    }
    tmpNode2->next = NULL;
    tmpNode2 = headNode2;
    printList(tmpNode2);
    
    while(tmpNode->next!=NULL){
        tmpNode = tmpNode->next;
    }
    tmpNode->next = headNode2;
    tmpNode = headNode;
    printf("\nList concatenated successfully!\n");
    printList(tmpNode);
    free(headNode);
    free(headNode2);
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