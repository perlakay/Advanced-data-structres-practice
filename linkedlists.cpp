#include <iostream>
using namespace std;

//linked lists you can add new elemenst but random acessing is not allowed becasue you each elemnst points to the one after it,
//so in order to tte to the fourth elemnst you need to move thourgh the list in order 
//so acessing elements is slower than arrays bec they have fixed size 
//linkedlists use more memeory bec its stores the value and pointer vs. an array which just stored the vlaue

//you cant represent an elemnst of a linked list with a built in data type, so you need to create your own 
//you need a class to represent elemenst of a link list, thats what the node classes are for 

class Node{
public: // we need to acess the members outside the class so it needs to be public 
    //we need to 2 pieces if teh node, value and pointer to next eleemnt 
    int value;
    Node * next; //pointer to the next node 
}; // this represents one elemnet in the linked list 

//function to print elemnst of the list;

void printList(Node*n){//we passed a node pointer, aka head, so we need to recive it as a parameter, here we will call it n, like any other function we give the parameter an overarching variable name for an object of that type 
    //we only pass a pointer becasue the object of the node class we created was a pointer, so in essence we are passing the entire object
    //we need to pass the first element so that we can traverse the list, mno matter how many elemnst the list contains, we only need the first beacseu each ine points to the next so we only need the starting pint 

    while (n!=NULL){ 
        //first we need to print value of the current elemnt
        //then move to the next element 
        cout << n->value << endl;
        n = n->next; //move to next element 
    }

}

int linkedlist(){
//now we want to create three elemnst in the list 

//pointer to first elemnst 
    Node * head = new Node(); //allocates space for new node not assignong values 
    Node * second = new Node();
    Node * third = new Node();

    //now we want to assign values and pointers to the next elemnt

    //link the list:

    head->value = 1; //value is the variable from the Node class
    second->value = 2; // the -> is like the . in classes instead of acessing member variables/function like head.value, when working with pointer we say head->value
    third -> value = 3; //this just assigns values, but we still need to link the list with pointers that point to the next element

    head-> next = second; // next is defined in the node class like value
    second -> next = third;
    third ->next = NULL; //thirs is the last elemnt 

    //acessing elements:
    printList(head); //pass head elemnt to the function, here you pass a node pointer so the function needs to revive a nod epointer 









}

