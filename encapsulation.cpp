#include <iostream>
using namespace std;
#include <list>

class YouTubeChannel {

//encapsulation means that we make for example the subscribercount member private,
//and then create subscribe and unsubscribe methods which then can increse/decrese the 
//subscribercount member. otherwise a user can just vhange the count, and thats not how you get subscribers, and 
//should not be allowed 

    
private:
    string Name;
    string OwnerName;
    int SubscriberCount;
    list<string> PublishedVideoTitles;

public:
    YouTubeChannel(string name , string ownername){
    Name = name; 
    OwnerName = ownername; 
    SubscriberCount = 0; 
    }

    void Subscribe(){
        SubscriberCount++; //now we can acess the subscribercount in the private class

}
    void Unsubscribe(){
        if (SubscriberCount > 0)
            SubscriberCount--; //so that we dont get -1 subscribers
        
}

    void PublishedVideo(string title){ //takes a strong paramter title 
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

int main(){
 
YouTubeChannel ytChannel("Perly's art", "Perly");

ytChannel.PublishedVideo("art1"); //invoke the publishvideo method we added which taakes the paprameter title 
ytChannel.Subscribe();
ytChannel.GetInfo();


}

