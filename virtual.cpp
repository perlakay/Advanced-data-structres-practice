#include <iostream>
using namespace std;


class instrument{
public:
    virtual void makesound(){
        cout << "playing" << endl;
    }

}; 

// 'virtual' means that is there is another instance or definition for t
//a function that is in both the base class and deroved class
//the version in the derived class will be the one implemented


class acordion:public instrument { //inherits from base class
    void makesound(){
        cout << "acordion playing" << endl;
    }
};

int main(){

 instrument i1;
 i1.makesound();

instrument*i2 = new acordion();
i2->makesound();


}
