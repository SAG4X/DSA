#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node *start=NULL;
struct node *create_list(struct node* );
struct node *display(struct node*);
struct node *insert_beg(struct node*);
struct node *insert_end(struct node*);
struct node *delete_beg(struct node*);
struct node *delete_end(struct node*);
struct node *delete_after(struct node*);

int main(){
	int option,num;
	printf("----------MAIN MENU------------\n");
	printf("1.Create a list\n");
	printf("2.display the list\n");
	printf("3.insert a node at the beginning\n");
	printf("4.insert a node at the end\n");
	printf("5.delete a node at the beginning\n");
	printf("6.delete a node at the end\n");
	printf("7.delete a node after a given node\n");
	printf("8.delete the entire list\n");
	printf("-1.EXIT\n");
	do{
		printf("\nInput your option : ");
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
			case 5 :start=delete_beg(start);
					break;
			case 6 :start=delete_end(start);
					break;
			case 7 :start=delete_after(start);
					break;										
		}
	}while(option!=-1);
	return 0;
}
struct node *create_list(struct node *start){
	struct node *new_node, *ptr;
	int num;
	printf("\nEnter -1 to end");
	printf("\nEnter the data : ");
	scanf("%d",&num);
	while(num!=-1){
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = num;
		if(start==NULL){
			new_node->next = new_node;
			start = new_node;
		}else{
			ptr=start;
			while(ptr->next != start)
				ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=start;
		}
		printf("\nEnter the data : ");
		scanf("%d",&num);
	}
	return start;
}
struct node *display(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr->next != start){
		printf("\t %d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\t %d ",ptr->data);
	return start;
}
struct node *insert_beg(struct node *start){
	struct node *new_node,*ptr;
	int num;
	printf("\nEnter the data : ");
	scanf("%d",&num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->next != start){
		ptr= ptr->next;
	}
	ptr->next=new_node;
	new_node->next=start;
	start=new_node;//only change with respect to the insert_end
	return start;
}
struct node *insert_end(struct node *start){
	struct node *new_node,*ptr;
	int num;
	printf("\nEnter the data : ");
	scanf("%d",&num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->next != start){
		ptr= ptr->next;
	}
	ptr->next=new_node;
	new_node->next=start;
	return start;
}
struct node *delete_beg(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr->next != start){
		ptr=ptr->next;
	}
	ptr->next=start->next;
	free(start);
	start=ptr->next;
	return start;
}
struct node *delete_end(struct node *start){
	struct node *ptr,*preptr;
	ptr=start;
	while(ptr->next != start){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}
struct node *delete_after(struct node *start){
	struct node *ptr,*preptr;
	int val;
	printf("\nEnter the value after which the node has to deleted : ");
	scanf("%d",&val);
	ptr=start;
	preptr=ptr;
	while(preptr->data != val){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next = ptr->next;
	if(ptr==start)
		preptr->next=ptr->next;
	free(ptr);	
	return start;
}
