#include <iostream>
#include <stack>
using namespace std;


//stack uses LIFO 


//5 functions for stack
//empty, size, top - gets top elemtn , push - adds, pop - remove elemenst 

void printstack(stack<int> stack){//takes a stack of integers as paramter 
//retursn top elemnt and then rmeoves it so that the next element is the top and then it will print the top elelmtn until the stack is empty 

    while (!stack.empty()){//while stack is not empty
        cout << stack.top() << endl;
        stack.pop();
        
    }
}

int main(){

    //empty,size,push,top,pop
    stack<int>numbersStack;

     //add elemenst - push takes an int here bec the stack is of type int  
    numbersStack.push(1); //adds 1 to the top of the stack 
    numbersStack.push(2);

    numbersStack.pop(); //removes top element
    

    if(numbersStack.empty())
        cout<< "stack is empty" << endl;
    else    
        cout << "not empty" << endl;

    cout << "size" << numbersStack.size() << endl;
    //outputs size of the stack


   



}