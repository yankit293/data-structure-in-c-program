

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
void sortList(nodeptr);

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
    printList(tmpNode);
    sortList(tmpNode);
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

void sortList(nodeptr current)
{
    nodeptr index = NULL;
    int temp;

    if (headNode == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            // Node index will point to node next to current
            index = current->next;

            while (index != NULL)
            {
                // If current node's data is greater than index's node data, swap the data between them
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}
