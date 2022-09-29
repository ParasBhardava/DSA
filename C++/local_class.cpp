/*
1. A local class type name can only be used in the enclosing function. For example, in the following program,  
   declarations of t and tp are valid in fun(), but invalid in main().

2. All the methods of Local classes must be defined inside the class only. For example, program 1 works fine and 
   program 2 fails in compilation.

3. A Local class cannot contain static data members. It may contain static functions though. For example, program 1  
   fails in compilation, but program 2 works fine.

4. Member methods of local class can only access static and enum variables of the enclosing function. Non-static  
   variables of the enclosing function are not accessible inside local classes. For example, the program 1 compiles and runs fine. But, program 2 fails in compilation.

5. Local classes can access global types, variables and functions. Also, local classes can access other local 
   classes of same function.. For example, following program works fine
*/

#include <iostream>
using namespace std;

void fun()
{
    // Local class
    class Test
    {

        static int i; //Error

    public:
        // Fine as the method is defined inside the local class
        void method()
        {
            cout << "Local Class method() called";
        }

        // compile fine
        static void method1()
        {
            cout << "Local Class method() called";
        }

    };

    // Error as the method is defined outside the local class
    // void Test::method()
    // {
    //      cout << "Local Class method()";
    // }

    Test t;   // Fine
    Test *tp; // Fine
}

int main()
{
    Test t;   // Error
    Test *tp; // Error
    return 0;
}