#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create_hll(struct node *,int);
struct node *display(struct node *);

int main(){
	int option,val;
	printf("------------MAIN MENU------------\n");
	printf("1.create a list\n");
	printf("2.display\n");
	printf("3.EXIT\n");
	do{
		printf("\nEnter your option : ");
		scanf("%d",&option);
		switch(option){
			case 1 : 
				printf("Enter the data : ");
				scanf("%d",&val);
				start=create_hll(start,val);
				break;
			case 2 :
				start=display(start);
				break;		
		}
	}while(option!=3);
	return 0;
}
struct node *create_hll(struct node *start,int data){
	struct node *ptr,*new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=NULL;
	
	if(start==NULL){
		start=(struct node *)malloc(sizeof(struct node));
		start->next=new_node;
	}else{
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=new_node;
	}
	return start;
}
struct node *display(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL){
		printf(" %d ",ptr->data);
		ptr=ptr->next;
	}
	return start;
}
