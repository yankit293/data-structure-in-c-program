//Write a program in C to create a single linked list of more than one node and display
//total number of nodes.

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
void countNode(nodeptr);

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
    tmpNode->next = NULL;
    tmpNode = headNode;
    countNode(tmpNode);
}
nodeptr getNode()
{
    nodeptr tmp;
    tmp = (nodeptr)malloc(sizeof(nodeptr));
    printf("\nEnter element:");
    scanf("%d", &tmp->data);
    return tmp;
}
void countNode(nodeptr tmp)
{
    int count = 0;
    while (tmp != NULL)
    {
        tmp = tmp->next;
        count++;
    }
    printf("\nTotal node in LinkedList:%d\n", count);
}