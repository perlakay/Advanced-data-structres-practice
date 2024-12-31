#include <iostream>
using namespace std;


class instrument{
public:
    virtual void makesound() = 0; 
    
    //this makes the function a pure virtual finction
    //it also makes the class an abstract class, because it has at least one pure virtual function
    // a pure virtial ffunction means that it will force each dervived class to have its own implementation of the function, 
    //for example here, its makesound, so each derived class
    // will need to have its own implementatino of the makesound function

}; 

// 'virtual' means that is there is another instance or definition for t
//a function that is in both the base class and deroved class
//the version in the derived class will be the one implemented


class acordion:public instrument { //inherits from base class
    void makesound(){
        cout << "acordion playing" << endl;
    }
};

class piano:public instrument{
    void makesound(){
        cout << "piano playing" << endl;
    }
};

int main(){

instrument*i2 = new acordion();
i2->makesound();

instrument*i3 = new piano();
i3->makesound();

instrument* instruments[2]={i2,i3};
//make an array of the pointers that point to the instrument dervived classes' objects
//(piano and acordion)

//now make them all play

for(int i=0;i,2;i++){
    instruments[i]->makesound();
}

}