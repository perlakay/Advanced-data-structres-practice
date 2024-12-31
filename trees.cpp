#include <iostream>
using namespace std;

//real life ex of trees, is like a folder woth folders with files, or a family tree
//it allows you to orgnazie you data 

//root noed are nodes that dont have parents, and leaf nodes are nodes that dont have children

//types of trees:
//1. regular tree, fluctuating amount of children
//2. binary tree, has paretn child relationship, but each parent can have no more than 2 child nodes
//3. binary search tree same as binary tree, but the data is organized in a very spcific way, ex. the root has a value of 30, the left child has a vlaue thats lower than the parent and thr right side has a vlue higher than the parent 


struct Node{
    int data;
    Node* left; //left child
    Node* right;//right child 
};

Node* createNode(int data){//returns a Node pointer bec its creating a new node 
//4 steps, create new node, set data, set pointers, we need to return a reference to the created node 
    Node* newNode = new Node;
    newNode -> data = data;
    newNode -> left = newNode -> right = nullptr; //sets both as nullptr bec its the only node right nwo 
    return newNode; //whoever invokes teh function will recoeve a reference to the new Node 

}

int main(){

    //each node has 3 parts, data, left child pointer, and right child pointer
    Node* root = createNode(1);

    root -> left = createNode(2);
    root -> right = createNode(3);
    root -> left -> left = createNode(4);



}