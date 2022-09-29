#include<iostream>
using namespace std;

class Complex
{
    int a, b;
public:
    // Creating a constructor
    //  Constructor is a special member function with same name as of the class.It is automatically invoked whenever
    // the object is created.
    //  It is use to initiallize the objects of its class

    Complex(void);// Constructor declaration

    void printNumber()
    {
        cout<<"Your number is "<<a<<" + "<<b<<"i"<<endl;
    }
};

Complex :: Complex(void) // ---> This is default contructor as no takes perameters
 {
    a = 10;
    b = 0;
    cout<<"Hello Jentleman"<<endl;
}



int main()
{
    Complex c;
    c.printNumber();

    return 0;
}

/* Characteristics of constructors

1. It should be declared in the public section of the class
2. They are automatically invoked whenever the object is created
3. They cannot return values and do not have return types
4. It can have default arguments
5. We cannot refer to the address

*/
