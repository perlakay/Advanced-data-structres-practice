#include <iostream>
#include <map>
#include <string>
#include <list>
using namespace std;


int main(){
//a pokedex
    
    map<string, list<string>> pokedex; //associate a string with a list of strings 

    list<string> pikachuAttacks{"thunder shock","tail whip","quick attack"};
    list<string> charmanderAttacks{"flame thrower","scary face"};
    list<string> chikoritaAttacks{"razor leaf","poison powder"};
    
    pokedex.insert(pair<string, list<string>>("Pikachu",pikachuAttacks ));
    pokedex.insert(pair<string, list<string>>("Charmander",charmanderAttacks ));
    pokedex.insert(pair<string, list<string>>("Chikorita",chikoritaAttacks ));

    
    for(auto pair : pokedex){
        cout << pair.first << "-";
    }
        for(auto attack : pair.second){//attack is what we will call the seocnd half of the pair, you can call it move or whatever 
            cout << attack << "-";


        cout << endl;
        }

    }
    



