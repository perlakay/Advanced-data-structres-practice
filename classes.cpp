#include <iostream>
using namespace std;
#include <list>

class YouTubeChannel {
    //a class is a user defined data type
    //attributes:
public:
    string Name;
    string OwnerName;
    int SubscriberCount;
    list<string> PublishedVideoTitles;
    //if you use a list, then you need to include lists up top


};

int main(){
    
//now you have a class and can create an object 
YouTubeChannel ytChannel;
//first you put the class and then you put the name 
//you want to call the new object, here the first channel is named ytChannel
//if the attributes are not public in the class, they wont be 
//available 

ytChannel.Name = "Perly's art";
ytChannel.OwnerName = "Perly";
ytChannel.SubscriberCount = 1200;
ytChannel.PublishedVideoTitles = {"art1", "art2", "art3"};

cout << "Name" << ytChannel.Name << endl;
cout << "Owner name" << ytChannel.OwnerName << endl;
cout << "Subscribers" << ytChannel.SubscriberCount << endl;
//for a list, you need a loop to print them all out 
cout << "Videos" << endl;
for(string videoTitle: ytChannel.PublishedVideoTitles){
    cout<< videoTitle << endl;
}
//for loop is published a list of type string, and then you can give it a name 
// videoTitle is a variable that stroed the list of videos for only that 
//specific instance of the class aka only for the first object/channel we created 
//aka ytChannel NOT for the whole class


