#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
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
        }
        else
        {
            tmpNode->next = currentNode;
            tmpNode = currentNode;
        }
    }
    tmpNode->next = headNode;
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
    
    while (tmp->next!= headNode)
    {
        printf("->[%d]", tmp->data);
        tmp = tmp->next;
    }
    printf("->[%d]", tmp->data);
}