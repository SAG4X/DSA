#include <stdio.h>
#include <stdlib.h>
#define max 100

void push();
void display();

int top = -1;
int stack[max];
int count = 0;

int main()
{
	int ch;
	printf("Stack operations : Insert(push)\n\n");
	while(1)
	{
		printf("To enter a element type 1.\n");
		printf("To exit type -1.\n\n");
		
		printf("Enter your choice: ");
		scanf("%d", &ch);
		printf("\n");
		
		switch(ch)
		{
			case 1 : push(); break;
			case -1 : exit(1); break;
			default : printf("Invalid choice.");
		}
	}
}

void push()
{
	int val;
	if(top == max-1)
	{
		printf("Stack is full");
	}
	else
	{
		printf("Enter the element: ");
		scanf("%d", &val);
		top++;
		stack[top] = val;
		count +=1;
	}
	display();
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
