#include <bits/stdc++.h>
using namespace std;

long long generateNumber(long long num, bool odd)
{
    long long dupnum = num;

    if (odd == true)
        dupnum /= 10;

    while (dupnum != 0)
    {
        num = num * 10 + (dupnum % 10);
        dupnum = dupnum / 10;
    }

    return num;
}

int main()
{
    for (int i = 1; i <= 10; i = i * 10)
    {
        // Odd digit generation
        for (int j = i; j < i * 10; j++)
        {
            cout << generateNumber(j, true) << " ";
        }
        cout << "\n";

        // Even digit generation
        for (int j = i; j < i * 10; j++)
        {
            cout << generateNumber(j, false) << " ";
        }

        cout << "\n";
        cout << "\n";
    }


    return 0;
}