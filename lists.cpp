#include <iostream>
#include <list>
using namespace std;


//what are conatainers? 
//like a box to store data 

int main(){

    list<int> myList; //list is dynamic, so you dont need to spcify size

    //pushback adds at the ned, pushfront adds at the beggining 

    myList.push_back(10);
    myList.push_back(20);

    myList.push_front(30);

    myList.erase(myList.begin());//paramter is a pointer to the item you want to delete 
    //myList.begin() is a pointer to the first element 

    //print data in the list 
    //each elemnt of a list is called a node, ot iterate through the list we use an iteratoe which is a pointer that points at the current element

    for(list<int>::iterator it= myList.begin(); it!=myList.end(); it++){//decalre and initiazle an iterator called it to point at myList and go thorugh 
    //the list until it hits the end of the list and increments by one 
        cout << *it << endl; //we need to dereference it to print the data

    }



}