#include <iostream>
using namespace std;

//destructors are special functions  to clean up resources an object was using up 

class book{
public:
    string title;
    string author;
    int* Rates; //can point to an integer of the first item in a dynamic array 
    int RatesCounter; //keeps track of how mnay elements are in the dynamic array 


    book(string t, string a){ //constrcutor 
        title = t;
        author = a;

        RatesCounter = 2;
        Rates = new int[RatesCounter]; //declaring a new array of length RatesCounter (aka 2 here)
    
        Rates[0] = 4; //set the 2 values 
        Rates[1] = 5;

        cout << title+"constructor invoked" << endl;

    }

    ~book(){ //destrcutor
        delete [] Rates; //you neeed this to delet the array
        //delete Rates; will cause a memeory leak
        //why? becasue thei will only delete the value currenlty stored on rates, not the whole array 
        Rates = nullptr; //good practice to ensure pointers are null and memeory is freed properly 
        cout << title+"destructor invoked" <<endl;
    }
     
    //destructor rules:
    //you need a tilda for a destructor 
    //name needs to be the nsmae as the class
    //no return type
    //no paramters
    //needs to be a class memebr function
    //needs to be public
    //only one per class
    //the compiler knwosn how to deal with simple situations, but once you start using pointers, then you need your own destrcutor


};




int main(){

book book1 ("harry potter" , "JK Rowling");
book book2 ("private" , "James patterson");

//book book3 = book2; this will cause an error, you need copy constructors
 
}