#include<iostream>
using namespace std;

int main(){
    //What is pointer?-----data type which holds the the address of other data types

    int a = 3;
    int* b = &a;

    // &------ (Address of) opearator
    cout<<"The address of a is "<<&a<<endl;
    cout<<"the address of a is "<<b<<endl;

    //* ------ (Value at) Dereference operator
    cout<<"The value at address b is "<<*b<<endl;

    //Pointer to pointer
    int** c =&b;
    cout<<"The address of b is "<<&b<<endl;
    cout<<"The address of b is "<<c<<endl;
    cout<<"The value at address c is "<<*c<<endl;
    cout<<"The value at address value at(value at(c)) is "<<**c<<endl;

return 0;
}
