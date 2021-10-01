#include<iostream>

using namespace std;


class BST 
{ 
	public:
    int data; 
    BST *left, *right; 
  
    public: 
      
    // Default constructor and definition
    BST(){
    	data = 0;
    	left = NULL;
    	right = NULL;
	}
      
    // Parameterized constructor and definition 
    BST(int value){
    	data = value; 
    	left = right = NULL; 
	}
      
    // Insert function. 
    BST* Insert(BST *, int); 
      
    // Inorder traversal. 
    void Inorder(BST *); 
}; 

// Insert function definition. 
BST* BST :: Insert(BST *root, int value) 
{ 
    if(!root) 
    { 
        // Insert the first node, if root is NULL. 
        return new BST(value); 
    } 
  
    // Insert data. 
    if(value > root->data) 
    { 
        // Insert right node data, if the 'value' 
        // to be inserted is greater than 'root' node data. 
          
        // Process right nodes. 
        root->right = Insert(root->right, value); 
    } 
    else
    { 
        // Insert left node data, if the 'value'  
        // to be inserted is greater than 'root' node data. 
          
        // Process left nodes. 
        root->left = Insert(root->left, value); 
    } 
      
    // Return 'root' node, after insertion. 
    return root; 
} 
  
// Inorder traversal function. 
// This gives data in sorted order. 
void BST :: Inorder(BST *root) 
{ 
    if(!root) 
    { 
        return; 
    } 
    
    Inorder(root->left); 
    cout << root->data <<" "; 
    Inorder(root->right); 
} 

//Implementation of search function
int search(BST *root, int key) 
{ 
    // Base Cases: root is null or node's value is present at root 
    if (root == NULL || root->data == key) 
       return 1; 
     
    // value of the node is greater than root's key 
    if (root->data < key) 
       return search(root->right, key); 
  
    // value of the node is smaller than root's key 
    return search(root->left, key); 
} 


int main() 
{ 
    BST b, *root = NULL; 
    //inserting the given nodes to the tree
    root = b.Insert(root, 15); 
    b.Insert(root, 10); 
    b.Insert(root, 20); 
    b.Insert(root, 12); 
    b.Insert(root, 8); 
	b.Insert(root, 18);
    b.Insert(root, 25);
    b.Insert(root, 16);
    b.Insert(root, 19);
    b.Insert(root, 30);
  
	//Search the node 16
	cout<<"Searching of node 16"<<endl;
	if(search(root,16)){
		cout<<"Search is success";
	}else{
		cout<<"Search is not success";
	}
    return 0; 
} 
