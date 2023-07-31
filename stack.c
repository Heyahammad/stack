#include <stdio.h>

int TOP = -1; // Initially Stack is empty
int Stack[20]; // Array for Stack

void Push(int itm);
int Pop();
int Peak();
int IsEmpty();
int IsFull();
void Traverse();

int main()
{
    int item, choice;
   
    while (choice != 5)
    {
        printf("\n\n");
        printf(" *******  STACK  OPERATIONS   ********* \n\n");
        printf("1- Push item \n2- Pop Item \n");
        printf("3- Peak (Top Item) \n4- Traverse / Display Stack Items \n");
        printf("5- Exit.");
        printf(" \n\nYour choice ---> ");
        scanf("%d", &choice);
       
        switch (choice)
        {
            case 1:
                if (IsFull())
                    printf("\nStack Full/Overflow\n");
                else
                {
                    printf("\nEnter a number: ");
                    scanf("%d", &item);
                    Push(item);
                }
                break;
               
            case 2:
                if (IsEmpty())
                    printf("\nStack is empty\n");
                else
                {
                    item = Pop();
                    printf("\nDeleted from Stack: %d\n", item);
                }
                break;
               
            case 3:
                if (IsEmpty())
                    printf("\nStack is empty\n");
                else
                {
                    item = Peak();
                    printf("\nPeak of Stack (Top): %d\n", item);
                }
                break;
               
            case 4:
                if (IsEmpty())
                    printf("\nStack is empty\n");
                else
                {
                    printf("\nList of Items pushed on Stack:\n");
                    Traverse();
                }
                break;
               
            case 5:
                break;
               
            default:
                printf("\n\nInvalid Choice\n");
        }
    }
   
    return 0;
}

void Push(int item)
{
    if (IsFull())
    {
        printf("\nStack Full/Overflow\n");
        return;
    }
   
    TOP++;
    Stack[TOP] = item;
    printf("\nItem Pushed: %d\n", item);
}

int Pop()
{
    int item;
   
    if (IsEmpty())
    {
        printf("\nStack is empty\n");
        return -1; // Return -1 to indicate underflow
    }
   
    item = Stack[TOP];
    TOP--;
    return item;
}

int Peak()
{
    if (IsEmpty())
    {
        printf("\nStack is empty\n");
        return -1; // Return -1 to indicate underflow
    }
   
    return Stack[TOP];
}

int IsEmpty()
{
    if (TOP == -1)
        return 1; // Stack is empty
    else
        return 0; // Stack is not empty
}

int IsFull()
{
    if (TOP == 19)
        return 1; // Stack is full
    else
        return 0; // Stack is not full
}

void Traverse()
{
    int i;
   
    for (i = TOP; i >= 0; i--)
        printf("%d ", Stack[i]);
}
