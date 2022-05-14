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
    printf("4. Delete node at first position\n");
    printf("5. Delete Node at last position\n");
    printf("6. Delete node at any position\n");
    printf("7. Search node where element is stored.\n");
    printf("8. Exit\n");
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
    //Delete node at fisrt position..
    else if(ch == 4){
        tmpNode = currentNode = headNode;
        tmpNode = tmpNode->next;
        headNode = tmpNode;
        free(currentNode);
        printList(tmpNode);
    }
    //Delete node at last position..
    else if(ch == 5){
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
    else if(ch == 6){
        tmpNode = currentNode, headNode;
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
    else if(ch == 7){
        tmpNode = headNode;
        int count = 0, flag =0;
        printf("Enter element which you want to Search?\n");
        scanf("%d", &elm);
        while(tmpNode!=NULL){
            if(tmpNode->data == elm){
                flag=1;
                break;
            }
            count++;
            tmpNode = tmpNode->next;
        }
        if(flag == 1)
            printf("Element fount at %d\n", count+1);
        else
            printf("Element not found\n");
    }
    //terminate program..
    else if(ch == 8)
        exit(0);
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
