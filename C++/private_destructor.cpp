#include <iostream>
#include <cstdlib>

// A class with private destuctor
class Test
{

private:
    ~Test() {}

    friend void destructTest(Test *);
};

// Only this function can destruct objects of Test
void destructTest(Test *ptr)
{
    delete ptr;
}

int main()
{
    // Test t;     // Error because the destructor is private.

    // Test* ptr;    // Fine because there is no object being constructed, the program just creates a pointer of  //
                     // type "Test *"
    
    // Test *ptr = new Test;     // fine because created using dynamic memory allocation, it is programmer’s 
                                //  responsibility to delete it.
    // Test* ptr = (Test*)malloc(sizeof(Test));

    // delete ptr;              // Error because destrutor is private
    // destructTest(ptr);       // fine

    return 0;
}

/* Use
Whenever we want to control destruction of objects of a class, we make the destructor private.
For dynamically created objects, it may happen that you pass a pointer to the object to a function and the function deletes the object.
If the object is referred after the function call, the reference will become dangling.
*/