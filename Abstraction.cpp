#include <iostream>
using namespace std;

//abstraction means showing the important info and not showing the details
//hide complex details behind simple procedures 

//abstract class is a class that has at least on pure virtual function

class smartphone{
public:
    virtual void takeAselfie() = 0; //this is a pure virtual function, beacsue it will force each dervived class to implement this function in its own way
    //this is abstraction, it shows the simple functionalities, without showing all the logic behind it, whoever wants to make a smartphone, needs to implement the functions aka derived classes will need to impklement 
    virtual void makeCall() = 0;

};

class Andriod:public smartphone{
public:
    void takeAselfie(){
        cout << "Andriod took a selfie\n"; 
    }

    void makeCall(){
        cout << "Andriod makes a call\n"; 
    }

};

class iphone:public smartphone{
public:
    void takeAselfie(){
        cout << "iphone took a selfie\n"; 
    }

    void makeCall(){
        cout << "iphone makes a call\n"; 
    }
};


 int main(){

smartphone * s1 = new Andriod(); //you can make a base class pointer, point to a derived class object 
s1->takeAselfie(); //use the -> to acess memebrs of a class when using pointers 

smartphone * i1 = new iphone();
i1->takeAselfie();

s1->makeCall();

i1->makeCall();

Andriod phone;
phone.takeAselfie();


}

