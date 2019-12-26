// insertion to the BST in C++
//object oriented program
#include <iostream> 
using namespace std; 
  
class BST 
{ 
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
  

int main() 
{ 
    BST b, *root = NULL; 
    root = b.Insert(root, 60); 
    b.Insert(root, 20); 
    b.Insert(root, 100); 
    b.Insert(root, 120); 
    b.Insert(root, 80); 
    
    //inserting 70 to BST
	b.Insert(root, 70);  
    
  
	cout<<"Inorder Traversal : ";
    b.Inorder(root); 
    return 0; 
} 
