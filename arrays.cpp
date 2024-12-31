#include <iostream>
using namespace std;

//what is an array?
//ti simplify data collection like any other data structure


int main(){

//first specify the type of array, which is the type of whats in the array
//then specify name and size
//to assign values to the elements use curly brackets
int size; 
cin >> size;
float monthArray[size]; //{100,220,300,0,200,250};
//also you dont need to initilaize elemts of an array when you create the array, you can do that later on 

/*cout << "enter amount:" << endl;
cin >> monthArray[0]; //this allows the user to set the elemts value 
monthArray[1] = 300;
monthArray[2] = 200;
monthArray[3] = 400;
monthArray[4] = 10;
monthArray[5] = 0;*/ //this code isnt optimal, so we can use a loop for better efficiancy 
float total = 0; 

for(int i=0; i < 5; i++){ //while i is less than the max index of our array with 6 elemenst adn starts at 0
    cout << "enter amount for month" << i + 1 << endl; //outputs strating at 1 instead of zero, so its more user friendly 
    cin >> monthArray[i]; 
    total+= monthArray[i]; //adds the value to grand total 
}

//to acess elements you use the name of the array and the index - index starts at 0
/*float total = monthArray[0] +monthArray[1]+monthArray[2]+monthArray[3]+monthArray[4]+monthArray[5];*/
float average = total /6;  
float inTwoYears = average *24; //24 months in 2 years

//can you have elements of different types in one array?
//no you can't 
//also you dont need to initilaize elemts of an array when you create the array, you can do that later on 

//an array is a type of collection which stores data in a continues chunck of memeory, its stores elements one after another
//you cant add elemnst in the middle ,beggining or ned, you would need a new array 
//the advantage to continues memeory is that acessing elemnst is faster beacsuse its stored continueously, not like a linked list which uses pointers 


    



}

