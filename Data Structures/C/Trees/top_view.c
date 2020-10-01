#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert(struct node* root, int data) {
	if(root == NULL) {
		struct node* node = (struct node*)malloc(sizeof(struct node));
		node->data = data;
		node->left = NULL;
        node->right = NULL;
        return node;
	  
	} else {
      	struct node* cur;
		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		}else {
            cur = insert(root->right, data);
            root->right = cur;
		}
		return root;
	}
}
struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 
//traversal
void inOrder(struct node *root){
	if(root!=NULL){
		inOrder(root->left);
		printf(" %d ",root->data);
		inOrder(root->right);
	}
}
void levelOrder( struct node *root) {
    int h = Height(root); 
    int i; 
    for (i=1; i<=h; i++) 
        printGivenLevel(root, i); 
}
void printGivenLevel(struct node* root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->data); 
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
} 
int Height(struct node *root){
	if(root==NULL){
		return 0;
	}else{
		int lh=Height(root->left);
		int rh=Height(root->right);
		if(lh>rh){
			return (lh+1);
		}else{
			return (rh+1);		
		}
	}
}
struct node *findMax(struct node *root){
	if(root==NULL || root->right==NULL)
		return root;
	else
		findMax(root->right);	
}
struct node *findMin(struct node *root){
	if(root==NULL || root->left==NULL)
		return root;
	else
		findMin(root->left);	
}
int main() {
  	struct node* root = NULL;
    int t,h,data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
    inOrder(root);
    h=Height(root);
    printf("\nHeight of Binary Tree : %d",h-1);
    
    return 0;
}

