#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << a << " " << b << "\n";

    a = a ^ b;
    b = b ^ a;
    a = a ^ b;

    cout << a << " " << b << "\n";

    // XOR operator
    // a ^ 0 = a
    // a ^ a = 0

    return 0;
}