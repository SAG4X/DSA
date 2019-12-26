#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next; 
};

struct node *top=NULL;
struct node *push(struct node *,int );
struct node *pop(struct node *);
struct node *display(struct node *);
int peek(struct node *);

 
int main(){
	int option,val;
	printf("----------MAIN MENU-----------------\n");
	printf("1.PUSH\n");
	printf("2.POP\n");
	printf("3.DISPLAY\n");
	printf("4.PEEK\n");
	
	do{
	printf("\nEnter the option : ");
	scanf("%d",&option);
	switch(option){
		case 1 : printf("\tEnter the value : ");scanf("%d",&val);push(top,val);break;
		case 2 : pop(top);break;
		case 3 : display(top);break;
		case 4 : peek(top);break;
		}
	}while(option != 5);
	return 0;
}
struct node *push(struct node *top,int val){
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=val;
	if(top==NULL){
		ptr->next=NULL;
		ptr=top;
	}
	else{
		ptr->next=top;
		top=ptr;
	}
	return top;
}

struct node *pop(struct node *top){
	struct node *ptr;
		ptr=top;
		if(ptr==NULL)
			printf("\nSTACK UNDERFLOW");
		else{
			top=top->next;
			printf("\nDeleted num is : %d",ptr->data);
			free(ptr);
		}
		return top; 	
}

struct node *display(struct node *top){
	struct node *ptr;
	ptr=top;
	if(top==NULL){
		printf("\nSTACK EMPTY");
	}else{
		
	while(ptr!=NULL)
		{
		printf(" %d ",ptr->data);
		ptr=ptr->next;
		}
	}
	return top;
}

int peek(struct node *top){
	printf("Peek is : %d",top->data);
}
