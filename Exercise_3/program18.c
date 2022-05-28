


#include<stdio.h>
#include<stdlib.h>
 struct node{
        int data;
        struct node *next, *prev;
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
            headNode->prev = headNode;
        }
        else{
            tmpNode->next = currentNode;
            currentNode->prev = tmpNode;
            tmpNode = currentNode;
        }
    }
    tmpNode->next = headNode;
    headNode->prev = tmpNode;
    printList(headNode);
    menu:
    printf("\n1. Insert a Node at 1st position in Circular doubly linked list.\n");
    printf("2. Insert a node at last Position in Circular doubly linked list.\n");
    printf("3. Insert a node at any postion in Circular doubly linked list.\n");
    printf("4. Exit\n");
    scanf("%d", &ch);

    //insert node at first position...
    if(ch == 1){
        while(tmpNode->next!=headNode){
            tmpNode = tmpNode->next;
        }
        currentNode = getNode();
        currentNode->prev = tmpNode;
        currentNode->next = headNode;
        tmpNode-> next = currentNode;
        headNode = currentNode;
        printList(headNode);
    }
    //insert node at last position..
    else if(ch == 2){
        tmpNode = headNode;
        while(tmpNode->next!=headNode){
            tmpNode = tmpNode->next;
        }
        currentNode = getNode();
        currentNode->next = headNode;
        currentNode->prev = tmpNode;
        tmpNode->next = currentNode;
        printList(headNode);
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
        currentNode->prev = tmpNode;
        tmpNode->next = currentNode;
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
    while(tmp->next!=headNode){
        printf("->[%d]", tmp->data);
        tmp = tmp->next;
    }
    printf("->[%d]", tmp->data);
}