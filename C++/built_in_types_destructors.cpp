// C++ allows even built-in type (primitive types) to have default constructors. The function style cast int() is 
// analogous to casting 0 to required type. 

#include <iostream>
using namespace std;

int main()
{

    cout << int() << endl;
    cout << float() << endl;
    cout << double() << endl;
    cout << char() << endl;

    return 0;
}
