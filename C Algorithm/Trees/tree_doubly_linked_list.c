#include <stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root;
struct node *head, *tail = NULL;

struct node *insert(int val){
	struct node *ptr,*new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=val;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}
void inOrder(struct node *root){
	if(root!=NULL){
	inOrder(root->left);
	printf(" %d ",root->data);
	inOrder(root->right);
	}
}
void convert_tree_to_dll(struct node *root){
	if(root==NULL)
		return;
	convert_tree_to_dll(root->left);
	
	if(head==NULL){
		head=tail=root;
		
	}
	else{
		tail->right=root;
		root->left=tail;
		tail=root;
	}
	convert_tree_to_dll(root->right);

}
int display(){
	struct node *ptr=head;
	if(head==NULL){
		printf("LIST IS EMPTY\n");
		return;
	}
	else{
		//ptr=root;
		printf("\nDoubly Linked List is : ");
		while(ptr!=NULL){
			printf(" %d ",ptr->data);
			ptr=ptr->right;
		}
	}	
}

int main(){
	root = insert(1);
	root->left = insert(2);
	root->right = insert(3);
	root->left->left = insert(4);
	root->left->right = insert(5);
	root->right->left = insert(6);
	root->right->right = insert(7);
	
	//inOrder(root);
	convert_tree_to_dll(root);
	display(root);
	return 0;
}
