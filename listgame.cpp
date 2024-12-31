#include <iostream>
#include <list>
using namespace std;

//we want to create a matching system so they can play fairly against each others, pros w pros etc...


void displayratings(const list<int>& playersRatings) {//takes a list as a parameter and the job of the function is to print out the list it recieves 
    for(list<int>::const_iterator it = playersRatings.begin(); it!=playersRatings.end(); it++){
        cout<<"rating: "<<*it<<endl;
          
    }
    
    //the & here means passing the origional, which makes it 
    //faster beacsue if it makes a copy, it takes time and resources
    //but if you want to make sure that it doesnt change the 
    //original, beacause you are passing the origional, you can make it a const, and use the const_iterator 
}

//function to order the players so that the ratings are pronted in order and add new players in the right spot 
//here we dont use const, beacsue the jobe of the function here is to change the original and add the new player 
void insertplayer(int newPlayerRating, list<int>& playerbyrating){ //two paramters, the new player and a list of already ordered players 
    for(list<int>::iterator it = playerbyrating.begin(); it != playerbyrating.end(); it++){
        if(*it > newPlayerRating){
            playerbyrating.insert(it, newPlayerRating);
            return;
        }
        //this if statement will see: is the current element bigger than the new one? yes, then we need to add this element in this spot so it will come right before the one bigger than it
        //this ordered the list
    }
    playerbyrating.push_back(newPlayerRating); 
    //if you iterate through the whole list, and nothing currently in the list is bigger than the new rating, then its at the end becasue its the biggest 
}

int main(){

    //initialize the list here with the ratings/skill levels  from 1-10 
    list<int> allplayers ={2,9,6,7,3,1,4,8,3,2,9}; 
    list<int> beginners; //ppl w rating 1-5
    list<int> pros; //ppl w rating 6-10

    
    //we need to iterate through the ratings list and sort them into begiinner or pros lists 

    for(list<int>::iterator it = allplayers.begin(); it!=allplayers.end(); it++){
        int rating = *it; 
        //stroes current rating iterator is pointing to, when you dereference it you get the value it 
        //points at instead of the adresss bec it is a pointer 

        if(rating>=1 && rating <=5){
            insertplayer(rating, beginners);//rating meaning the dereferences value of it at that point 
        }
        else if (rating >=6 && rating<=10){
            insertplayer(rating, pros); 
            //this calls the function to insert the players and sort them in order
        }


    cout<<"beginners: "<<endl;
    displayratings(beginners);

    cout<<"Pros: "<<endl;
    displayratings(pros);



        
    }

}