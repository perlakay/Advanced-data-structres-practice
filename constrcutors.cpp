#include <iostream>
using namespace std;
#include <list>

//the problem here is that right now each time we want to create
//another instance of the class we have to copy all the code in the main file
//thats where constrcutors come in

class YouTubeChannel {
    
public:
    string Name;
    string OwnerName;
    int SubscriberCount;
    list<string> PublishedVideoTitles;
    
//a constrcutor is a special methos invoked each time you create an object of the class
//2 rules, constrcutor has the same name as the class, and no return type 
    YouTubeChannel(string name , string ownername){
        //we want to recive 2 parameters, one for name and one for ownername 
    Name = name; //here we say the parameter name will be equal to the sttribute Name defined in the class
    OwnerName = ownername; 
    SubscriberCount = 0; //we dont need to pass this value, becasue a blank channel has no subscribers 

    }
    //now instead of having to print everythng out we can use a class method aka getters 
    void GetInfo(){
        cout << "Name" << Name << endl;
        cout << "Owner name" << OwnerName << endl;
        cout << "Subscribers" << SubscriberCount << endl;
        cout << "Videos" << endl;
        for(string videoTitle: PublishedVideoTitles){
            cout<< videoTitle << endl;
}//we dont need the ytChannel. anymore, becasue we are in the class itself 
    }
};

int main(){
 
YouTubeChannel ytChannel("Perly's art", "Perly");
//now we can just use one line to set everything up sintead of seprate lines like in the previous file


//nw we want to add videos
ytChannel.PublishedVideoTitles.push_back("art1");
//the push back medthod adds thinsg to the list 

//invoke getter method 
ytChannel.GetInfo();


}

