//Write a program in C to create a single linked list and create a copy of list. 


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
    nodeptr getNode2();
    void printList(nodeptr);
int main(){
    
    int length, i, node=0;
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
    while(tmpNode!=NULL){
        currentNode2 = getNode2();
        currentNode2->data = tmpNode->data;
        if(node==0){
            headNode2 = tmpNode2 = currentNode2;

        }
        else{
            tmpNode2->next = currentNode2;
            tmpNode2 = currentNode2;

        }
        tmpNode = tmpNode->next;
        node++;
    }
    tmpNode2->next = NULL;
    tmpNode2 = headNode2;
    printf("\nLinkedList Copied Successfully!\n");
    printList(tmpNode2);
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
nodeptr getNode2(){
    nodeptr tmp2;
    tmp2 = (nodeptr)malloc(sizeof(nodeptr));
    return tmp2;
}
void printList(nodeptr tmp){
    printf("\nPrinting List:\n");
    while(tmp!=NULL){
        printf("->[%d]", tmp->data);
        tmp = tmp->next;
    }
}