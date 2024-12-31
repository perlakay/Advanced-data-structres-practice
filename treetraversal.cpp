#include <iostream>
using namespace std;

//two tree traversal algorithms 
//BFS first seachred the width DFS starts with depth 
//refer to video for visualization of how they work

//here we focus on DFS
//there are 3

//preorder, inrdoer, and postorder
//preorder, print data left child roiht child
//inorder left child print data right child 
//postorder lieft child, right child, print data 


struct Node{
    int data;
    Node* left; //left child
    Node* right;//right child 
};

Node* createNode(int data){ 
    Node* newNode = new Node;
    newNode -> data = data;
    newNode -> left = newNode -> right = nullptr; //sets both as nullptr bec its the only node right nwo 
    return newNode; //whoever invokes teh function will recoeve a reference to the new Node 

}
//its a recursive function , which means it will keep going until it hist the base case 
//preorder
void printTree(Node* root){
    if(root == nullptr) return; //base case 
    
    cout << root -> data << endl; //print data
    printTree(root->left);//calls itself for the left child
    printTree(root->right);//calls itself for the right child 
}

void PrintTrees(Node* root){
    if(root == nullptr) return; //base case 
    
    PrintTrees(root->left);
    cout << root -> data << endl; 
    PrintTrees(root->right);
}

void PrintT(Node* root){
    if(root == nullptr) return; //base case 
    
    PrintT(root->left);
    PrintT(root->right);
    cout << root -> data << endl; 
}



int main(){

    //each node has 3 parts, data, left child pointer, and right child pointer
    Node* root = createNode(1);

    root -> left = createNode(2);
    root -> right = createNode(3);

    root -> left -> left = createNode(4);
    root -> left -> right = createNode(5);
    root -> right -> right = createNode(6);
    root -> right -> left = createNode(7);

    root -> left -> right -> left  = createNode(9);
    root -> right -> right -> left = createNode(15);

    
    printTree(root);

}