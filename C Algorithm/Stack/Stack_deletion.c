#include <stdio.h>
#include <stdlib.h>
#define max 100

void push(int);
void pop();
void display();

int top = -1;
int stack[max];
int count = 0;

int main()
{
	int ch;
	printf("Stack operations : Delete(pop)\n\n");
	push(0);
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	push(8);
	push(9);
	display();
	while(1)
	{
		printf("To delete a element type 1.\n");
		printf("To exit type -1.\n\n");
		
		printf("Enter your choice: ");
		scanf("%d", &ch);
		printf("\n");
		
		switch(ch)
		{
			case 1 : pop(); break;
			case -1 : exit(1); break;
			default : printf("Invalid choice.");
		}
	}
}

void push(int val)
{
	if(top == max-1)
	{
		printf("Stack is full");
	}
	else
	{
		top++;
		stack[top] = val;
		count +=1;
	}
}

void pop()
{
	if(top == -1)
	{
		printf("Stack is empty.");
	}
	else
	{
		printf("Deleted element is %d\n", stack[top]);
		top = top-1;
		count -= 1;
	}
	printf("\n");
}

void display()
{
	int i;
	if(top == -1)
	{
		printf("Stack is empty.");
	}
	else
	{
		printf("[");
		for(i=0; i<count; i++)
		{
			printf("%d, ", stack[i]);
		}
		printf("\b\b ]\n\n");
	}
}
