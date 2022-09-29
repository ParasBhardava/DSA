#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int a;
    cin>>a;
    cout<<"Hello World"<<endl;
    cerr << "An error occured"<<endl;
    clog << "An error occured"<<endl;
    return 0;
}

/*
Un-buffered standard error stream (cerr): The C++ cerr is the standard error stream which is used to output the errors. This is also an instance of the iostream class. As cerr in C++ is un-buffered so it is used when one needs to display the error message immediately. It does not have any buffer to store the error message and display later.

buffered standard error stream (clog): This is also an instance of iostream class and used to display errors but unlike cerr the error is first inserted into a buffer and is stored in the buffer until it is not fully filled. or the buffer is not explicitly flushed (using flush()). The error message will be displayed on the screen too.
*/
