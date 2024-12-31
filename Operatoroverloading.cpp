#include <iostream>
using namespace std;
#include<string>
#include<list>


struct YouTubeChannel {
    string Name;
    int SubscriberCount;
    //constructor
    YouTubeChannel(string name, int count){
        Name = name;
        SubscriberCount = count;
    }

    bool operator==(const YouTubeChannel&channel) const { // we need to tell the compiler knwo that the parameters will not change by using const 
        return this->Name == channel.Name;
        //checks if the two channels have the same name, and if they do they are equal
        //this overloading is so that we can use the .remove function when overlaoding the -= operator in the MyCollection class 
    }
};
//if you use a class make sure to set the memebrs to public
//members of a class are private my default, members of a struct are public by default

//the rule for naming opertaors is that they need to be called operator, and then the operator you want to overload 
//the two operands need to be passed as parameters 
// cout and COUT are the same, just here we use all caps to differentiate between the two 
//the second operand is youtubecahnnel, now the object is of type YouTubeChannel and we give all object one name here it is ytchannel
//cout is of type ostream so we need to include that here as well
//we use pass by reference when its not cheap to copy like user defined data types, so its easier to pass by refrence (&)
ostream& operator<<(ostream& COUT, YouTubeChannel& ytchannel ){
    COUT<< "Name: " << ytchannel.Name << endl;
    COUT << "Subscribers: " << ytchannel.SubscriberCount << endl;
    //use COUT to reference the object that is the same as the paramter COUT
    return COUT;
    //you need to return an ostream type to do cout << yt1 << yt2;
}
//this one is a global function so you need to pass both parameters/operands 

struct MyCollection{
    list<YouTubeChannel>myChannels;
    //overload the operator as a member function, and then you only need to pass one operand, the one that is not part of this class, so here its yt1 

    void operator+=(YouTubeChannel& channel){
        this->myChannels.push_back(channel); 
        //so 'this' means that we are talking about myChannels aka the first operand which is the list we defined 
        //push back means add to the list of mychannels the second operand aka yt1
        //myChannles is the name of the list we defined in the MyCollection class
        //we only need to pass one operand beacsue we are overloading within the class so the first operand would already be available 
    }
    void operator-=(YouTubeChannel& channel){
        //now to remove channels 
        this->myChannels.remove(channel);
        //in order to remove the function uses the == operator, so we would need to overload that operator as well to use the remove function
        //because it checks if the channels are equal, we need to overload this operator in the YouTubeChannels class
    }
};

ostream& operator<<(ostream& COUT, MyCollection& myCollection){
    //use a loop to print out a list 
    for(YouTubeChannel ytChannel:myCollection.myChannels) {
        COUT << ytChannel << endl;
    //so this loop says for each YouTubeChannel object (which we call ytChannel) in myCollection (which is the variable assigned
    //to all objects of the MyCollection class) in myChannled (the list in the class) print it out for us 
    return COUT;

    }
}



int main(){

YouTubeChannel yt1 = YouTubeChannel("Perly", 100);
YouTubeChannel yt2 = YouTubeChannel("Perly2", 200);

MyCollection myCollection;
myCollection += yt1;
myCollection += yt2;
cout << myCollection; //object of the MyCollection class 
myCollection -= yt2;


//if you wanted to write cout<<yt1 , you would get an error because the insertion operator
// (<<) doesnt knwo how to behave 
// the two operands in this case is - 1: cout and 2: yt1
cout << yt1;

operator<<(cout, yt1); //another way to invoke 

}