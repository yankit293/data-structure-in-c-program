#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stk[MAX], tos=-1;

int isEmpty()
{
    if (tos == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (tos == MAX - 1)
        return 1;
    else
        return 0;
}

void push(int x)
{

    if (!isFull())
    {
        tos++;
        stk[tos] = x;
        printf("%d is pushed into Stack\n", x);
    }
    else
        printf("Stack is Full\n");
}
int pop()
{
    int x;
    if (!isEmpty())
    {
        x = stk[tos];
        tos--;
        return x;
    }
    else
        return -1;
}
void display()
{
    int i;
    if (!isEmpty())
    {
        printf("Stack is:");
        for (i = tos; i >= 0; i--)
            printf("%d\t", stk[i]);
    }
    else
        printf("Stack is Empty!\n");
}
int main()
{

    int i, ch, val, result;
menu:
    
    printf("\n1. Push into Stack\n");
    printf("2. Pop from Stack\n");
    printf("3. Check Stack underflow\n");
    printf("4. check Stack Overflow\n");
    printf("5. Display Stack\n");
    printf("6. Exit\n");
    printf("Enter your Choice:");
    scanf("%d", &ch);

    if (ch == 1)
    {
        printf("Enter value to push in stack\n");
        scanf("%d", &val);
        push(val);
    }
    else if (ch == 2)
    {
        result = pop();
        if (result != -1)
            printf("%d is poped from stack\n", result);
        else
            printf("Stack is Empty!\n");
    }
    else if (ch == 3)
        isEmpty();
    else if (ch == 4)
        isFull();
    else if (ch == 5)
        display();
    else if (ch == 6)
        exit(0);
    else
        printf("Invalid choice!\n");
    goto menu;

    return 0;
}