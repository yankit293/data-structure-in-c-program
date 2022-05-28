

#include<stdio.h>
#include<stdlib.h>
 struct node{
        int coe, exp;
        struct node *next;
    };
    typedef struct node * nodeptr;
    nodeptr headNode, currentNode, tmpNode;
    nodeptr headNode2, currentNode2, tmpNode2;
    nodeptr getNode();
    void printList(nodeptr);
int main(){
    
    int len1, len2, i;
    here:
    printf("Enter Largest Polynomial expression First if equal no need\n");
    printf("\nEnter total term in  1st polynomial:");
    scanf("%d", &len1);
    printf("\nEnter total term in 2nd polynomial:");
    scanf("%d", &len2);
    if(len1<len2)
        goto here;
    printf("\nFirst Polynomial:");
    for(i=0; i<len1; i++){
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
    printList(headNode);

    printf("\nSecond Polynomial:");
    for(i=0; i<len2; i++){
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
    printList(headNode2);
    tmpNode = headNode;
    tmpNode2 = headNode2;

    while(tmpNode!=NULL){
        if(tmpNode->exp == tmpNode2->exp){
            tmpNode->coe = tmpNode->coe + tmpNode2->coe;
            tmpNode = tmpNode->next;
            tmpNode2 = tmpNode2->next;
        }
        else if(tmpNode->exp > tmpNode2->exp){
            tmpNode = tmpNode->next;
        }
        else if(tmpNode->exp < tmpNode2->exp){
            tmpNode2 = tmpNode2->next;
        }
    }
    printf("\nSum of polynomial:\n");
    printList(headNode);
    free(headNode);
    free(headNode2);
    return 0;
}
nodeptr getNode(){
    nodeptr tmp;
    tmp = (nodeptr)malloc(sizeof(nodeptr));
    printf("\nEnter coefficient:");
    scanf("%d", &tmp->coe);
    printf("\nEnter Exponent:");
    scanf("%d", &tmp->exp);
    
    return tmp;
}

void printList(nodeptr tmp){
    printf("\nPrinting List:\n");
    while(tmp!=NULL){
        printf("->[%d:%d]", tmp->coe,tmp->exp);
        tmp = tmp->next;
    }
}