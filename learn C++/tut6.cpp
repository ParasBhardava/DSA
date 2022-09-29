# include<iostream>

using namespace std;

int main(){
    int a=4, b=5;
    cout<<"operators in c++:"<<endl;
    cout<<"Following are the types of operators in c++"<<endl;

    // Arithmetic operators
    cout<<"The value of  a + b is "<<a+b<<endl;
    cout<<"The value of  a - b is "<<a-b<<endl;
    cout<<"The value of  a * b is "<<a*b<<endl;
    cout<<"The value of  a / b is "<<a/b<<endl;
    cout<<"The value of  a % b is "<<a%b<<endl;
    cout<<"The value of  a++ is "<<a++<<endl;
    cout<<"The value of  a-- is "<<a--<<endl;
    cout<<"The value of  ++a is "<<++a<<endl;
    cout<<"The value of  --a is "<<--a<<endl;

    //Assignment operators - used to assign values of variables
    //int a =3, b=9;
    //char d ='v'

    // Comparison operators
    cout<<"the value of a == b is "<<(a==b)<<endl;
    cout<<"the value of a > b is "<<(a>b)<<endl;
    cout<<"the value of a < b is "<<(a<b)<<endl;
    cout<<"the value of a <= b is "<<(a<=b)<<endl;
    cout<<"the value of a >= b is "<<(a>=b)<<endl;
    cout<<"the value of a != b is "<<(a!=b)<<endl;

    //Logical operators
    cout<<"Following are the logical operators in c++"<<endl;
    cout<<"The value of logical and operator ((a==b) && (a<b)) is:"<<((a==b)&&(a<b))<<endl;
    cout<<"The value of logical or operator ((a==b) || (a<b)) is:"<<((a==b)||(a<b))<<endl;
    cout<<"The value of logical not operator (!(a==b)) is:"<<(!(a==b))<<endl;



    return 0;
}
