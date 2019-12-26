#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *tree;
void create_tree(struct node *);
struct node *insertElement(struct node *,int );
struct node *inorderTraversal(struct node *);
void preorderTraversal(struct node *);
struct node *postorderTraversal(struct node *);
struct node *findSmallestElement(struct node *);
struct node *findLargestElement(struct node *);
struct node *deleteElement(struct node * ,int );
int totalnodes(struct node *);
int totalExternalNodes(struct node *);
int totalInternalNodes(struct node *);
int height(struct node *);
struct node *mirrorImage(struct node *);
struct node *deleteTree(struct node *);
int getHeight(struct node* start) 
{ 
	struct node *root=start;
    if (root->left==NULL && root->right==NULL)  
       return 0;
    else if(root->left==NULL || root->right==NULL)
        return 1;    
   else 
   { 
       /* compute the depth of each subtree */
       int lDepth = 1+getHeight(root->left); 
       int rDepth = 1+getHeight(root->right); 
  
       /* use the larger one */
       if (lDepth >= rDepth)  
           return(lDepth-1); 
       else {
           return(rDepth-1);
           } 
   } 
}



int main(){
	int option,val;
	struct node *ptr;
	printf("---------MAIN OPERATION--------------\n");
	printf("1.insert node\n.display\n2.InorderTraversal\n3.PreorderTraversal\n4.PostOrderTraversal\n5.Smallest element\n6.LargestElement\n");
	printf("7.DeleteElement\n8.TotalNodes\n9.TotalExternalnodes\n10.TotalInternalNodes\n11.height\n12.MirrorImage\n13.DeleteTree\n");
	do{
		printf("\nExit to type -1");
		printf("\nInput your option : ");
		scanf("%d",&option);
		switch(option){
		case 1 :
			printf("Enter value : ");
			scanf("%d",&val);
			tree=insertElement(tree,val);
			break;
		case 2  :
			printf("\nElements of the tree is : ");
			inorderTraversal(tree); 
			break;
		case 3  :
			printf("\nElements of the tree is : ");
			preorderTraversal(tree); 
			break;	
		case 4  :
			printf("\nElements of the tree is : ");
			postorderTraversal(tree); 
			break;	
		case 5  :
			ptr=findSmallestElement(tree);
			printf("\nSmallest element is : %d",ptr->data); 
			break;	
		case 6  :
			ptr=findLargestElement(tree);
			printf("\nLargest element is : %d",ptr->data); 
			break;
		case 7  :
			printf("\nEnter the data to delete : ");
			scanf("%d",&val);
			tree=deleteElement(tree,val);
			break;
		case 8 :
			printf("\nTotal nodes are : %d",totalnodes(tree));
			break;
		case 9 :
			printf("\nTotal external nodes : %d",totalExternalNodes(tree));
			break;
		case 10 :
			printf("\nTotal internal nodes : %d",totalInternalNodes(tree));
			break;
		case 11 :
			printf("\nHeight of the tree is  : %d",height(tree));
			break;
		case 12 :
			tree=mirrorImage(tree);
			break;
		case 13 :
			tree=deleteTree(tree);
			break;													
		}	
	}while(option != -1);
	return 0;
}
void create_tree(struct node *tree){
	tree=NULL;
}
struct node *insertElement(struct node *tree,int val){
	struct node *ptr,*nodeptr,*parentptr;
	ptr=(struct node*)malloc(sizeof(struct node*));
	ptr->data=val;
	ptr->left=NULL;
	ptr->right=NULL;
	if(tree==NULL){
		tree=ptr;
		tree->left=NULL;
		tree->right=NULL;
	}else{
		parentptr=NULL;
		nodeptr=tree;
		while(nodeptr!=NULL){
			parentptr=nodeptr;
			if(val<nodeptr->data)
				nodeptr=nodeptr->left;
			else
				nodeptr=nodeptr->right;	
		}
		if(val<parentptr->data)
			parentptr->left=ptr;
		else
			parentptr->right=ptr;		
	}
	return tree;
}
struct node *inorderTraversal(struct node *tree){
	if(tree!=NULL){
		inorderTraversal(tree->left);
		printf(" %d ",tree->data);
		inorderTraversal(tree->right);
	}
}
struct node *postorderTraversal(struct node *tree){
	if(tree!=NULL){
		postorderTraversal(tree->left);
		postorderTraversal(tree->right);
		printf(" %d ",tree->data);
	}
}
void preorderTraversal(struct node *tree){
	if(tree!=NULL){
		printf(" %d ",tree->data);
		preorderTraversal(tree->left);
		preorderTraversal(tree->right);
	}
}
struct node *findSmallestElement(struct node *tree){
	if(tree==NULL || tree->left==NULL){
		return tree;
	}else
		return findSmallestElement(tree->left);
}
struct node *findLargestElement(struct node *tree){
	if(tree==NULL || tree->right==NULL){
		return tree;
	}else
		return findLargestElement(tree->right);
}
struct node *deleteElement(struct node *tree,int val){
	struct node *cur,*parent,*suc,*psuc,*ptr;
	if(tree->left==NULL)
	{
		printf("\nThe tree is empty");
		return (tree);
	}
	parent=tree;
	cur=tree->left;
	while(cur!=NULL && val!= cur->data){
		parent = cur;
		cur=(val<cur->data)? cur->left : cur->right;
	}
	if(cur==NULL){
		printf("\nThe value to be deleted not found");
		return(tree);
	}
	if(cur->left==NULL){
		ptr=cur->right;
	}
	else if(cur->right==NULL)
		ptr=cur->right;
	else{
		psuc=cur;
		cur=cur->left;
		while(suc->left!=NULL){
			psuc=suc;
			suc=suc->right;
		}
		if(cur==psuc)
			suc->left=cur->left;
		else{
			suc->right=cur->left;
			psuc->left=suc->right;
			suc->right=cur->right;
		}
		ptr=suc;	
	}
	if(parent->left ==cur)
		parent->left=cur;	
	else
		parent->right=ptr;
	free(ptr);
	return tree;		
}
int totalnodes(struct node *tree){
	if(tree==NULL)
		return 0;
	else
		return (totalnodes(tree->left)+totalnodes(tree->right)+1);	
}
int totalExternalNodes(struct node *tree){
	if(tree==NULL)
		return 0;
	else if((tree->left==NULL) && (tree->right==NULL))
		return 1;
	else
		return totalExternalNodes(tree->left) + totalExternalNodes(tree->right);		
}
int totalInternalNodes(struct node *tree){
	if(tree==NULL || tree->left==NULL && tree->right==NULL)
		return 0;
	else
		return totalExternalNodes(tree->left) + totalExternalNodes(tree->right) + 1;
}
int height(struct node *tree){
	int heightleft,heightright;
	if(tree==NULL){
		return 0;
	}else{
		heightleft =height(tree->left);
		heightright=height(tree->right);
		if(heightleft > heightright)
			return heightleft + 1;
		else
			return heightright + 1;	
	}
}
struct node *mirrorImage(struct node *tree){
	struct node *ptr;
	if (tree != NULL)
	{
		mirrorImage(tree->left);
		mirrorImage(tree->right);
		ptr=tree->left;
		ptr->left=ptr->right;
		tree->right=ptr;
		
	}
}
struct node *deleteTree(struct node *tree){
	if(tree!=NULL){
		deleteTree(tree->left);
		deleteTree(tree->right);
		free(tree);
	}
}
