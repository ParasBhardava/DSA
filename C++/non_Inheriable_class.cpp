/* A program with compilation error to demonstrate that Final class cannot
be inherited */
#include <iostream>
using namespace std;

class Final; // The class to be made final

class MakeFinal // used to make the Final class final
{
private:
    MakeFinal()
    {
        cout << "MakFinal constructor" << endl;
    }
    friend class Final;
};

class Final : virtual MakeFinal
{
public:
    Final()
    {
        cout << "Final constructor" << endl;
    }
};

class Derived : public Final // Compiler error
{
public:
    Derived()
    {
        cout << "Derived constructor" << endl;
    }
};

int main()
{
    Derived d;
    return 0;
}

// 2nd method using final identifier
/*
#include <iostream>
using namespace std;

class Base final
{
	// body
};
class Derived : public Base // compile error because base class is final
{
	// body
};

int main()
{
    return 0;
}
*/