#include <iostream>
using namespace std;

int main(){

int n=5;
cout<<&n<<endl;
//&n gives the memory adress of the variable 

int * ptr = &n;
//creates a pointer variable called ptr which holds the memeory adress of the variable n
cout<<ptr<<endl;

//dereference means acessing the value stored by the pointer, so here we want to acess the value n is strign which is 5
cout<<*ptr<<endl;
//you use the * bef the pointer to dereference

*ptr=10;
//this will store the value of 10 to the adress that previously held the value of n aka 5
//so now the memeory adress for n/5 is assigned to 10
cout<<*ptr<<endl;
//if you now try to cout the value of the variable n you will get 10 because you reassigned it thourgh memroy adresses 

//your pointer has to be the same type as the variable it is pointing to, so to point to an int, the pointer would have to be of type int 

//(pointers by default are not assigned an adress, you need to initialize them with a varible, which has an adress)


return 0;

}