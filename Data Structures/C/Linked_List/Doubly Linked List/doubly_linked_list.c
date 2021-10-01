#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
	struct node *next;
	int data;
	struct node *prev;
};

struct node *start=NULL;
struct node *create_list(struct node* );
struct node *display(struct node*);
struct node *insert_beg(struct node*);
struct node *insert_end(struct node*);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node*);
struct node *delete_end(struct node*);
struct node *delete_after(struct node*);
struct node *delete_before(struct node *);
struct node *delete_list(struct node*);

int main(){
	int option;
	//clrscr();
	printf("----------MAIN MENU------------\n");
	printf("1.Create a list\n");
	printf("2.display the list\n");
	printf("3.insert a node at the beginning\n");
	printf("4.insert a node at the end\n");
	printf("5.insert a node before the given node\n");
	printf("6.insert a node after the given node\n");
	printf("7.delete a node at the beginning\n");
	printf("8.delete a node at the end\n");
	printf("9.delete a node before a given node\n");
	printf("10.delete a node after a given node\n");
	printf("11.delete the entire list\n");
	printf("12.EXIT\n");
	
	do{
		printf("\nEnter your option : ");
		scanf("%d",&option);
		switch(option){
			case 1 :start=create_list(start);
					printf("CIRCULAR LINKED LIST CREATED\n");
					break;
			case 2 :start=display(start);
					break;
			case 3 :start=insert_beg(start);
					break;
			case 4 :start=insert_end(start);
					break;
			case 5 :start =insert_before(start);
					break;		
			case 6 :start=insert_after(start);
					break;
			case 7 :start=delete_beg(start);
					break;
			case 8 :start=delete_end(start);
					break;		
			case 9 :start=delete_before(start);
					break;		
			case 10 :start=delete_after(start);
					break;		
			case 11 :start=delete_list(start);
					printf("Doubly Link List is Deleted\n");
					break;								
		}	
	}while(option !=12);
	getch();
	return 0;
}
struct node *create_list(struct node *start){
	struct node *ptr,*new_node;
	int num;
	printf("\nEnter -1 to exit : ");
	printf("\nEnter the data : ");
	scanf("%d",&num);
	while(num !=-1){
		if(start==NULL){
			new_node=(struct node*)malloc(sizeof(struct node));
			new_node->prev=NULL;
			new_node->data=num;
			new_node->next=NULL;
			start=new_node;
			
		}else{
			ptr=start;
			new_node=(struct node*)malloc(sizeof(struct node));
			new_node->data=num;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->prev=ptr;
			new_node->next=NULL;
		}
		printf("\nEnter the data : ");
		scanf("%d",&num);
	}
	return start;
}
struct node *display(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL){
		printf("\t %d",ptr->data);
		ptr=ptr->next;
	}
	return start;
}
struct node *insert_beg(struct node *start){
	struct node *new_node;
	int num;
	printf("\nEnter the data : ");
	scanf("%d",&num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	start->prev=new_node;
	new_node->next=start;
	new_node->prev=NULL;
	start=new_node;
	return start;
}
struct node *insert_end(struct node *start){
	struct node *new_node,*ptr;
	int num;
	printf("\nEnter the data : ");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->prev=ptr;
	new_node->next=NULL;
	return start;
}
struct node *insert_before(struct node *start){
	struct node *ptr,*preptr,*new_node;
	int val,pos;
	if(start==NULL){
		insert_beg(start);
	}else{
		printf("Enter the data : ");
		scanf("%d",&val);
		printf("Give after which node should insert : ");
		scanf("%d",&pos);
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=val;
		new_node->prev=NULL;
		new_node->next=NULL;
		ptr=start;
		preptr=ptr;
		while(ptr->data!=pos){
			
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=new_node;
		new_node->prev=ptr->prev;
		new_node->next=ptr;
		ptr->prev=new_node;
	return start;
	}
}
struct node *insert_after(struct node *start){
	
}
struct node *delete_beg(struct node *start){
	struct node *ptr;
	ptr=start;
	start=start->next;
	start->prev=NULL;//special condition in doubly ll
	free(ptr);
	return start;
}
struct node *delete_end(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	ptr->prev->next=NULL;
	free(ptr);
	return start;	
	}
}
struct node *delete_after(struct node *start){
	struct node *ptr,*temp;
	int val;
	printf("Enter the which after node should delete : ");
	scanf("%d",&val);
	ptr=start;
	while(ptr->data!=val){
		ptr=ptr->next;
	}
	temp=ptr->next;
	ptr->next=temp->next;
	temp->next->prev=ptr;
	free(temp);
	return start;	
}
struct node *delete_before(struct node *start){
	struct node *ptr,*temp;
	int val;
	printf("Enter which before node should delete : ");
	scanf("%d",&val);
	ptr=start;
	while(ptr->data!=val)
		ptr=ptr->next;
	temp=ptr->prev;
	if(temp==start)
		start=delete_beg(start);
	else{
		ptr->prev=temp->prev;
		temp->prev->next=ptr;
		
	}	
	free(temp);
	return start;		
}
struct node *delete_list(struct node *start){
	while(start!=NULL)
		start=delete_beg(start);
	return start;	
}

