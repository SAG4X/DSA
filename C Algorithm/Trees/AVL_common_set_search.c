/*
----------------------Methodology---------------------------
i/ First input the size of the Set A 

ii/ Insert the elements into a AVL Tree (mlogm)

iii/Then we input our second Sea B to an array (we can put it to AVL too but it not efficient when searching is done)

iv/Then search one by one from the array elments in the AVL tree

v/ if the output returns 1 and flag is wave then it true then its flase




*/

#include<stdio.h> 
#include<stdlib.h> 
//--------------------------- Tree one AVL--------------------------//
// An AVL tree node 
struct vertex 
{ 
    int data; 
    int height;//balance factor either -1,0,1 is acceptable
    struct vertex *left; 
    struct vertex *right; 
     
}; 

struct vertex* newNode(int key){ 
    struct vertex* node = (struct vertex*) malloc(sizeof(struct vertex)); 
    node->data   = key; 
    node->left   = NULL; 
    node->right  = NULL; 
    node->height = 1;  
    return(node); 
} 
 
struct vertex *rightRotate(struct vertex *y) 
{ 
    struct vertex *x = y->left; 
    struct vertex *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
  
    // Return new root 
    return x; 
} 
   
struct vertex *leftRotate(struct vertex *x) 
{ 
    struct vertex *y = x->right; 
    struct vertex *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    // Return new root 
    return y; 
} 
 
int height(struct vertex *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 
  
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
  
// Get Balance factor of node N 
int getBalance(struct vertex *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right);
	//return N->left->height - N->right->height; 
} 
  
struct vertex* insert(struct vertex* node, int key) 
{ 
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return(newNode(key)); 
  
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key); 
    else // Equal keys are not allowed in BST 
        return node; 
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
  
    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
    int balance = getBalance(node); 
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && key < node->left->data) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->data) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->data) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->data) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 

    return node; 
} 


// inorder traversal for AVL
void inorder(struct vertex *root) { 
    if(root != NULL) { 
        inorder(root->left); 
        printf("%d ", root->data);
		inorder(root->right); 
    } 
} 
//Searching the element
//-----------------------search method--------------------------//
int search(struct vertex* root, int key) 
{ 
    
	if(root==NULL){
		return 0;
	} 
    if (root->data == key) 
    	return 1; 
     

    if (root->data < key){
    	return search(root->right, key); 
	}else{
		return search(root->left, key); 
	}

}  

//---------------------------------------------------------------------//


int main() 
{ 
  int i,j=0,n1,n2,val,flag = 0;
  struct vertex *root1 = NULL;
  struct vertex *root2 = NULL;
  //serach array
  int temp[25]={0};
  
  //Set 1
  printf("Set A\nInsert the number of nodes in AVL Tree 1 : "); 
  scanf("%d",&n1);
  
  for(i=0;i<n1;i++){
	printf("Insert the node value  : ");
	scanf("%d",&val);
	root1 = insert(root1,val);
  }
  //Set 2
  printf("Set B\nInsert the number of element in Set B : "); 
  scanf("%d",&n2);
  
  for(i=0;i<n2;i++){
	printf("Insert the node value  : ");
	scanf("%d",&val);
	temp[j++] = val;
  }
  
  //Traversal
  printf("Inorder traversal AVL tree : "); 
  inorder(root1);
  
  
  //serach algorithm(QUESTION)
  for(i=0;i<n2;i++){
  	if(search(root1,temp[i]) && flag == 0){
  		//complexity of the condition equals to (mlogm +nlogn)
  		//if there are common elements the condition is true
  		printf("\ntrue");
  		flag = 1;
	}
  } 
  if(flag==0){
  	//if the condition is false there are not common data
  	printf("\nfalse");
  }
  
  return 0; 
} 
