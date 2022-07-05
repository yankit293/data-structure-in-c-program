#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct node{
    int item;
    struct node *next;
};
typedef struct node *nodeptr;
nodeptr headNode, cNode, tmpNode, Tos;
int count=0;
nodeptr getNode();
int pop();
void push(int);
int isEmpty();
int isFull();
void peek();
void display();
int main()
{

    int i, ch, val, result;
    headNode = NULL;
    Tos = headNode;
menu:
    
    printf("\n1. Push into Stack\n");
    printf("2. Pop from Stack\n");
    printf("3. Display Stack\n");
    printf("4. Exit\n");
    printf("Enter your Choice:");
    scanf("%d", &ch);

    if (ch == 1)
    {
        printf("\nEnter value to push in stack\n");
        scanf("%d", &val);
        push(val);
    }
    else if (ch == 2)
    {
        result = pop();
        if (result != -1)
            printf("\n %d is poped from stack\n", result);
        else
            printf("Stack is Empty!\n");
    }
    else if(ch==3)
        display();
    else if (ch == 4){
        free(headNode);
        exit(0);
    }
    else
        printf("Invalid choice!\n");
    goto menu;

    return 0;
}
int isEmpty()
{
    if (Tos == NULL)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (count == MAX)
        return 1;
    else
        return 0;
}

void push(int x)
{

    if (!isFull())
    {
        cNode = getNode();
        cNode->item = x;
        cNode->next = headNode;
        headNode = cNode;
        Tos = headNode;
        count++;
        printf("\n %d is pushed into Stack\n", x);
    }
    else
        printf("Stack is Full\n");
}
int pop()
{
    int x;
    if (!isEmpty())
    {
        tmpNode = cNode = headNode;
        x = tmpNode->item;
        headNode = tmpNode->next;
        Tos = headNode;
        count--;
        free(cNode);
        return x;
    }
    else
        return -1;
}
void display()
{
    int i;
    tmpNode = headNode;
    if (!isEmpty())
    {
        printf("\n\nStack is:");
        while(tmpNode!=NULL){
            printf("->[%d]", tmpNode->item);
            tmpNode = tmpNode->next;
        }
    }
    else
        printf("Stack is Empty!\n");
}
nodeptr getNode(){
    nodeptr tmp;
    tmp = (nodeptr)malloc(sizeof(nodeptr));
    return tmp;
}