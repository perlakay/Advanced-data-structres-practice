#include <iostream>
using namespace std;


class car{

private:
    string color;
    int year;
    string manufacturer;

public:
    string color;
    void GetInfo(car c){
        cout << "color: " << c.color << "year: " << c.year << "manufactuere: " << c.manufacturer << endl;

    }

    ostream& operator<<(car& c ){
        cout << "color:" << c.color << endl;
    } 

    car(string Cl, int y, string m){
        color = Cl;
        year = y;
        manufacturer = m;

    }




};


int main(){

car c("red",2024, "ford");


 

}
