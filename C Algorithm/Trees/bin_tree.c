#include<stdio.h>
#include<malloc.h>


struct node{

	int data;
	struct node *left;
	struct node *right;
};
	
struct node *root;

struct node *create_node(int value);
struct node *insert(struct node* root,int value);		//recursive method of inserting into tree
void search(struct node* node,int value);
int delete (struct node* node,int value);
struct node *find_max(struct node* curr);		//To find min value
void preorder(struct node* node);
void inorder(struct node* node);
void postorder(struct node* node);
		
int main(){
	
	//struct node *root=NULL;
	root=insert(root,43);
	root=insert(root,22);
	root=insert(root,32);
	root=insert(root,87);
	root=insert(root,60);
	root=insert(root,11);
	//delete(root,67);
	preorder(root);
	//delete(root,32);
	
	return 0;
}

void preorder(struct node* node){
	
	if(node==NULL){
		return;
	}
	else{
		printf("%d  ",node->data);
		preorder(node->left);
		preorder(node->right);
	}
	
}

void inorder(struct node* node){
	
	if(node==NULL){
		return;
	}
	else{
		inorder(node->left);
		printf("%d  ",node->data);
		inorder(node->right);
	}
	
}

void postorder(struct node* node){
	
	if(node==NULL){
		return;
	}
	else{
		postorder(node->left);
		postorder(node->right);
		printf("%d  ",node->data);
	}
	
}

struct node *create_node(int value){
	struct node *ptr=(struct node*)malloc(sizeof(struct node)); 			// pointer to creating new node
	
	
	if(ptr==NULL){
		printf("cannot allocate memory\n");
	}
	
	ptr->data=value;
	ptr->left=NULL;
	ptr->right=NULL;
	
	return ptr;
}

struct node *find_max(struct node* curr){
	while(curr->right!=NULL){
		curr=curr->right;
	}
	return curr;
}

struct node *insert(struct node* root,int value){
	if(root==NULL){
		root=create_node(value);
		return root;
	}

	else{
		if(value<root->data){
			root->left=insert(root->left,value);		//traverse left sub-tree
		}
		else if(value>root->data){
			root->right=insert(root->right,value);		//traverse right sub-tree
		}		
	}
	
	return root;
	
}

int delete (struct node* node,int value){
	
	struct node *parent=NULL;
	
	if(node==NULL){
		printf("Doesn't exist in tree\n");
		printf("value=%dnodedata=%d\n",value,node->data);
	}
	
	printf("value=%dnodedata=%d\n",value,node->data);
	if(value==node->data){ //have to add the cases, if the node is found
		if(node->right==NULL&& node->left==NULL){	// if there are no chldren
			printf("found both arent empty\n");
			if(root==node){ //
				
				return(root->data); 
				free(root);
			}else{
				
				return(node->data);
				free(node); 			
			} 
			
			printf("Deleted node successfully\n");
		}
		else if(node->right!=NULL && node->left!=NULL){
			printf("found both arent empty\n");		//debug
			struct node *chosen=find_max(node->left); 		//The choice to replace is the rightmost child of the left sub tree
			int chosen_value=chosen->data;
			delete(root,chosen_value);							//Delete the chosen node recursively
			
			node->data=chosen_value;						//Replace the current nodes data with the previously chosens value ;)
			
		}
		else {
			struct node *child=(node->left)? node->left:node->right;
			delete (child,value);
			//Not finished
		}
			
	}else if(value<node->data){
		printf("checking left subtree for delete\n");
		delete(node->left,value);		//traverse left sub-tree
	}
	else{
		printf("checking right subtree for delete\n");
		delete(node->right,value);
	}
		
}
