#include <iostream>
using namespace std;

//copy constrcutors are used when you want to make a new object based off of another object that already exists
//there is a default copy constrcutors, but when you have pointers, you need a custom one 

//copy constrcutor rules:
//needs to be public 
//no return type
//same name as the class
//takes one paramter which has the same type as the class it belongs to
//so paramter type and class the constrcutor is in, must be the same 

class book{
public:
    string title;
    string author;
    int* Rates; //book ratings 
    int RatesCounter; 


    book(string t, string a){ 
        title = t;
        author = a;

        RatesCounter = 2;
        Rates = new int[RatesCounter]; 
    
        Rates[0] = 4; 
        Rates[1] = 5;

        cout << title+"constructor invoked" << endl;

    }

    ~book(){ 
        delete [] Rates; 
        Rates = nullptr; 
        cout << title+"destructor invoked" <<endl;
    }

    book(const book& original){ //object of type book called original 
        //so here we have a logical error, we want to pass by value so that we only pass a copy 
        //but in order to create a copy constrcutor, you need an existing copy constrcutor, and in order to create a copy constrcutor we need to pass the book 
        //but passing the book by value gives us an error, so we pass by reference, however this creates the possibility for someon to change the origional, becaus epassing by reference means passing the origional
        //but by setting the origional object to a constant, it cant be changed

        //we still have an error, beacsue we copy over the adress for the rates array, when the destructor gies to delet the copy, that array has already been deallocated when deleting the original so we get an error
        //so we also need to copy the rates array into a new array with a new adress 
        title = original.title;
        author = original.author;
        RatesCounter = original.RatesCounter;

        Rates = new int[RatesCounter];
        for( int i = 0; i < RatesCounter; i++){
            Rates[i] = original.Rates[i];

        }
        
        //we use a loop to copy all the leemnst in our original array into the new one 
        //this is the correct way to create a copy constrcutor 


    }

     
};

int main(){

book book1 ("harry potter" , "JK Rowling");
book book2 ("private" , "James patterson");

book book3(book2); 

//whenever a new object is created base don an existing one, its a copy constructor, not assignemnt 
//when you assign new values to an existing object, thats assignemtn

//passing by avlue invokes copy constrcutor as well

}