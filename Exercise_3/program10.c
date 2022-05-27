
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
            headNode->prev = NULL;
        }
        else
        {
            tmpNode->next = currentNode;
            currentNode->prev = tmpNode;
            tmpNode = currentNode;
        }
    }
    tmpNode->next = NULL;
    tmpNode = headNode;
    printList(tmpNode);
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
    while (tmp != NULL)
    {
        printf("->[%d]", tmp->data);
        tmp = tmp->next;
    }
}