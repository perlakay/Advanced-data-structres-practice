#include <iostream>
using namespace std;

//doubly linked lists can be traversed in two directions
//you can add nodes in 4 pleaces, begginin, end, beofre and after a node. in singly linked lists you can only add after a node bec  theres no pointer to the previous node
//but they take more space 

class Node{ //you can also use a strcut bec then its public by deault 
public:
    int value;
    Node* next;
    Node* previous;

};

//traverse the list backwards and froward

void printForward(Node*head){//we take the head node as a parameter beacsue we start from there to traverse 
    Node* traverser = head; //starts at the front 
    while(traverser != nullptr){
        cout << traverser->value << endl;
        traverser = traverser -> next; //move to the next node 
    }

}

void printForward(Node*tail){//we take the head node as a parameter beacsue we start from there to traverse 
    Node* traverser = tail; //starts at the front 
    while(traverser != nullptr){
        cout << traverser->value << endl;
        traverser = traverser -> previous; //move to the previous node 
    }

}


int main(){

    Node* head;
    Node* tail;
    //we need a head and tail first for our list 

    //4 steps for adding the first node
    //1. create node
    //2. set value 
    //3.take care of pointers
    //4.if its the only element we need to set it as head and tail 

    Node* node = new Node(); //why Node*? and not Node, linked lists have pointer beacsue they are dynamically allocated 
    //in order to dynamically allocate you need pointers 

    node->value = 4;

    //set next and prev pointers 
    node-> next = nullptr;
    node -> previous = nullptr;

    //set node as both head and tail bec its the only elemnt 
    head = node;
    tail = node;

    //5 steps for adding the second node 
    //1. create new node
    //2. set value 
    //3. take care of pointers 
    //4. prevous node needs to point to our new node
    //5. new node needs to become the tail 

    //we already added the variable nod einto our list so we dont need it anymore, so we can resue it 

    node = new Node(); //however sinece node was already created, we can just reassign it instead of creating a new node from scratch 
    node -> value = 5;
    node -> next = nullptr;
    node -> previous = tail;  //its added after the tail
    tail -> next = node; // we tell the tail, hey someone comes after you now 

    tail = node; //this node is now the last node 

    //to add the third node you can copy all the code from adding teh seocnd one beacsue its all the same, just change the value 





}