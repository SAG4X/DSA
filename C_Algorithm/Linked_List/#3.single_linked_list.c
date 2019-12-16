#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct node{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create_list(struct node*);
struct node *display(struct node*);
struct node *insert_beginning(struct node*);
struct node *insert_end(struct node*);
struct node *insert_before(struct node*);
struct node *insert_after(struct node*);
struct node *delete_beg(struct node*);
struct node *delete_end(struct node*);
struct node *delete_node(struct node*);
struct node *sort_list(struct node*);
void reversePrint(struct node *start) {
    struct node *new_node,*ptr,*preptr;
    ptr=start;
    if(start==NULL){
        return;
    }else{
    while(ptr!=NULL){
        reversePrint(ptr->next);
        printf("%d\n",ptr->data);
        return;
    }
    }

}

int main(int argc, char *argv[]){
	int option;
	printf("-------MAIN MENU-----\n");
	printf("1.create a list\n");
	printf("2.Display the list\n");
	printf("3.insert  a node at beginning\n");
	printf("4.insert a node at the end\n");
	printf("5.insert a node before a given node\n");
	printf("6.insert a node after a given node\n");
	printf("7.delete a node from the beginning\n");
	printf("8.delete a node from a end \n");
	printf("9.delete a given node\n");
	printf("10.sort the list\n");
	printf("-1.EXIT\n"); 
	do{
		printf("\nEnter your option :");
		scanf("%d",&option);
		
		switch(option){
			case 1 :
				start= create_list(start);
				printf("LINKED LIST CREATED\n");
				reversePrint(start);
				break;
			case 2 :
				start= display(start);
				break;
			case 3 :
				start= insert_beginning(start);
				break;	
			case 4 :
				start= insert_end(start);
				break;
			case 5 :
				start= insert_before(start);
				break;
			case 6 :
				start= insert_after(start);
				break;
			case 7 :
				start=delete_beg(start);
				break;
			case 8 :
				start=delete_end(start);
				break;
			case 9 :
				start= delete_node(start);
				break;
			case 10 :
				start=sort_list(start);
				break;						
		}
	}while(option!=-1);	
}
struct node *create_list(struct node *start){
	struct node *new_node,*ptr;
	int num;
	printf("Enter -1 to end\n");
	printf("Enter the data : ");
	scanf("%d",&num);
	while(num!=-1){
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node -> data=num;
		if(start==NULL){
			new_node->next=NULL;
			start=new_node;
		}else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
				ptr->next =new_node;
				new_node->next=NULL;
		}
			printf("Enter the data : ");
			scanf("%d",&num);
		
	}
	return start;
}
struct node *display(struct node *start){
	struct node *ptr;
	ptr = start;
	while(ptr != NULL){
		printf("\t %d", ptr->data);
		ptr = ptr->next;
	}
	return start;
}

struct node *insert_beginning(struct node *start){
	struct node *new_node;
	int num;
	printf("\nEnter the data : ");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node -> data =num;
	new_node -> next =start;
	start=new_node;
	return start;
}
struct node *insert_end(struct node *start){
	struct node *ptr,*new_node;
	int num;
	printf("\nEnter the data : ");
	scanf("%d",&num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node -> data=num;
	new_node -> next=NULL;
	ptr=start;
	while(ptr->next!=NULL)
		ptr = ptr->next;
		ptr->next=new_node;
		return start;
}
struct node *insert_before(struct node *start){
	struct node *ptr,*new_node,*preptr;
	int num,val;
	printf("\nEnter the data :");
	scanf("%d",&num);
	printf("Enter the value before which data has to be inserted :");
	scanf("%d",&val);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->data !=val){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next =new_node;
	new_node->next=ptr;
	return start;
}
struct node *insert_after(struct node *start){
	struct node *new_node,*ptr,*preptr;
	int num,val;
	printf("\nEnter the data : ");
	scanf("%d",&num);
	printf("Enter the value after the data has to be inserted : ");
	scanf("%d",&val);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node-> data =num;
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr -> next=new_node;
	new_node->next=ptr;
	return start;
}
struct node *delete_beg(struct node *start){
	struct node *ptr;
	ptr=start;
	start=start -> next;
	free(ptr);
	return start;
}
struct node *delete_end(struct node *start){
	struct node *ptr,*preptr;
	ptr=start;
	while(ptr->next!=NULL){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
	return start;
}
struct node *delete_node(struct node *start){
	struct node *ptr,*preptr;
	int val;
	printf("\nEnter the value of the node which has to be deleted :");
	scanf("%d",&val);
	ptr=start;
	if(ptr->data==val){
		start=delete_beg(start);
		return start;
	}else{
		while(ptr->data!=val){
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
		return start;	
	}
}
struct node *sort_list(struct node *start){
	struct node *ptr1,*ptr2;
	int temp;
	ptr1=start;
	while(ptr1->next !=NULL){
		ptr2=ptr1->next;
		while(ptr2 != NULL){
			if(ptr1->data>ptr2->data){
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}ptr2=ptr2->next;
		}
		ptr1=ptr1->next;	
	}
	return start;
}
