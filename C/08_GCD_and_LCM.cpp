#include <bits/stdc++.h>
using namespace std;

int GCD(int num1, int num2)
{
    while (num2 != 0)
    {
        int rem = num1 % num2;
        num1 = num2;
        num2 = rem;
    }
    return num1;
}

int main()
{
    cout << "GCD: " << __gcd(18, 12) << "\n"; // inbuilt function to fing GCD
    cout << "GCD: " << GCD(18, 12) << "\n";
    cout << "LCM: " << 18 * 12 / GCD(18, 12) << "\n";

    return 0;
}

// NOTE :
// A*B = GCD(A, B)*LCM(A, B)