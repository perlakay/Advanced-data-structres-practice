#include <iostream>
#include <map>
#include <string>
using namespace std;

//a map data collection stores elemnts in key value pairs, each element consists of key and pair
//like a dictionary, apple = der Apfel in german associating string with another string
//the key is always a simple data type, but the value its associated to, can be a complex data type like a list of strings, another map, etc

int main(){

    map<string, string> myDictionary; //so you have first your type, and the type of youe value for a dictionalry, its two strings, and then you have the nsmae of the map 
    
    //insert elements:
    //using german here 
    myDictionary.insert(pair<string, string>("apple","der Apfel"));
    myDictionary.insert(pair<string, string>("banana","die Banane"));
    myDictionary.insert(pair<string, string>("orange","die orange, die apfelsine"));
    myDictionary.insert(pair<string, string>("strawberry","die erdbeere"));

    //print dictionary:

    for(auto pair:myDictionary){ // : means in 
        cout<<pair.first<< pair.second << endl; //prints the word AND its pair, the translation
    }

    //orders elements by key in ascending order, so alphabetical or for numbers, in order
    //if you dont want it to sort the elements you need to use an unordered map, just add #include <unordered_map> and change the type instead of map to unordered_map 

    //acess specific element and setting/changing values:
    myDictionary["strawberry"] = "Die erdbeere"; //you add teh key in the brackets, for maps keys need to be unique but values do not

    //function size returns size of map 
    cout << myDictionary.size() << endl;

    myDictionary.erase("apple"); //deletes elements 

    myDictionary.clear(); //clears elements 

    

}