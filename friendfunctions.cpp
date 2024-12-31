#include <iostream>
using namespace std;

//Friend Functions
//These functions has acess tp private and protected members of a class because of the friendship relationship

class equalateralTriangle{
//these members are private, bec members of a class are private by default 
    float a; //length of the side 
    float circumference;
    float area;

public: 
    void setA(float length){ // takes the parameter length 
        a = length;
        circumference = a*3; // we can include these here because they are all calculated from a, whihc is the input 
        //parameter here aka length 
        area = (1.73 * a * a)/4;

    }

    //friend void Printresults(equalateralTriangle); // you dont need to specify the name of the paramter, just the type here 
    //a class can have multiple freind functions 

    //you can also have a friend class 
    friend class homework;

};

//gloabal function 
//void Printresults(equalateralTriangle et){ //takes a traingle or object of the equalateralTriangle class which has attributes of circumference and area
    //cout << "circumference=" << et.circumference<<endl;
    //cout << "area=" << et.area<<endl; 
//}

class homework {
public:
    void Printresults(equalateralTriangle et){ //takes a traingle or object of the equalateralTriangle class which has attributes of circumference and area
    cout << "circumference=" << et.circumference<<endl;
    cout << "area=" << et.area<<endl; 
    }
};



int main(){

    equalateralTriangle et;
    et.setA(3);

    //Printresults(et); //you need to pass the et/object of the class as the paramter 
    //the function is not directly in the class so you dont bneed to do et.printresults to acess/invoke 

    homework math;
    math.Printresults(et);


//some tips: frindship is not mutual so we have acess to private members from the triangle class in homework but we wouldnt have acess to private members of homework in traingle 
//nor are freidns  inherited 
    

}