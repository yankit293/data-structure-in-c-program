//Write a program in C to create a circular doubly linked list of more than one node and display it. 

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node *nodeptr;
nodeptr headNode, currentNode, tmpNode;
nodeptr getNode();
void printList(nodeptr);

int main()
{
    int length, i;
    printf("Enter the length of list:");
    scanf("%d", &length);

    for (i = 0; i < length; i++)
    {
        currentNode = getNode();
        if (i == 0)
        {
            headNode = tmpNode = currentNode;
            headNode->prev = headNode;
        }
        else
        {
            tmpNode->next = currentNode;
            currentNode->prev = tmpNode;
            tmpNode = currentNode;
        }
    }
    tmpNode->next = headNode;
    headNode->prev = tmpNode;
    printList(headNode);
}
nodeptr getNode()
{
    nodeptr tmp;
    tmp = (nodeptr)malloc(sizeof(nodeptr));
    printf("\nEnter element:");
    scanf("%d", &tmp->data);
    return tmp;
}
void printList(nodeptr tmp)
{
    printf("\nPrinting List:\n");
    while (tmp->next != headNode)
    {
        printf("->[%d]", tmp->data);
        tmp = tmp->next;
    }
    printf("->[%d]", tmp->data);
}