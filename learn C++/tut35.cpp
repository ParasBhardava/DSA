#include<iostream>
using namespace std;

//Destructor never takes an argument nor does it return value

int count = 0;
class num
{
public:
    num()
    {
        count++;
        cout<<"This is the time when constructor is called for object number"<<count<<endl;
    }

    ~num(){
        cout<<"This the time when my destructor is called for object number"<<count<<endl;
        count--;
    }
};

int main()
{
    cout<<"We are inside main function"<<endl;
    cout<<"Creating first object n1"<<endl;
    num n1;{
        cout<<"Creating to more objects"<<endl;
        num n2, n3;
        cout<<"Exiting this block"<<endl;
    }
    cout<<"Back to main"<<endl;

    return 0;
}
