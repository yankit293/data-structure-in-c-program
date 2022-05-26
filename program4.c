//Write a program in C to create a single linked list of more than one node and delete
//an element at (i) first position (ii) last position and (iii) at specified position.

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
    
    int length, i, ch, elm;
    printf("Enter the length of list:");
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
    menu:
    printf("\n1. Delete node at first position\n");
    printf("2. Delete Node at last position\n");
    printf("3. Delete node at any position\n");
    printf("4. Exit\n");
    scanf("%d", &ch);

    
    //Delete node at fisrt position..
    if(ch == 1){
        tmpNode = currentNode = headNode;
        tmpNode = tmpNode->next;
        headNode = tmpNode;
        free(currentNode);
        printList(tmpNode);
    }
    //Delete node at last position..
    else if(ch == 2){
        tmpNode = currentNode = headNode;
        while(tmpNode->next!=NULL){
            currentNode = tmpNode;
            tmpNode = tmpNode->next;
        }
        free(tmpNode);
        currentNode->next = NULL;
        printList(headNode);

    }
    //Delete at any position
    else if(ch == 3){
        tmpNode  = headNode;
        printf("Enter element which you want to delete node\n");
        scanf("%d", &elm);
        while(tmpNode->next!=NULL){
            if(tmpNode->data == elm)
                break;
            currentNode = tmpNode;
            tmpNode = tmpNode->next;
            
        } 
        currentNode->next = tmpNode->next;
        free(tmpNode);
        printList(headNode);
    }
    //terminate program..
    else if(ch == 4){
        free(headNode);
        exit(0);
    }   
    else
        printf("Invalid Choice\n");
    goto menu;
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