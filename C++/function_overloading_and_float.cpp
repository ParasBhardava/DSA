#include <iostream>
using namespace std;

void test(float s, float t)
{
    cout << "Function with float called ";
}

void test(int s, int t)
{
    cout << "Function with int called ";
}

int main()
{
    test(3.5, 5.6);         // test(3.5f, 5.6f)
    return 0;
}
