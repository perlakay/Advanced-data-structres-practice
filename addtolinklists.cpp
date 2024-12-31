#include <iostream>
using namespace std;

//how to insert nodes into linked lists

//the first way to indert an elemnt is at the beggining 

class Node{
public: 
    int value;
    Node * next; 
    }; 

void printList(Node*n){

    while (n!=NULL){ 
        cout << n->value << endl;
        n = n->next; 
    }

}

void insertAtTheFront(Node**head, int newValue){ //we need to recieve a pointer to a pointer and the new value for the new node. we pass a pointer to a pointer beacsue we need to switch th epointer head poinst to, not the value of 1 that head stores 
    //3 steps, create a new node, put in fromt of current head and move the current head to point at the new node becasue now head is second 
    
    // 1. Prepare new node:
    Node* newNode = new Node();
    newNode -> value = newValue;
 
    //2. Put in from of current head 
    newNode -> next = *head; //assign head node pointer to newNode, which makes the newNode point to the current head 

    //3. move head of the list to point to the newNode 
    *head = newNode; //make the head equal to the newNode, so this sets the newNode as the head node  
}

void insertAtTheEnd(Node** head, int newValue){
    //1. prepare new node
    Node* newNode = new Node();
    newNode -> value = newValue;
    newNode -> next = NULL; //beacsue its the last node 

    //2. if list is empty, new node is the head
    if(*head==NULL){
        *head = newNode;
        return;
    }
//When we say "the list is empty", we mean:

/*The head exists.
The head points to NULL, signifying that there are no elements yet.
For example:

Node* head = NULL;  // Head exists but points to nothing (empty list).
When you insert the first element, head will point to a node:

Node* head = new Node();
head->value = 10;
head->next = NULL;*/

    //3.find last node
    //to get to the last element you need to traverse the list starting from the first node
    Node*last = *head; //start at forst node
    while (last->next!=NULL){
        last = last -> next;//move across the list 
    }

    //4.insert new node after the last node 
    last->next = newNode; //newNode is moved to be after the last we just found with teh while loop


}

void insertAfter(Node*previous, int newValue){//insert a new node aftera specific node 
    //1.check if previous node is NULL
    if(previous == NULL){
        cout<<"previous cannot be NULL" << endl;
        return; //end function 
    }
    //2. prepare new node 
    Node* newNode = new Node();
    newNode -> value = newValue;
    //3. insert new node after previous element 
    newNode ->next = previous -> next; //sets the new node to poiont to what the previous node was pointing to, becasue if you sever the connection between nodes A and B, you will lose node B beacsue only A knwos where it is 
    //then you can set node A to point to new node, an now it goes A->newNode->B
    previous->next = newNode;


}

int linkedlist(){

    Node * head = new Node(); 
    Node * second = new Node();
    Node * third = new Node();

    head->value = 1; 
    second->value = 2; 
    third -> value = 3; 

    head -> next = second; 
    second -> next = third;
    third -> next = NULL; 

    printList(head); 
    insertAtTheFront(&head, -1);//you pass the adress of the current head, so that we can assign it to the new head?? and the new value you want to add 
    insertAtTheEnd(&head, 4);
    insertAfter(head, -1); //dont need &head beacsue were not reassigning anything, just adding a completly nee node? 

}
