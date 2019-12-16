#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//-----------------LINKED LIST TRAVERSING AND CREATING LIST---------------------------
//DATA node 
struct node{
	int data;
	struct node *next;
};
//linked list assigning to start
struct node *start=NULL;


void create_list(int n);
int print_numbers(struct node *);
struct node *getnode();
int search_element(struct node *);

int main(){
	int nodes,i;
	printf("Enter the num of nodes : ");
	scanf("%d",&nodes);
	//create the list
	create_list(nodes);
	//print the list
	print_numbers(start);
	//search the element
	search_element(start);
	return 0;
}
struct node *getnode(){
	struct node* newnode;
	newnode =(struct node*)malloc(sizeof(struct node));
	printf("\tEnter data : ");
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	return newnode;
}
void create_list(int n){
	int t,i;
	struct node *newnode,*temp;
	
	for(i=0;i<n;i++){
		newnode=getnode();
		if(start==NULL){
			start = newnode;
		}else{
			temp=start;
			while(temp->next != NULL){
				temp=temp->next;
			}temp->next =newnode;
		}
	}
	//return start;
}
int print_numbers(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL){
		printf(" %d ",ptr->data);
		ptr=ptr->next;
	}
	
}

int search_element(struct node *start){
	struct node *ptr;
	int data;
	printf("\n\t Input which to search : ");
	scanf("%d",&data);
	ptr=start;
	while(ptr!=NULL){
		if(ptr->data=data){
			printf(" %d search success\n",data);
			break;
		}
		ptr=ptr->next;	
	}
}
