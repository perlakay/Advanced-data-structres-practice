#include <iostream>
using namespace std;
#include <list>

class YouTubeChannel {
    
private:
    string Name;
    int SubscriberCount;
    list<string> PublishedVideoTitles;

protected://protected acess mosdifyer allows us to acess the property to be acessed by derived classes 

    string OwnerName;
public:
    YouTubeChannel(string name , string ownername){
    Name = name; 
    OwnerName = ownername; 
    SubscriberCount = 0; 
    }

    void Subscribe(){
        SubscriberCount++; 

}
    void Unsubscribe(){
        if (SubscriberCount > 0)
            SubscriberCount--; 
}

    void PublishedVideo(string title){  
        PublishedVideoTitles.push_back(title);
    }

    void GetInfo(){
        cout << "Name" << Name << endl;
        cout << "Owner name" << OwnerName << endl;
        cout << "Subscribers" << SubscriberCount << endl;
        cout << "Videos" << endl;
        for(string videoTitle: PublishedVideoTitles){
            cout<< videoTitle << endl;
}
    }
};

class CookingYTChannel:public YouTubeChannel{
//this allows the new class to inherit t=fomr the Youtibechannel class
//the publis means everything publis in the base class will be available in the dervived class
public:
    CookingYTChannel(string name, string Ownername):YouTubeChannel(name, Ownername){
//we call the constrcutor from the base class
}   
    void Practice(){
        cout << OwnerName << "practicing cooking"<<endl;
    }//this method is available only for this new class

};

int main(){

CookingYTChannel ytChannel("Perly's kitchen","perly");
ytChannel.GetInfo();

}