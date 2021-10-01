/* Write a menu driven program to perform the following operations of a stack using array by using suitable user defined functions for each case.
a) Check if the stack is empty 
b) Display the contents of stack 
c) Push
d) Pop
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int stack_arr[MAX];
int top = -1;

void push(int item);
int pop();
int peek();
int isEmpty();
int isFull();
void display();

int main()
{
        int choice,item;
        while(1)
        {
                printf("\n1.Push\n");
                printf("2.Pop\n");
                printf("3.Display the top element\n");
                printf("4.Display all stack elements\n");
                printf("5.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                 case 1 :
                        printf("\nEnter the item to be pushed : ");
                        scanf("%d",&item);
                        push(item);
                        break;
                 case 2:
                        item = pop();
                        printf("\nPopped item is : %d\n",item );
                        break;
                 case 3:
                        printf("\nItem at the top is : %d\n", peek() );
                        break;
                 case 4:
                        display();
                        break;
                 case 5:
                        exit(1);
                 default:
                        printf("\nWrong choice\n");
                }
        }

        return 0;

}

void push(int item)
{
        if( isFull() )
        {
                printf("\nStack Overflow\n");
                return;
        }
        top = top+1;
        stack_arr[top] = item;
}

int pop()
{
        int item;
        if( isEmpty() )
        {
                printf("\nStack Underflow\n");
                exit(1);
        }
        item = stack_arr[top];
        top = top-1;
        return item;
}

int peek()
{
        if( isEmpty() )
        {
                printf("\nStack Underflow\n");
                exit(1);
        }
        return stack_arr[top];
}

int isEmpty()
{
        if( top == -1 )
                return 1;
        else
                return 0;
}

int isFull()
{
        if( top == MAX-1 )
                return 1;
        else
                return 0;
}

void display()
{
        int i;
        if( isEmpty() )
        {
                printf("\nStack is empty\n");
                return;
        }
    printf("\nStack elements :\n\n");
        for(i=top;i>=0;i--)
                printf(" %d\n", stack_arr[i] );
        printf("\n");
}
