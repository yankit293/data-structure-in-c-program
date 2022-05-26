//Write a program in C to create a single linked list of more than one node and insert a
//node at (i) first position (ii) last position and (iii) specified location 


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
    printf("\n1. Insert a Node at 1st position.\n");
    printf("2. Insert a node at last Position.\n");
    printf("3. Insert a node at any postion\n");
    printf("4. Exit\n");
    scanf("%d", &ch);

    //insert node at first position...
    if(ch == 1){
        currentNode = getNode();
        currentNode->next = headNode;
        headNode = tmpNode = currentNode;
        printList(tmpNode);
    }
    //insert node at last position..
    else if(ch == 2){
        tmpNode = headNode;
        while(tmpNode->next!=NULL){
            tmpNode = tmpNode->next;
        }
        currentNode = getNode();
        currentNode->next = NULL;
        tmpNode->next = currentNode;
        tmpNode = headNode;
        printList(tmpNode);
    }
    //Insert node at any location...
    else if(ch ==3){
        tmpNode = headNode;
        printf("Enter element after which you want to insert node\n");
        scanf("%d", &elm);
        while(tmpNode->next!=NULL){
            if(tmpNode->data == elm)
                break;
            tmpNode = tmpNode->next;
        } 
        currentNode = getNode();
        currentNode->next = tmpNode->next;
        tmpNode->next = currentNode;
        tmpNode = headNode;
        printList(tmpNode);
    }
   
    //terminate program..
    else if(ch == 4){
        free(headNode);
        exit(0);
    }
    else
        printf("Invalid Choice\n");
    goto menu;
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