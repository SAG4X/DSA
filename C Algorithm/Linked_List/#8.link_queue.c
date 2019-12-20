#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next; 
};
struct queue{
	struct node *front;
	struct node *rear;
};

struct queue *q;
void create_queue(struct queue *);
struct node *insert(struct queue *,int );
struct node *deleteq(struct queue *);
struct node *display(struct queue *);
int peek(struct queue *);

 
int main(){
	int option,val;
	create_queue(q);
	
	printf("----------MAIN MENU-----------------\n");
	printf("1.INSERT\n");
	printf("2.DELETE\n");
	printf("3.DISPLAY\n");
	printf("4.PEEK\n");
	printf("5.exit\n");
	do{
	printf("\nEnter the option : ");
	scanf("%d",&option);
	switch(option){
		case 1 : printf("\tEnter the value : ");
				 scanf("%d",&val);
				 q = insert(q,val);
				 break;
		case 2 : q = deleteq(q);
				 break;
		case 3 : q = display(q);
				 break;
		case 4 : val = peek(q);
				 break;
		}
	}while(option != 5);
	return 0;
}
void create_queue(struct queue *q){
	q->rear=NULL;
	q->front=NULL;
}
struct queue *insert(struct queue *q,int data){
	struct node *new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=data;
	if(q->front==NULL){
		q->front=new_node;
		q->rear=new_node;
		q->front->next=q->rear->next=NULL;
	}
	else{
		q->rear->next=new_node;
		q->rear=new_node;
		q->rear->next=NULL;
	}
	return q;
}
struct queue *deleteq(struct queue *q){
	struct node *ptr;
	ptr=q->front;
	if(q->front==NULL)
		printf("\nUNDERFLOW");
	else{
		q->front=q->front->next;
		printf("Value deleted is : %d ",ptr->data);
		free(ptr);
	}	
	return q;
}
struct queue *display(struct queue *q){
	struct node *ptr;
	ptr=q->front;
	if(ptr== NULL)
		printf("\nQueue is UNDERFLOW");
	else{
		while(ptr!=q->rear){
			printf(" %d ",ptr->data);
			ptr=ptr->next;
		}
		printf(" %d ",ptr->data);
	}	
	return q;
}
int peek(struct queue *q){
	if(q->front==NULL){
		printf("\nQueue is empty");
		return -1;
	}else{
		return q->front->data;
	}
}
