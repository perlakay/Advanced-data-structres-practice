#include <iostream>
using namespace std;


class User{

public:
    string FirstName;
    string LastName;
    int Age;
    string Email;
    
    //constrcutor rules:
    //constructors need to have the same name as the class 
    //they dont have a return type 
    //constructors need to be public 
    //default constrcutor doesnt have any parametrs
    //if you dont create a default constrcutor yourself, C++ creates one for you
    //default constrcutors are invoked when you create an object of the class
    //when you create a constrcutor, you lose the defaul one provided by C==

//User(){} empty default constrcutor looks like this 

//default constrcutor with some set values
    User(){
        FirstName = "n";
        LastName = "ln";
        Age = 0;
        Email = "none";
    } 

    //parameterized constrcutor 
    User(string fname, string lname, int age){
        FirstName = "fname";
        LastName = "lname";
        Age = age;
        Email = fname + lname + "@mail.com"; //generates email based on paramters 

    }



};
//non member global function 
void GetUserinfo(User u){

    cout << "FirstName: " << u.FirstName << endl;
    cout << "LastName: " << u.LastName << endl;
    cout << "Age: " << u.Age << endl;
    cout << "Email: " << u.Email << endl;
    
}

int main(){

    //User user1;
    //without a constrcutir you would need to manually assign values to each property
    //user1.Age = 10;

    User user1("Perly", "D", 20);
    //you can choose which constrcutor you want to incoke, but only one cane be invoked 
    GetUserinfo(user1);


}