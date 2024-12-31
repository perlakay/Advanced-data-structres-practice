#include <iostream>
using namespace std;
#include <list>

class YouTubeChannel {
    
private:
    string Name;
    int SubscriberCount;
    list<string> PublishedVideoTitles;

protected:
    string OwnerName;
    int ContentQuality;


public:
    YouTubeChannel(string name , string ownername){
    Name = name; 
    OwnerName = ownername; 
    SubscriberCount = 0; 
    ContentQuality = 0;

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
    void CheckAnalytics(){
        if(ContentQuality < 5)
         cout<< Name << "has bad quality"<< endl;
        else
            cout << Name << "good quality" <<endl;
    }
};

class CookingYTChannel:public YouTubeChannel{
public:
    CookingYTChannel(string name, string Ownername):YouTubeChannel(name, Ownername){

}   
    void Practice(){
        cout << OwnerName << "practicing cooking"<<endl;
        ContentQuality++;
    
    }
};

class SingersYTChannel:public YouTubeChannel{
public:
    SingersYTChannel(string name, string Ownername):YouTubeChannel(name, Ownername){

}   
    void Practice(){
        cout << OwnerName << "practicing singing"<<endl;
        ContentQuality++;
    }
};
 


int main(){

CookingYTChannel ytChannel("Perly's kitchen","perly");
SingersYTChannel ytChannel2("Perly sings","perly");

ytChannel.Practice();
ytChannel2.Practice();
ytChannel2.Practice();

YouTubeChannel * yt1=&ytChannel;
YouTubeChannel * yt2=&ytChannel2; //pointers to the YT channels
//a pointer from a base class can point to an object of a derived class


yt1->CheckAnalytics();
yt2->CheckAnalytics();

}