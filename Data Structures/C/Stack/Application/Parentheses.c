#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

void push(char);
char pop();

int top = -1;
char exp[max];

int main()
{
	int ch, i, t = 1;
	char x;
	printf("Input an expression: ");
	gets(exp);
	for(i=0; i<strlen(exp); i++){
		if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
		{
			push(exp[i]);
		}
		if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
		{
			if(top == -1)
			{
				t = 0;
			}
			else
			{
				x = pop();
				if(exp[i] == ')' && (x == '[' || x == '{'))
				{
					t = 0;
				}
				if(exp[i] == ']' && (x == '(' || x == '{'))
				{
					t = 0;
				}
				if(exp[i] == '}' && (x == '[' || x == '('))
				{
					t = 0;
				}
			}
		}
	}
	if(top >= 0)
	{
		t = 0;
	}
	if(t == 1)
	{
		printf("\nValid expression.\n");
	}
	else
	{
		printf("\nInvalid expression.\n");
	}
	return 0;
}

void push(char c)
{
	if(top == max-1)
	{
		printf("Stack is full.");
	}
	else
	{
		top++;
		exp[top] = c;
	}
}

char pop()
{
	if(top == -1)
	{
		printf("Stack is empty.");
	}
	else
	{
		return (exp[top--]);
	}
}
