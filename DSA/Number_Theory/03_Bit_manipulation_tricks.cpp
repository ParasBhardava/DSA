#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x = 4;
    int y = 5;

    if (x & 1)
        cout << x << " is odd number\n";
    else
        cout << x << " is even number\n";

    if (y & 1)
        cout << y << " is odd number\n";
    else
        cout << y << " is even number\n";

    // Capital letter to small letter
    char A = 'A';
    char a = (A | (1 << 5));
    cout << a << "\n";

    // small letter to capital letter
    A = (a & (~(1 << 5)));
    cout << A << "\n";

    cout << char(1 << 5) << "\n"; // space
    cout << char('Z' | ' ') << "\n";
    cout << char('z' & '_') << "\n";

    return 0;
}